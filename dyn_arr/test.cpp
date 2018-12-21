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

	cout << check_size(arr, size, 5*1024) << endl;
	print(increase_size(arr, size, 10), size + 10);
	
	return 0;	
	
}
