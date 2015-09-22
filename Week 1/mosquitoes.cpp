#include<iostream>
#include<string>
using namespace std;



int N,M;

 int s1,s2;
int main()
{

    int T;
    long long tempX,tempY;
    long long sum=0;
    int xLow=0,xHigh=0,yLow=0,yHigh=0;
    //cin>>T;
    T=1;
    int i;
    long long op;
    for(i=0;i<T;i++)
    {
        cin>>N;
        for(int j=0;j<N;j++)
        {
            cin>>tempX;
            if(xLow==0){xLow=tempX;}
            else
            {
                if(tempX<xLow){xLow=tempX;}
            }
            if(xHigh==0){xHigh=tempX;}
            else
            {
                if(tempX>xHigh){xHigh=tempX;}
            }


            cin>>tempY;
            if(yLow==0){yLow=tempY;}
            else
            {
                if(tempY<yLow){yLow=tempY;}
            }
            if(yHigh==0){yHigh=tempY;}
            else
            {
                if(tempY>yHigh){yHigh=tempY;}
            }

        }
        s1=xHigh-xLow;
        s2=yHigh-yLow;
        if(s1>s2)
        {
            cout<<(s1*s1);
        }
        else
        {
            cout<<(s2*s2);
        }

    }
    return(0);
}
