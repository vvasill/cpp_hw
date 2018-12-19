#include <iostream>
#include <cstdlib>

using namespace std;

void init( int* arr, int arr_size, int min, int max)
{
	for( int i = 0; i < arr_size; i++ )
	{
		arr[i] = int( ( float(rand())/RAND_MAX * max ) ) + min;
	}
}

void print_arr( int* arr, int arr_size )
{
	for( int i = 0; i < arr_size; i++ )
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int &a, int &b)
{
	int temp;	
	temp = a;
	a = b;
	b = temp;
}

bool check_size( int* arr, int arr_size )
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

void increase_size( int* &arr, int &arr_size, int inc )
{
	int *temp_arr = new int[arr_size + inc];
	delete [] arr;	
	arr = temp_arr;
}

void sort_arr( int* arr, int arr_size)
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
