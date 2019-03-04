#include <fstream>
#include <algorithm>
#define nmax 505
#define inf 1<<30
using namespace std;
ifstream f("barbie.in");
ofstream g("barbie.out");
int n,m,s,a[nmax],b[nmax];
int m1,m2,v[10005];

int main()
{
    int i,j;
    f>>m1>>m2>>n;
    s=m2-m1;
    for (i=1;i<=n;i++)
        f>>b[i]>>a[i];

    for (i=1;i<=s;i++) {
        v[i]=inf;
        for (j=1;j<=n;j++)
            if (i>=a[j])
                v[i]=min(v[i],v[i-a[j]]+b[j]);
    }
    g<<v[s];
    return 0;
}
