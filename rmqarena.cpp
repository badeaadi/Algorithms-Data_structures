#include <fstream>
#define lgmax 17
#define nmax 100005
using namespace std;
ifstream f("rmq.in");
ofstream g("rmq.out");
int n,m,v[lgmax][nmax];
int log,lg[nmax];

void rmq()
{
    int i,j,l;
    for (i=2;i<=n;i++)
        lg[i]=lg[i/2]+1;
    //v[i][j]=maximul(j,j+(1<<i)-1)
    for (i=1;(1<<i)<=n;i++) {
        l=1<<(i-1);
        for (j=1;j<=n-(1<<i)+1;j++)
            v[i][j]=min(v[i-1][j],v[i-1][j+l]);
    }
}
int main()
{
    int i,j,x,y;
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>v[0][i];
    rmq();
    for (i=1;i<=m;i++) {
        f>>x>>y;
        log=lg[y-x+1];
        g<<min(v[log][x],v[log][y-(1<<log)+1])<<'\n';

    }
    return 0;
}
