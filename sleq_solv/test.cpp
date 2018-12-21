#include <iostream>
#include <fstream>
#include <cstdlib>
#include "linalg.h"
#include "matrix.h"

using namespace std;

int main(int argc, char* argv[])	
{
	srand(time(0));
	int n;
	double temp;

	ifstream f_in;
	f_in.open("ex.txt");
	f_in >> n;
	double* x = new double[n];
		
	matrix *a_ptr = new plain_matrix(n,n+1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n+1; j++)
		{
			f_in >> temp;
			a_ptr->set(i, j, temp);
		}
	
	a_ptr->print();

	gauss(a_ptr);

	a_ptr->print();

	delete a_ptr;
	return 0;	
}
