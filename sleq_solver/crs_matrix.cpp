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
	_nzn = 0;
	_MEl = NULL;
	_CI = NULL;
	_SII = NULL;
}

crs_matrix::crs_matrix(const int n, const int m, const int nzn)
{
	_row = n;
	_col = m;
	_nzn = nzn;
	_MEl = NULL;
	_CI = NULL;
	_SII = new double[n+1];
	for (int i = 0; i < n+1; i++)
        _SII[i] = 0;
}

crs_matrix::crs_matrix(const int n, const int m, const int k, double* a, double* b, double* c)
{
	_row = n;
	_col = m;
	_nzn = 0;

	//smth
}

crs_matrix::crs_matrix(const int n, const int m, const double** that)
{
	_row = n;
	_col = m;
	_nzn = 0;

	//smth    
}

crs_matrix::crs_matrix(const crs_matrix& that)
{
	/*_row = that.row();
	_col = that.col();
	_arr = new double*[_row];
	_CI = new double*[_row;
	_SII = new double*[_row];

	for(int i = 0; i < _row; i++)
		for (int j = 0; j < _col; j++)
			_arr[i][j] = that._arr[i][j];*/
}

crs_matrix::~crs_matrix()
{
	if (_MEl != NULL)	
		delete [] _MEl;	
	if (_CI != NULL)	
		delete [] _CI;	
	if (_SII != NULL)	
		delete [] _SII;
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

void crs_matrix::init(const int min, const int max)
{
	for(int i = 0; i < _nzn; i++)
		_MEl[i] = int( ( float(rand())/RAND_MAX * max ) ) + min;
	for(int j = 0; j < _nzn; j++)
		_CI = int( ( float(rand())/RAND_MAX * _col ) ) + 1;
	for(int k = 0; k < col(); k++)
		_SII[i] = ;
}
