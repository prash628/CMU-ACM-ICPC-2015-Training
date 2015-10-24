#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;



int N,M;
 int res;

struct mystruct
{
    int dist;
    int pos;
    int align;
};

vector< vector<int> > horizEdges;
vector< vector<int> > vertEdges;

int main()
{
    std::ios::sync_with_stdio(false);
	int T;
	//cin>>T;
	T=1;

	for(int i=0;i<T;i++)
	{
		cin>>N;
		cin>>M;

		for(int p=0;p<N;p++)
        {
            horizEdges.push_back(vector<int>());
        }
        for(int q=0;q<M;q++)
        {
            vertEdges.push_back(vector<int>());
        }
		for(int p=0;p<N;p++)
        {
            for(int q=0;q<M;q++)
            {
               char x;
               cin>>x;
               if(x=='#')
               {
                   horizEdges[p].push_back(q);
                   vertEdges[q].push_back(p);
               }
            }
        }



		queue<struct mystruct> myQ;
		struct mystruct firstOne;
		firstOne.dist=0;
		firstOne.pos=N-1;
		firstOne.align=0;
		myQ.push(firstOne);

		int vertVisit[1001];
		int horizVisit[1001];
		for(int p=0;p<1001;p++)
        {
            vertVisit[p]=0;
            horizVisit[p]=0;
        }

		int feasible=0;
		while(!myQ.empty())
        {
            struct mystruct topOne;
            topOne=myQ.front();
            myQ.pop();
            int curDist=topOne.dist;
            int curPos=topOne.pos;
            int curAlign=topOne.align;

            if(curAlign==0 && curPos==0)
            {
                feasible=1;
                cout<<curDist<<"\n";
                break;
            }

            if(curAlign==0)
            {
                if(horizVisit[curPos]==0)
                {
                    horizVisit[curPos]=1;
                    vector<int> adj=horizEdges[curPos];
                    for(vector<int>::const_iterator it=adj.begin();it!=adj.end();it++)
                    {
                        int verPos=*it;
                        if(vertVisit[verPos]==0)
                        {
                            struct mystruct newOne;
                            newOne.align=(curAlign+1)%2;
                            newOne.dist=curDist+1;
                            newOne.pos=verPos;
                            myQ.push(newOne);
                        }
                    }
                }
            }
            else
            {
                if(vertVisit[curPos]==0)
                {
                    vertVisit[curPos]=1;
                    vector<int> adj=vertEdges[curPos];
                    for(vector<int>::const_iterator it=adj.begin();it!=adj.end();it++)
                    {
                        int horPos=*it;
                        if(horizVisit[horPos]==0)
                        {
                            struct mystruct newOne;
                            newOne.align=(curAlign+1)%2;
                            newOne.dist=curDist+1;
                            newOne.pos=horPos;
                            myQ.push(newOne);
                        }
                    }
                }
            }


        }
        if(feasible==0)
        {
            cout<<-1<<"\n";
        }


	}
	return(0);
}
