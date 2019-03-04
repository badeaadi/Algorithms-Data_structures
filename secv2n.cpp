#include <cstdio>
#define nmax 50005
#define inf 1<<30
int n,k,smax=-inf,p,q;
int v[nmax],s[nmax];
int snow=inf,pnow;

int main()
{
    freopen("secv2.in","r",stdin);
    freopen("secv2.out","w",stdout);
    int i,j;
    scanf("%d %d",&n,&k);
    for (i=1;i<=n;i++) {
        scanf("%d",&v[i]);
        s[i]=s[i-1]+v[i];
    }
    for (i=k;i<=n;i++) {
        if (s[i-k]<snow) {
            snow=s[i-k];
            pnow=i-k+1;
        }
        if (s[i]-snow>smax) {
            smax=s[i]-snow;
            p=pnow;;q=i;
        }
    }
    printf("%d %d %d",p,q,smax);


    return 0;
}
