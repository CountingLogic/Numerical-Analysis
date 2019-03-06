//RUNGE KUTTA SECOND ORDER
#include<iostream>
#include<cmath>
using namespace std;
inline float f(float a,float b)
{
    return (-a*b);
}
void rktwo()
{
    int i;
    float x,y,x1,xf,h,y1,s1,s2,s;
    cout<<"enter the interval where solution is sought \n";
    cin>>x1>>xf;
    cout<<"enter the step size \n";
    cin>>h;
    cout<<" enter the value of y1 at x1 \n";
    cin>>y1;
    i=1;
    x=x1;
    y=y1;
    cout<<" I "<<" X "<<" Y \n";
    cout<<i<<"  "<<x<<"  "<<y<<endl;
    do
    {
        s1=f(x,y);
        s2=f(x+h,y+s1*h);
        s=(s1+s2)/2;
        y=y+s*h;
        x=x+h;
        i=i+1;
        cout<<i<<" "<<x<<" "<<y<<endl;
    }
    while(x<xf);
}
main()
{
    rktwo();
}
