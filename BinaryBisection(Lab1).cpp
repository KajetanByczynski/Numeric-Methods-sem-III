#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;
double root(double xl, double xr, double TOLERANCE);

int main()
{
    double A;
    cout << "Hello world!" << endl;
    A=root(0,1,pow(10.0,-8.0));
    cout << setprecision(8)<<A;
    return 0;
}
double f(double x)
{
return  cos(x)-x;
}
double root(double xl, double xr, double TOLERANCE)
{
    double xm=(xr+xl)/2;
    while (abs((xr-xl)/xm) >= TOLERANCE)
    {
        xm=(xr+xl)/2;
        if(f(xl)*f(xm)>0.0)
        {
        xl=xm;
        }
        else
        {
        xr=xm;
        }
    }
    return xm;
}
