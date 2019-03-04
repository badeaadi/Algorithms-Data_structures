#include <cstdio>
#include <set>
#include <algorithm>
#define nmax 100005
using namespace std;
set <int> v;
set <int> :: iterator it;
int n,m,uz[nmax],k[nmax*2];
int a[nmax],b[nmax];
int p[nmax],pas=1<<20;

void bkt(int nr)
{
    int i;
    if (nr<=m) {
        for (i=1;i<=m;i++)
            if (uz[i]==0) {
                uz[i]=1;
                p[nr]=i;
                bkt(nr+1);
                p[nr]=0;
                uz[i]=0;
                }
        }
    else {

        for (i=1;i<=n;i++) {
            v.insert(a[i]);
            k[a[i]]=i;
        }
        for (i=1;i<=m;i++) {
            if (i%2==1) {
                it=v.end();
                it--;
                v.erase(it);
            }
            else
                v.erase(v.begin());
            v.insert(b[p[i]]);
            int y=0,x,ok=1;
            for (it=v.begin();it!=v.end();it++) {
                x=*it;
                if (k[x]) {
                    if (k[x]>y)
                        y=k[x];
                    else {
                        ok=0;
                        break;
                    }
                }
            }
            if (ok==1)
                pas=min(pas,i);
        }
    }
}
int main()
{
    int i,j;
    freopen("seriale.in","r",stdin);
    freopen("seriale.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (i=1;i<=m;i++)
        scanf("%d",&b[i]);
    sort(b+1,b+m+1);
    bkt(1);
    printf("%d",pas);
    return 0;
}
