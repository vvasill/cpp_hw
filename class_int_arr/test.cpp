#include <iostream>
#include <cstdlib>
#include "int_arr.h"

using namespace std;

int main( int argc, char* argv[] )	
{
		
	srand(time(0));
	int size, min, max;
	
	//cin >> size;
	//cin >> min;
	//cin >> max;
	size = 10;
	min = 1;
	max = 5;

	int_arr arr(size);
	int_arr arr2(size);

	arr.init(min, max);
	arr2.init(min, max);
	arr.print();
	arr2.print();

	arr.set(1, 100);
	arr.print();

	arr = arr2;
	arr.print();

	arr2.init(min, max);
	arr2.print();

	arr += arr2;
	arr.print();

	arr = arr - arr2;
	arr.print();

	(arr&arr2).print();
	
	cout << arr[5] << endl;

	arr.sort();
	arr.print();

	cout << arr*arr2 << endl;

	arr2 = arr.increase_size(10);
	arr2.print();

	return 0;	
	
}
