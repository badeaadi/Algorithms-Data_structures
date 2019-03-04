#include <cstdio>
#include <algorithm>
#define nmax 30005
using namespace std;
int v[nmax],r[nmax];
int n,b,c,sol;
int dif;

long long binaryup(int mid)
{
    long long d=0;
    for (int i=1;i<=n;i++) {
        r[i]=v[i]+mid;
        if (r[i]>b)
            r[i]=b;
        d+=r[i]-v[i];
    }
    return d;
}

long long binarydown(int mid)
{
    long long d=0;
    for (int i=1;i<=n;i++) {
        r[i]=v[i]-mid;
        if (r[i]<0)
            r[i]=0;
        d+=r[i]-v[i];
    }
    return d;
}




int main()
{
    int i,j;
    freopen("abc.in","r",stdin);
    freopen("abc.out","w",stdout);
    scanf("%d %d %d",&n,&b,&c);
    dif=c;
    for (i=1;i<=n;i++) {
        scanf("%d",&v[i]);
        dif-=v[i];
    }

    if (dif==0) {
        for (i=1;i<=n;i++)
            printf("%d ",v[i]);
        return 0;
    }
    else
    if (dif>0) {
        for (i=1<<16;i;i>>=1)
            if (sol+i<=b&&binaryup(sol+i)<dif)
                sol+=i;
        sol++;
        for (i=1;i<=n;i++) {
            r[i]=v[i];
            r[i]+=min(sol,dif);
            if (r[i]>b)
                r[i]=b;
            dif-=r[i]-v[i];
        }
    }
    else {
        for (i=1<<16;i;i>>=1)
            if (sol+i<=b&&binarydown(sol+i)>dif)
                sol+=i;
        sol++;
        for (i=1;i<=n;i++) {
            r[i]=v[i];
            r[i]-=min(sol,-dif);
            if (r[i]<0)
                r[i]=0;
            dif-=r[i]-v[i];
        }
    }
    for (i=1;i<=n;i++)
        printf("%d ",r[i]);

    return 0;
}
