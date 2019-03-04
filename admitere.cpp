#include <fstream>
#include <queue>
#include <algorithm>
#include <cstring>
#define nmax 2015
using namespace std;
ifstream f("admitere.in");
ofstream g("admitere.out");
priority_queue <int, vector <int>, greater<int> > a,b;
struct elev{int a,b,poz;} v[nmax];
char sa[nmax*2],sb[nmax*2];
int x[nmax],y[nmax],z[nmax*2];
int p,n,m,sol[nmax];

int sorta(const elev &x,const elev &y)
{
    return x.a<y.a;
}
int sortb(const elev &x,const elev &y)
{
    return x.a<y.a;
}
void solvefirst()
{
    int i,j,pa,pb;
    for (i=1;i<=m;i++)
        z[x[i]]=-1;
    for (i=1;i<=n;i++)
        z[v[i].a]=v[i].poz;
    i=4000;j=m;
    pa=0;
    while (j) {
        while (z[i]==0)
            i--;
        if (z[i]>0) {
            pa++;
            sa[z[i]]='R';
        }
        j--,i--;
    }
    memset(z,0,sizeof(z));
    for (i=1;i<=m;i++)
        z[y[i]]=-1;
    for (i=1;i<=n;i++)
        z[v[i].b]=v[i].poz;

    i=4000;j=m;
    pb=0;
    while (j) {
        while (z[i]==0)
            i--;
        if (z[i]>0) {
            pb++;
            sb[z[i]]='U';
        }
        j--,i--;
    }
    for (i=1;i<=n;i++) {
        if (sa[i]==0)
            sa[i]='X';
        if (sb[i]==0)
            sb[i]='X';
    }
    g<<max(pa,pb)<<'\n';
    if (pa>pb)
        g<<sa+1<<'\n';
    else
        g<<sb+1<<'\n';
}
void solvesecond()
{


}
int main()
{
    int i;
    f>>p>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x[i];
        a.push(x[i]);
    }
    for (i=1;i<=m;i++) {
        f>>y[i];
        b.push(y[i]);
    }
    for (i=1;i<=n;i++) {
        f>>v[i].a>>v[i].b;
        v[i].poz=i;
    }
    if (p==1)
        solvefirst();
    else
        solvesecond();
    return 0;
}
