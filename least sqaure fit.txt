//Least Square Fit SELF
#include<iostream>
using namespace std;
main()
{
    int i,n;
    float x[20],y[20],den,a,b,smx,smx2,smxy,smy;
    cout<<"Enter the no. of data points : ";
    cin>>n;
    cout<<"\nInput the data : ";
    for(i=1;i<=n;i++)
    {
        cout<<"\nx["<<i<<"] = ";
        cin>>x[i];
        cout<<"y["<<i<<"] = ";
        cin>>y[i];
    }
    smx2=0;
    smx=0;
    smy=0;
    smxy=0;
    for(i=1;i<=n;i++)
    {
            smx+=x[i];
            smy+=y[i];
            smx2+=x[i]*x[i];
            smxy+=x[i]*y[i];
    }
    den=n*smx2-smx*smx;
    b=(n*smxy-smx*smy)/den;
    a=(smy-b*smx)/n;
    cout<<"Values of coefficients a and b :\n";
    cout<<"a = "<<a;
    cout<<"\nb = "<<b<<endl;
    cout<<"y = "<<a<<" + "<<b<<"x"<<" is the regression line"<<endl;
}
