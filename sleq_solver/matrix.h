#ifndef MATRIX_H
#define MATRIX_H

class matrix
{
	public:
		virtual int row() const = 0;
		virtual int col() const = 0;
		virtual double get(int, int) const = 0;
		virtual void set(int, int, double) = 0;		
		virtual void print() const = 0;	
		virtual void init(double) = 0;
		virtual matrix* tr() const = 0;
		virtual matrix* abs() = 0;

		virtual matrix* operator+ (const matrix* that) const = 0;		
		virtual matrix* operator- (const matrix* that) const = 0;	
		virtual matrix* operator* (const matrix* that) const = 0;
};

#endif // MATRIX_H
