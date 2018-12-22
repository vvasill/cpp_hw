#include <iostream>
#include <math.h>
#include <iomanip>
#include "TComplex.h"
#include "TMatrix.h"
#define eps 10E-14

using namespace std;

TMatrix::TMatrix()
{
    Nstr = 0;
    Ncol = 0;

    fM = new TComplex* [Nstr];
    for (int i = 0; i < Nstr; i++)
        fM[i] = new TComplex [Ncol];

    fM = NULL;
}

TMatrix::TMatrix(int n, int m)
{
    TComplex z(0, 0);

    Nstr = n;
    Ncol = m;

    fM = new TComplex* [Nstr];
    for (int i = 0; i < Nstr; i++)
        fM[i] = new TComplex [Ncol];

    for (int i = 0; i < Nstr; i++)
        for (int j = 0; j < Ncol; j++)
            fM[i][j] = z;
}

TMatrix::TMatrix(TMatrix& a)
{
    Copy(a);
}

TMatrix::~TMatrix()
{
    for (int i = 0; i < Nstr; i++)
        delete [] fM[i];
    delete fM;
}

int TMatrix::dim()
{
    return(Nstr);
}

TComplex TMatrix::GetEl(int x, int y)
{
    return(fM[x][y]);
}

void TMatrix::SetEl(int x, int y, TComplex m)
{
    fM[x][y] = m;
}

void TMatrix::Copy(TMatrix& a)
{
    Nstr = a.Nstr;
    Ncol = a.Ncol;

    fM = new TComplex* [Nstr];
    for (int i = 0; i < Nstr; i++)
        fM[i] = new TComplex [Ncol];

    for (int i = 0; i < Nstr; i++)
        for (int j = 0; j < Ncol; j++)
            fM[i][j] = a.fM[i][j];
}

void TMatrix::Tr()
{
    TComplex d(0, 0);

    for (int j = 0; j < Ncol - 1; j++)
        for (int i = j + 1; i < Nstr; i++)
        {
            d = fM[i][j]/fM[j][j];

            for (int k = j; k < Ncol; k++)
            {
                 fM[i][k] = fM[i][k] - d * fM[j][k];
                 //if (fabs(fM[k][j].GetRe()) <= fabs(fM[Nstr - 1][Nstr - 1].GetRe()) * eps) fM[k][j].SetRe(0);
                 //if (fabs(fM[k][j].GetIm()) <= fabs(fM[Nstr - 1][Nstr - 1].GetIm()) * eps) fM[k][j].SetIm(0);
            }
        }
}

TMatrix TMatrix::Obr()
{
    TMatrix temp(Nstr, Ncol);

    temp.Copy(*this);

    temp.Output();

    TMatrix E(Ncol, Nstr);

    for (int i = 0; i < Nstr; i++)
        for (int j = 0; j < Ncol; j++)
        {
            if (i == j) E.fM[i][j] = TComplex(1, 0);
            else
                E.fM[i][j] = TComplex(0, 0);
        }

    TComplex d(0, 0);

    for (int j = 0; j < Ncol - 1; j++)
        for (int i = j + 1; i < Nstr; i++)
        {
            d = temp.fM[j][j];

            for (int k = j; k < Ncol; k++)
            {
                E.fM[j][k] = E.fM[j][k] / d;
                E.fM[i][k] -= temp.fM[i][j] * E.fM[j][k];

                temp.fM[j][k] = temp.fM[j][k] / d;
                temp.fM[i][k] -= temp.fM[i][j] * temp.fM[j][k];
            }
        }

    temp.fM[Nstr - 1][Ncol - 1] = temp.fM[Nstr - 1][Ncol - 1]/temp.fM[Nstr - 1][Ncol - 1];
    E.fM[Nstr - 1][Ncol - 1] = E.fM[Nstr - 1][Ncol - 1] / temp.fM[Nstr - 1][Ncol - 1];

    for (int j = Ncol - 1; j > 0; j--)
        for (int i = j - 1; i >= 0; i--)
        {
            for (int k = Ncol - 1; k >= j; k--)
            {
                E.fM[i][k] -= temp.fM[i][j] * E.fM[j][k];
                temp.fM[i][k] -= temp.fM[i][j] * temp.fM[j][k];
            }
        }

    return E;
}

TMatrix TMatrix::operator =(TMatrix &a)
{
    if (&a == this) return a;
    else
    {
        for (int i = 0; i < Nstr; i++)
             delete [] fM[i];
        delete fM;

        Copy(a);

        return *this;
    }
}

void TMatrix::Input(int i, int j, TComplex M)
{
    fM[i][j] = M;
}

void TMatrix::Output()
{
    for (int i = 0; i < Nstr; i++)
    {
        for (int j = 0; j < Ncol; j++)
            cout << setw(3) << fM[i][j].GetRe() << " + i*" << fM[i][j].GetIm() << "  ";
        cout << endl;
    }
    cout << endl;
}

void TMatrix::Trans()
{
    for (int i = 0; i < Nstr; i++)
        for (int j = 0; j < Ncol; j++)
             if (i > j)
             {
                 fM[i][j] = fM[i][j] + fM[j][i];
                 fM[j][i] = fM[i][j] - fM[j][i];
                 fM[i][j] = fM[i][j] - fM[j][i];
             }
}

TComplex TMatrix::det_1()
{
    TComplex temp(1, 0);

    if (Nstr > 1)
    {
        TMatrix a(Nstr - 1, Ncol - 1);

        for (int j = 0; j < Ncol; j++)
        {
            int t = 0;

            for (int i = 1; i < Nstr; i++)
                for (int s = 0; s < Ncol; s++)
                {
                    if (s == j) ++t;
                    else
                        a.fM[i - 1][j - t] = fM[i][s];
                }

            temp = temp + TComplex(pow(-1, j), pow(-1, j)) * fM[0][j] * a.det();
        }
    }
    else
        temp = fM[0][0];

    return temp;
}

TComplex TMatrix::det()
{
    TComplex temp(1, 0);

    Tr();

    for (int i = 0; i < Nstr; i++)
        for (int j = 0; j < Ncol; j++)
            if (i == j) temp = temp * fM[i][j];

    return temp;
}

TMatrix operator +(TMatrix& a, TMatrix& b)
{
    if (a.Nstr != b.Nstr && a.Ncol != b.Ncol)
    {
        cout << "undefined operation";
    }
    else
    {
        TMatrix temp(a.Nstr, a.Ncol);

        for (int i = 0; i < a.Nstr; i++)
            for (int j = 0; j < a.Ncol; j++)
                temp.fM[i][j] = a.fM[i][j] + b.fM[i][j];

        return temp;
    }
}

TMatrix operator -(TMatrix& a, TMatrix& b)
{
    if (a.Nstr != b.Nstr && a.Ncol != b.Ncol)
    {
        cout << "undefined operation";
    }
    else
    {
        TMatrix temp(a.Nstr, a.Ncol);

        for (int i = 0; i < a.Nstr; i++)
            for (int j = 0; j < a.Ncol; j++)
                temp.fM[i][j] = a.fM[i][j] + b.fM[i][j];

        return temp;
    }
}

TMatrix operator *(TComplex t, TMatrix& a)
{
    TMatrix temp(a.Nstr, a.Ncol);

    for (int i = 0; i < a.Nstr; i++)
        for (int j = 0; j < a.Ncol; j++)
            temp.fM[i][j] = t * a.fM[i][j];

    return temp;
}

TMatrix operator *(TMatrix& a, TMatrix& b)
{
    if (a.Nstr != b.Ncol)
    {
        cout << "undefined operation";
    }
    else
    {
        TMatrix temp(a.Nstr, a.Ncol);

        for (int i = 0; i < a.Nstr; i++)
            for (int j = 0; j < a.Ncol; j++)
                for (int s = 0; s < a.Nstr; s++)
                temp.fM[i][j] = a.fM[i][s] * b.fM[s][j];

        return temp;
    }
}
