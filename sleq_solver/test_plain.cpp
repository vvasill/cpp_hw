#include <iostream>
#include <fstream>
#include <cstdlib>

#ifndef LINALG_H
	#include "linalg.h"
#endif

#ifndef PLAIN_MATRIX_H
	#include "plain_matrix.h"
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

	ifstream f_in;
	f_in.open("ex1.txt");
	f_in >> n;
	
	//=======================================================
	//plain_matrix testing

	matrix *x_ptr = new plain_matrix(n, 1);
	matrix *x_temp_ptr = new plain_matrix(n, 1);
	matrix *a_ptr = new plain_matrix(n, n+1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n+1; j++)
		{
			f_in >> temp;
			a_ptr->set(i, j, temp);
		}
	f_in.close();
	cout << "input:" << endl;
	a_ptr->print();

	gauss(a_ptr, x_ptr);
	cout << "answer:" << endl;
	x_ptr->print();

	min_res(a_ptr, x_ptr, x_temp_ptr);
	cout << "answer:" << endl;
	x_ptr->print();

	delete x_ptr;
	delete a_ptr;
	delete x_temp_ptr;

	return 0;	
}
