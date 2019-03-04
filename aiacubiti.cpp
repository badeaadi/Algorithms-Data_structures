#include <fstream>
#define nmax 1200005
using namespace std;
ifstream f("aiacubiti.in");
ofstream g("aiacubiti.out");
long long ans;
int v[nmax];

void gen(int p,int k,int c)
{
    if (c==0&&(k<(1<<20))) {
        ans+=v[k];
        return;
    }
    if (p<=19) {
        if (c)
            gen(p+1,k^(1<<p),c-1);
        if (c<=19-p)
            gen(p+1,k,c);
    }
}
int main()
{
    int i,j,n;
    f>>n;
    for (i=1;i<=n;i++) {
        f>>j;
        gen(0,j,4);
        v[j]++;
    }
    g<<ans<<'\n';
    return 0;
}
