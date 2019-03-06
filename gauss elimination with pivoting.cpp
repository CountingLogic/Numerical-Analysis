//gauss elimination with pivoting
#include<iostream>
#include<cmath>
using namespace std;
void gausselim()
{
    float a[20][20],x[20],temp,s,max;
    int i,j,k,n,m,q,p;
    cout<<"enter the number of rows/coloumns";
    cin>>n;
    cout<<"enter the values of the augmented matrix \n ";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n+1;j++)
        {
            cout<<"a["<<i<<"]["<<j<<"] = ";
            cin>>a[i][j];
        }
    }
    //triangularisation
    for(k=1;k<=n-1;k++)
    {
        max=fabs(a[k][k]);
        p=k;
        for(m=k+1;m<=n;m++)
        {
            if(fabs(a[m][k])>max)
            {
                max=fabs(a[m][k]);
                p=m;
            }
        }
        if(p!=k)
        {
            for(q=k;q<=n+1;q++)
            {
                temp=a[k][q];
                a[k][q]=a[p][q];
                a[p][q]=temp;
            }
        }
        for(i=k+1;i<=n;i++)
        {
            temp=a[i][k]/a[k][k];
            for(j=k;j<=n+1;j++)
            a[i][j]=a[i][j]-temp*a[k][j];
        }
    }

    //back substitution
    x[n]=a[n][n+1]/a[n][n];
    for(i=n-1;i>=1;i--)
    {
        s=0;
        for(j=i+1;j<=n;j++)
        {
            s=s+a[i][j]*x[j];
            x[i]=(a[i][n+1]-s)/a[i][i];
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<"x["<<i<<"]= "<<x[i]<<endl;
    }

}
main()
{
    gausselim();
}

