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
	if	(size%n == 0)
	{
		_colnum = n;	
	}
	else
	{
		cout << "operation is forbidden" << endl;
		exit(0);
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
	result._colnum = this->_colnum;
	return result;
}

int_matrix int_matrix::operator- (const int_matrix& that)
{
	int_matrix result = int_matrix();
	result = int_arr::operator- (that);
	result._colnum = this->_colnum;
	return result;
}

int_matrix int_matrix::operator* (const int_matrix& that)
{
	/*for(int i = 0; i < ; i++)
	{
		for(int j = 0; j < _colnum; j++)
			cout << matrix_get(i, j) << " ";
		cout << endl;
	}*/
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
