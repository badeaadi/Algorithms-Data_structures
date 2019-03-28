#include <cstdio>
#define nmax 100005
using namespace std;
int n,m,k,a[nmax],b[nmax];

int main()
{
    int i,j;
    freopen("stergeri.in","r",stdin);
    freopen("stergeri.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for (i=1;i<=m;i++)
        scanf("%d %d",&a[i],&b[i]);
    for (i=m;i>=1;i--)
        if (k>=a[i])
            k+=b[i]-a[i]+1;
    printf("%d\n",k);

    return 0;
}
