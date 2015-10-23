#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int N;
string s,t;
long long alpha[26][26];
long long dp[26][26];
struct mystruct
{
    int pos;
    long long dist;
};

bool operator<(const struct mystruct &left,const struct mystruct &right)
{
    return(left.dist>right.dist);
}

void func(int i,int j);

int main()
{
    int T;
    //cin>>T;
    T=1;

    for(int i=0; i<T; i++)
    {
        cin>>s;
        cin>>t;
        cin>>N;
        for(int p=0; p<26; p++)
        {
            for(int q=0; q<26; q++)
            {
                alpha[p][q]=-1;
            }
        }

        for(int p=0; p<N; p++)
        {
            char x,y;
            long long wt;
            cin>>x;
            cin>>y;
            cin>>wt;

            int x1,y1;
            x1=x-'a';
            y1=y-'a';

            if(alpha[x1][y1]==-1)
            {
                alpha[x1][y1]=wt;
            }
            else
            {
                if(alpha[x1][y1]>wt)
                {
                    alpha[x1][y1]=wt;
                }
            }
        }

        for(int p=0; p<26; p++)
        {
            for(int q=0; q<26; q++)
            {
                func(p,q);
            }

        }

        int sz1,sz2;
        sz1=s.length();
        sz2=t.length();

        if(sz1!=sz2)
        {
            cout<<-1<<"\n";
        }
        else
        {
            int feasibility=1;
            long long res=0;
            for(int p=0; p<sz1; p++)
            {
                int str1Char,str2Char;
                str1Char=s[p]-'a';
                str2Char=t[p]-'a';
                //cout<<"FROM "<<(char)(str1Char+'a')<<"to "<<(char)(str2Char+'a')<<"is"<<dp[str1Char][str2Char]<<"\n";
                //cout<<"FROM "<<(char)(str2Char+'a')<<"to "<<(char)(str1Char+'a')<<"is"<<dp[str2Char][str1Char]<<"\n";
                long long temp,minCost;
                int minPos=-1;
                minCost=-1;

                for(int p=0; p<26; p++)
                {
                    if(dp[str1Char][p]!=-1 && dp[str2Char][p]!=-1)
                    {
                        long long xx=dp[str1Char][p]+dp[str2Char][p];
                        if(minCost==-1)
                        {
                            minCost=xx;
                            minPos=p;
                        }
                        else
                        {
                            if(minCost>xx)
                            {
                                minCost=xx;
                                minPos=p;
                            }
                        }
                    }
                }

                if(minCost==-1)
                {
                    feasibility=0;
                    break;
                }
                res+=minCost;
                s[p]=minPos+'a';
            }
            if(feasibility==0)
            {
                cout<<-1<<"\n";
            }
            else
            {
                cout<<res<<"\n";
                cout<<s<<"\n";
            }
        }

    }
    return(0);
}


void func(int src,int dest)
{
    int visit[26];
    for(int p=0; p<26; p++)
    {
        visit[p]=0;
    }

    priority_queue<struct mystruct> pq;

    struct mystruct first;
    first.pos=src;
    first.dist=0;
    pq.push(first);


    long long minDist=-1;
    while(!pq.empty())
    {
        struct mystruct topOne;
        topOne=pq.top();
        pq.pop();

        int currentPos=topOne.pos;
        long long currentDist=topOne.dist;
        if(currentPos==dest)
        {
            minDist=currentDist;
            break;
        }
        if(visit[currentPos]==0)
        {
            visit[currentPos]=1;
            for(int p=0; p<26; p++)
            {
                if(visit[p]==0)
                {
                    if(alpha[currentPos][p]!=-1)
                    {
                        struct mystruct newOne;
                        newOne.dist=currentDist+alpha[currentPos][p];
                        newOne.pos=p;
                        pq.push(newOne);
                    }
                }
            }
        }
    }
    dp[src][dest]=minDist;
}
