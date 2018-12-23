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
	_MEl = NULL;
	_CI = NULL;
	_SII = NULL;
}

crs_matrix::crs_matrix(const int n, const int m)
{
	_row = n;
	_col = m;
	_MEl = NULL;
	_CI = NULL;
	_SII = new double[n+1];
	for (int i = 0; i < n+1; i++)
        _SII[i] = 0;
}

crs_matrix::crs_matrix(const int n, const int m, const double** that)
{
	_row = n;
	_col = m;
	int q = 0, number = 0;

    for (int i = 0; i < _row; i++)
        for (int j = 0; j < _col; j++)
            if (that[i][j] != 0.0)
				number++;

    _MEl = new double[number];
    _CI = new int[number];
    _SII = new int[_row + 1];
    int *temp = new int[number];

    temp[0] = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < ; j++) {
            if (Mat(i, j) != 0) {
                element[q] = Mat(i, j);
                ColIndex[q] = j;
                nStrInpt[q] = i;
                q++;
            }
        }
    }

    bool par = true;
    int g = 1, s = 0, d = 0, k = 0;

    for (int l = 0; l <= number; l++) {
        // if start lines are zeros
        if (nStrInpt[l] > 0 && s == 0) {
            g = nStrInpt[l] - 1;
            for (int f = 0; f <= g; f++) {
                StrInpt[k] = d;
                k++;
            }
        }
        // nonzero lines
        if (nStrInpt[l] != nStrInpt[l - 1] && s == 1) {
            par = true;
            d++;
            g = nStrInpt[l] - nStrInpt[l - 1];
            if (g > 1) {
                for (int f = 1; f < g; f++) {
                    StrInpt[k] = d;
                    k++;
                }
            }
        }
        if (par) {
            StrInpt[k] = d;
            k++;
            par = false;
        } else d = d + 1;
        s = 1;
    }

    // if last lines are zeros
    if (k != Mat.getNstr() + 1) {
        int h = (Mat.getNstr() + 1 - k);
        for (int f = 0; f < h; f++) {
            StrInpt[k] = d;
            k++;
        }
    }

    StrInpt[Mat.getNstr()] = number;
}

crs_matrix::crs_matrix(const crs_matrix& that)
{
	_row = that.row();
	_col = that.col();
	_arr = new double*[_row];
	_CI = new double*[_row;
	_SII = new double*[_row];

	for(int i = 0; i < _row; i++)
		for (int j = 0; j < _col; j++)
			_arr[i][j] = that._arr[i][j];
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
