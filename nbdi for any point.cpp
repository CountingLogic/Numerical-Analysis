//derivative by NBDI for any point
#include<iostream>
#include<cmath>
using namespace std;
inline int fact(int h)
{
    return (h<1?1:h*fact(h-1));
}
void dernbdi()
{
    int i,j,k,p,m,n;
    float x[20],y[20],bd[20][20],X,sm,sm1,pr,dery,h,z;
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
    sm=bd[k][1];
    for(j=2;j<=k-1;j++)
    {
        sm1=0;
        for(p=0;p<=(j-1);p++)
        {
            pr=1;
            for(m=0;m<=(j-1);m++)
            if(m!=p)
            pr*=(z+m);
            sm1+=pr;
        }
        sm=sm+(bd[k][j]*sm1)/fact(j);
    }
    dery=sm/h;
    cout<<"the derivative is "<<dery<<endl;

}
main()
{
    dernbdi();
}
