//TRAPEZOIDAL
#include<iostream>
#include<cmath>
using namespace std;
inline float f(float x)
{
    return (1/(1+x));
}
void traptab()
{
    int i,n,k,a,b;
    float x[20],y[20],I,h,sm;
    cout<<"enter the no. of tabulated points";
    cin>>k;
    n=k-1;
    cout<<"enter the limits of integration";
    cin>>a>>b;
    h=(b-a)/n;
    for(i=1;i<=n+1;i++)
    {
        cout<<"x["<<i<<"]= ";
        cin>>x[i];
        cout<<"y["<<i<<"]= ";
        cin>>y[i];
    }
    sm=(y[1]+y[n+1])/2;

    for(i=2;i<=n;i++)
    {
        sm=sm+y[i];
    }
    I=sm*h;
    cout<<"the integrated value is"<<I<<endl;

}
void trap()
{
    int i,k,n;
    float h,a,b,sm,I;
    cout<<"enter the no. of tabulated points";
    cin>>k;
    n=k-1;
    cout<<"enter the limit of integration";
    cin>>a>>b;
    h=(b-a)/n;
    sm=(f(a)+f(b))/2;
    for(i=1;i<=n-1;i++)
    {
        sm=sm+(f(a+(i*h)));
    }
    I=sm*h;
    cout<<"the integration is"<<I<<endl;

}
main()
{
    char ch;
    cout<<"enter '1' for tabulated function and enter '2' for given function";
    cin>>ch;
    if(ch=='1')
    traptab();
    else
    trap();
}
