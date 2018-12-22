#include <iostream>
#include <cstdlib>
#include <stdexcept>

#ifndef PLAIN_MATRIX_H
	#include "plain_matrix.h"
#endif

using namespace std;

//=======================================================
//constructors

plain_matrix::plain_matrix()
{
	_row = 0;
	_col = 0;
	_arr = NULL;
}

plain_matrix::plain_matrix(const int n, const int m)
{
	_row = n;
	_col = m;
	_arr = new double*[n];
    for (int i = 0; i < n; i++)
        _arr[i] = new double [m];
}

plain_matrix::plain_matrix(const plain_matrix& that)
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

plain_matrix& plain_matrix::operator= (const plain_matrix& that)
{
	if (this != &that)
	{	
		if (_arr != NULL)	
		{
			for (int i = 0; i < _row; i++) 
				delete [] _arr[i];
			delete [] _arr;
		}
	
		_row = that.row();
		_col = that.col();
		_arr = new double*[_row];
    	for (int i = 0; i < _row; i++)
        	_arr[i] = new double [_col];

		for(int i = 0; i < _row; i++)
			for (int j = 0; j < _col; j++)
				_arr[i][j] = that._arr[i][j];
	}
	return *this;
}

/*plain_matrix plain_matrix::operator+ (const plain_matrix& that) const
{
	if (col() == that.col() and row() == that.row()) 
	{ 
		plain_matrix result = plain_matrix(row(), col());

		for(int i = 0; i < row(); i++)
			for(int j = 0; j < col(); j++)
				result.set(i, j, get(i,j) + that.get(i,j));

		return result; 
	}
	else
		throw length_error("operation is forbidden");
}*/

/*plain_matrix plain_matrix::operator- (const plain_matrix& that) const
{
	if (col() == that.col() and row() == that.row()) 
	{ 
		plain_matrix result = plain_matrix(row(), col());

		for(int i = 0; i < row(); i++)
			for(int j = 0; j < col(); j++)
				result.set(i, j, get(i,j) - that.get(i,j));

		return result; 
	}
	else
		throw length_error("operation is forbidden");
}*/

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

void plain_matrix::init(double num)
{
	for(int i = 0; i < row(); i++)
		for(int j = 0; j < col(); j++)
			set(i, j, num);
}
