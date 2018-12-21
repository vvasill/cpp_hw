#include <iostream>
#include <cstdlib>
#include "func.h"

using namespace std;

void init(int* arr, const int arr_size, const int min, const int max)
{
	for (int i = 0; i < arr_size; i++)
		arr[i] = int( ( float(rand())/RAND_MAX * max ) ) + min;
}

void print(int* arr, const int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void swap(int &a, int &b)
{
	int temp;	
	temp = a;
	a = b;
	b = temp;
}

void sort(int* arr, const int arr_size)
{	
	int n = arr_size;
	bool swapped;
    do
	{
      	swapped = false;
        for (int i = 1; i < n; i++)
            if (arr[i-1] > arr[i])
			{
                swap(arr[i-1], arr[i]);
                swapped = true;
			}
        n--;
    } while (swapped  == true);
}

bool check_size(int* arr, const int arr_size, const int limit)
{
	int size;
	bool check;

	size = sizeof(arr) + (sizeof(int) * arr_size);
	if (size < limit) 
		check = true;
	else 
		check = false;

	return(check);
}

int* increase_size(int* arr, int arr_size, const int inc)
{
	int new_size = arr_size + inc;

	int* result = new int[new_size];

	for (int i = 0; i < arr_size; i++)
		result[i] = arr[i];
	for (int i = arr_size; i < new_size; i++)
		result[i] = 0;
	
	return result;
}
