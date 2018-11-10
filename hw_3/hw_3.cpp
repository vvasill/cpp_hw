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

	int_arr *arr = new int_arr(size);

	arr->init(min, max);
	arr->print_arr();
	arr->sort_arr();
	arr->print_arr();

	arr->check_size();
	arr->increase_size(1);
	arr->check_size();
	
	return 0;	
	
}
