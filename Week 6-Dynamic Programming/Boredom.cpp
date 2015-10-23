#include<iostream>
#include<string>
using namespace std;



int N;
 long long res;
 long long A[100001];

 long long dp[100001];

int maxNum;
long long func(long long pos);
int main()
{

    int T;
    //cin>>T;
    T=1;
int temp;
    for(int i=0;i<T;i++)
    {
        cin>>N;
for(int i=0;i<100001;i++)
{
    A[i]=0;dp[i]=-1;
}
maxNum=-1;
        for(int i=0;i<N;i++)
        {
            cin>>temp;

            A[temp]+=1;
            if(temp>maxNum)
            {
                maxNum=temp;
            }
        }
        res=func(1);
        cout<<res<<"\n";

    }
    return(0);
}

long long func(long long pos)
{
    long long res;
    if(pos>maxNum)
    {
        return(0);
    }
    if(dp[pos]!=-1)
    {
        return(dp[pos]);
    }
    long long case1,case2;

    case1=(A[pos]*pos)+func(pos+2);

    case2=func(pos+1);
    if(case1>case2)
    {
        res=case1;
    }
    else
    {
        res=case2;
    }
    dp[pos]=res;
    //cout<<"AT POS:"<<pos<<"case1 is:"<<case1<<"case 2:"<<case2<<"\n";
    return(res);
}
