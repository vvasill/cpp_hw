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

	double m1[6] = {1, 5, 2, 3, 7, 9};
	int m2[6] = {1, 0, 3, 2, 1, 3};
	int m3[5] = {0, 1, 3, 4, 6};
	crs_matrix *a = new crs_matrix(4, 4, 6, m1, m2, m3);	
	crs_matrix *b = new crs_matrix(4, 4, 6);	

	cout << "input:" << endl;
	a->print();
	cout << endl;
	
	(*b) = a;
	b->print();
	cout << endl;

	((*a) + b)->print();
	cout << endl;	
	(a->tr())->print();

	delete a;
	delete b;

	//=======================================================
	//linalg with crs_matrix testing
	
	matrix *a_ptr = new crs_matrix(4, 4, 6, m1, m2, m3);
	matrix *x_ptr = new crs_matrix(4, 1, 4);
	
	gauss(a_ptr, x_ptr);
	cout << "answer:" << endl;
	x_ptr->print();

	delete a_ptr;
	delete x_ptr;

	return 0;	
}
