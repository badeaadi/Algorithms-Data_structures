#include <cstdio>
#define nmax 40
using namespace std;
long long v[nmax];
bool ok;

void prod(long long p)
{
    int i;
    if (!ok&&p%2==0)
        p/=2,ok=1;
    for (i=1;i<=v[0];i++)
        v[i]*=p;
    for (i=1;i<=v[0];i++) {
        v[i+1]+=v[i]/10;
        v[i]%=10;
    }
    if (v[v[0]+1])
        v[0]++;
    while (v[v[0]]>10) {
        v[v[0]+1]+=v[v[0]]/10;
        v[v[0]]%=10;
        v[0]++;
    }
}
int main()
{
    freopen("tort.in","r",stdin);
    freopen("tort.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    v[0]=v[1]=1;
    prod(n+1);prod(m+1);prod(1LL*n+m+2);
    for (int i=v[0];i>=1;i--)
        printf("%d",v[i]);
    return 0;
}
