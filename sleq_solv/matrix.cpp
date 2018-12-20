#include "matrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//=======================================================
//plain_matrix::

plain_matrix::plain_matrix()
{
	_arr = NULL;
	_row = 0;
	_col = 0;
}

plain_matrix::plain_matrix(const int n, const int m)
{
	double** _arr = new double*[n];
    for (int i = 0; i < n; i++)
        _arr[i] = new double [m];
	_row = n;
	_col = m;
}

plain_matrix::~plain_matrix()
{
	if ( _arr != NULL )	
	{
		for (int i = 0; i < _row; i++) 
			delete [] _arr[i];
		delete [] _arr;
	}
}

int plain_matrix::col() const
{
	return _col;
}

int plain_matrix::row() const
{
	return _row;
}

double plain_matrix::get(int i, int j) const
{
	if (i >= row() or j >= col())
	{
		cout << "index out of range" << endl;
		exit(0); 
	}
	else
		return _arr[i][j];
}

void plain_matrix::set(int i, int j, int num)
{
	if (i >= row() or j >= col())
	{
		cout << "index out of range" << endl;
		exit(0); 
	}
	else
		_arr[i][j] = num;
}

void plain_matrix::print() const
{
	for(int i = 0; i < row(); i++)
	{
		for(int j = 0; j < col(); j++)
			cout << get(i, j) << " ";
		cout << endl;
	}
}
