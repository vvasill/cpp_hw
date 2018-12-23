#ifndef CRS_MATRIX_H
#define CRS_MATRIX_H
	
#ifndef CRS_H
	#include "matrix.h"
#endif

class crs_matrix : public matrix
{
	private:
		int _row;
		int _col;
		double** _arr;
	public:
		crs_matrix();
		crs_matrix(int, int);
		crs_matrix(const crs_matrix&);
		~crs_matrix();		
	
		virtual int row() const;
		virtual int col() const;
		virtual double get(int, int) const;
		virtual void set(int, int, double);
		virtual void print() const;
		virtual void init(double);
		virtual int max(crs_matrix*);
};

#endif // CRS_MATRIX_H
