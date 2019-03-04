#include <fstream>
#define nmax 1005
#define umax 100005
using namespace std;
char sol[nmax][nmax],v[nmax][nmax],t[umax];
short l1[umax],c1[umax];
short l2[umax],c2[umax];
int n,m,u,q,l,c;
ifstream f("rox.in");
ofstream g("rox.out");

int main()
{
    int i,j,k;
    f>>n>>m>>u;
    for (i=1;i<=u;i++)
        f>>l1[i]>>c1[i]>>l2[i]>>c2[i]>>t[i];
    for (k=0;k<=25;k++) {
        for (j=1;j<=u;j++)
            if (t[j]==k+'A') {
                v[l1[j]][c1[j]]^=1;
                v[l1[j]][c2[j]+1]^=1;
                v[l2[j]+1][c1[j]]^=1;
                v[l2[j]+1][c2[j]+1]^=1;
            }
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++) {
                v[i][j]^=v[i-1][j]^v[i][j-1]^v[i-1][j-1];
                sol[i][j]+=v[i][j];
            }
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                v[i][j]=0;
        }
    f>>q;
    for (i=1;i<=q;i++) {
        f>>l>>c;
        g<<int(sol[l][c])<<'\n';
    }
    return 0;
}
