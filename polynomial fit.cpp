//polynomial fit
#include<iostream>
#include<cmath>
using namespace std;
void polyfit()
{
    int i,j,k,n,m;
    float a[20][20],b[20],aik,s,x[20],y[20];
    cout<<"enter the order of polynomial \n";
    cin>>n;
    cout<<"enter the no. of data points \n";
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cout<<"x["<<i<<"]= ";
        cin>>x[i];
        cout<<"y["<<i<<"]= ";
        cin>>y[i];
    }
    for(i=1;i<=n+1;i++)
    {
        for(j=1;j<=n+1;j++)
        {
            a[i][j]=0;
            for(k=1;k<=m;k++)
            {
                a[i][j]+=pow(x[k],i+j-2);
            }
        }
        a[i][n+2]=0;
        for(k=1;k<=m;k++)
        {
            a[i][j]+=y[k]*pow(x[k],i-1);
        }
    }
    //solution by gauss elimination
    for(k=1;k<=n;k++)
    {
        for(i=k+1;i<=n+1;i++)
        {
            aik=a[i][k]/a[k][k];
            for(j=k;j<=n+2;j++)
            {
                a[i][j]=a[i][j]-aik*a[k][j];
            }

        }
    }
    b[n+1]=a[n+1][n+2]/a[n+1][n+1];
    for(i=n;i>=1;i--)
    {
        s=0;
        for(j=i+1;j<=n+1;j++)
        {
            s+=a[i][j]*b[j];
            b[i]=(a[i][n+2]-s)/a[i][i];
        }
    }
    for(i=1;i<=n+1;i++)
    {
        cout<<"the coefficients are "<<"b["<<i<<"]= "<<b[i]<<endl;
    }
    cout<<"polynomial is y= "<<b[1]<<"+"<<b[2]<<"x +"<<b[3]<<"x2";
}
main()
{
    polyfit();
}
