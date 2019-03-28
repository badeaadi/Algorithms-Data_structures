#include <cstdio>
#include <algorithm>
#include <cstring>
#define nmax 305

using namespace std;
int n,m,k,solfin;
int v[nmax][nmax];
int a[nmax*nmax],b;
int cnt[nmax*nmax],nrcnt;

void normalizeaza(int &x)
{
    int sol=0;
    for (int bit=1<<16;bit;bit>>=1)
        if(sol+bit<=b&&a[sol+bit]<=x)
            sol+=bit;
    x=sol;
}
void add(int x)
{
    cnt[x]++;
    if (cnt[x]==1)
        nrcnt++;
}
void take(int x)
{
    cnt[x]--;
    if (cnt[x]==0)
        nrcnt--;

}
void verify(int l,int c)
{
    int lat=1;
    int l1=l,l2=l;
    int c1=c,c2=c;
    int i,j;
    add(v[l1][c1]);
    while (l2+1<=n&&c2+1<=m) {
        for (i=l1;i<=l2;i++)
            add(v[i][c2+1]);
        for (j=c1;j<=c2;j++)
            add(v[l2+1][j]);
        l2++;c2++;
        add(v[l2][c2]);
        lat++;

        while (nrcnt>k) {
            lat--;
            for (i=l1;i<=l2;i++)
                take(v[i][c1]);
            for (j=c1+1;j<=c2;j++)
                take(v[l1][j]);
            l1++;c1++;
        }
        solfin=max(solfin,lat);
    }
    solfin=max(solfin,lat);
    memset(cnt,0,sizeof(cnt));
    nrcnt=0;
}
int main()
{
    int i,j;
    freopen("submatrix.in","r",stdin);
    freopen("submatrix.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            scanf("%d",&v[i][j]);
            a[++b]=v[i][j];
        }
    sort(a+1,a+b+1);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            normalizeaza(v[i][j]);

    for (i=1;i<=n;i++)
        verify(i,1);
    for (j=2;j<=m;j++)
        verify(1,j);
    printf("%d\n",solfin);
    return 0;
}
