#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func1(double x)
{
    return (6435 * pow(x,8) -12012 * pow(x, 6) + 6930 * pow(x,4) - 1260 * pow(x,2) + 35)/128;
}

double func(double x)
{
  return func1(x);
}

double div(double x)
{
    double dx=0.0000001;
    return (func(x+dx)-func(x))/dx;
}



double NRM(double X0)
{

    double Xi,Xi1,ERROR=10000,TOLERANCE=pow(10.0,-8.0);
    Xi=X0;
    while(ERROR>TOLERANCE)
    {
        Xi1=Xi-(func(Xi)/div(Xi));
        ERROR=abs((Xi1-Xi)/Xi1);
        Xi=Xi1;
    }
    return Xi1;
}

double LongNRM(double start,double finish)
{
    double last_result=0,result;
    for(double i=start;i<=finish;i+=0.01)
    {
        result=NRM(i);
        if(result!=last_result)
        {
            cout << result << "\n";
            last_result=result;
        }
    }
}
int main()
{
    //cout << "Hello world!\n" << "Give X0:";
    //double X0;
    //cin >> X0 ;
    //double result=NRM(X0);
    double result=LongNRM(0,1);
    //cout << "result: ";
    cout << setprecision(8) << result;
    return 0;
}


