#include <cstdio>
#include <algorithm>
#define nmax 100005
using namespace std;

struct func{int a;int b;int ord;} v[nmax];

bool cmpsort(const func &x,const func &y)
{
    if (x.a!=y.a)
        return x.a<y.a;
    return x.b<y.b;
}
int main()
{
    int n,m,i,j;
    freopen("vmin.in","r",stdin);
    freopen("vmin.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++) {
        scanf("%d %d",&v[i].a,&v[i].b);
        v[i].ord=i;
    }
    sort(v+1,v+n+1,cmpsort);

    i=1;
    for (j=2;j<=n;j++)
        if (1LL*v[j].b<v[i].b)
            i=j;

    for (;m;m--) {
        scanf("%d",&j);
        while (i>1&&1LL*v[i-1].a*j+v[i-1].b<1LL*v[i].a*j+v[i].b)
            i--;
        printf("%d ",v[i].ord);
    }
    return 0;
}
