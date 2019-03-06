//NBDI
#include<iostream>
#include<cmath>
using namespace std;
inline int fact(int p)
{
    return (p<1?1:p*fact(p-1));
}
void bdi()
{
    int i,j,k,n,m;
    float bd[20][20],x[20],y[20],X,z,sm,pr;
    cout<<"enter the point of interpolation";
    cin>>X;
    cout<<"enter the no. of tabulated points";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"x["<<i<<"]= ";
        cin>>x[i];
        cout<<"y["<<i<<"]= ";
        cin>>y[i];
    }
    i=n;
    while(X<x[i])
    i=i-1;
    k=i;
    z=(X-x[k])/(x[k]-x[k-1]);
    for(j=1;j<=n-1;j++)
    {
        for(i=j+1;i<=n;i++)
        {
            if(j==1)
            {
                bd[i][j]=y[i]-y[i-1];
            }
            else
            {
                bd[i][j]=bd[i][j-1]-bd[i-1][j-1];
            }
        }
    }
    sm=y[k];
    for(i=1;i<=k-1;i++)
    {
        pr=1;
        for(j=0;j<=i-1;j++)
        {
            pr=pr*(z+j);
            m=fact(i);
            sm=sm+(bd[k][i]*pr)/m;
        }
    }
    cout<<"interplated value "<<sm<<endl;
}
main()
{
    bdi();
}
