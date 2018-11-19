#include <iostream>
#include <cstdlib>
#include "int_arr.h"

using namespace std;

int main( int argc, char* argv[] )
{
		
	srand(time(0));
	int size, min, max;
	
	cin >> size;
	cin >> min;
	cin >> max;

	int_arr arr1 = int_arr(size);
	int_arr arr2 = int_arr(size);
	int_arr arr3 = int_arr(2*size);

	arr1.init(min, max);
	arr2.init(min, max);
	arr1.print_arr();
	arr2.print_arr();

	cout << arr1[1];
	print();

	return 0;	
	
}
