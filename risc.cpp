#include <cstdio>
#include <queue>
#include <algorithm>
#define inf 1<<29
#define nmax 305
#define qmax 100005
using namespace std;
struct query{int a;int b;int r;int ord;};
priority_queue<pair <int, int>, vector <pair <int,int > > , greater <pair <int ,int > > > h;
query k[qmax];
int sol[qmax];
int n,m,q;
int v[nmax][nmax];

bool risccomp(const query &a,const query &b)
{
    return a.r<b.r;
}
int main()
{
    int i,j,t,r;
    int x,y,z;
    freopen("risc.in","r",stdin);
    freopen("risc.out","w",stdout);
    scanf("%d %d %d",&n,&m,&q);
    for (i=1;i<=n;i++) {
        scanf("%d",&j);
        h.push(make_pair(j,i));
        for (j=1;j<=n;j++)
            if (i!=j)
                v[i][j]=inf;
    }
    for (i=1;i<=m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        v[x][y]=min(v[x][y],z);
        v[y][x]=min(v[y][x],z);
    }
    for (i=1;i<=q;i++) {
        scanf("%d %d %d",&k[i].a,&k[i].b,&k[i].r);
        k[i].ord=i;
    }
    sort(k+1,k+q+1,risccomp);
    for (i=1;i<=q;i++) {
        while (!h.empty()&&h.top().first<=k[i].r) {
            j=h.top().second;
            for (t=1;t<=n;t++)
                for (r=1;r<=n;r++)
                    if (t!=r&&t!=j&&r!=j)
                        v[t][r]=min(v[t][r],v[t][j]+v[j][r]);
            h.pop();
        }
        if (v[k[i].a][k[i].b]!=inf)
            sol[k[i].ord]=v[k[i].a][k[i].b];
        else
            sol[k[i].ord]=-1;
    }
    for (i=1;i<=q;i++)
        printf("%d\n",sol[i]);

    return 0;
}
