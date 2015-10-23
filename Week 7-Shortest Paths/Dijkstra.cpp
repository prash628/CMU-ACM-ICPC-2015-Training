
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;



int N,M;
int res;


struct node
{
    int neighb;
    long long wt;
    int prevOne;
};
vector< vector < struct node> > graph;

priority_queue <struct node> pq;

bool operator<(const struct node &left, const struct node &right) {
 return(left.wt>right.wt);
}

int visit[100001];

int prev[100001];

int main()
{

    int T;
    //cin>>T;
    T=1;


    for(int i=0;i<T;i++)
    {
        cin>>N;
        cin>>M;

        for(int j=0;j<100001;j++)
        {
            visit[j]=0;
            graph.push_back(vector<struct node>());
        }

        for(int j=0;j<M;j++)
        {
            int a,b;
            long long wt;
            struct node x1,x2;

            cin>>a;

            cin>>b;
            cin>>wt;
            a--;
            b--;
            x1.neighb=b;
            x1.wt=wt;
            graph[a].push_back(x1);


            x2.neighb=a;
            x2.wt=wt;
            graph[b].push_back(x2);
        }

        struct node first;
        first.neighb=0;
        first.wt=0;
        first.prevOne=-1;
        pq.push(first);
        int done=0;
        long long minDist;

        while(!pq.empty())
        {
            struct node topOne;
            topOne=pq.top();
            int posI=topOne.neighb;
            long long distI=topOne.wt;

            pq.pop();

            if(posI==N-1)
            {
                prev[posI]=topOne.prevOne;
                done=1;
                minDist=distI;
                break;
            }
            if(visit[posI]==0)
            {
                prev[posI]=topOne.prevOne;
                for( vector<struct node>::const_iterator it=graph[posI].begin();it!=graph[posI].end();it++)
                {
                    if(visit[it->neighb]==0)
                    {
                        struct node addition;
                        addition.neighb=it->neighb;
                        addition.wt=distI+it->wt;
                        addition.prevOne=posI;
                        pq.push(addition);

                    }
                }
            }
        visit[posI]=1;

        }

        if(done==0)
        {
            cout<<-1<<"\n";
        }
        else
        {
                vector<int> order;
                int sz=0;
                int what=N-1;
                order.push_back(what);
                while(what!=-1)
                {
                    what=prev[what];
                    order.push_back(what);
                    sz++;
                }

                for(int x=sz-1;x>=0;x--)
                {
                    cout<<order[x]+1<<" ";
                }

            cout<<"\n";
        }

    }
    return(0);
}
