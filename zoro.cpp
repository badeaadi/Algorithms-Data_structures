#include <cstdio>
#include <fstream>
#define nmax 1005
using namespace std;
ifstream f("zoro.in");
ofstream g("zoro.out");
int n,m,v[nmax][nmax],sol[nmax][nmax];
int lin[nmax],col[nmax];
short p[nmax*nmax],q[nmax*nmax];

int main()
{
    int i,j,k;
    f>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            f>>v[i][j];
            p[v[i][j]]=i;
            q[v[i][j]]=j;
        }
    for (i=1;i<=n;i++)
        lin[i]=-(1<<30);
    for (j=1;j<=m;j++)
        col[j]=-(1<<30);

    for (k=n*m;k>=1;k--) {
        i=p[k];j=q[k];
        if (i==1&&j==1)
            sol[i][j]=1;
        else
            sol[i][j]=max(lin[i],col[j])+1;

        lin[i]=max(lin[i],sol[i][j]);
        col[j]=max(col[j],sol[i][j]);
    }
    g<<sol[n][m]<<'\n';

    return 0;
}
