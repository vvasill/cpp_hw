#include "int_matrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//constructors

int_matrix::int_matrix() : int_arr()
{
	_colnum = 0;
}

int_matrix::int_matrix(int size, int n) : int_arr(size) 
{
	if	(size%n != 0)
	{
		cout << "operation is forbidden" << endl;
		exit(0);	
	}
	else
	{
		_colnum = n;
	}
}

int_matrix::int_matrix(const int_matrix& that) : int_arr(that)
{
    _colnum = that._colnum;
}

int_matrix::int_matrix(const int_arr& that) : int_arr(that)
{
    _colnum = 0;
}

int_matrix::~int_matrix()
{
}

//----------------------------------------------------------------------------------------------
//operators

int_matrix& int_matrix::operator= (const int_matrix& that)
{
	_colnum = that._colnum;
	return *this;
}

int_matrix& int_matrix::operator= (const int_arr& that)
{
	_colnum = 0;
	return *this;
}

int int_matrix::operator() (const int i, const int j)
{
	get(j + i*_colnum);
}

int_matrix& int_matrix::operator+= (const int_matrix& that)
{
	int_arr::operator+= (that);
	_colnum = 0;
	return *this;
}

int_matrix& int_matrix::operator-= (const int_matrix& that)
{
	int_arr::operator-= (that);
	_colnum = 0;
	return *this;
}

int_matrix int_matrix::operator+ (const int_matrix& that)
{
	int_matrix result = int_matrix();
	result = int_arr::operator+ (that);
	result._colnum = col();
	return result;
}

int_matrix int_matrix::operator- (const int_matrix& that)
{
	int_matrix result = int_matrix();
	result = int_arr::operator- (that);
	result._colnum = col();
	return result;
}

int_matrix int_matrix::operator* (const int_matrix& that)
{
	if	(size%n != 0)
	{
		cout << "operation is forbidden" << endl;
		exit(0);	
	}
	else
	{
		int temp;
		for(int i = 0; i < raw(); i++)
		{
			for(int j = 0; j < col(); j++)
			{
				temp = this->(i,j)*that.(i,j) + this->(i,j)*that.(i,j);
				matrix_set(i,j,temp);
			}
		}
	}
}	
		
int_matrix int_matrix::operator& (const int_matrix& that)
{
	int_arr::operator& (that);
}

//----------------------------------------------------------------------------------------------
//functions
int int_matrix::col()
{
	return _colnum;
}

int int_matrix::raw()
{
	int rawnum = int(size()/col());
	return rawnum;
}

int int_matrix::matrix_get(int i, int j)
{
	get(j + i*col());
}

void int_matrix::matrix_set(int i, int j, int num)
{
	set(j + i*col(), num);
}

void int_matrix::print_matrix()
{
	for(int i = 0; i < raw(); i++)
	{
		for(int j = 0; j < col(); j++)
			cout << matrix_get(i, j) << " ";
		cout << endl;
	}
}
