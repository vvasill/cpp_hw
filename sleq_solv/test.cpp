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
	f_in.open("ex1.txt");
	f_in >> n;
	
	matrix *x_ptr = new plain_matrix(n, 1);
	matrix *a_ptr = new plain_matrix(n, n+1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n+1; j++)
		{
			f_in >> temp;
			a_ptr->set(i, j, temp);
		}
	cout << "input:" << endl;
	a_ptr->print();

	x_ptr = gauss(a_ptr);
	cout << "answer:" << endl;
	x_ptr->print();

	delete a_ptr;
	delete x_ptr;
	return 0;	
}
