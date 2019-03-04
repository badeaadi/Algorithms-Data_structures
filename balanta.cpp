#include <cstdio>
#include <algorithm>
#define nmax 1100
using namespace std;
int n,m,k,r;
int a[nmax],b[nmax],t[nmax];
int p[nmax],q[nmax];


void mustbe(int x[],int y[])
{
    int i;
    for (i=1;i<=n;i++)
        t[i]=0;
    for (i=1;i<=k;i++)
        t[y[i]]=1;
    for (i=1;i<=n;i++)
        if (t[i]==0)
            x[i]=0;
}
int main()
{
    freopen("balanta.in","r",stdin);
    freopen("balanta.out","w",stdout);
    scanf("%d %d",&n,&m);
    int i,j;
    for (i=1;i<=n;i++)
        p[i]=1,q[i]=1;

    for (i=1;i<=m;i++) {
        scanf("%d",&k);
        for (j=1;j<=k;j++)
            scanf("%d",&a[j]);
        for (j=1;j<=k;j++)
            scanf("%d",&b[j]);

        scanf("%d",&r);
        if (r==2) {
            r=1;
            for (j=1;j<=k;j++)
                swap(a[j],b[j]);
        }
        if (r==0) {
            for (j=1;j<=k;j++) {
                p[a[j]]=q[a[j]]=0;
                p[b[j]]=q[b[j]]=0;
            }
        }
        else {
            mustbe(p,a);
            mustbe(q,b);
        }
    }
    k=0;
    for (i=1;i<=n;i++)
        if (p[i]==1||q[i]==1) {
            k++;
            r=i;
        }
    if (k==1)
        printf("%d\n",r);
    else
        printf("0\n");
    return 0;
}
