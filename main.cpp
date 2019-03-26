#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double i)
{
  return cos(i)-i;
}

int FP_method(float left_boundary, float right_boundary)
{
    double XL=left_boundary;
    double XR=right_boundary;
    double Tolerance=pow(10.0,-8.0);
    double ERROR=abs(XL-XR);
    double XM=0;
    double last=0;
    int i=1;

    while(ERROR>Tolerance)
    {
    last=XM;
    XM=(XL*f(XR)-XR*f(XL))/(f(XR)-f(XL));

    if(f(XM)*f(XL)>0) XL=XM;
    else XR=XM;

    cout << "XR= " << setprecision(16) << XR << "\t" << "XL= " << setprecision(16) << XL << "\t" << "XM= " << XM << endl;


    ERROR=abs((XM-last)/XM);
    // cout << i << ": " << setprecision(8) << XM << " Error: " << ERROR << endl;
    i++;
    }
    cout << endl << setprecision(8) << XM;
}

int main()
{
    FP_method(0,1);
    return 0;
}
