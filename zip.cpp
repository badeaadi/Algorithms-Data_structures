#include <fstream>
#include <cstring>
#define nmax 105
using namespace std;
ifstream f("zip.in");
ofstream g("zip.out");
char s[nmax][nmax],aux[nmax<<1];
int n,m,k,dp[nmax][nmax];
int dist[nmax][nmax],z[nmax<<1];

int zalg(int a,int b)
{
    int i,l=0,r=0,c=1<<30;
    memset(aux,0,sizeof(aux));
    strcat(aux+1,s[b]);
    strcat(aux+1,s[a]);
    memset(z,0,sizeof(z));
    for (i=2;i<=2*k;i++) {
        if (r>=i)
            z[i]=min(z[i-l+1],r-i+1);
        while (i+z[i]<=2*k&&aux[i+z[i]]==aux[1+z[i]])
            z[i]++;
        if (i+z[i]-1>r) {
            r=i+z[i]-1;
            l=i;
        }
        if (i>=k+2&&i+z[i]-1==2*k)
            c=min(c,k-z[i]);
    }
    return min(c,k);
}
int main()
{
    int i,j,t;
    f>>n>>m>>k;f.get();
    for (i=1;i<=n;i++) {
        f.getline(s[i],nmax);
        for (j=1;j<=n;j++)
            dp[i][j]=1<<28;
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
            dist[i][j]=zalg(i,j);
        dp[1][i]=k;
    }
    for (i=1;i<m;i++)
        for (j=1;j<=n;j++)
            for (t=1;t<=n;t++)
                dp[i+1][t]=min(dp[i+1][t],dp[i][j]+dist[j][t]);
    j=1<<30;
    for (i=1;i<=n;i++)
        j=min(j,dp[m][i]);
    g<<j<<'\n';
    return 0;
}
