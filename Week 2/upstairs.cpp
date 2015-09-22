#include<iostream>
#include<string>
#include <algorithm>
using namespace std;



int N;
int A[100000];
int sum[100000];

int main()
{

    int T;
    int temp;
    //cin>>T;
    T=1;
    int minPos=-1;
    int minCost=-1;
    int sum=0;

long long case1Sum,case2Sum;

    for(int i=0; i<T; i++)
    {
        cin>>N;
        for(int j=0; j<N; j++)
        {

            cin>>temp;
            A[j]=temp;

        }
    }

    if(N-2>0)
    {
        case1Sum=0;
        if(A[N-1]-A[N-2]>0)
        {
            case1Sum+=A[N-1]-A[N-2];
        }
        if(A[N-2]-A[N-3]>0)
        {
            case1Sum+=A[N-2]-A[N-3];
        }
        case2Sum=0;
        if(A[N-2]-A[N-1]>0)
        {
            case2Sum+=A[N-2]-A[N-1];
        }
        if(A[N-1]-A[N-3]>0)
        {
            case2Sum+=A[N-1]-A[N-3];
        }
        if(case1Sum-case2Sum>0)
        {
            minPos=N-2;
            minCost=case1Sum-case2Sum;
        }

    }
    if(N-2==0)
    {
        if(A[N-1]>A[N-2])
        {
            minPos=N-2;
            minCost=A[N-1]-A[N-2];
        }
    }



    for(int i=(N-3); i>0; i--)
        {
            case1Sum=0;
            if(A[i]-A[i-1]>0)
            {
                case1Sum+=A[i]-A[i-1];
            }
            if(A[i+1]-A[i]>0)
            {
                case1Sum+=A[i+1]-A[i];
            }
            if(A[i+2]-A[i+1]>0)
            {
                case1Sum+=A[i+2]-A[i+1];
            }

            //Case2-swap
            case2Sum=0;
            if(A[i+1]-A[i-1]>0)
            {
                case2Sum+=A[i+1]-A[i-1];
            }
            if(A[i]-A[i+1]>0)
            {
                case2Sum+=A[i]-A[i+1];
            }
            if(A[i+2]-A[i]>0)
            {
                case2Sum+=A[i+2]-A[i];
            }

            //cout<<"FOR i="<<i<<"ANSWER IS:"<<case2Sum-case1Sum<<"\n";
            if(case2Sum-case1Sum<0)
            {
                if(case1Sum-case2Sum>=minCost)
                {
                    minPos=i;
                    minCost=case1Sum-case2Sum;
                }
            }

        }
        if(N>2)
        {
            case1Sum=0;
            if(A[1]-A[0]>0)
            {
                case1Sum+=A[1]-A[0];
            }
            if(A[2]-A[1]>0)
            {
                case1Sum+=A[2]-A[1];
            }
            case2Sum=0;
            if(A[0]-A[1]>0)
            {
                case2Sum+=A[0]-A[1];
            }
            if(A[2]-A[0]>0)
            {
                case2Sum+=A[2]-A[0];
            }
            if(case2Sum<case1Sum)
            {
                if(case1Sum-case2Sum>=minCost)
                {
                    minPos=0;

                }
            }
        }

        if(minPos==-1)
        {
            cout<<-1;
        }
        else
        {

    cout<<minPos+1;
        }






    return(0);
}
