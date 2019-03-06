//straight line fit for linear equation
#include<iostream>
#include<cmath>
using namespace std;
void lsf()
{
    int i,n;
    float x[20],y[20],smx,smy,smxy,smx2,den,b,a;
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
        smx+=x[i];
        smy+=y[i];
        smxy+=x[i]*y[i];
        smx2+=x[i]*x[i];
    }
    den=(n*smx2-smx*smx);
    b=(n*smxy-smx*smy)/den;
    a=(smy-b*smx)/n;
    cout<<"value of coefficients a is "<<a<<"and b is"<<b<<endl;
    cout<<"the regression line is y= "<<a<<" + "<<b<<"x"<<endl;
}
main()
{
    lsf();
}
