#include "matrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//=======================================================
//plain_matrix::

plain_matrix::plain_matrix()
{
	_arr = NULL;
	_raw = 0;
	_col = 0;
}

plain_matrix::plain_matrix(int n, int m)
{
	_raw = n;
	_col = m;
	double **_arr = new double*[m];
	for (int i = 0; i < n; i++)	
		_arr[i] = new double[m];
}

plain_matrix::~plain_matrix()
{
	for (int i = 0; i < raw(); i++)	
		delete [] _arr[i];
	delete [] _arr;
}

int plain_matrix::col() const
{
	return _col;
}

int plain_matrix::raw() const
{
	return _raw;
}

double plain_matrix::get(int i, int j) const
{
	if (i >= raw() or j >= col())
	{
		cout << "index out of range" << endl;
		exit(0); 
	}
	else
		return _arr[i][j];
}

void plain_matrix::set(int i, int j, int num)
{
	if (i >= raw() or j >= col())
	{
		cout << "index out of range" << endl;
		exit(0); 
	}
	else
		_arr[i][j] = num;
}

void plain_matrix::print() const
{
	for(int i = 0; i < raw(); i++)
	{
		for(int j = 0; j < col(); j++)
			cout << get(i, j) << " ";
		cout << endl;
	}
}
