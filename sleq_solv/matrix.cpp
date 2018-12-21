#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "matrix.h"

using namespace std;

//=======================================================
//constructors

plain_matrix::plain_matrix()
{
	_arr = NULL;
	_row = 0;
	_col = 0;
}

plain_matrix::plain_matrix(const int n, const int m)
{
	_arr = new double*[n];
    for (int i = 0; i < n; i++)
        _arr[i] = new double [m];
	_arr[1][1] = 10;
	_row = n;
	_col = m;
}

plain_matrix::~plain_matrix()
{
	if (_arr != NULL)	
	{
		for (int i = 0; i < _row; i++) 
			delete [] _arr[i];
		delete [] _arr;
	}
}

//=======================================================
//operators

/*double plain_matrix::operator() (const int i, const int j) const
{
	get(i,j);
}
double& plain_matrix::operator() (const int i, const int j)
{
	return (*this)(i,j);
}*/

//=======================================================
//functions

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
	if (i < row() and j < col())
		return _arr[i][j];
	else
		throw invalid_argument("index out of range");
}

void plain_matrix::set(int i, int j, double num)
{
	if (i < row() or j < col())
		_arr[i][j] = num;
	else
		throw invalid_argument("index out of range");
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
