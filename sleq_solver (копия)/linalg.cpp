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
	{
        for (int i = j+1; i < row; i++)
        {				
            temp = a->get(i, j) / a->get(j, j);
			
            for (int k = j; k < col; k++)
				a->set(i, k, a->get(i, k) - temp * a->get(j, k));
        }
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

	/*for(int i = 0; i < x_old->row(); i++)
		for(int j = 0; j < x_old->col(); j++)
			x_old->set(i, j, 1.0);
	
	for (int i = 0; i < row; i++)    
		x->set(i, 0, x_old->get(i,0) + 2*eps);

	max(x);
		
	while (delta(x, x_old) > eps)
	{
		cout << "***" << endl;
		delta(x, x_old);
		exit(0);
	}

	//smth

	return true;
}

double delta(const matrix* x, const matrix* y)
{
	double delta = 0;
	
	//delta = max( ((*x) - y)->abs() );

	return delta;
}

double max(const matrix* x)
{
	double max = 0;
	for(int i = 0; i < x->row(); i++)
		for(int j = 0; j < x->col(); j++)
		{
			if (x->get(i,j) >= max)
				max = x->get(i,j);
		}
	return max;*/
}


//max element searching

/*		max = get(j,j);
		col_max = 0;

		for(int k = 1; k < col-1; k++)
			if (get(i,k) > max)
			{
				max = get(i,k);
				col_max = k;
			}

			//column swap : j and col_max
			for(int i = j+1; i < row; i++)
			{
				temp = a->get(i, col_num);
				a->set(i, col_num, a->get(i, 0));
				a->set(i, 0, temp);
			}

			a->print();*/
