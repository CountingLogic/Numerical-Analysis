//gauss seidal
#include<iostream>
#include<cmath>
using namespace std;
void gs()
{
    int i,j,k,n;
    float a[20][20],s,xo[20],eps=0.0001,itrmax=10,x[20],er;
    cout<<"enter the number of rows/coloumns";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n+1;j++)
        {
            cout<<"a["<<i<<"]["<<j<<"]= ";
            cin>>a[i][j];
        }
    }
    	//INITIALIZATION
	for(i=1;i<=n;i++)
	{
		xo[i]=0;
	}
	//ITERATION
	for(k=1;k<=itrmax;k++)
	{
		for(i=1;i<=n;i++)
		{
			s=0;
			for(j=1;j<=n;j++)
			{
				if(i!=j)
				s=s+a[i][j]*xo[j];
			}
			x[i]=(a[i][n+1]-s)/a[i][i];
			er=fabs((x[i]-xo[i])/x[i]);
			if(er<eps)
			goto stp;
		}
		for(i=1;i<=n;i++)
		xo[i]=x[i];
	}

    if(er>eps)
    cout<<"non convergent solution";
    return;
    stp: {cout<<"convergent solution in"<<k<<"iterations"<<endl;
          for(i=1;i<=n;i++)
          cout<<"x["<<i<<"]= "<<x[i]<<endl;
         }
}
main()
{
    gs();
}
