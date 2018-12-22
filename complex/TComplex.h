#ifndef TCOMPLEX_H
#define TCOMPLEX_H

class TComplex
{
    private:
        double Re,Im;

    public:
        TComplex();
        TComplex(double, double);
        ~TComplex();

    public:
        double GetRe();
        double GetIm();

        void SetRe(double);
        void SetIm(double);
        void Output();
        double GetMod();

        friend TComplex operator +(TComplex, TComplex);
        friend TComplex operator -(TComplex, TComplex);
        friend TComplex operator *(TComplex, TComplex);
        friend TComplex operator /(TComplex, TComplex);
        TComplex operator +=(TComplex);
        TComplex operator -=(TComplex);
        TComplex operator *=(TComplex);
        TComplex operator /=(TComplex);
        TComplex operator =(TComplex);
};

#endif // TCOMPLEX_H
