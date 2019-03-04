#include <fstream>
#include <algorithm>
#define nmax 55
using namespace std;
ifstream f("balcon.in");
ofstream g("balcon.out");
int n,m,v[nmax*nmax],x,y;
int s[nmax][nmax];
int main()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) {
            f>>x;
            v[++m]=x;
        }
    sort(v+1,v+m+1);
    m=0;
    for (x=1,y=n;x<=y;x++,y--) {

        for (j=x;j<=y;j++)
            s[x][j]=v[++m];
        for (j=x+1;j<=y;j++)
            s[j][y]=v[++m];
        for (j=y-1;j>=x;j--)
            s[y][j]=v[++m];
        for (j=y-1;j>x;j--)
            s[j][x]=v[++m];
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
            g<<s[i][j]<<' ';
        g<<'\n';
    }

    return 0;
}
