#include <cstdio>
#include <vector>
#include <algorithm>
#define nmax 260000
#define mmax 520000
using namespace std;
vector <int> p[nmax],r[nmax];
struct query{int a;int b;int o;} q[mmax];
int n,m,e,c[nmax],t[nmax],niv[nmax];
int first[nmax],last[nmax];
int lev=-1,levmax,poz,val,sol[mmax];
int poz1,poz2,k;
int v[nmax*5];

void dfseuler(int nod)
{
    int nod2;
    first[nod]=++e;
    levmax=max(levmax,niv[nod]);
    for (int i=0;i<p[nod].size();i++) {
        nod2=p[nod][i];
        niv[nod2]=niv[nod]+1;
        dfseuler(nod2);
    }
    last[nod]=++e;
}
bool querysorting(const query &x,const query &y)
{
    if (x.b!=y.b)
        return x.b<y.b;
    return niv[x.a]<niv[y.a];
}
void update(int nod,int st,int dr)
{
    v[nod]+=val;
    if (st==dr)
        return;
    int mid=(st+dr)>>1;
    if (poz<=mid)
        update(nod*2,st,mid);
    else
        update(nod*2+1,mid+1,dr);
}
void queryarb(int nod,int st,int dr)
{
    if (poz1<=st&&dr<=poz2) {
        val+=v[nod];
        return;
    }
    int mid=(st+dr)>>1;

    if (mid>=poz1)
        queryarb(nod*2,st,mid);
    if (mid+1<=poz2)
    queryarb(nod*2+1,mid+1,dr);


}
int main()
{
    int i,j,k;
    freopen("arb.in","r",stdin);
    freopen("arb.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for (i=2;i<=n;i++) {
        scanf("%d",&t[i]);
        p[t[i]].push_back(i);
    }
    scanf("%d",&m);
    dfseuler(1);
    for (i=1;i<=n;i++)
        r[niv[i]].push_back(i);
    for (i=1;i<=m;i++) {
        scanf("%d %d",&q[i].a,&q[i].b);
        q[i].b+=niv[q[i].a];
        q[i].o=i;
    }
    sort(q+1,q+m+1,querysorting);
    for (i=1;i<=m;i++) {
        while (lev<levmax&&lev<q[i].b) {
            lev++;
            for (j=0;j<r[lev].size();j++) {
                k=r[lev][j];
                poz=first[k];
                val=c[k];
                update(1,1,e);
            }
        }
        poz1=first[q[i].a];
        poz2=last[q[i].a];
        val=0;
        queryarb(1,1,e);
        sol[q[i].o]=val;
    }
    for (i=1;i<=m;i++)
        printf("%d\n",sol[i]);
    return 0;
}
