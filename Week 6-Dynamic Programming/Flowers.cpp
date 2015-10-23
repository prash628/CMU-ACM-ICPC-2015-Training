#include<iostream>
#include<string>
using namespace std;



int N,K;
 long long res;

 int a,b;

 long long dp[100001];
 long long sumDp[100001];

 long long func(int pos);


int main()
{

    int T;
    cin>>T;
    cin>>K;
    //T=1;

    N=100001;
    //Precompute
    dp[0]=1;
    for(int i=1;i<100001;i++)
    {
        dp[i]=dp[i-1];
        if(i-K>=0)
        {
            dp[i]=(dp[i]+dp[i-K])%1000000007;
        }
    }


    long long temp=0;
    for(int i=1;i<100001;i++)
    {
        temp=(temp+dp[i]);
        sumDp[i]=temp;
    }

    sumDp[0]=0;
    for(int i=0;i<T;i++)
    {
        cin>>a;
        cin>>b;


        long long temp1=sumDp[b];
        long long temp2=sumDp[a-1];

       res=temp1-temp2;
       res=res%1000000007;
       cout<<res<<"\n";
    }
    return(0);
}
