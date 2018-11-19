#include "int_arr.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int_arr::int_arr( int size )
{
 	
	_arr = new int [size];
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
	if (i >= _size) 
	{ 
		cout << "index out of range"; 
		exit(0); 
	} 
	return _arr[i];
}

int_arr& int_arr::operator +(const int_arr& sm)
{
	int i,j;
	this->_size = _size + sm._size;

	for(i = 0; i < _size; i++)
		this->data[i] = data[i];
	for(j = _size; j < sm._size; j++)
		this->data[j] = sm.data[j];

	return *this;
}

int int_arr::size()
{
	return(_size);
}

void int_arr::init( int min, int max )
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

void int_arr::increase_size( int inc )
{

	int_arr *temp_arr = new int_arr(_size + inc);
	delete [] _arr;	
	*_arr = *temp_arr->_arr;
	_size = temp_arr->_size;

}

void int_arr::sort_arr()
{
		
	int n = _arrsize;
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
