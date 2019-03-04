#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#define nmax 10005
#define umax 150
#define mmax 100005
#define inf 1<<30
using namespace std;
vector <int> p[nmax],v[nmax];
queue <int> q;
bitset <nmax> in;
int c[umax][umax],f[umax][umax],z[umax][umax];
int n,m,u,x,y,t[umax],r[umax],dest;
int d[nmax],sol;


void bellmanford(int nod,int ind)
{
    int i,nod2,nod3;
    q.push(nod);
    for (i=1;i<=n;i++)
        d[i]=inf;
    d[nod]=0;
    q.push(nod);
    in[nod]=1;
    while (!q.empty()) {
        nod2=q.front();
        q.pop();
        in[nod2]=0;
        for (i=0;i<p[nod2].size();i++) {
            nod3=p[nod2][i];
            if (d[nod3]>d[nod2]+1) {
                d[nod3]=d[nod2]+1;
                if (in[nod3]==0) {
                    in[nod3]=1;
                    q.push(nod3);
                }
            }
        }
    }
    int a1,b1;
    for (i=1;i<=y;i++) {
        a1=ind;
        b1=r[i];
        v[a1].push_back(i+u);
        v[i+u].push_back(a1);
        c[ind][i+u]=1;
        z[ind][i+u]=d[b1];
        z[i+u][ind]=-d[b1];
    }
}
int cuplaj()
{
    int i,nod,nod2;
    for (i=1;i<=dest;i++)
        d[i]=inf;
    d[0]=0;
    in.reset();
    in[0]=1;
    q.push(0);
    while (!q.empty()) {
        nod=q.front();
        q.pop();
        in[nod]=0;
        for (i=0;i<v[nod].size();i++) {
            nod2=v[nod][i];
            if (d[nod2]>d[nod]+z[nod][nod2]&&f[nod][nod2]<c[nod][nod2]) {
                d[nod2]=d[nod]+z[nod][nod2];
                t[nod2]=nod;
                if (in[nod2]==0) {
                    in[nod2]=1;
                    q.push(nod2);
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
    freopen("atac2.in","r",stdin);
    freopen("atac2.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&u,&x);
    int i,a,b;
    for (i=1;i<=u;i++)
        scanf("%d",&t[i]);
    for (i=1;i<=m;i++) {
        scanf("%d %d",&a,&b);
        p[a].push_back(b);
        p[b].push_back(a);
    }

    for (i=0;i<p[x].size();i++)
        r[++y]=p[x][i];

    dest=2*u+1;

    for (i=1;i<=u;i++) {
        v[0].push_back(i);
        v[i].push_back(0);
        c[0][i]=1;
    }

    for (i=1;i<=y;i++) {
        v[i+u].push_back(dest);
        v[dest].push_back(i+u);
        c[i+u][dest]=1;
    }

    for (i=1;i<=u;i++)
        bellmanford(t[i],i);

    while (cuplaj()) {
        sol+=d[dest];
        for (i=dest;i;i=t[i]) {
            f[t[i]][i]++;
            f[i][t[i]]--;
        }
    }
    printf("%d",sol);
    return 0;
}
