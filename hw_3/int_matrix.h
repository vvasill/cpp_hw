#ifndef INT_MATRIX_H
#define INT_MATRIX_H

#include "int_arr.h"

class int_matrix : public int_arr
{
	private:
		int _colnum;
		int_matrix();
	public:
		int_matrix(int, int);
		int_matrix(const int_matrix &);
		~int_matrix();	
		
		int matrix_get(int, int);
		void matrix_set(int, int, int);
		void print_matrix();

		int_matrix& operator= (const int_matrix&);
		int operator[] (const int) const;
		int_arr& operator+= (const int_arr&);
		int_arr& operator-= (const int_arr&);
		friend int_arr operator+ (const int_arr, const int_arr);
		int_arr operator- (const int_arr&);
		int_arr operator* (const int_arr&);	
		int_arr operator& (const int_arr);
};

#endif // INT_MATRIX_H
