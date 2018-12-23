#include <iostream>
#include <fstream>
#include <cstdlib>

#ifndef LINALG_H
	#include "linalg.h"
#endif

#ifndef PLAIN_MATRIX_H
	#include "crs_matrix.h"
#endif

using namespace std;

int main(int argc, char* argv[])	
{
	srand(time(0));
	int n;
	double temp;

	//=======================================================
	//crs_matrix testing

	matrix *a_ptr = new crs_matrix(n, n+1, );
	a_ptr->init(1,10);

	cout << "input:" << endl;
	a_ptr->print();

	/*gauss(a_ptr, x_ptr);
	cout << "answer:" << endl;
	x_ptr->print();
	

	matrix *x_ptr = new crs_matrix(n, 1);
	gauss(a_ptr, x_ptr);
	cout << "answer:" << endl;
	x_ptr->print();
	
	delete x_ptr;
	delete a_ptr;

	return 0;	
}
