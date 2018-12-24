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

crs_matrix::crs_matrix(int n, int m, int nzn)
{
	_row = n;
	_col = m;
	_nzn = nzn;
	_MEl = NULL;
	_CI = NULL;
	_SII = new double[_row + 1];
	for (int i = 0; i < _row + 1; i++)
        _SII[i] = 0;
}

crs_matrix::crs_matrix(int n, int m, int k, double* a, double* b, double* c)
{
	_row = n;
	_col = m;
	_nzn = 0;

	//smth
}

crs_matrix::crs_matrix(int n, int m, double** that)
{
	_row = n;
	_col = m;
	_nzn = 0;

	//smth    
}

crs_matrix::crs_matrix(const crs_matrix* that)
{
	_row = that->row();
	_col = that->col();
	_nzn = that->nzn();
	_MEl = new double*[_nzn];
	_CI = new double*[_nzn];
	_SII = new double*[_row + 1];

	for(int i = 0; i < _nzn; i++)
		_MEl[i] = that->_MEl[i];
	for(int j = 0; j < _nzn; j++)
		_CI[i] = that->_CI[i];
	for(int j = 0; j < _row+1; j++)
		_SII[i] = that->_SII[i];
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

crs_matrix* crs_matrix::operator= (const crs_matrix* that)
{
	if ((_col == that->_col) and (_str == that->_str) and (_nzn == that->_nzn)) 
	{
		for (int i = 0; i < _nzn; i++) 
		{
			_MEl[i] = that->_MEl[i];
			_CI[i] = that->_CI[i];
        }
	
		for (int i = 0; i < _row; i++)
			_SII[i] = that->_SII[i];
	}
	else
	{
		delete [] _MEl;
        delete [] _CI;
        delete [] _SII;

        _MEl = new double[that->_nzn];
        _CI = new int[that->_nzn];
        _SII = new int[that->_row + 1];
		_row = that->_row;     	
		_col = that->_col;

        for (int i = 0; i < _row + 1; i++)
            _SII[i] = that->_SII[i];
       
        for (int i = 0; i < _nzn; i++)
		{
			_MEl[i] = that->_MEl[i];
			_CI[i] = that->_CI[i];
        }
	}

	return this;
}

matrix* operator+ (const matrix* that) const
{
	crs_matrix* res_ptr = new crs_matrix(row(), col(), nzn());

	int d = 0;
	if (col() == that->col() and row() == that->row()) 
	{
		res_ptr->_row = _row;		
		res_ptr->_col = _col;
        res_ptr->_CI = new int[_nzn + that->_nzn];
        res_ptr->_SII = new int[_row + 1];
        res_ptr->_SII[0] = 0;

		for (int i = 0; i < _nzn + that->_nzn; i++)
			res_ptr->CI[i] = 0;
	
		int *temp = new int[_col];
      	for (int i = 0; i < _col; i++)
          	temp[i] = 0;
       
		 for (int k = 0; k < _row; k++) {
            for (int j = _SII[k]; j < _SII[k + 1]; j++)
                temp[_CI[j]] = 1;

			for (int j = that->SII[l]; j < that->SII[l + 1]; j++)
				temp[that->_CI[j]] = 1;
	
			for (int i = 0; i < _col(); i++)
				if (temp[i] == 1) 
				{
                    res_ptr->_CI[d] = i;
                    temp[i] = 0;
                    d++;
                }

            res_ptr->SII[l + 1] = d;
        }

        if (d < _nzn + that->_nzn)
		{
            int *tmp_CI = new int[d];
            for (int i = 0; i < d; i++)
                tmp_CI[i] = res_ptr->CI[i];
            
            delete [] res_ptr->CI;
            res_ptr->_CI = tmp_CI;
        }

        res_ptr->_MEl = new double[d];
        for (int i = 0; i < d; i++)
            res_ptr->_MEl[i] = 0;
      
        double *temp_el = new double[_col];
        for (int i = 0; i < _col; i++)
            temp_el[i] = 0;

        for (int l = 0; l < _row; l++)
		{
            for (int j = _SII[l]; j < _SII[l + 1]; j++) 	
				temp_el[_CI[j]] = _MEl[j];

            for (int j = that->SII[l]; j < that->_SII[l + 1]; j++)
            	temp_el[that->_CI[j]] += that->_MEl[j];

            for (int i = res_ptr->_SII[l]; i < res_ptr->_SII[l + 1]; i++)	
				res_ptr->_MEl[i] = temp_el[res_ptr->_CI[i]];

			for (int i = 0; i < _col; i++)
           		temp_el[i] = 0;
        }
   
		return res_ptr;
	}
	else
		throw length_error("operation is forbidden");
}

matrix* operator- (const matrix* that) const
{
	crs_matrix* res_ptr = new crs_matrix(row(), col(), nzn());
	return res_ptr;
}

matrix* operator* (const matrix* that) const
{
	crs_matrix* res_ptr = new crs_matrix(row(), col(), nzn());
	return res_ptr;
}

//=======================================================
//functions

int crs_matrix::row() const
{
	return _row;
}

int crs_matrix::col() const
{
	return _col;
}

int crs_matrix::nzn() const
{
	return _nzn;
}

double crs_matrix::get(int i, int j) const
{
	if (i < row() and j < col())
	{
		double temp;
    	for (int k = _SII[i]; k < _SII[i + 1]; k++)
    	    if (_CI[k] == j)
    	        temp = _MEl[k];
    	return temp;
	}
	else
		throw invalid_argument("index out of range");
}

void crs_matrix::set(int i, int j, double num)
{
	if (i < row() or j < col())
	{
		if (get(i, j) == 0) 
		{
			_SII[_row]++;
    		double *tmp_MEl = new double[_SII[_row]];
    		int *tmp_CI = new int[_SII[_row]];
    		for (int k = 0; k < _SII[_row]; k++) 
			{
				tmp_MEl[k] = _MEl[k];
				tmp_CI[k] = _CI[k];
    		}
		
			tmp_MEl[k] = num;
			tmp_CI[k] = j;
	
			for (int m = k + 1; m < _SI[_row]; m++) 
			{
				tmp_MEl[m] = _MEl[m - 1];
        		tmp_CI[m] = _CI[m - 1];
  			}
	
			for (k = i; k < Nstr - 1; k++) 
				_SI[k + 1]++;
	
			delete [] _MEl;
			delete [] _CI;

			_MEl = tmp_MEl;
			_CI = tmp_CI;
		}
		if (num == 0)
		{
			//smth
			exit(0);
		}
		else
		{
			for (int k = _SII[i]; k < _SII[i + 1]; k++) 
				if (_CI[k] == j) 
					_MEl[k] = num;
		}
	}
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

void crs_matrix::init()
{
	_MEl = {1, 5, 2, 3, 7, 9};
	_CI = {1, 0, 3, 2, 1, 3};
	_SII = {0, 1, 3, 4, 6};
}

matrix* crs_matrix::tr() const
{
	crs_matrix* res_ptr = new crs_matrix(row(), col(), nzn());

    res_ptr->_row = col();
    res_ptr->_col = row();
	res_ptr->_nzn = nzn();

    res_ptr->_MEl = new double[_nzn];
    res_ptr->_CI = new int[_nzn];
    res_ptr->_SII = new int[_row + 1];

    for (int i = 0; i < _nzn; i++)
	{
        res_ptr->_MEl[i] = 0;
        res_ptr->_CI[i] = 0;
    }
	
    for (int i = 0; i < _nzn + 1; i++)
		res_ptr->_SII[i] = 0;

    for (int i = 0; i < _nzn; i++)
		res_ptr->_SII[_CII[i] + 1]++;

    for (int i = 0; i < res_ptr->_row; i++)
        res_ptr->_SII[i + 1] += res_ptr->_SII[i];

    for (int i = 0; i < _row; i++)
        for (int j = A.StrInpt[i]; j < A.StrInpt[i + 1]; j++)
		{
			res_ptr->_MEl[res_ptr->_SII[_CI[j]]] = _MEl[j];
			res_ptr->_CI[res_ptr->SII[_CI[j]]] = i;
			res_ptr->_SII[_CI[j]]++;
        }

    for (int i = res_ptr->_row; i > 0; i--)
        res_ptr->_SII[i] = res_ptr->_SII[i - 1];
	
    res_ptr->SII[0] = 0;

    return res_ptr;
}
