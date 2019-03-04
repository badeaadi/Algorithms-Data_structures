#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define nmax 1000005
using namespace std;
long long sol,s,v[nmax*2],w[nmax*2];
int n,m;

int main()
{
    int i,j,k,p;
    freopen("scandura.in","r",stdin);
    freopen("scandura.out","w",stdout);
    scanf("%d %d",&n,&m);
    memset(v,1,sizeof(v));
    memset(w,1,sizeof(w));
    for (i=1;i<=n;i++)
        scanf("%lld",&v[i]);
    reverse(v+1,v+n+1);
    while ((n-1)%(m-1))
        v[++n]=0;
    reverse(v+1,v+n+1);

    i=1;j=1;k=0;
    while ((k-j+1)+(n-i+1)>1) {
        s=0;
        for (p=1;p<=m;p++)
            if (v[i]<w[j]) {
                s+=v[i];
                i++;
            }
            else {
                s+=w[j];
                j++;
            }
        w[++k]=s;
        sol+=s;
    }
    printf("%lld\n",sol);
    return 0;
}
