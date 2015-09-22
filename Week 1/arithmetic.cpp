#include<iostream>
#include<string>
using namespace std;



int N,M;


int main()
{

    int T;
    long long temp;
    long long sum=0;
    //cin>>T;
    T=1;
    int i;
    long long op;
    for(i=0;i<T;i++)
    {
        cin>>N;
        for(int j=0;j<N;j++)
        {
            cin>>temp;
            op=(temp*(j+1))-sum;
            sum+=op;
            cout<<(op);
            if(j!=N-1)
            {
                cout<<" ";
            }

        }
    }
    return(0);
}
