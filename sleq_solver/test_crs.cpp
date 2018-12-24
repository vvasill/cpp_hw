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

	crs_matrix *a = new crs_matrix(6, 6, 12);
	matrix *a_ptr;
	a_ptr = a;
	
	a->init();

	cout << "input:" << endl;
	a_ptr->print();

	/*gauss(a_ptr, x_ptr);
	cout << "answer:" << endl;
	x_ptr->print();
	

	matrix *x_ptr = new crs_matrix(n, 1);
	gauss(a_ptr, x_ptr);
	cout << "answer:" << endl;
	x_ptr->print();*/
	
	delete a_ptr;

	return 0;	
}
