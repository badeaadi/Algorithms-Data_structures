#include <cstdio>
#include <algorithm>
#include <deque>
#define nmax 13
#define inf 1000000000
using namespace std;
deque <int> a;
int n,k,v[nmax][nmax];
int d[2][1<<nmax];

void solve()
{
    scanf("%d",&n);
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            scanf("%d",&v[i][j]);
    for (i=2;i<(1<<n);i++)
        d[i]=inf;
    d[1]=0;
    for (i=1;i<(1<<n);i++) {
        a.clear();b.clear();
        for (j=0;j<n;j++)
            if (i&(1<<j))
                a.push_back(j);
            else
                b.push_back(j);
        dynamic(i,d[i]);
    }
}
int main()
{
    int t;
    freopen("bcast.in","r",stdin);
    freopen("bcast.out","w",stdout);
    for (scanf("%d",&t;t;t--)
        printf("%d\n",solve());
    return 0;
}
