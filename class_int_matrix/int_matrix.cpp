#include "int_matrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//======================================================================================
//constructors

int_matrix::int_matrix() : int_arr()
{
	_col = 0;
}

int_matrix::int_matrix(int size, int n) : int_arr(size) 
{
	if	(size%n == 0)
		_col = n;
	else
		throw length_error("length error");
}

int_matrix::int_matrix(const int_matrix& that) : int_arr(that)
{
    _col = that._col;
}

int_matrix::int_matrix(const int_arr& that) : int_arr(that)
{
    _col = 0;
}

int_matrix::~int_matrix()
{
}

//======================================================================================
//operators

int_matrix& int_matrix::operator= (const int_matrix& that)
{
	int_arr::operator= (that);
	_col = that.col();
	return *this;
}

int_matrix& int_matrix::operator= (const int_arr& that)
{
	int_arr::operator= (that);
	_col = 0;
	return *this;
}

int int_matrix::operator() (const int i, const int j) const
{
	get(j + i*col());
}

int& int_matrix::operator() (const int i, const int j)
{
	return (*this)[j + i*col()];
}

int_matrix& int_matrix::operator+= (const int_matrix& that)
{
	int_arr::operator+= (that);
	_col = 0;
	return *this;
}

int_matrix& int_matrix::operator-= (const int_matrix& that)
{
	int_arr::operator-= (that);
	_col = 0;
	return *this;
}

int_matrix int_matrix::operator+ (const int_matrix& that) const
{
	int_matrix result = int_matrix();
	result = operator+ (that);
	result._col = col();
	return result;
}

int_matrix int_matrix::operator- (const int_matrix& that) const
{
	int_matrix result = int_matrix();
	result = int_arr::operator- (that);
	result._col = col();
	return result;
}

int_matrix int_matrix::operator* (const int_matrix& that) const
{
	if	(col() == that.raw())
	{
		int_matrix result(raw()*that.col(), that.col());
		int temp;
		int_arr vec1;
		int_arr vec2;

		for(int i = 0; i < raw(); i++)
		{
			vec1 = vec_from_raw(i);
			for(int j = 0; j < that.col(); j++)
			{
				vec2 = that.vec_from_col(j);
				temp = vec1*vec2;
				result.set_el(i, j, temp);
			}
		}

		return result;
	}
	else
		throw length_error("operation is forbidden");
}	
		
int_matrix int_matrix::operator& (const int_matrix& that) const
{
	int_arr::operator& (that);
}

//======================================================================================
//functions
int int_matrix::col() const
{
	return _col;
}

int int_matrix::raw() const
{
	int raw = int(size()/col());
	return raw;
}

int int_matrix::get_el(int i, int j) const
{
	get(j + i*col());
}

int_arr int_matrix::vec_from_col(int n) const
{
	int_arr result = int_arr(raw());
	for(int i = 0; i < result.size(); i++)
		result.set(i, get_el(i, n));
	return result;
}

int_arr int_matrix::vec_from_raw(int n) const
{
	int_arr result = int_arr(col());
	for(int j = 0; j < result.size(); j++)
		result.set(j, get_el(n, j));
	return result;
}

void int_matrix::set_el(int i, int j, int num)
{
	set(j + i*col(), num);
}

void int_matrix::print_matrix() const
{
	for(int i = 0; i < raw(); i++)
	{
		for(int j = 0; j < col(); j++)
			cout << get_el(i, j) << " ";
		cout << endl;
	}
}

int_matrix int_matrix::tr() const
{
	int_matrix result = int_matrix(size(), raw());
	for(int i = 0; i < raw(); i++)
		for(int j = 0; j < col(); j++)
			result.set_el(j, i, get_el(i,j));
	return result;
}
