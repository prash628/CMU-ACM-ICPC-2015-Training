#include<iostream>
#include<string>
using namespace std;

int N,M;

long long A[1000][1000];
long long dp11[1000][1000];  //To get to that point
long long dp12[1000][1000];  //From that point to end
long long dp21[1000][1000];
long long dp22[1000][1000];
long long func11(int posi,int posj);
long long func12(int posi,int posj);
long long func21(int posi,int posj);
long long func22(int posi,int posj);

int main()
{

    int T;
    //cin>>T;
    T=1;

    for(int i=0; i<T; i++)
    {
        cin>>N;
        cin>>M;
        for(int p=0; p<N; p++)
        {
            for(int q=0; q<M; q++)
            {
                cin>>A[p][q];
                dp11[p][q]=-1;
                dp12[p][q]=-1;
                dp22[p][q]=-1;
                dp21[p][q]=-1;
            }
        }

        for(int p=0; p<N; p++)
        {
            for(int q=0; q<M; q++)
            {
                func11(p,q);
                func12(p,q);
                func21(p,q);
                func22(p,q);
            }
        }


        long long maxcost=-1;
        for(int p=0; p<N; p++)
        {
            for(int q=0; q<M; q++)
            {
                if(p!=0 && p!=N-1 && q!=0 && q!=M-1)
                {
                    long long temp1=0;
                    long long temp2=0;
                    temp1=dp11[p][q-1]+dp12[p][q+1]+dp21[p+1][q]+dp22[p-1][q];
                    temp2=dp11[p-1][q]+dp12[p+1][q]+dp21[p][q-1]+dp22[p][q+1];
                    long long temp;
                    if(temp1>temp2)
                    {
                        temp=temp1;
                    }
                    else
                    {
                        temp=temp2;
                    }
                    if(temp>maxcost)
                    {
                        maxcost=temp;
                    }
                }

            }
        }
        cout<<maxcost<<"\n";
    }
    return(0);
}



long long func11(int i,int j)
{
    if(i<0||j<0)
    {
        return(0);
    }

    if(dp11[i][j]!=-1)
    {
        return(dp11[i][j]);
    }

    long long temp1,temp2;
    temp1=A[i][j]+func11(i-1,j);
    temp2=A[i][j]+func11(i,j-1);
    if(temp1>temp2)
    {
        dp11[i][j]=temp1;
    }
    else
    {
        dp11[i][j]=temp2;
    }
    return(dp11[i][j]);
}




long long func12(int i,int j)
{
    if(i>=N||j>=M)
    {
        return(0);
    }

    if(dp12[i][j]!=-1)
    {
        return(dp12[i][j]);
    }

    long long temp1,temp2;
    temp1=A[i][j]+func12(i+1,j);
    temp2=A[i][j]+func12(i,j+1);
    if(temp1>temp2)
    {
        dp12[i][j]=temp1;
    }
    else
    {
        dp12[i][j]=temp2;
    }
    return(dp12[i][j]);
}


long long func21(int i,int j)
{

    if(i>=N||j<0)
    {
        return(0);
    }

    if(dp21[i][j]!=-1)
    {
        return(dp21[i][j]);
    }

    long long temp1,temp2;
    temp1=A[i][j]+func21(i,j-1);
    temp2=A[i][j]+func21(i+1,j);
    if(temp1>temp2)
    {
        dp21[i][j]=temp1;
    }
    else
    {
        dp21[i][j]=temp2;
    }
    return(dp21[i][j]);
}



long long func22(int i,int j)
{

    if(i<0||j>=M)
    {
        return(0);
    }

    if(dp22[i][j]!=-1)
    {
        return(dp22[i][j]);
    }

    long long temp1,temp2;
    temp1=A[i][j]+func22(i,j+1);
    temp2=A[i][j]+func22(i-1,j);
    if(temp1>temp2)
    {
        dp22[i][j]=temp1;
    }
    else
    {
        dp22[i][j]=temp2;
    }
    return(dp22[i][j]);
}
