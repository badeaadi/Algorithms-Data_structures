#include <fstream>
#include <cmath>
#include <algorithm>
#define eps 0.000001
#define nmax 200005
using namespace std;
ifstream f("rays.in");
ofstream g("rays.out");
struct event{double u;double s;} v[nmax];
int n,m,k,x[nmax],a[nmax],b[nmax];
double l;

bool sortcomp(const event &a,const event &b)
{
    return a.u<b.u;
}
int solve(int t)
{
    int i,j;
    for (i=1,m=0,k=0;i<=n;i++)
        if ((x[i]<0)==t) {
            m++;
            v[m].u=a[i]/abs(1.0*x[i]);
            v[m].s=b[i]/abs(1.0*x[i]);
            if (v[m].u>v[m].s)
                swap(v[m].u,v[m].s);
        }
    sort(v+1,v+m+1,sortcomp);
    for (i=1,l=-1<<30;i<=m;i++) {
        if (l<v[i].u) {
            l=v[i].s;
            k++;
        }
        else
            l=min(l,v[i].s);
    }
    return k;
}
int main()
{
    int i;
    f>>n;
    for (i=1;i<=n;i++)
        f>>x[i]>>a[i]>>b[i];

    g<<solve(1)+solve(0)<<'\n';

    return 0;
}
