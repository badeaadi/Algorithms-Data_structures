#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#define nmax 1005
#define inf 1<<25
using namespace std;
queue <pair <int,int> > c;
const int dl[4]={1,-1,0,0};
const int dc[4]={0,0,1,-1};
int n,m,s,h,w,v[nmax][nmax];
int k[nmax][nmax],d[nmax][nmax];

int main()
{
    int i,j,i1,j1,p,q,t;
    freopen("date.in","r",stdin);
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            scanf("%d",&v[i][j]);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            v[i][j]=v[i][j]+v[i-1][j]+v[i][j-1]-v[i-1][j-1];
    scanf("%d %d",&h,&w);

    for (i=1;i+h-1<=n;i++)
        for (j=1;j+w-1<=m;j++) {
            p=i+h-1;
            q=j+w-1;
            if (v[p][q]-v[i-1][q]-v[p][j-1]+v[i-1][j-1]==0)
                k[i][j]=1;
        }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            d[i][j]=inf;
    scanf("%d %d",&i,&j);
    c.push(make_pair(i,j));
    d[i][j]=0;
    scanf("%d %d",&p,&q);
    while (!c.empty()) {
        i=c.front().first;
        j=c.front().second;
        c.pop();
        for (t=0;t<=3;t++) {
            i1=i+dl[t];
            j1=j+dc[t];
            if (k[i1][j1]==0)
                continue;
            if (d[i1][j1]>d[i][j]+1) {
                d[i1][j1]=d[i][j]+1;
                c.push(make_pair(i1,j1));
            }
        }
    }
    if (d[p][q]==inf)
        cout<<-1<<'\n';
    else
        cout<<d[p][q];
    return 0;
}
