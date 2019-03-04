#include <cstdio>
#include <algorithm>
#define nmax 105
using namespace std;
int n,k,d1,d2,sol[nmax];
int v[nmax][nmax][nmax];

void sum(int a[],int b[])
{
    int i;
    a[0]=max(a[0],b[0])+1;
    for (i=1;i<=b[0];i++)
        a[i]+=b[i];
    for (i=1;i<=a[0];i++)
        if (a[i]>9){
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    if (a[a[0]]==0)
        a[0]--;
}
int main()
{
    int i,j,t;
    freopen("sg1.in","r",stdin);
    freopen("sg1.out","w",stdout);
    scanf("%d %d %d %d",&n,&k,&d1,&d2);
    if (k==0) {
        printf("1");
        return 0;
    }
    for (i=1;i<=n;i++)
        v[1][i][0]=v[1][i][1]=1;

    for (i=2;i<=k;i++)
        for (j=i;j<=n;j++)
            for (t=j-d1-1;t>=j-d2-1&&t>=1;t--)
                sum(v[i][j],v[i-1][t]);

    for (i=k;i<=n;i++)
        sum(sol,v[k][i]);
    if (!sol[0]) {
        printf("0");
        return 0;
    }
    for (i=sol[0];i>=1;i--)
        printf("%d",sol[i]);

    return 0;
}
