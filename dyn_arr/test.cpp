#include <iostream>
#include <cstdlib>
#include "func.h"

using namespace std;

int main( int argc, char* argv[] )
{
	
	srand(time(0));
	int size, min, max;
	
	//size = atoi( argv[1] );
	cin >> size;
	cin >> min;
	cin >> max;

	int *arr = new int[size];

	init(arr, size, min, max);
	print_arr(arr, size);
	sort_arr(arr, size);
	print_arr(arr, size);

	check_size(arr, size);
	increase_size(arr, size, 1);
	check_size(arr, size);
	
	return 0;	
	
}
