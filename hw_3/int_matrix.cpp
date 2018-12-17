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
	_colnum = n;
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
}	
		
int_matrix int_matrix::operator& (const int_matrix& that)
{
	int_arr::operator& (that);
}

//----------------------------------------------------------------------------------------------
//functions
int int_matrix::matrix_get(int i, int j)
{
	get(j + i*_colnum);
}

void int_matrix::matrix_set(int i, int j, int num)
{
	set(j + i*_colnum, num);
}

void int_matrix::print_matrix()
{
	for(int i = 0; i < int(size()/_colnum); i++)
	{
		for(int j = 0; j < _colnum; j++)
			cout << matrix_get(i, j) << " ";
		cout << endl;
	}
}
