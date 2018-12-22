#include <iostream>
#include <complex>
#include <math.h>
#include <fstream>

using namespace std;

complex <double> i (0 , 1);

complex <double> I (0 , 0);

double fi = 300, d_om = 0.01, dt = 0.1;

double A(double);

//ifstream f_in;
ofstream f_out;

int main()
{
    //f_in.open("data");
    f_out.open("results");

    for (double t = -1000; t < 1000; t += dt)
    {
        I = 0;
        for (double om = -5; om < 5; om += d_om)
        {
            I += A(om)*exp(-i*fi)*exp(-i*om*t)*d_om;
        }

        f_out << t << " " << abs(I) << endl;
    }

    return 0;
}

double A(double omega)
{
    return(exp(-pow(omega/d_om, 2)));
}
