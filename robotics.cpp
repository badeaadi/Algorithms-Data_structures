#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
#define nmax 1005
using namespace std;
bitset <nmax*2> d[nmax*2];
short v[nmax][nmax];
int x[nmax*2],y[nmax*2],z[nmax*2];
int n,m,t,r[nmax*2],s[nmax*2],f[nmax*2];

int paint()
{
    int i,j,k=0;
    for (i=1;i<=m;i++) {
        v[x[i]][y[i]]++;
        if (z[i]==1)
            for (j=1;j<=t;j++) {
                if (x[i]-j>=1&&y[i]+j<=n)
                    v[x[i]-j][y[i]+j]++;
                if (x[i]+j<=n&&y[i]-j>=1)
                    v[x[i]+j][y[i]-j]++;
            }
        else
            for (j=1;j<=t;j++) {
                if (x[i]-j>=1&&y[i]-j>=1)
                    v[x[i]-j][y[i]-j]++;
                if (x[i]+j<=n&&y[i]+j<=n)
                    v[x[i]+j][y[i]+j]++;
            }
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            k+=v[i][j];
    return k;
}
inline int modul(int x)
{
    if (x<0)
        return -x;
    return x;
}
int dreptunghi(int t)
{
    int i,j,k,o,p,q;
    for (i=1;i<=m;i++)
        d[i].reset();
    for (i=1;i<=m;i++)
        if (z[i]==2) {
            for (j=1,k=0;j<=m;j++)
                if (z[j]==1) {
                    p=s[j]+f[i];
                    if (p&1)
                        continue;
                    p>>=1;
                    q=s[j]-p;
                    if (p<1||q<1||p>n||q>n)
                        continue;
                    if (modul(p-x[j])>t)
                        continue;
                    if (modul(p-x[i])>t)
                        continue;
                    r[++k]=j;
                }
            for (j=1;j<=k;j++)
                for (o=j+1;o<=k;o++)
                    if (d[r[j]][r[o]])
                        return 1;
                    else
                        d[r[j]][r[o]]=1;
        }
    return 0;
}

int main()
{
    int i,j;
    freopen("robotics.in","r",stdin);
    freopen("robotics.out","w",stdout);
    scanf("%d %d %d",&n,&m,&t);
    for (i=1;i<=m;i++) {
        scanf("%d %d %d",&x[i],&y[i],&z[i]);
        s[i]=x[i]+y[i];
        f[i]=x[i]-y[i];
    }
    printf("%d\n",paint());

    int sol;
    for (sol=0,i=1<<9;i;i>>=1)
        if (dreptunghi(sol+i)==0)
             sol+=i;
    sol++;
    if (sol<(1<<10))
        printf("%d\n",sol);
    else
        printf("0\n");

    return 0;
}
