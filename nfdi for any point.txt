//derivative by NFDI for any point
#include<iostream>
#include<cmath>
using namespace std;
inline int fact(int h)
{
    return (h<1?1:h*fact(h-1));
}
void dernfdi()
{
    int i,j,k,n,p,m;
    float fd[20][20],x[20],y[20],X,h,z,dery,sm,sm1,pr;
    cout<<"enter the point of differentiation";
    cin>>X;
    cout<<"enter the the no. of tabulated points";
    cin>>n;
    //enter values
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
    h=(x[k+1]-x[k]);
    z=(X-x[k])/h;

    for(j=1;j<=n-1;j++)
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
    //derivative
    sm=fd[k][1];
    for(j=2;j<=n-k;j++)
    {
        sm1=0;
        for(p=0;p<=j-1;p++)
        {
            pr=1;
            for(m=0;m<=j-1;m++)
            if(m!=p)
            pr*=(z-m);
            sm1+=pr;


        }
        sm=sm+(fd[k][j]*sm1)/fact(j);
    }
    dery=sm/h;
    cout<<"the derivative is"<<dery<<endl;
}
main()
{
    dernfdi();
}
