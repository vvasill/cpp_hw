#ifndef PLAIN_MATRIX_H
#define PLAIN_MATRIX_H
	
#ifndef MATRIX_H
	#include "matrix.h"
#endif

class plain_matrix : public matrix
{
	private:
		int _row;
		int _col;
		double** _arr;
	public:
		plain_matrix();
		plain_matrix(int, int);
		plain_matrix(const plain_matrix&);
		~plain_matrix();		
	
		virtual int row() const;
		virtual int col() const;
		virtual double get(int, int) const;
		virtual void set(int, int, double);
		virtual void print() const;
		virtual matrix* tr() const;
		virtual matrix* abs();

		plain_matrix* operator= (const plain_matrix* that);	
		virtual matrix* operator+ (const matrix* that);		
		virtual matrix* operator- (const matrix* that);	
		virtual matrix* operator* (const matrix* that);
};

#endif // PLAIN_MATRIX_H
