#include<iostream>
#include<string>
using namespace std;



int N,P;
int Row[6000];
int rowTime[6000];
int colTime[6000];
int Col[6000];

 string what;

int main()
{
std::ios::sync_with_stdio(false);
    int a,b;
    int T;
    //cin>>T;
    T=1;


    for(int i=0;i<6000;i++)
    {
       Row[i]=0;
       Col[i]=0;
       colTime[i]=-1;
       rowTime[i]=-1;
    }
    for(int i=0;i<T;i++)
    {
        cin>>N;
        cin>>P;
                for(int j=0;j<P;j++)
        {

             cin>>what;
             cin>>a;
             cin>>b;
             if(what=="COL")
             {
                 Col[a-1]=b;
                 colTime[a-1]=j;
             }
             else
             {
                 Row[a-1]=b;
                 rowTime[a-1]=j;

             }

        }
    }
    long long sum=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(rowTime[i]>colTime[j])
            {
                sum+=Row[i];

            }
            else
            {
                sum+=Col[j];

            }

        }
    }
    cout<<sum;
    return(0);
}
