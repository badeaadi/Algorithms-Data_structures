#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#define nmax 205
#define inf 1<<30
using namespace std;
vector <int> v[nmax*2];
queue <int> q;
bitset <nmax*2> uz;
int f[nmax*2][nmax*2],c[nmax*2][nmax*2];
int d[nmax*2],t[nmax*2];
int n,m,x,dest,z[nmax*2][nmax*2];
int sol;

void tie(int a,int b,int d,int e)
{
    v[a].push_back(b);
    v[b].push_back(a);
    c[a][b]=d;
    z[a][b]=e;
    z[b][a]=-e;

}
int bfs()
{
    int i,a,b;
    d[1]=0;
    for (i=2;i<=dest;i++)
        d[i]=inf;
    q.push(1);
    uz[1]=1;
    while (!q.empty()) {
        a=q.front();
        uz[a]=0;
        q.pop();
        for (i=0;i<v[a].size();i++) {
            b=v[a][i];
            if (f[a][b]<c[a][b]&&d[b]>d[a]+z[a][b]) {
                d[b]=d[a]+z[a][b];
                t[b]=a;
                if (uz[b]==0) {
                    uz[b]=1;
                    q.push(b);
                }
            }
        }
    }
    if (d[dest]==inf)
        return 0;
    return 1;
}
int main()
{
    freopen("renovare.in","r",stdin);
    freopen("renovare.out","w",stdout);
    int i,j,a,b,r,e;
    scanf("%d %d %d",&n,&m,&x);
    dest=2*n+1;
    for (i=1;i<=m;i++) {
        scanf("%d %d %d %d",&a,&b,&r,&e);
        tie(a,b,r,0);
        tie(a,b+n,inf,e);
    }
    for (i=1;i<n;i++)
        tie(i+n,i,inf,0);

    tie(2*n,n,inf,0);
    tie(n,dest,x,0);

    while (bfs()) {

        int cmin=inf;
        for (i=dest;i!=1;i=t[i])
            cmin=min(cmin,c[t[i]][i]-f[t[i]][i]);
        for (i=dest;i!=1;i=t[i]) {
            f[t[i]][i]+=cmin;
            f[i][t[i]]-=cmin;
        }
        sol+=cmin*d[dest];
    }
    printf("%d\n",sol);
    return 0;
}
