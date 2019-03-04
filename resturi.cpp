#include <fstream>
#define nmax 35
#define pmax 205
using namespace std;
ifstream f("resturi.in");
ofstream g("resturi.out");
int q[pmax];
int n,p[nmax],r[nmax];




void solve()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++)
        f>>p[i]>>r[i];
    initialization(q,r[1]);
    for (i=2;i<=n;i++) {
        m=1;
        initialization(l,1);
        for (j=1;j<i;j++) {
            m=m*p[j]%p[i];
            prod(l,p[j]);
        }
        b=r[i]
    }
}
int main()
{
    int t;
    for (f>>t;t;t--,solve());
    return 0;
}
