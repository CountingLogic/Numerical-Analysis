//NFDI
#include<iostream>
using namespace std;
inline int fact(int p)
{
    return (p<1?1:p*fact(p-1));
}
void nfdi()
{
    int i,j,k,m,n;
    float x[20],y[20],z,pr,X,fd[20][20],sm;
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
    i=1;
    while(X>x[i])
    i=i+1;
    k=i-1;
    z=(X-x[k])/(x[k+1]-x[k]);
    for(j=1;j<=(n-1);j++)
    {
        for(i=1;i<=(n-j);i++)
        {
            if(j==1)
            {
                fd[i][j]=y[i+1]-y[i];
            }
            else
           {
               fd[i][j]=fd[i+1][j-1]-fd[i][j-1];
           }
        }
    }
    //interpolated value
    sm=y[k];
    for(i=1;i<(n-k);i++)
    {
        pr=1;
        for(j=0;j<=(i-1);j++)
        {
            pr=pr*(z-j);
            m=fact(i);
            sm=sm+(fd[k][i]*pr)/m;
        }

    }
    cout<<"interpolated value of y at x is "<<sm<<endl;
}
main()
{
    nfdi();
}
