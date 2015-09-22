#include<iostream>
#include<string>
using namespace std;



int N,K;
 long long res;

int A[200000];
long long P[200000];
long long prefix[200002];
long long memo[200000][2];

long long sum=0;
long long func(int pos,int done);

long long what(int pos);
int main()
{

    int T;
    for(int i=0;i<200002;i++)
    {

        for(int j=0;j<2;j++)
        {
            memo[i][j]=-1;
        }
    }
    //cin>>T;
    T=1;
    for(int i=0;i<T;i++)
    {
        cin>>N;cin>>K;
        for(int j=0;j<N;j++)
        {
            cin>>A[j];

        }
        //Prefix sum
        prefix[0]=0;

        for(int j=1;j<=N;j++)
        {
            prefix[j]=prefix[j-1]+A[j-1];
        }

        res=func(0,0);

        cout<<res<<"\n";


    }
    return(0);
}
long long func(int pos,int done)
{

    if(pos>=N)
    {
        return(0);
    }
    if(done>=2)
    {
        return(0);
    }
    if(memo[pos][done]!=-1){return(memo[pos][done]);}

    long long opt1,opt2;
    opt1=func(pos+K,done+1)+what(pos);
    opt2=func(pos+1,done);
    if(opt1>opt2)
    {
        memo[pos][done]=opt1;
    }
    else
    {
        memo[pos][done]=opt2;
    }
    return(memo[pos][done]);
}

long long what(int pos)
{
    if(pos+K>=N)
    {
        return(prefix[N]-prefix[pos]);
    }
    return(prefix[pos+K]-prefix[pos]);
}
