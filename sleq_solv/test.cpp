#include <iostream>
#include <cstdlib>
#include "linalg.h"

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
	int_matrix matrix3(size, n);

	matrix.init(min, max);
	matrix.print_matrix();
	cout << endl;

	matrix.tr().print_matrix();
	matrix2.init(min, max);
	matrix2.print_matrix();
	cout << endl;
	
	(matrix.tr()*matrix2).print_matrix();
	cout << endl;
	(matrix*matrix2.tr()).print_matrix();

	return 0;	
}
