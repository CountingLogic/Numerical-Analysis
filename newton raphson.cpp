//newton raphson
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
inline float f(float x)
{
    return (x*x+2*x-2);
}
inline float der(float x)
{
    return (2*x+2);
}
void nr()
{
    float a,c,h,eps=0.0001;
    int count;
    cout<<"enter the initial root interval";
    cin>>a;
    if(der(a)!=0)
    {
        count=0;
        do
        {
            h=f(a)/der(a);
            c=a-h;
            count=count+1;
            if(fabs((c-a)/c)<eps && (f(c)==0))
            break;
            else
            a=c;

        }while((count<=20) && fabs(f(c))>eps);
        cout<<"root = "<<c<<endl;
        cout<<"iterations= "<<count<<endl;
    }
    else
    {
        cout<<"initial root incorrect";
    }

}
main()
{
    nr();
}
