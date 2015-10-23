#include<iostream>
#include<string>
using namespace std;

int N;
double P;
int time;

double dp[2002];


int main()
{
    int T;
    //cin>>T;
    T=1;
    double res=0.0;
    for(int i=0;i<T;i++)
    {
        cin>>N;
        cin>>P;
        cin>>time;


        for(int j=1;j<2001;j++)
        {
           dp[j]=0.0;
        }
        dp[1]=1.0;


        for(int j=1;j<=time;j++)
        {
            double step=0.0;
            for(int k=j;k>=1;k--)
            {
                if(k>N)
                {

                }
                else
                {
                    double temp1,temp2;
                    temp1=dp[k];
                    temp2=temp1*P;
                    dp[k]=dp[k]-temp2;
                    dp[k+1]+=temp2;
                    step+=temp2;
                }
            }
            res+=step;
        }

        cout.precision(15);

        cout<<fixed<<res<<"\n";

    }
    return(0);
}
