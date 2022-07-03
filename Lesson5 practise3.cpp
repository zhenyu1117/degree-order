#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define INF 1000 
using namespace std;
int d[1000][1000];
int minn(int a,int b) {return a > b ? b : a; }
int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M) != EOF)
    {
        int x,y;
        for(int i =1;i<=N;i++)
        {
            for(int j =1;j<=N;j++)
                d[i][j] = INF;
            d[i][i] = 0;
        }
        for(int i = 0;i<M;i++)
        {
            scanf("%d%d",&x,&y);
            d[x][y] = 1;
        }
        for(int k = 1;k<= N;k++)
        {
            for(int i = 1;i<=N;i++)
            {
                for(int j  =1; j <=N;j++)
                    d[i][j] = minn(d[i][j],d[i][k] + d[k][j]);
            }
        }
        int ans = 0;
        for(int i = 1;i<=N;i++)
        {
            int t = 1;
            for(int j =1;j<=N;j++)
            {
                if(d[i][j] == INF && d[j][i] == INF)
                    t = 0;
            }
            if(t)
                ans ++;
        }
        printf("%d\n",ans);
    }
}

