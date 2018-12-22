#ifndef TMATRIX_H
#define TMATRIX_H

class TMatrix
{
    private:
        TComplex **fM;
        int Nstr, Ncol;
        void Copy(TMatrix&);

    public:
        TMatrix();
        TMatrix(int , int);
        TMatrix(TMatrix&);
        ~TMatrix();

    public:
        TMatrix operator =(TMatrix&);
        friend TMatrix operator +(TMatrix&, TMatrix&);
        friend TMatrix operator -(TMatrix&, TMatrix&);
        friend TMatrix operator *(TComplex, TMatrix&);
        friend TMatrix operator *(TMatrix&, TMatrix&);

        int dim();
        void Input(int, int, TComplex);
        void Output();
        TComplex GetEl(int, int);
        void SetEl(int, int, TComplex);
        void Trans();
        void Tr();
        TMatrix Obr();
        TComplex det();
        TComplex det_1();
};

#endif
