#include <cstdio>
#define nmax 1005
using namespace std;
int n,v[nmax],s[nmax];
int p,q,k[nmax];

void solve()
{
    int i,j;
    for (i=1,p=0,q=0;i<=n;i++) {
        s[i]=(s[i-1]+v[i])%n;
        if (s[i]==0) {
            p=1;q=i;
            break;
        }
    }
    for (i=1;i<=n;i++)
        k[i]=0;
    if (!p)
        for (i=1;i<=n;i++) {
            if (k[s[i]]) {
                p=k[s[i]]+1;
                q=i;
                break;
            }
            k[s[i]]=i;
        }
    for (i=p;i<=q;i++) {
        printf("%d ",v[i]);
        v[i]=0;
    }
    j=1;
    n=n-(q-p+1);
    for (i=1,j=1;i<=n;i++) {
        while (v[j]==0)
            j++;
        v[i]=v[j++];
    }
    printf("\n");
}
int main()
{
    freopen("razboi2.in","r",stdin);
    freopen("razboi2.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    while (n)
        solve();

    return 0;
}
