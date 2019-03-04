#include <cstdio>
#include <algorithm>
#include <bitset>
#define nmax 105
using namespace std;
int n,sol,v[nmax];
int p,t,q,c[nmax*nmax],r[nmax*nmax];
bitset <nmax> uz;

int modul(int x)
{
    if (x<0)
        return -x;
    return x;
}
int main()
{
    int i,j;
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    for (i=1;i<=n;i++) {
        uz.reset();
        uz[i]=1;
        t=1;q=0;
        c[1]=i;
        r[1]=1;
        do
        {
            p=q+1;
            q=t;
            for (;p<=q;p++) {
                for (j=1;j<=n;j++)
                    if (uz[j]==0&&modul(v[j]-v[c[p]])<=r[p]) {
                        t++;
                        uz[j]=1;
                        c[t]=j;
                        r[t]=r[p]+1;
                    }
            }


        } while (t>q);
        if (t>sol)
            sol=t;
    }
    printf("%d",sol);

    return 0;
}
