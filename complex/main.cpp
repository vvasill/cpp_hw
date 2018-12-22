#include <iostream>
#include <fstream>
#include <math.h>
#include "TComplex.h"
#include "TMatrix.h"

using namespace std;

void solve(TMatrix&, TMatrix&, TMatrix&);
void direct(TMatrix&, TMatrix&);
void reverse(TMatrix&, TMatrix&, TMatrix&);

int main()
{
    ifstream f_in;
    f_in.open("data");

    double d;
    int dim = 0;

    f_in >> dim;

    TMatrix a(dim, dim);
    TMatrix a_1(dim, dim);
    TMatrix b(dim, 1);
    TMatrix x(dim, 1);

    TComplex z_1(10.0, 0.0);

    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
        {
            f_in >> d;
            z_1.SetRe(d);
            a.Input(i, j, z_1);
        }

    for (int i = 0; i < dim; i++)
    {
        f_in >> d;
        z_1.SetRe(d);
        b.Input(i, 0, z_1);
    }

    f_in.close();

    //solve(a, b, x);

    //x.Output();

    a_1 = a.Obr();
    (a * a).Output();

    return 0;
}

void solve(TMatrix& a, TMatrix& b, TMatrix& x)
{
    TMatrix temp_a(a.dim(), a.dim());
    TMatrix temp_b(a.dim(), 1);

    temp_a = a;
    temp_b = b;

    a.Output();
    b.Output();

    direct(temp_a, temp_b);
    reverse(temp_a, temp_b, x);
}

void direct(TMatrix& a, TMatrix& b)
{
    TComplex d(0, 0);

    for (int j = 0; j < a.dim() - 1; j++)
        for (int i = j + 1; i < a.dim(); i++)
        {
            d = a.GetEl(i, j)/a.GetEl(j, j);

            for (int k = j; k < a.dim(); k++)
            {
                 a.SetEl(i, k, a.GetEl(i, k) - d * a.GetEl(j, k));
            }

            b.SetEl(i, 0, b.GetEl(i, 0) - d * b.GetEl(j, 0));
        }
}

void reverse(TMatrix& a, TMatrix& b, TMatrix& x)
{
    int n = x.dim() - 1;
    TComplex q(0, 0);

    x.SetEl(n, 0, b.GetEl(n, 0) / a.GetEl(n, n));

    for (int i = n - 1; i >= 0; i--)
    {
        q = b.GetEl(i, 0);
        for (int j = a.dim() - 1; j > i; j--)
            q -= a.GetEl(i, j) * x.GetEl(j, 0);

         x.SetEl(i, 0, q / a.GetEl(i, i));
    }
}
