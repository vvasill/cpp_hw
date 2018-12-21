#include <iostream>
#include <cstdlib>
#include "linalg.h"

using namespace std;

matrix* gauss(matrix* a)
{
    double temp;
	int row = a->row();
	int col = a->col();
	matrix *x = new plain_matrix(row, 1);

    for (int j = 0; j < col-1; j++)
        for (int i = j+1; i < row; i++)
        {
            temp = a->get(i, j) / a->get(j, j);

            for (int k = j; k < col; k++)
				a->set(i, k, a->get(i, k) - temp * a->get(j, k));
        }
    
    x->set(row-1, 0, a->get(row-1, col-1) / a->get(row-1, row-1));

    for (int i = row-2; i >= 0; i--)
    {
        temp = a->get(i, col-1);
        for (int j = row-1; j > i; j--)
            temp -= a->get(i, j) * x->get(j, 0);
        x->set(i, 0, temp / a->get(i, i));
    }
	
	return x;
}

matrix* min_res(matrix* a)
{
	double temp;
	int row = a->row();
	int col = a->col();
	matrix *x = new plain_matrix(row, 1);

	//smth

	return x;
}
