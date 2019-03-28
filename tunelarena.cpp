#include <cstdio>
#include <vector>
#include <algorithm>
#define nmax 260
#define eps 1e-7
using namespace std;
vector <pair <int,int> > g[nmax];
double v[nmax][nmax],r;
int n,m,p[nmax];

int main ()
{
    int i,j,t,k,x,y,z;
    freopen("tunel.in","r",stdin);
    freopen("tunel.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (i=1;i<=m;i++) {
        scanf ("%d%d%d",&x,&y,&z);
        g[x].push_back(make_pair(y,z));
        g[y].push_back(make_pair(x,z));
    }

    for (i=1;i<=n;i++) {
        x=g[i].size();
        for (j=0;j<g[i].size();j++) {
            y=g[i][j].first;
            z=g[i][j].second;
            v[i][y]+=-1.0;
            v[i][n+1]+=1.0*z;
        }
        v[i][i]=x;
    }
    for (i=1;i<=n;i++)
        v[i][n]=0.0;

    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
            if (!(v[i][j]>=-eps&&v[i][j]<=eps)) {
                p[i] = j;
                break;
            }
        if (!p[i])
            continue;

        for (t=1;t<=n;t++) {
            if (t==i||((v[t][p[i]]>=-eps&&v[t][p[i]]<=eps)))
                continue;

            r=v[t][p[i]]/v[i][p[i]];

            for (j=1;j<=n+1;j++)
                v[t][j]=v[t][j]-r*v[i][j];
        }
    }

    printf ("%.5f\n",v[1][n+1]/v[1][1]);
    return 0;
}
