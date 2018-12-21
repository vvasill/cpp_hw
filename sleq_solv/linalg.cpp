#include <iostream>
#include <cstdlib>
#include "linalg.h"

using namespace std;

double* gauss(matrix* a)
{
    double temp;
	int n = a->row() - 1;
	double*	x = new double[a->row()];

    for (int j = 0; j < n - 1; j++)
        for (int i = j + 1; i < n; i++)
        {
            temp = a->get(i,j) / a->get(j,j);

            for (int k = j; k < n + 1; k++)
                  a->set(i, k, a->get(i,k) - temp * a->get(j,k));
        }
    
    x[n] = a->get(n, n + 1) / a->get(n,n);

    for (int i = n - 1; i >= 0; i--)
    {
        temp = a->get(i, n + 1);
        for (int j = n; j > i; j--)
            temp -= a->get(i,j) * x[j];
        x[i] =  temp / a->get(i,i);
    }
	
	a->print();	
	return x;
}

double* min_res(matrix* a)
{
	double*	x = new double[a->row()];
	//smth
	return x;
}
