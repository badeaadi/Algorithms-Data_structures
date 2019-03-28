#include <cstdio>
#include <algorithm>
#define valmax 34000
#define nmax 100005
#define ub(i) i&(-i)
using namespace std;
int n,a,b,v[nmax],aib[valmax];
long long sol;
int query(int pos)
{
    int s=0;
    if (pos>=1)
        for (int i=pos;i>=1;i-=ub(i))
            s+=aib[i];
    return s;
}
void update(int pos)
{
    if (pos>=1)
        for (int i=pos;i<valmax;i+=ub(i))
            aib[i]++;
}
int main()
{
    int i,j;
    freopen("teams.in","r",stdin);
    freopen("teams.out","w",stdout);
    scanf("%d %d %d",&n,&a,&b);
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    for (i=1;i<=n;i++) {
        sol+=query(b-v[i])-query(a-v[i]-1);
        update(v[i]);
    }
    printf("%lld",sol);
    return 0;
}
