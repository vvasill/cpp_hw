#include <iostream>
#include <cstdlib>
#include <stdexcept>

#ifndef CRS_MATRIX_H
	#include "crs_matrix.h"
#endif

using namespace std;

//=======================================================
//constructors

crs_matrix::crs_matrix()
{
	_row = 0;
	_col = 0;
	_arr = NULL;
}

crs_matrix::crs_matrix(const int n, const int m)
{
	_row = n;
	_col = m;
	_arr = new double*[n];
    for (int i = 0; i < n; i++)
        _arr[i] = new double [m];
}

crs_matrix::crs_matrix(const crs_matrix& that)
{
	_row = that.row();
	_col = that.col();
	_arr = new double*[_row];
    for (int i = 0; i < _row; i++)
        _arr[i] = new double [_col];

	for(int i = 0; i < _row; i++)
		for (int j = 0; j < _col; j++)
			_arr[i][j] = that._arr[i][j];
}

crs_matrix::~crs_matrix()
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


//=======================================================
//functions

int crs_matrix::col() const
{
	return _col;
}

int crs_matrix::row() const
{
	return _row;
}

double crs_matrix::get(int i, int j) const
{
	if (i < row() and j < col())
		return _arr[i][j];
	else
		throw invalid_argument("index out of range");
}

void crs_matrix::set(int i, int j, double num)
{
	if (i < row() or j < col())
		_arr[i][j] = num;
	else
		throw invalid_argument("index out of range");
}

void crs_matrix::print() const
{
	for(int i = 0; i < row(); i++)
	{
		for(int j = 0; j < col(); j++)
			cout << get(i, j) << " ";
		cout << endl;
	}
}

void crs_matrix::init(double num)
{
	for(int i = 0; i < row(); i++)
		for(int j = 0; j < col(); j++)
			set(i, j, num);
}

int crs_matrix::max(crs_matrix* that)
{
	int temp = 0;
	return 1;
}
