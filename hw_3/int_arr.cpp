#include "int_arr.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int_arr::int_arr( int size )
{
 	
	_arr = new int[size];
	_size = size;

};

int_arr::int_arr()
{

	_arr = NULL;
	_size = 0;

};

int_arr::~int_arr()
{

	if ( _arr != NULL )	
		delete [] _arr;

};

int& int_arr::operator[] (const int i) const
{
	int res;

	if (i >= _size) 
	{ 
		cout << "index out of range"; 
		exit(0); 
	}
	else
		res = _arr[i];

	return res;
}

int_arr& operator+=(const int_arr r_arr)
{
	for(i = 0; i < r_arr._size; i++)
		this._arr[this._size + i] = r_arr._arr[i];
	this._size += r_arr._size

	return this;
}

int_arr operator+(const int_arr l_arr, const int_arr r_arr)
{
	int_arr res;
	res = this.sum(s_arr);
	return res;
}

int_arr int_arr::sum(const int_arr s_arr)
{
	int i, j, size;
	size = arr._size + s_arr._size;
	int_arr result = int_arr(size);

	for(i = 0; i < this._size; i++)
		result._arr[i] = this._arr[i];
	for(j = this._size; j < s_arr._size; j++)
		result._arr[j] = s_arr._arr[j];

	return result;
}

int int_arr::size()
{
	return(_size);
}

int int_arr::get(int i)
{
	return _arr[i];
}

void int_arr::set(int i, int num)
{
	_arr[i] = num;
}

void int_arr::init(int min, int max)
{

	for( int i = 0; i < _size; i++ )
	{
		_arr[i] = int( ( float(rand())/RAND_MAX * max ) ) + min;
	}

}

void int_arr::print_arr()
{
	
	for( int i = 0; i < _size; i++ )
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

void int_arr::sort_arr()
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
