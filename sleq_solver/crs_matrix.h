#ifndef CRS_MATRIX_H
#define CRS_MATRIX_H
	
#ifndef MATRIX_H
	#include "matrix.h"
#endif

class crs_matrix : public matrix
{
	private:
		int _row = 0;
    	int _col = 0;
		int _nzn = 0;
		double* _MEl;
		int* _CI;
		int* _SII;
	public:
		crs_matrix();
		crs_matrix(const int, const int, const int);
		crs_matrix(const int, const int, const int, double*, double*, double*);
		crs_matrix(const int, const int, const double**);
		crs_matrix(const crs_matrix&);
		~crs_matrix();		
	
		virtual int row() const;
		virtual int col() const;
		virtual double get(int, int) const;
		virtual void set(int, int, double);
		virtual void print() const;
		void init(const int, const int);
	
		crs_matrix* operator= (const crs_matrix* that);	
		virtual matrix* operator+ (const matrix* that) const;		
		virtual matrix* operator- (const matrix* that) const;	
		virtual matrix* operator* (const matrix* that) const;
};

#endif // CRS_MATRIX_H
