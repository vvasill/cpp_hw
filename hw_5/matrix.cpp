#include "matrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

matrix::matrix( int row, int col )
{
 	
	_m = new int [];
	_row = row;	
	_col = col;

}

matrix::matrix()
{

	_m = NULL;
	_row = 0;
	_col = 0;

}

matrix::~matrix()
{

	if ( _m != NULL )	
		delete [] _m;

}

int matrix::det()
{
}

void init( int min, int max )
{
}

void print_arr()
{
}
