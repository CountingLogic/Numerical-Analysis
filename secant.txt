//SECANT METHOD
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
inline float f(float x)
{
    return (x*x*x-9*x*x+1);
}
void sec()
{
	float eps=0.0001;
    float a,b,c;
    int count;
    cout<<"enter initial root interval";
    cin>>a>>b;
    if((f(a)*f(b))<0)
{
    count=0;
        do
        {
            c=(a*f(b)-b*f(a))/(f(b)-f(a));
            count=count+1;
            if(fabs((c-b)/c)<eps && (f(c)==0))
            break;
            else
            a=b;
            b=c;
            }while((count<=100) && fabs(f(c))>eps);
        cout<<"root="<<c<<endl;
    cout<<"iterations"<<count<<endl;
}
       else
       cout<<"initial interval incorrect";

    }



main()
{
   sec();
}
