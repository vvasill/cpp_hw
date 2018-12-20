#include "matrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//constructors

matrix::matrix()
{
	_arr = NULL;
}

matrix::~matrix()
{
	if ( _arr != NULL )	
		delete[] _arr;
}

void matrix::print()
{
	for(int i = 0; i < raw(); i++)
	{
		for(int j = 0; j < col(); j++)
			cout << get(i, j) << " ";
		cout << endl;
	}
}

double_matrix::double_matrix(int n, int m)
{
	_arr = new double[n][m];
	_raw = n;
	_col = m;
}

double_matrix::~double_matrix()
{
}
