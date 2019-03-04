#include <fstream>
#define lgmax 20
#define nmax 200005
using namespace std;
ifstream f("reborn.in");
ofstream g("reborn.out");
int n,m,q,t,x[nmax],y[nmax];
int v[lgmax][nmax];

int main()
{
    int i,j,a,b;
    f>>n>>m>>q;
    for (i=1;i<=m;i++) {
        f>>x[i]>>y[i];
        v[0][x[i]]=max(v[0][x[i]],y[i]);
    }
    for (i=1;i<=n;i++) {
        v[0][i]=max(v[0][i],v[0][i-1]);
        v[0][i]=max(v[0][i],i);
    }
    for (i=1;i<lgmax;i++) {
        for (j=1;j<=n;j++)
            v[i][j]=v[i-1][v[i-1][j]];
    }
    for (i=1;i<=q;i++) {
        f>>a>>b;
        if (a>b)
            swap(a,b);
        t=0;
        if (v[lgmax-1][a]<b) {
            g<<-1<<'\n';
            continue;
        }
        for (j=lgmax-1;j>=1;j--)
            if (v[j][a]<b)
                break;

        for (;j>=0;j--) {
            if (v[j][a]<=b) {
                t+=1<<j;
                a=v[j][a];
            }
        }
        if (a<b)
            t++,a=v[0][a];
        g<<t<<'\n';
    }
    return 0;
}
