#include "int_arr.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int_arr::int_arr( int size )
{
 	
	arr_ = new int [size];
	size_ = size;

};

int_arr::int_arr()
{

	arr_ = NULL;
	size_ = 0;

};

int_arr::~int_arr()
{

	if ( arr != NULL )	
		delete [] arr_;

};

int int_arr::size()
{
	return(size_);
}

int& int_arr::operator[] (const int i) const
{
	if (i >= size_) 
	{ 
		cout << "index out of range"; 
		exit(0); 
	} 
	return arr_[i];
}

int_arr int_arr::operator+ (int_arr& arr)
{
      int_arr result;
      result.arr_ = this->arr_;
      result.size_ = (this->size_);
      return result;
}

void int_arr::init( int min, int max )
{

	for( int i = 0; i < size_; i++ )
	{
		arr_[i] = int( ( float(rand())/RAND_MAX * max ) ) + min;
	}

}

void int_arr::print_arr()
{
	
	for( int i = 0; i < size_; i++ )
	{
		cout << arr_[i] << " ";
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

	size = sizeof(arr_) + (sizeof(int) * size_);
	if (size < 5*1024) 
		check = true;
	else 
		check = false;

	return(check);

}

void int_arr::increase_size( int inc )
{

	int_arr *temp_arr = new int_arr(size_ + inc);
	delete [] arr_;	
	*arr_ = *temp_arr->arr_;
	size_ = temp_arr->size_;

}

void int_arr::sort_arr()
{
		
	int n = size_;
	bool swapped;
    do
	{
      	swapped = false;
        for ( int i = 1; i < n; i++ )
            if ( arr_[i-1] > arr_[i] )
			{
                swap(arr_[i-1], arr_[i]);
                swapped = true;
			}
        n--;
    } while ( swapped  == true );

}
