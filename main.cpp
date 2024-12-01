#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
float f6(float a, float b, float c, float x);
int main()
{
  float a, b, c, xn, xk, xd;
  cout<<"Enter 6 numbers\n";
  cin>>a>>b>>c>>xn>>xk>>xd;
  int ac=a;
  int bc=b;
  int cc=c;

  while (xn<=xk) {
    if (((ac && bc)^cc)!=0)
        cout<<xn<<" - "<<f6(a,b,c,xn)<<endl;
    else
        cout<<xn<< " - "<<floor(f6(a,b,c,xn))<<endl;
    xn+=xd;

  }
}
float f6(float a, float b, float c, float x){
    if (x<1 && c != 0)
        return a*pow(x,2)+(b/c);
    if (x>15 && c==0)
        return (x-a)/pow(x-c,2) ;
    return x*x+c*c;
}