#include <cstdio>
#include <algorithm>
#define nmax 155
#define inf 1<<30
using namespace std;
int v[nmax][nmax],s[nmax][nmax];
int n,p,q,sol=-inf;

void solve(int k)
{
    int i,j;
    for (i=k;i<=n;i++)
        for (j=q;j<=n;j++)
    sol=max(sol,s[i][j]-s[i-k][j]-s[i][j-q]+s[i-k][j-q]);
}
int main()
{
    int i,j;
    freopen("rland.in","r",stdin);
    freopen("rland.out","w",stdout);
    scanf("%d %d %d",&n,&p,&q);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) {
            scanf("%d",&v[i][j]);
            s[i][j]=v[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    solve(p);
    printf("%d\n",sol);
    for (i=p-1;i>=1;i--)
        solve(i);
    printf("%d\n",sol);
    return 0;
}
