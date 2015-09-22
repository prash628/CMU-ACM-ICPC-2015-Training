#include<iostream>
#include<string>
using namespace std;

 long long findCurrent(int pos);
 long long findNext(int pos);
 long long findVal(long long x,int splits);
 long long sumUpto(long long n);

int N,M,K;
 struct whatevz
 {
    long long nextSave;
    int splits;
    long long x;
 }A[100];

int main()
{

    int T;
    long long temp;
    long long sum=0;
    long long res=0;
    long long maxBenifit;
    int maxLocation;
    //cin>>T;
    T=1;
    int i;
    long long op;
    for(i=0;i<T;i++)
    {
        cin>>N;
        cin>>M;
        cin>>K;
        for(int j=0;j<N;j++)
        {
           cin>>temp;
           A[temp-1].x+=1;
        }
    }
    for(int j=0;j<K;j++)
    {
        for(int i=0;i<M;i++)
        {
            A[i].nextSave=findCurrent(i)-findNext(i);
            //cout<<"Next save for "<<i<<"is:"<<A[i].nextSave<<"\n";
        }
        maxBenifit=0;
        maxLocation=0;
        for(int i=0;i<M;i++)
        {
            if(A[i].nextSave>maxBenifit)
            {
                maxLocation=i;
                maxBenifit=A[i].nextSave;
            }
        }
        A[maxLocation].splits+=1;
    }
    for(int i=0;i<M;i++)
    {
        sum+=findCurrent(i);
    }
    cout<<sum;
    return(0);
}
long long findCurrent(int pos)
{
    return(findVal(A[pos].x,A[pos].splits));
}

long long findNext(int pos)
{
    return(findVal(A[pos].x,A[pos].splits+1));
}
long long findVal(long long x,int splits)
{
    long long res;
    if(splits==0)
    {
        return(sumUpto(x));
    }
    splits++;
    long long div,mod;
    div=x/splits;
    mod=x%splits;
    res=splits*sumUpto(div);
    res+=(mod*(div+1));
    return(res);
}
long long sumUpto(long long n)
{
    return((n*(n+1))/2);
}
