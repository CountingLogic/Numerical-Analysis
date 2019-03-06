
//straight line fit for power function
#include<iostream>
#include<cmath>
using namespace std;
void lsf()
{
    int i,n;
    float x[20],y[20],smx,smy,smxy,smx2,den,b,c,a;
    cout<<"enter the no. of tabulated points";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"x["<<i<<"]= ";
        cin>>x[i];
        cout<<"y["<<i<<"]= ";
        cin>>y[i];
    }
    smx=0;smy=0;smxy=0;smx2=0;
    for(i=1;i<=n;i++)
    {
        smx+=log10(x[i]);
        smy+=log10(y[i]);
        smxy+=log10(x[i])*log10(y[i]);
        smx2+=log10(x[i])*log10(x[i]);
    }
    den=(n*smx2-smx*smx);
    b=(n*smxy-smx*smy)/den;
    c=(smy-b*smx)/n;
    a=pow(10,c);
    cout<<"value of coefficients a is "<<a<<"and b is"<<b<<endl;
    cout<<"the regression line is y= "<<a<<"x^"<<b<<endl;
}
main()
{
    lsf();
}
