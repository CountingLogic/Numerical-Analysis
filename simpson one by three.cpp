//SIMPSON ONE BY THREE
#include<iostream>
#include<cmath>
using namespace std;
inline float f(float x)
{
    return (x*x);
}
void simponebythreetab()
{
    int i,n,k;
    float x[20],y[20],a,b,sm,I,h,sm2,sm4;
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
    sm=(y[1]+y[n+1]);
    sm2=0;
    sm4=0;
    for(i=2;i<=n;i+=2)
    {
        sm4=sm4+y[i];
    }
    for(i=3;i<=n-1;i+=2)
    {
        sm2=sm2+y[i];
    }
    I=(sm+4*sm4+2*sm2)*(h/3);
    cout<<"the integrated value is"<<I<<endl;

}
void simponebythree()
{
    int i,n,k;
    float sm,sm2,sm4,h,a,b,I;
    cout<<"enter the number of tabulated points";
    cin>>k;
    n=k-1;
    cout<<"enter the integration limits";
    cin>>a>>b;
    h=(b-a)/n;
    sm=(f(a)+f(b));
    sm2=0;
    sm4=0;
    for(i=1;i<=n;i+=2)
    {
        sm4=sm4+f(a+(i*h));

    }
    for(i=2;i<=n;i+=2)
    {
        sm2=sm2+f(a+(i*h));
    }
    I=(sm+4*sm4+2*sm2)*(h/3);
    cout<<"the integrated value"<<I<<endl;

}
main()
{
    char ch;
    cout<<"enter choice '1' for tabulated function and  '2' for given fucntion";
    cin>>ch;
    if(ch=='1')
    {
       simponebythreetab();
    }
    else
    {
        simponebythree();
    }
}
