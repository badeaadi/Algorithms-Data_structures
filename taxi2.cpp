#include <cstdio>
#include <algorithm>
#define nmax 1005
#define mod 1000000007
using namespace std;
int a[nmax],b[nmax],c[nmax],sol;
int n,m,v[nmax][nmax];

int main()
{
    int i,j,k;
    freopen("taxi2.in","r",stdin);
    freopen("taxi2.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (i!=j)
                v[i][j]=1<<29;
    for (i=1;i<n;i++) {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        v[a[i]][b[i]]=c[i];
        v[b[i]][a[i]]=c[i];
    }
    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                if (v[i][j]>v[i][k]+v[k][j])
                    v[i][j]=v[i][k]+v[k][j];
    if (m==1) {
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                sol+=v[i][j];
        printf("%d",sol);
    }
    return 0;
}
