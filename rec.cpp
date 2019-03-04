#include <cstdio>
#include <fstream>
#define smax 12005
#define mod 666013
using namespace std;
int v[smax];
int s,n,f;

int main()
{
    freopen("rec.in","r",stdin);
    freopen("rec.out","w",stdout);
    scanf("%d %d %d",&s,&n,&f);
    int i,j,k;
    s-=n*f;
    if (s<0) {
        printf("0\n");
        return 0;
    }
    v[0]=1;
    for (j=1;j<=n;j++)
        for (i=0;i<=s-j;i++) {
            v[i+j]+=v[i];
            if (v[i+j]>mod)
                v[i+j]-=mod;
        }
    printf("%d\n",v[s]);

    return 0;
}
