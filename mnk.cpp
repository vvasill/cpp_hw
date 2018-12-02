#include <iostream>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n, i;
double delta = 0, delta_a = 0, delta_b = 0;
double a, b, S_a, S_b, r, sigma_0;
double x[100], y[100], sigma[100];

void non_eq_disp();
void eq_disp();

int main()
{
    int eq;

    ifstream f_in;
    ofstream f_out;
    f_in.open("data.txt");
    f_in >> eq;
    f_out.open("data.txt");
    f_out << eq;

    cout << "equal or not equal? ";
    cin >> eq;
    cout << "number of measurements: ";
    cin >> n;
    cout << "x: ";
    for (i = 0; i < n; i++)
        cin >> x[i];
    cout << "y: ";
    for (i = 0; i < n; i++)
        cin >> y[i];

    if (eq == 0) non_eq_disp();
    else eq_disp();

    f.close();

    return 0;
}

void eq_disp()
{
    double d1 = 0, d2 = 0, d3 = 0, d4 = 0;
    double x_r = 0, y_r = 0, s_x = 0, s_y = 0;

    cout << "sigma_0: ";
    cin >> sigma_0;
    for (i = 0; i < n; i++)
    {
         d1 += pow(x[i], 2);
         d2 += x[i];
    }
    delta += n * d1 - pow(d2, 2);

    d1 = d2 =0;

    for (i = 0; i < n; i++)
    {
         d1 += x[i]*y[i];
         d2 += x[i];
         d3 += y[i];
    }
    delta_a += n * d1 - d2 * d3;

    d1 = d2 = d3 = 0;

    for (i = 0; i < n; i++)
    {
         d1 += pow(x[i], 2);
         d2 += y[i];
         d3 += x[i];
         d4 += x[i]*y[i];
    }
    delta_b += d1 * d2 - d3 * d4;

    a = delta_a/delta;
    b = delta_b/delta;

    S_a = sqrt(pow(sigma_0, 2)*n/delta);
    S_b = sqrt(pow(sigma_0, 2)*d1/delta);

    for (i = 0; i < n; i++)
    {
        x_r += x[i]/n;
        y_r += y[i]/n;
    }

    for (i = 0; i < n; i++)
    {
        s_x += pow(x[i] - x_r, 2)/(n - 1.0);
        s_y += pow(y[i] - y_r, 2)/(n - 1.0);
    }

    s_x = sqrt(s_x);
    s_y = sqrt(s_y);

    for (i = 0; i < n; i++)
    {
        r += (x[i] - x_r)*(y[i] - y_r);
    }

    r /= ((n - 1) * s_x * s_y);

    cout << endl;
    cout << "a: " << a << " b: " << b << endl;
    cout << "S_a: " << S_a << " S_b: " << S_b << endl;
    cout << "r: " << r << endl;
}

void non_eq_disp()
{
    double d1 = 0, d2 = 0, d3 = 0, d4 = 0;

    cout << "sigma: ";
    for (i = 0; i < n; i++)
        cin >> sigma[i];

    for (i = 0; i < n; i++)
        sigma[i] = (1.0/pow(sigma[i], 2));

    for (i = 0; i < n; i++)
    {
        d1 += pow(x[i], 2) * sigma[i];
        d2 += sigma[i];
        d3 += x[i] * sigma[i];
    }

    delta += d1 * d2 - pow(d3, 2);
    d1 = d2 = d3 = 0;

    for (i = 0; i < n; i++)
    {
        d1 += x[i] * y[i] * sigma[i];
        d2 += sigma[i];
        d3 += x[i] * sigma[i];
        d4 += y[i] * sigma[i];
    }

    delta_a += d1 * d2 - d3 * d4;
    d1 = d2 = d3 = d4 = 0;

    for (i = 0; i < n; i++)
    {
        d1 += pow(x[i], 2) * sigma[i];
        d2 += y[i] * sigma[i];
        d3 += x[i] * sigma[i];
        d4 += x[i] * y[i] * sigma[i];
    }

    delta_b += d1 * d2 - d3 * d4;
    d1 = d2 = d3 = d4 = 0;

    a = delta_a/delta;
    b = delta_b/delta;

    for (i = 0; i < n; i++)
    {
        d1 += sigma[i];
        d2 += pow(x[i],2) * sigma[i];
    }

    S_a = sqrt(d1/delta);
    S_b = sqrt(d2/delta);

    cout << endl;
    cout << "a: " << a << " b: " << b << endl;
    cout << "S_a: " << S_a << " S_b: " << S_b << endl;
}
