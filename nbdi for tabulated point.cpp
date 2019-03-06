//derivative by NBDI for tabulated point
#include<iostream>
#include<cmath>
using namespace std;
inline int fact(int p)
{
    return (p<1?1:p*fact(p-1));
}
void derbdi()
{
    int i,j,k,n,m,p;
    float bd[20][20],x[20],y[20],X,h,sm,sm1,pr,dery,z;
    cout<<"enter the point of differentiation";
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
    h=(x[k+1]-x[k]);
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
    sm=0;
    for(j=1;j<=k-1;j++)
    {
        sm=sm+(bd[k][j])/j;
    }
    dery=sm/h;
    cout<<"the derivative is"<<dery<<endl;
}
main()
{
    derbdi();
}
