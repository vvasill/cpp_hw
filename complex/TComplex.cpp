#include <iostream>
#include <math.h>
#include "TComplex.h"

using namespace std;

TComplex::TComplex()
{
    Re = 0;
    Im = 0;
}

TComplex::TComplex(double vRe, double vIm)
{
    Re = vRe;
    Im = vIm;
}

TComplex::~TComplex()
{

}

double TComplex::GetRe()
{
    return Re;
}

double TComplex::GetIm()
{
    return Im;
}

void TComplex::SetRe(double vRe)
{
    Re = vRe;
}

void TComplex::SetIm(double vIm)
{
    Im = vIm;
}

void TComplex::Output()
{
    cout << Re << " + i*" << Im << endl;
}

double TComplex::GetMod()
{
    return(sqrt(Re*Re + Im*Im));
}

TComplex operator +(TComplex a, TComplex b)
{
    TComplex temp;

    temp.Re = a.Re + b.Re;
    temp.Im = a.Im + b.Im;

    return temp;
}

TComplex operator -(TComplex a, TComplex b)
{
    TComplex temp;

    temp.Re = a.Re - b.Re;
    temp.Im = a.Im - b.Im;

    return(temp);
}

TComplex operator *(TComplex a, TComplex b)
{
    TComplex temp;

    temp.Re = a.Re * b.Re - a.Im * b.Im;
    temp.Im = a.Im * b.Re + a.Re * b.Im;

    return temp;
}

TComplex operator /(TComplex a, TComplex b)
{
    TComplex temp;

    temp.Re = (a.Re * b.Re + a.Im * b.Im)/(pow(b.Re, 2) + pow(b.Im, 2));
    temp.Im = (a.Im * b.Re - a.Re * b.Im)/(pow(b.Re, 2) + pow(b.Im, 2));

    return temp;
}

TComplex TComplex::operator =(TComplex m)
{
    TComplex temp;

    Re = m.Re;
    Im = m.Im;

    temp.Re = Re;
    temp.Im = Im;

    return(temp);
}

TComplex TComplex::operator +=(TComplex m)
{
    TComplex temp;

    Re += m.Re;
    Im += m.Im;

    temp.Re = Re;
    temp.Im = Im;

    return(temp);
}

TComplex TComplex::operator -=(TComplex m)
{
    TComplex temp;

    Re -= m.Re;
    Im -= m.Im;

    temp.Re = Re;
    temp.Im = Im;

    return(temp);
}

TComplex TComplex::operator *=(TComplex m)
{
    TComplex temp;

    temp.Re = Re * m.Re - Im * m.Im;
    temp.Im = Im * m.Re + Re * m.Im;

    return temp;
}

TComplex TComplex::operator /=(TComplex m)
{
    TComplex temp;

    temp.Re = (Re * m.Re + Im * m.Im)/(pow(m.Re, 2) + pow(m.Im, 2));
    temp.Im = (Im * m.Re - Re * m.Im)/(pow(m.Re, 2) + pow(m.Im, 2));

    return temp;
}
