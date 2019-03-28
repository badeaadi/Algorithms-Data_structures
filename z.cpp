#include <cstdio>
using namespace std;

long long rec(int n,int x,int y)
{
    if (n==0)
        return 1;
    int k=1<<(n-1);
    if (x<=k) {
        if (y<=k)
            return rec(n-1,x,y);
        return 1LL*k*k+rec(n-1,x,y-k);
    }
    if (y<=k)
        return 1LL*2*k*k+rec(n-1,x-k,y);
    return 1LL*3*k*k+rec(n-1,x-k,y-k);
}
int main()
{
    int i,j,n,k,x,y;
    freopen("z.in","r",stdin);
    freopen("z.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (i=1;i<=k;i++) {
        scanf("%d %d",&x,&y);
        printf("%lld\n",rec(n,x,y));
    }
    return 0;
}
