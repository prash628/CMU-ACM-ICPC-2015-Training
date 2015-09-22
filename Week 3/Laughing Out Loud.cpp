#include<iostream>
#include<string>
using namespace std;



int N;
 int res;

 string y;
 string x;

 long long memo[100000][3];

 long long func(int i,int j);
int main()
{
    std::ios::sync_with_stdio(false);
    y="LOL";
    int T;
    //cin>>T;
    cin>>T;
    long long res;
    for(int i=0;i<T;i++)
    {
        cin>>x;
        N=x.length();
        for(int j=0;j<100000;j++)
        {

            for(int i=0;i<3;i++)
            {
                memo[j][i]=-1;
            }
        }
        res=func(0,0);
        cout<<res<<"\n";

    }
    return(0);
}
long long func(int i,int j)
{
    long long sum;
     if(j>=3)
    {
        return(1);
    }

    if(i>=N)
    {
        return(0);
    }

    if(memo[i][j]!=-1)
    {
        return(memo[i][j]);
    }

    if(x[i]==y[j])
    {
        sum=func(i+1,j+1);
        sum+=func(i+1,j);
    }
    else
    {

        sum=func(i+1,j);
    }
    memo[i][j]=sum;
    return(memo[i][j]);

}
