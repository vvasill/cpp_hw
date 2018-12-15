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

	int_arr arr(size);
	int_arr arr2(arr);

	arr.init(min, max);
	arr2.init(min, max);
	arr.print();
	arr2.print();

	arr.set(1, 100);
	arr.print();
	//arr = arr2;
	//arr.print();	

	/*arr.check_size();
	arr.increase_size(1);
	arr.check_size();*/
	
	return 0;	
	
}
