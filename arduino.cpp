#include <fstream>
#include <algorithm>
#include <set>
#define nmax 12
#define mod 1000000007
using namespace std;
ifstream f("arduino.in");
ofstream g("arduino.out");
set <int> w;
int p[nmax*nmax][nmax],t[nmax*nmax];
int n,m,r,k,v[nmax],sol;
int glob;

void gen(int k,int c)
{
    int i,j;
    if (k<=n) {
        gen(k+1,c+1);
        for (i=1;i<k;i++)
            if (v[i]==0) {
                v[k]=i;
                gen(k+1,c);
                v[k]=0;
            }
        return;
    }
    if (c>m)
        return;
    for (i=1;i<=r;i++) {
        w.clear();
        for (j=1;j<=p[i][0];j++)
            if (v[p[i][j]])
                w.insert(v[p[i][j]]);
            else
                w.insert(p[i][j]);
        if (w.size()!=t[i])
            return;
    }
    glob++;
    int s=1;
    for (i=m;i>=m-c+1;i--)
        s=1LL*s*i%mod;
    sol=(1LL*sol+s)%mod;
}
int main()
{
    int i,j;
    f>>n>>m;
    f>>r;
    for (i=1;i<=r;i++) {
        f>>t[i];
        f>>p[i][0];
        for (j=1;j<=p[i][0];j++)
            f>>p[i][j];
        sort(p[i]+1,p[i]+p[i][0]+1);
    }
    gen(1,0);
    g<<sol<<'\n';

    return 0;
}
