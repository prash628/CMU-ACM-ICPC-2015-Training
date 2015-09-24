#include<iostream>
#include<string>
using namespace std;



int N,M;
 int res;


long long A[10000];

long long real[10000];

int Q;

char x;

long long l,r;
int P;


long long modvalue;
int main()
{

    int T;
    //cin>>T;
    T=1;
long long sum;
    for(int i=0;i<T;i++)
    {
        cin>>N;
        cin>>M;
        for(int j=0;j<N;j++)
        {
            cin>>A[j];
            real[j]=A[j]%M;
        }
        cin>>Q;
        for(int j=0;j<Q;j++)
        {
            cin>>x;
            if(x=='s')
            {
                sum=0;
                cin>>l;
                l--;
                cin>>r;
                r--;
                cin>>modvalue;
                modvalue=modvalue%M;
                for(int p=l;p<=r;p++)
                {
                    if(real[p]==modvalue)
                    {
                        sum=(sum+A[p]);
                    }
                }
                cout<<sum<<"\n";

            }
            if(x=='+')
            {
                cin>>P;
                P--;
                cin>>r;
                A[P]+=r;
                real[P]=A[P]%M;
                cout<<A[P]<<"\n";
            }
            if(x=='-')
            {
                cin>>P;
                P--;
                cin>>r;
                if(A[P]-r>=0)
                {
                    A[P]=A[P]-r;real[P]=A[P]%M;
                }

                cout<<A[P]<<"\n";
            }
        }


    }
    return(0);
}
