#include <fstream>
#include <algorithm>
#define nmax 18
#define inf 1<<30
using namespace std;
ifstream f("zebughil.in");
ofstream g("zebughil.out");
int n,maxg,v[nmax];
int d[1<<(nmax-1)],l[1<<(nmax-1)];




void solveone()
{
    int i,j,in,nc,ng;
    f>>n>>maxg;
    for (i=0;i<n;i++)
        f>>v[i];
    for (i=1;i<=(1<<n)-1;i++)
        d[i]=inf;

    for (i=0;i<(1<<n)-1;i++) {
        for (j=0;j<n;j++)
        if (!(i&(1<<j))) {
            in=i+(1<<j);
            if (l[i]+v[j]<=maxg) {
                nc=d[i];
                ng=l[i]+v[j];
            }
            else {
                nc=d[i]+1;
                ng=v[j];
            }
            if (nc==0)
                nc++;
            if (nc<d[in]||(nc==d[in]&&ng<=l[in])) {
                d[in]=nc;
                l[in]=ng;
            }
        }
    }
    g<<d[(1<<n)-1]<<'\n';
}
int main()
{
    int t;
    for (t=1;t<=3;t++)
        solveone();

    return 0;
}
