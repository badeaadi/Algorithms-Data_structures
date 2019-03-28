#include <fstream>
#define nmax 2005
using namespace std;
ifstream f("trmax.in");
ofstream g("trmax.out");
short n,m,k,t,dp[nmax][nmax],x,y;
short v[nmax][nmax],s[nmax][nmax];

int main()
{
    int i,j;
    f>>n>>m>>k;
    for (i=1;i<=k;i++) {
        f>>x>>y;
        v[x][y]=1;
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            s[i][j]=(v[i][j]==0?s[i][j-1]+1:0);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            dp[i][j]=min(dp[i-1][j-1]+1,(s[i][j]+1)/2);
            t=max(t,dp[i][j]);
        }
    g<<1LL*t*t<<'\n';

    return 0;
}
