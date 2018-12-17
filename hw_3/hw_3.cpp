#include <iostream>
#include <cstdlib>
#include "int_matrix.h"

using namespace std;

int main( int argc, char* argv[] )	
{
	srand(time(0));
	int size, n, min, max;
	
	//cin >> size;
	//cin >> n;
	//cin >> min;
	//cin >> max;
	size = 10;
	n = 2;
	min = 1;
	max = 5;

	int_matrix matrix(size, n);
	int_matrix matrix2(size, n);

	matrix.init(min, max);
	matrix2.init(min, max);
	matrix.print();
	matrix2.print();

	matrix = matrix2;
	matrix.print_matrix();
	
	matrix.matrix_set(1,1,0);
	matrix.print_matrix();

	return 0;	
}
