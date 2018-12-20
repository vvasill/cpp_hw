#include <iostream>
#include <cstdlib>

using namespace std;

double_vec gauss(const double_matrix& a)
{
    double temp;
	int n = a.raw() - 1;
	double_vec x = double_vec(a.raw());

    for (int j = 0; j < n - 1; j++)
        for (int i = j + 1; i < n; i++)
        {
            temp = a[i][j] / a[j][j];

            for (int k = j; k < n + 1; k++)
                  a[i][k] = a[i][k] - temp * a[j][k];
        }
    
    x[n] = a[n][n + 1] / a[n][n];

    for (int i = n - 1; i >= 0; i--)
    {
        temp = c[i][n + 1];
        for (int j = n; j > i; j--)
            temp -= a[i][j] * x[j];
        x[i] =  temp / a[i][i];
    }
		
	return x;
}

double_vec min_res(const double_matrix& a)
{
}
