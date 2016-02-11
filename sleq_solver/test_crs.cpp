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

	double m1[7] = {1, 5, 2, 7, 10, 4, 5};
	int m2[7] = {1, 0, 1, 1, 2, 0, 2};
	int m3[5] = {0, 1, 3, 5, 7};
	crs_matrix a(4, 3, 7, m1, m2, m3);	
	double m11[8] = {5, 7, 7, 1, -5, 2, 4, 1};
	int m22[8] = {0, 2, 4, 1, 3, 1, 2, 4};
	int m33[4] = {0, 3, 5, 8};
	crs_matrix b(3, 5, 8, m11, m22, m33);	

	cout << "input:" << endl;
	a.print();
	cout << endl;
	b.print();
	cout << endl;

	a * b;
	cout << endl;
	//(a->tr())->print();

	//=======================================================
	//linalg with crs_matrix testing
	
	double m4[10] = {1, 1, 1, 5, 2, 2, 3, 7, 9, 4};
	int m5[10] = {0, 1, 4, 1, 3, 4, 2, 1, 3, 4};
	int m6[5] = {0, 3, 6, 7, 10};

	matrix *a_ptr = new crs_matrix(4, 5, 10, m4, m5, m6);
	/*double m111[11] = {1, 5, 5, 3, 5, 7, 4, 2, 9, 6, 9};
	int m222[11] = {0, 0, 1, 3, 4, 2, 3, 0, 1, 3, 4};
	int m333[5] = {0, 1, 5, 7, 11};
	matrix* a_ptr = new crs_matrix(4, 5, 11, m111, m222, m333);	*/
	matrix* x_ptr = new crs_matrix(4, 1, 4);

	cout << "input:" << endl;
	a_ptr->print();
	cout << endl;
	
	gauss(a_ptr, x_ptr);

	a_ptr->print();
	cout << "answer:" << endl;
	x_ptr->print();

	return 0;	
}
