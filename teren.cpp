#include <cstdio>
#define nmax 305
using namespace std;
int n,m,v[nmax][nmax];
int l[nmax][nmax],c[nmax][nmax];

int main()
{
    int i,j,p,q,k;
    freopen("teren.in","r",stdin);
    freopen("teern.out","w",stdout);
    scanf("%d %d %d",&n,&m,&x);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            scanf("%d",&v[i][j]);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            l[i][j]=v[i][j]+l[i][j-1]
            c[i][j]=v[i][j]+c[i-1][j];
        }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            k=0;
            for (p=i;p<=n;p++) {
                k+=v[p][j];
                if (k>x) {
                    k--;
                    p--;
                    break;
                }
            }
            sol=max(sol,p-i+1);
            for (q=j+1;q<=m;q++) {
                x+=c[p][]


            }
        }


    return 0;
}
