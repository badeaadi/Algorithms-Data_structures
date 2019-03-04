#include <cstdio>
#include <algorithm>
#define nmax 50010
#define inf 1<<30
#define mod 5010
using namespace std;
int heap[nmax],poz[nmax],nrh;
int n,v[nmax],z[nmax],r[mod],q[mod];
int minim,minsol,t[nmax];


void downgrade()
{
    poz[heap[1]]=-1;
    heap[1]=heap[nrh];
    nrh--;
    if (nrh==0)
        return;
    poz[heap[1]]=1;
    heap[nrh+1]=0;

    int son,nod=1;
    do
    {
        son=0;
        if (nod*2<=nrh&&z[heap[nod*2]]<z[heap[nod]])
            son=nod*2;
        if (nod*2+1<=nrh&&z[heap[nod*2+1]]<z[heap[nod]]&&z[heap[nod*2+1]]<z[heap[nod*2]])
            son=nod*2+1;

        if (son) {
            swap(poz[heap[nod]],poz[heap[son]]);
            swap(heap[nod],heap[son]);
            nod=son;
        }

    } while (son);

}
void upgrade(int nod)
{
    while (nod>1&&z[heap[nod]]<z[heap[nod/2]]) {
        swap(poz[heap[nod]],poz[heap[nod/2]]);
        swap(heap[nod],heap[nod/2]);
        nod/=2;
    }
}
void dijsktra()
{
    int i,j,k;
    z[0]=0;
    heap[++nrh]=0;
    while (nrh) {
        i=heap[1];
        downgrade();
        for (j=0;j<minim;j++)
            if (r[j]!=inf) {
            k=i+q[j];
            if (k>minim)
                k-=minim;
            if (z[k]>z[i]+r[j]) {
                z[k]=z[i]+r[j];
                if (poz[k]>0)
                    upgrade(poz[k]);
                else {
                    heap[++nrh]=k;
                    poz[k]=nrh;
                }
            }
        }
    }
}

int main()
{
    int i,j;
    freopen("banuti.in","r",stdin);
    freopen("banuti.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    minim=v[1];
    for (i=1;i<minim;i++) {
        z[i]=inf;
        r[i]=inf;
    }
    r[0]=inf;
    for (i=1;i<=n;i++)
        if (v[i]<r[v[i]%minim]) {
            r[v[i]%minim]=v[i];
            q[v[i]%minim]=v[i]%minim;
        }
    dijsktra();

    for (i=0;i<minim;i++)
        if (z[i]==inf) {
            printf("-1\n");
            return 0;
        }
    for (i=1;i<minim;i++)
        minsol=max(minsol,z[i]);

    printf("%d\n",minsol-minim);

    return 0;
}
