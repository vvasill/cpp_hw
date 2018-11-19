#include <iostream>
#include <cstdlib>
#include "int_arr.h"

using namespace std;

int main( int argc, char* argv[] )
{
		
	srand(time(0));
	int size, min, max;
	
	//size = atoi( argv[1] );
	cin >> size;
	cin >> min;
	cin >> max;

	int_arr *arr1 = new int_arr(size);
	int_arr *arr2 = new int_arr(size);

	arr1->init(min, max);
	arr2->init(min, max);
	arr1->print_arr();
	arr2->print_arr();

	(arr1+arr2)->print_arr();

	return 0;	
	
}
