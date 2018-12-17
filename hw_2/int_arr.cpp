#include "int_arr.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//constructors

int_arr::int_arr(int size)
{
	_arr = new int[size];
	_size = size;
}

int_arr::int_arr()
{
	_arr = NULL;
	_size = 0;
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
		delete[] _arr;
}

//----------------------------------------------------------------------------------------------
//operators

int_arr& int_arr::operator= (const int_arr& that)
{
	if (this != &that)
	{	
		delete[] _arr;
		_size = that._size;
		_arr = new int[_size];
		for(int i = 0; i < _size; i++)
			_arr[i] = that._arr[i];
	}
	return *this;
}

int int_arr::operator[] (const int i) const
{
	if (i >= _size) 
	{ 
		cout << "index out of range" << endl; 
		exit(0); 
	}
	else
		return _arr[i];
}

int_arr& int_arr::operator+= (const int_arr& that)
{
	if (that._size != _size) 
	{ 
		cout << "operation is forbidden" << endl; 
		exit(0); 
	}
	else
	{
		for(int i = 0; i < _size; i++)
			this->_arr[i] += that._arr[i];
		return *this;
	}	
}

int_arr& int_arr::operator-= (const int_arr& that)
{
	if (that._size != _size) 
	{ 
		cout << "operation is forbidden" << endl; 
		exit(0); 
	}
	else
	{
		for(int i = 0; i < _size; i++)
			this->_arr[i] -= that._arr[i];
		return *this;
	}	
}

int_arr operator+(const int_arr first_that, const int_arr second_that)
{
	if (first_that._size != second_that._size) 
	{ 
		cout << "operation is forbidden" << endl; 
		exit(0); 
	}
	else
	{
		int size = first_that._size + second_that._size;
		int_arr result = int_arr(size);

		for(int i = 0; i < size; i++)
			result._arr[i] = first_that[i] + second_that[i];

		return result;
	}
}

int_arr int_arr::operator-(const int_arr& that)
{
	if (that._size != _size) 
	{ 
		cout << "operation is forbidden" << endl; 
		exit(0); 
	}
	else
	{
		int_arr result = int_arr(_size);

		for(int i = 0; i < _size; i++)
			result._arr[i] = _arr[i] - that._arr[i];

		return result;
	}
}

int_arr int_arr::operator*(const int_arr& that)
{
	if (that._size != _size) 
	{ 
		cout << "operation is forbidden" << endl; 
		exit(0); 
	}
	else
	{
		int_arr result = int_arr(_size);

		for(int i = 0; i < _size; i++)
			result._arr[i] = _arr[i] * that._arr[i];

		return result;
	}
}

int_arr int_arr::operator& (const int_arr that)
{
	int size = _size + that._size;
	int_arr result = int_arr(size);

	for(int i = 0; i < _size; i++)
	{
		result._arr[i] = _arr[i];
	}
	for(int j = _size; j < size; j++)
	{
		result._arr[j] = that._arr[j-(_size)];
	}

	return result;
}

//--------------------------------------------------------------------------------------
//functions

int int_arr::size()
{
	return(_size);
}

void int_arr::set(int i, int num)
{
	if (i >= _size)
	{
		cout << "index out of range" << endl;
		exit(0); 
	}
	else
		_arr[i] = num;
}

int int_arr::get(int i)
{
	if (i >= _size)
	{
		cout << "index out of range" << endl;
		exit(0); 
	}
	else
		return(_arr[i]);
}

void int_arr::init(int min, int max)
{
	for(int i = 0; i < _size; i++)
	{
		_arr[i] = int( ( float(rand())/RAND_MAX * max ) ) + min;
	}
}

void int_arr::print()
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

bool int_arr::check_size()
{
	int size;
	bool check;

	size = sizeof(_arr) + (sizeof(int) * _size);
	if (size < 5*1024) 
		check = true;
	else 
		check = false;

	return(check);
}

void int_arr::increase_size(int inc)
{
	int_arr *temp_arr = new int_arr(_size + inc);
	delete [] _arr;	
	*_arr = *temp_arr->_arr;
	_size = temp_arr->_size;
}

void int_arr::sort()
{
	int n = _size;
	bool swapped;
    do
	{
      	swapped = false;
        for ( int i = 1; i < n; i++ )
            if ( _arr[i-1] > _arr[i] )
			{
                swap(_arr[i-1], _arr[i]);
                swapped = true;
			}
        n--;
    } while ( swapped  == true );
}
