#include<iostream>
#include<string>
using namespace std;



int N,K;
int res;

long long dist[300][300];

long long func();

int main()
{

    int T;
    //cin>>T;
    T=1;
    int a,b;
    long long c;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        for(int p=0; p<N; p++)
        {
            for(int q=0; q<N; q++)
            {
                cin>>dist[p][q];
            }
        }
        cin>>K;
        for(int p=0; p<K; p++)
        {
            cin>>a;
            cin>>b;
            cin>>c;

            a--;b--;

            if(c<dist[a][b])
            {
                dist[a][b]=c;
                dist[b][a]=c;
            }



            int visit[300][300];
            for(int x=0; x<N; x++)
            {
                for(int y=0; y<N; y++)
                {
                    visit[x][y]=0;
                }
            }
            for(int x=0; x<N; x++)
            {
                for(int y=0; y<N; y++)
                {

                        visit[x][y]=1;
                        visit[y][x]=1;
                        long long ia,ab,bj;
                        ia=dist[x][a];
                        ab=dist[a][b];
                        bj=dist[b][y];
                        long long res1=ia+ab+bj;

                        long long ib,ba,aj;
                        ib=dist[x][b];
                        ba=dist[a][b];
                        aj=dist[a][y];
                        long long res2=ia+ab+bj;

                        long long one=res1;
                        if(res2<one)
                        {
                            one=res2;
                        }
                        if(one<dist[x][y])
                        {
                            dist[x][y]=one;
                            dist[y][x]=one;
                        }

                }

            }
            cout<<func()<<" ";
        }
    }
    return(0);
}

long long func()
{
    int A[300][300];
    for(int x=0; x<300; x++)
    {
        for(int y=0; y<300; y++)
        {
            A[x][y]=0;
        }
    }

    long long res=0;
    for(int x=0; x<N; x++)
    {
        for(int y=0; y<N; y++)
        {
            if(A[x][y]==0)
            {
                res+=dist[x][y];
                A[x][y]=1;
                A[y][x]=1;

            }
        }
    }
    return(res);
}
