#include <cstdio>
#include <vector>
#include <bitset>
#define nmax 260
#define mmax 7010
using namespace std;
vector <int> v[nmax];
bitset <nmax> uz;
int n,m,sol,nr,t[nmax];
int l[nmax],r[nmax];

int cuplaj(int x)
{
    int i,y;
    uz[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (r[y]==0) {
            l[x]=y;
            r[y]=x;
            return 1;
        }
    }
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (uz[r[y]]==0&&cuplaj(r[y])) {
            l[x]=y;
            r[y]=x;
            return 1;
        }
    }
    return 0;
}
void recursion(int x)
{
    if (l[x]&&uz[l[x]]==0) {

        t[++nr]=l[x];
        uz[l[x]]=1;
        recursion(l[x]);
    }
}
int main()
{
    freopen("strazi.in","r",stdin);
    freopen("strazi.out","w",stdout);
    int i,j,ok,x,y;
    scanf("%d %d",&n,&m);
    for (i=1;i<=m;i++) {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
    }
    do {
        uz.reset();
        ok=0;
        for (i=1;i<=n;i++)
            if (l[i]==0&&cuplaj(i))
                ok=1;
    } while (ok);

    for (i=1;i<=n;i++)
        if (l[i])
            sol++;
    printf("%d\n",n-sol-1);
    uz.reset();

    for (i=1;i<=n;i++)
        if (r[i]==0&&uz[i]==0) {
            t[++nr]=i;
            if (nr!=1)
                printf("%d %d\n",t[nr-1],t[nr]);
            uz[i]=1;
            recursion(i);
        }
    for (i=1;i<=n;i++)
        if (uz[i]==0) {
            t[++nr]=i;
            if (nr!=1)
                printf("%d %d\n",t[nr-1],t[nr]);
            uz[i]=1;
            recursion(i);
        }

    for (i=1;i<=n;i++)
        printf("%d ",t[i]);
    return 0;
}
