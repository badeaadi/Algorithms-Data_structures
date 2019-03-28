#include <cstdio>
#include <algorithm>
#define nmax 800
#define inf 1<<30
using namespace std;
const int dl[4]={-1,1,0,0};
const int dc[4]={0,0,-1,1};
int n,m,v[nmax][nmax],d[nmax][nmax];
int h[nmax*nmax],l[nmax*nmax],c[nmax*nmax],p;
int l1,c1,poz[nmax][nmax];

void upheap(int nod)
{
    h[nod]=d[l[nod]][c[nod]];
    while (nod!=1&&h[nod]<h[nod/2]) {
        swap(h[nod],h[nod/2]);
        swap(poz[l[nod]][c[nod]],poz[l[nod/2]][c[nod/2]]);
        swap(l[nod],l[nod/2]);
        swap(c[nod],c[nod/2]);
        nod/=2;
    }
}
void addheap(int i,int j)
{
    p++;
    h[p]=d[i][j];
    l[p]=i;c[p]=j;
    poz[i][j]=p;
    upheap(p);
}
void downheap(int nod)
{
    int fiu;
    do
    {
        fiu=nod;
        if (nod*2<=p&&h[nod*2]<h[fiu])
            fiu=nod*2;
        if (nod*2+1<=p&&h[nod*2+1]<h[fiu])
            fiu=nod*2+1;

        if (fiu!=nod) {
            swap(h[nod],h[fiu]);
            swap(poz[l[nod]][c[nod]],poz[l[fiu]][c[fiu]]);
            swap(l[nod],l[fiu]);
            swap(c[nod],c[fiu]);
            nod=fiu;
        }
        else
            break;

    } while (1);
}
void popheap()
{
    h[1]=h[p];h[p]=0;
    l[1]=l[p];l[p]=0;
    c[1]=c[p];c[p]=0;
    p--;
    downheap(1);
}
int main()
{
    freopen("volum.in","r",stdin);
    freopen("volum.out","w",stdout);
    int i,j,k;
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            scanf("%d",&v[i][j]);
            d[i][j]=inf;
            if (i==1||i==n||j==1||j==m) {
                d[i][j]=v[i][j];
                addheap(i,j);
            }
        }
    while (p) {
        i=l[1];
        j=c[1];
        popheap();
        for (k=0;k<4;k++) {
            l1=i+dl[k];
            c1=j+dc[k];
            if (d[i][j]<d[l1][c1]) {
                if (d[l1][c1]==inf)
                    addheap(l1,c1);
                d[l1][c1]=d[i][j];

                if (d[l1][c1]<v[l1][c1])
                    d[l1][c1]=v[l1][c1];

                upheap(poz[l1][c1]);
            }
        }
    }
    long long sol=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            sol+=d[i][j]-v[i][j];

    printf("%lld",sol);

    return 0;
}
