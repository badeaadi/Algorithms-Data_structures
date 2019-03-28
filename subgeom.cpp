#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define nmax 5005
#define vmax 100005
using namespace std;
int n,x[nmax],v[vmax];
int sol,xmin,xmax;

int solve()
{
    int i,j,k;
    scanf("%d",&n);
    xmin=1<<30;
    xmax=0;
    for (i=1;i<=n;i++) {
        scanf("%d",&x[i]);
        xmin=min(xmin,x[i]);
        xmax=max(xmax,x[i]);
    }
    sol=1;
    memset(v,0,sizeof(v));
    for (i=2;xmin*i*i<=xmax;i++) {
        for (j=1;j<=n;j++) {
            v[x[j]]=1;
            if (x[j]%i==0)
                v[x[j]]=v[x[j]/i]+1;
            sol=max(sol,v[x[j]]);
        }
        for (j=1;j<=n;j++)
            v[x[j]]=0;
    }
    if (sol==1) {
        for (i=1;i<=n;i++) {
            k=sqrt(double(x[i]));
            for (j=1;j<=k;j++)
                if (x[i]%j==0)
                    if (v[j]||(v[x[i]/j]&&j!=1))
                    return 2;
            v[x[i]]=1;
        }
    }
    return sol;
}

int main()
{
    int i,j,k,t;
    freopen("subgeom.in","r",stdin);
    freopen("subgeom.out","w",stdout);
    for (scanf("%d",&t);t;t--)
        printf("%d\n",solve());
    return 0;
}
