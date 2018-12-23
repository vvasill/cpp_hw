#include <iostream>
#include <cstdlib>

#ifndef LINALG_H
	#include "linalg.h"
#endif

using namespace std;

bool gauss(matrix* a, matrix* x)
{
    double temp;
	int row = a->row();
	int col = a->col();

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
	
	return true;
}

bool min_res(matrix* a, matrix* x, matrix* x_old)
{
	double temp;
	int row = a->row();
	int col = a->col();

	double eps = 0.001;
	x_old->init(1.0);
	
	for (int i = 0; i < row; i++)    
		x->set(i, 0, x_old->get(i,0) + 2*eps);

	temp = a->max();

	((*x) + x)->print();

	/*while ( max( abs(sub(x, x_old)) ) > eps )
	{
		cout << eps;
	}*/

	//smth

	return true;
}
