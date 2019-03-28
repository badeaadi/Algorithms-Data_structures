#include <fstream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#define nmax 2005
#define kmax 16
#define inf 1<<29
using namespace std;
ifstream f("ubuntzei.in");
ofstream g("ubuntzei.out");
int n,m,k,a[kmax+2];
vector <pair <int,int> >v[nmax];
queue <int> q;
int s[1<<kmax][kmax+2];
int c[kmax+2][kmax+2],d[nmax];

void bellmanford(int p)
{
    int i,j,l,o;
    for (i=1;i<=n;i++)
        d[i]=inf;
    q.push(a[p]);
    d[a[p]]=0;
    while (!q.empty()) {
        o=q.front();
        q.pop();
        for (i=0;i<v[o].size();i++) {
            j=v[o][i].first;
            l=v[o][i].second;
            if (d[j]>d[o]+l) {
                d[j]=d[o]+l;
                q.push(j);
            }
        }
    }
    for (i=0;i<=k;i++)
        c[p][i]=d[a[i]];

}
int main()
{
    int i,j,l,x,y,z;
    f>>n>>m;
    f>>k;
    for (i=0;i<k;i++)
        f>>a[i];
    for (i=1;i<=m;i++) {
        f>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    a[k]=n;
    a[k+1]=1;
    bellmanford(k+1);
    if (k==0) {
        g<<c[k+1][k];
        return 0;
    }
    for (i=0;i<k;i++)
        bellmanford(i);

    for (i=0;i<(1<<k);i++)
        for (j=0;j<=k;j++)
            s[i][j]=inf;
    for (i=0;i<k;i++)
        s[1<<i][i]=c[k+1][i];

    for (i=0;i<(1<<k);i++)
        for (j=0;j<k;j++)
            if (i&(1<<j))
                for (l=0;l<k;l++)
                    if ((i&(1<<l))==0)
                        s[i^(1<<l)][l]=min(s[i^(1<<l)][l],s[i][j]+c[j][l]);
    int sol=inf;
    for (i=0;i<k;i++)
        sol=min(sol,s[(1<<k)-1][i]+c[i][k]);
    g<<sol<<'\n';

    return 0;
}
