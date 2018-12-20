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
		
	plain_matrix a = plain_matrix(n,n+1);
	matrix& pt = a;

	cout << a.row() << " " << a.col() << endl;

	/*for (int i = 0; i < n; i++)
		for (int j = 0; j < n+1; j++)
		{
			//f_in >> temp;
			//a.set(i, j, temp);
		}
	
	a.print();*/

	return 0;	
}
