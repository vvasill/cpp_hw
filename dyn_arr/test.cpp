#include "func.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	
	srand(time(0));
	int size, min, max;

	cin >> size;
	cin >> min;
	cin >> max;

	int *arr = new int[size];

	init(arr, size, min, max);
	print(arr, size);
	sort(arr, size);
	print(arr, size);

	increase_size(arr, size, 10);
	print(arr, size);
	
	return 0;	
	
}
