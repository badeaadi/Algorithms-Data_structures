#include <cstdio>
#define cmax 11
#define nmax 1005
#define mod 60106
using namespace std;
int n,s,a[cmax][cmax],v[cmax][cmax],m[cmax];
int d1[nmax][cmax],d2[nmax][cmax];

int main()
{
    freopen("tablite.in","r",stdin);
    freopen("tablite.out","w",stdout);
    scanf("%d %d",&n,&s);
    int i,j,t,r;
    for (i=0;i<=9;i++)
        for (j=0;j<=9;j++)
            a[i][j]=1;
    for (i=2;i<=9;i++)
        for (j=2;j<=9;j++)
            if (i%j==0||j%i==0)
                a[i][j]=0;
    for (i=0;i<=9;i++)
        for (j=0;j<=9;j++)
            if (a[i][j]==1)
                v[i][++m[i]]=j;

    for (i=1;i<=9;i++)
        d1[i][i]=1;
    for (n--;n;n--) {
        for (j=1;j<=s;j++)
            for (t=0;t<=9;t++)
                for (r=1;r<=m[t];r++)
                    d2[j+v[t][r]][v[t][r]]+=d1[j][t];

        for (j=1;j<=s;j++)
            for (t=0;t<=9;t++) {
                d1[j][t]=d2[j][t];
                d2[j][t]=0;
                d1[j][t]%=mod;
            }
    }
    j=0;
    for (i=0;i<=9;i++)
        j+=d1[s][i];
    printf("%d\n",j%mod);

    return 0;
}
