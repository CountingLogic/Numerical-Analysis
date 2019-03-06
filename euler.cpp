//euler method
#include<iostream>
#include<cmath>
using namespace std;
inline float f(float a,float b)
{
    return (a+b);
}
void euler()
{
    int i;
    float x,y,y1,x1,xf,h;
    cout<<"enter the interval where solution is sought \n";
    cin>>x1>>xf;
    cout<<"enter the step size \n";
    cin>>h;
    cout<<"enter the intial value of y1 at x1 \n";
    cin>>y1;
    i=1;
    x=x1;
    y=y1;
    cout<<" I "<<" X "<<" Y \n";
    cout<<i<<"  "<<x<<"  "<<y<<endl;
    do
    {
        y=y+h*f(x,y);
        x=x+h;
        i=i+1;
        cout<<i<<" "<<x<<" "<<y<<endl;
    }
    while(x<xf);

}
main()
{
    euler();
}

