#include <fstream>
#define nmax 510
#define mmax 110
using namespace std;
ifstream f("tetris2.in");
ofstream g("tetris2.out");
int n,m,v[nmax][nmax],v1[nmax][nmax],q[nmax],sol;
int p[mmax][mmax],p1[mmax][mmax],t[mmax][mmax];

void makeprefix(int i)
{
    int j,l=0;
    t[i][1]=0;
    l=0;
    for (j=2;j<m;j++) {
        while (l&&p[i][j]!=p[i][l+1])
            l=t[i][l];
        if (p[i][j]==p[i][l+1])
            l++;
        t[i][j]=l;
    }
}
int main()
{
    int i,j,k,l;
    f>>n;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            f>>v[i][j];
            v1[i][j]=v[i][j];
        }
        for (j=1;j<n;j++)
            v[i][j]=-v[i][j]+v[i][j+1];
        v[i][n]=0;
    }
    f>>m;
    if (m==1) {
        g<<n*n<<'\n';
        return 0;
    }
    for (i=1;i<=m;i++) {
        for (j=1;j<=m;j++) {
            f>>p[i][j];
            p1[i][j]=p[i][j];
        }
        for (j=1;j<m;j++)
            p[i][j]-=p[i][j+1];
        p[i][m]=0;
        makeprefix(i);

    }
    for (k=1;k<=n-m+1;k++) {
        for (i=k;i<=k+m-1;i++) {
            l=0;
            for (j=1;j<n;j++) {
                while (l&&v[i][j]!=p[i-k+1][l+1])
                    l=t[i-k+1][l];
                if (v[i][j]==p[i-k+1][l+1])
                    l++;
                if (l==m-1) {
                    q[j]++;
                    l=t[i-k+1][l];
                }
            }
        }
        for (j=1;j<n;j++) {
            if (q[j]==m) {
                l=1;
                for (i=k+1;i<=k+m-1;i++)
                    if (v1[i][j-m+2]-v1[i-1][j-m+2]!=-p1[i-k+1][1]+p1[i-k][1])
                        l=0;
                if (l)
                    sol++;
            }
            q[j]=0;
        }
    }
    g<<sol;
    return 0;
}
