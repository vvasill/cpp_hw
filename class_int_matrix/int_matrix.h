#ifndef INT_MATRIX_H
#define INT_MATRIX_H

#if !defined(INT_ARR_H)
	#include "int_arr.h"
#endif

class int_matrix : public int_arr
{
	private:
		int _col;
		int_matrix();
	public:
		int_matrix(int, int);
		int_matrix(const int_matrix&);
		int_matrix(const int_arr&);
		~int_matrix();	
		
		int col() const;
		int row() const;
		int get_el(int, int) const;
		int_arr vec_from_col(int) const;
		int_arr vec_from_row(int) const;
		void set_el(int, int, int);
		void print_matrix() const;
		int_matrix tr() const;

		int_matrix& operator= (const int_matrix&);
		int_matrix& operator= (const int_arr&);
		int operator() (const int, const int) const;
		int& operator() (const int, const int);
		int_matrix& operator+= (const int_matrix&);
		int_matrix& operator-= (const int_matrix&);
		int_matrix operator+ (const int_matrix&) const;
		int_matrix operator- (const int_matrix&) const;
		int_matrix operator* (const int_matrix&) const;	
		int_matrix operator& (const int_matrix&) const;
};

#endif // INT_MATRIX_H
