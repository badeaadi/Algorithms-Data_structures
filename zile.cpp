#include <cstdio>
#define nmax 1005
using namespace std;
int a[nmax],b[nmax],p;
int fin;

void bkt(int n,int z,int k)
{
    if (fin==1)
        return;
    if (z==0) {
        if (n==0&&k==0) {
            for (int i=1;i<=p;i++)
                for (int j=1;j<=b[i];j++)
                    printf("%d ",a[i]);
        fin=1;
        }
        return;
    }
    for (int i=2;i*(i-1)/2<=k&&i<=n;i++) {
        a[++p]=z;
        b[p]=i;
        bkt(n-i,z-1,k-i*(i-1)/2);
        a[p]=0;
        b[p--]=0;
    }
}
int main()
{
    freopen("zile.in","r",stdin);
    freopen("zile.out","w",stdout);
    int n,z,k;
    scanf("%d %d %d",&n,&z,&k);
    bkt(n,z,k);
}
