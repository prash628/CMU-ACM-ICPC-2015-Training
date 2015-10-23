#include<iostream>
#include<string>
using namespace std;



int N,K,D;
 int res;

 long long dp[101][2];


long long func(int pos,int done);

int main()
{

    int T;
    //cin>>T;
    T=1;

    for(int i=0;i<T;i++)
    {
        cin>>N;
        cin>>K;
        cin>>D;


        for(int j=0;j<101;j++)
        {
            dp[j][0]=-1;
            dp[j][1]=-1;
        }
        res=func(0,0);
        cout<<res<<"\n";

    }
    return(0);
}


long long func(int pos,int done)
{
    if(pos>N)
    {
        return(0);
    }

    if(pos==N)
    {
        if(done==0)
        {
            return(0);
        }
        else
        {
            return(1);

        }
    }

    if(dp[pos][done]!=-1)
    {
        return(dp[pos][done]);
    }

    long long res=0;
    for(int p=1;p<=K;p++)
    {
        if(p>=D)
        {
            res=(res+func(pos+p,1))%1000000007 ;
        }
        else
        {
            res=(res+func(pos+p,done))%1000000007 ;
        }
    }
    dp[pos][done]=res;


    return(res);
}
