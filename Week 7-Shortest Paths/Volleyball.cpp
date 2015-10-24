#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;



int N,M;
int X,Y;
int res;

struct mystruct
{
    int neighb;
    long long dist;
};

long long maxD[1001];
long long costD[1001];
vector< vector<struct mystruct> > roads;

vector< vector<int> > feasiblePaths;

bool operator<(const struct mystruct &left, const struct mystruct &right)
{
    return(left.dist>right.dist);
}

void findFeasiblePaths(int pos);
long long findDist();

int main()
{
	int T;
	//cin>>T;
	T=1;

	for(int i=0;i<T;i++)
	{
		cin>>N;
		cin>>M;
		cin>>X;
		cin>>Y;
		X--;Y--;

		for(int x=0;x<1001;x++)
        {
            roads.push_back(vector<struct mystruct>());
            feasiblePaths.push_back(vector<int>());
        }

		for(int x=0;x<M;x++)
        {
            long long u,v,w;
            cin>>u;
            cin>>v;
            cin>>w;
            u--;v--;
            struct mystruct newRoad1;
            newRoad1.dist=w;
            newRoad1.neighb=v;
            roads[u].push_back(newRoad1);
            struct mystruct newRoad2;
            newRoad2.dist=w;
            newRoad2.neighb=u;
            roads[v].push_back(newRoad2);
        }

        for(int x=0;x<N;x++)
        {
            long long a,b;
            cin>>a;
            cin>>b;
            maxD[x]=a;
            costD[x]=b;
        }

        for(int x=0;x<N;x++)
        {
            findFeasiblePaths(x);
        }

        /*for(int x=0;x<N;x++)
        {
            cout<<"\n\nNEIGHBS FOR POS:"<<x+1<<"are:\n";
            vector<int> adj=feasiblePaths[x];
            for(vector<int>::const_iterator it=adj.begin();it!=adj.end();it++)
            {
                int nextPos=*it;
                cout<<nextPos<<"  ";

            }

        }*/



        cout<<findDist()<<"\n";

	}
	return(0);
}

void findFeasiblePaths(int pos)
{
    int visit[1001];
    for(int i=0;i<N;i++)
    {
        visit[i]=0;
    }
    priority_queue<struct mystruct> pq;
    struct mystruct firstOne;
    firstOne.neighb=pos;
    firstOne.dist=0;

    long long maxDist=maxD[pos];
    pq.push(firstOne);
    while(!pq.empty())
    {
        struct mystruct topOne;

        topOne=pq.top();
        pq.pop();
        long long curDist;
        int curPos;
        curPos=topOne.neighb;
        curDist=topOne.dist;
        //cout<<"FOR POS:"<<pos<<"lookin at"<<curPos<<"\n";
        if(curDist>maxDist)
        {
            break;
        }
        if(visit[curPos]==0)
        {
            feasiblePaths[pos].push_back(curPos);
            visit[curPos]=1;
            vector< struct mystruct> adj=roads[curPos];
            for(vector< struct mystruct>:: const_iterator it=adj.begin();it!=adj.end();it++)
            {
                long long nextDist=it->dist;
                int nextPos=it->neighb;
                long long newDist=nextDist+curDist;
                if(newDist<=maxDist &&visit[nextPos]==0)
                {
                    struct mystruct newNode;
                    newNode.dist=newDist;
                    newNode.neighb=nextPos;
                    pq.push(newNode);
                }
            }
        }
    }
}

long long findDist()
{
    long long res=0;
    int feasible=-1;
    priority_queue<struct mystruct> pq;

    struct mystruct firstOne;
    firstOne.neighb=X;
    firstOne.dist=0;
    pq.push(firstOne);

    int visit[1001];
    for(int i=0;i<1001;i++)
    {
        visit[i]=0;
    }

    while(!pq.empty())
    {
        struct mystruct topOne;
        topOne=pq.top();
        pq.pop();
        long long curDist=topOne.dist;
        int curPos=topOne.neighb;

        if(curPos==Y)
        {
            return(curDist);
        }
        long long nextDist=curDist+costD[curPos];
        if(visit[curPos]==0)
        {
            visit[curPos]=1;
            vector< int > adj=feasiblePaths[curPos];
            for(vector<int>::const_iterator it=adj.begin();it!=adj.end();it++)
            {
                int nextPos=*it;
                if(visit[nextPos]==0)
                {
                    struct mystruct newNode;
                    newNode.neighb=nextPos;
                    newNode.dist=nextDist;
                    pq.push(newNode);
                }

            }
        }

    }


    return(feasible);
}
