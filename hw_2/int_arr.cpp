#include "int_arr.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int_arr::int_arr( int size )
{
 	
	arr = new int [size];
	arr_size = size;

};

int_arr::int_arr()
{

	arr = NULL;
	arr_size = 0;

};

int_arr::~int_arr()
{

	if ( arr != NULL )	
		delete [] arr;

};

int int_arr::size()
{
	return(arr_size);
}

void int_arr::init( int min, int max )
{

	for( int i = 0; i < arr_size; i++ )
	{
		arr[i] = int( ( float(rand())/RAND_MAX * max ) ) + min;
	}

}

void int_arr::print_arr()
{
	
	for( int i = 0; i < arr_size; i++ )
	{
		cout << arr[i] << " ";
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

	size = sizeof(arr) + (sizeof(int) * arr_size);
	if (size < 5*1024) 
		check = true;
	else 
		check = false;

	return(check);

}

void int_arr::increase_size( int inc )
{

	int_arr *temp_arr = new int_arr(arr_size + inc);
	delete [] arr;	
	*arr = *temp_arr->arr;
	arr_size = temp_arr->arr_size;

}

void int_arr::sort_arr()
{
		
	int n = arr_size;
	bool swapped;
    do
	{
      	swapped = false;
        for ( int i = 1; i < n; i++ )
            if ( arr[i-1] > arr[i] )
			{
                swap(arr[i-1], arr[i]);
                swapped = true;
			}
        n--;
    } while ( swapped  == true );

}
