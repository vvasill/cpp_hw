#include "int_arr.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

//======================================================================================
//constructors

int_arr::int_arr()
{
	_arr = NULL;
	_size = 0;
}

int_arr::int_arr(int size)
{
	_arr = new int[size];
	_size = size;
}

int_arr::int_arr(const int_arr& that)
{
	_size = that._size;
	_arr = new int[_size];
	for(int i = 0; i < _size; i++)
		_arr[i] = that._arr[i];
}

int_arr::~int_arr()
{
	if ( _arr != NULL )	
		delete [] _arr;
}

//======================================================================================
//operators

int_arr& int_arr::operator= (const int_arr& that)
{
	if (this != &that)
	{	
		delete[] _arr;
		_size = that.size();
		_arr = new int[that.size()];
		for(int i = 0; i < that.size(); i++)
			_arr[i] = that[i];
	}
	return *this;
}

int int_arr::operator[] (const int i) const
{
	if (i < size()) 
		return get(i); 
	else
		throw invalid_argument("index out of range");
}

int& int_arr::operator[] (const int i)
{
	if (i < size()) 
		return _arr[i];
	else
		throw invalid_argument("index out of range");
}

int_arr& int_arr::operator+= (const int_arr& that)
{
	if (size() == that.size()) 
	{
		for(int i = 0; i < size(); i++)
			set(i, get(i) + that[i]);
		return *this;
	}
	else	
		throw length_error("operation is forbidden");
}

int_arr& int_arr::operator-= (const int_arr& that)
{
	if (size() == that.size()) 
	{
		for(int i = 0; i < size(); i++)
			set(i, get(i) + that[i]);
		return *this;
	}
	else	
		throw length_error("operation is forbidden");	
}

int_arr operator+(const int_arr& first_that, const int_arr& second_that)
{
	if (first_that.size() == second_that.size()) 
	{ 
		int res_size = first_that.size() + second_that.size();
		int_arr result = int_arr(res_size);

		for(int i = 0; i < res_size; i++)
			result.set(i, first_that[i] + second_that[i]);

		return result;
	}
	else
		throw length_error("operation is forbidden");
}

int_arr int_arr::operator-(const int_arr& that) const
{
	if (size() == that.size()) 
	{ 
		int_arr result = int_arr(size());

		for(int i = 0; i < size(); i++)
			result.set(i, get(i) - that[i]);

		return result; 
	}
	else
		throw length_error("operation is forbidden");
}

int int_arr::operator*(const int_arr& that) const
{
	if (size() == that.size()) 
	{
		int result = 0;

		for(int i = 0; i < size(); i++)
			result += get(i) * that[i];

		return result;
	}
	else
		throw length_error("operation is forbidden");
}

int_arr int_arr::operator& (const int_arr& that) const
{
	int res_size = size() + that.size();
	int_arr result = int_arr(res_size);

	for(int i = 0; i < size(); i++)
		result.set(i, get(i));
	for(int j = size(); j < res_size; j++)
		result.set(j, that[j - size()]);

	return result;
}

//======================================================================================
//functions

int int_arr::size() const
{
	return(_size);
}

void int_arr::set(int i, int num)
{
	if (i < size())
		_arr[i] = num;
	else
		throw invalid_argument("index out of range");
}

int int_arr::get(int i) const
{
	if (i < size())
		return(_arr[i]);
	else
		throw invalid_argument("index out of range");
}

void int_arr::init(int min, int max)
{
	for(int i = 0; i < size(); i++)
	{
		set(i, int( ( float(rand())/RAND_MAX * max ) ) + min);
	}
}

void int_arr::print() const
{
	for(int i = 0; i < _size; i++)
	{
		cout << _arr[i] << " ";
	}
	cout << endl;
}

void int_arr::swap(int &a, int &b)
{
	int temp;	
	temp = a;
	a = b;
	b = temp;
}

bool int_arr::check_size(int limit) const
{
	int size;
	bool check;

	size = sizeof(_arr) + (sizeof(int) * _size);
	if (size < limit) 
		check = true;
	else 
		check = false;

	return(check);
}

void int_arr::increase_size(int inc)
{
	int new_size = size() + inc;
	_size = new_size;
	for (int i = 1; i < new_size; i++)
		set(i, 0);
}

void int_arr::sort()
{
	int n = size();
	bool swapped;
    do
	{
      	swapped = false;
        for (int i = 1; i < n; i++)
            if (get(i-1) > get(i))
			{
                swap(_arr[i-1], _arr[i]);
                swapped = true;
			}
        n--;
    } while (swapped  == true);
}
