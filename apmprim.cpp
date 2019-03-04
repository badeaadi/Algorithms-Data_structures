#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define nmax 200005
#define inf 2000000000
using namespace std;
int n,m,k;
int heap[nmax];
int poz[nmax],ans;
int d[nmax],l[nmax];

vector <pair <int, int > > v[nmax];
vector <pair <int,int > > sol;

void heapup(int p)
{
    while (p>1&&d[heap[p]]<d[heap[p/2]]) {

        swap(poz[heap[p]],poz[heap[p/2]]);
        swap(heap[p],heap[p/2]);
        p>>=1;
    }
}
void extractheap()
{
    swap(poz[heap[1]],poz[heap[k]]);
    swap(heap[1],heap[k]);
    heap[k]=poz[heap[k]]=0;
    k--;

    int nod=1;
    int son1,son2,son;
    do {
        son1=(nod<<1),son2=(nod<<1)+1;
        son=0;
        if (son1<=k&&d[heap[son1]]<d[heap[nod]])
            son=son1;
        if (son2<=k&&d[heap[son2]]<d[heap[nod]]&&d[heap[son2]]<d[heap[son1]])
            son=son2;

        if (son) {
            swap(poz[heap[nod]],poz[heap[son]]);
            swap(heap[nod],heap[son]);
            nod=son;
        }
    } while (son);

}
int main()
{
    freopen("apm.in","r",stdin);
    freopen("apm.out","w",stdout);
    scanf("%d %d",&n,&m);
    int i,j;
    int x,y,z;
    for (i=1;i<=m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    poz[1]=1;
    heap[1]=1;
    for (i=2;i<=n;i++) {
        d[i]=inf;
        heap[i]=i;
        poz[i]=i;
    }
    for (k=n;k;) {
        i=heap[1];
        ans+=d[i];
        if (l[i])
            sol.push_back(make_pair(l[i],i));
        d[i]=-inf;
        extractheap();
        for (j=0;j<v[i].size();j++) {
            y=v[i][j].first;
            z=v[i][j].second;
            if (z<d[y]) {
                d[y]=z;
                heapup(poz[y]);
                l[y]=i;
            }
        }
    }
    printf("%d\n%d\n",ans,sol.size());
    for (i=0;i<sol.size();i++)
        printf("%d %d\n",sol[i].first,sol[i].second);

    return 0;
}
