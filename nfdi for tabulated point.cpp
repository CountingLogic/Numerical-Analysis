//derivative by NFDI for tabulated point
#include<iostream>
#include<cmath>
using namespace std;
inline int fact(int p)
{
    return (p<1?1:p*fact(p-1));
}
void dernfdi()
{
    int i,j,k,m,n,p;
    float x[20],y[20],z,pr,X,fd[20][20],sm,h,dery,sm1;
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
    k=i;

    h=(x[k+1]-x[k]);
    for(j=1;j<=(n-1);++j)
    {
        for(i=1;i<=(n-j);++i)
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
    //derivative'
    sm=0;
    for(j=1;j<=n-k;j++)
    {
        sm=sm+(fd[k][j]*pow(-1,j+1))/j;
    }
    dery=sm/h;
    cout<<"the derivative is"<<dery<<endl;
}
    main()
    {
        dernfdi();
    }

