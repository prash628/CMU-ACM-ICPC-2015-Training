 #include<iostream>
#include<string>
#include<cmath>
using namespace std;



int N,D;
int A[2000];
 long long res;


int main()
{

    int T;
    //cin>>T;
    T=1;

    res=0;

    for(int i=0;i<T;i++)
    {
        cin>>N;
        cin>>D;

        for(int j=0;j<N;j++)
        {
        cin>>A[j];

        }

        for(int j=0;j<N-1;j++)
        {
            int x=A[j];
            int y=A[j+1];
            double temp=0;
            if(x>=y)
            {
               temp=(double)(x-y)/(double)D;
               temp=ceil(temp);

               if(y+(D*temp)<=x)
               {
                   temp+=1;
               }
               A[j+1]=y+(D*temp);
            }
            res+=(int)temp;
        }


        cout<<res<<"\n";

    }
    return(0);
}
