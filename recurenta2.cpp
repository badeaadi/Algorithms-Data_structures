#include <cstdio>
#define nmax 7
#define mod 666013
using namespace std;
int v[nmax][nmax],r[nmax][nmax];
int k[nmax][nmax];


int prod(int a[][nmax],int b[][nmax])
{
    int c[nmax][nmax]={0};
    int i,j,t;
    for (i=0;i<nmax;i++)
        for (j=0;j<nmax;j++) {
            for (t=0;t<nmax;t++)
                c[i][j]=(c[i][j]+1LL*a[i][t]*b[t][j])%mod;
        }
    for (i=0;i<nmax;i++)
        for (j=0;j<nmax;j++)
            a[i][j]=c[i][j];
}
int main()
{
    int i,j,a,b,c,x1,x2,n;
    freopen("recurenta2.in","r",stdin);
    freopen("recurenta2.out","w",stdout);
    scanf("%d %d %d %d %d %d",&a,&b,&c,&x1,&x2,&n);
    v[0][0]=1;v[1][0]=a;v[2][0]=b;v[3][0]=c;
    v[1][1]=a;v[2][1]=b;v[3][1]=c;v[4][1]=a;v[5][1]=b;v[6][1]=c;
    v[1][2]=1;v[4][2]=1;
    v[3][3]=1;v[6][3]=1;
    v[4][4]=a;v[5][4]=b;v[6][4]=c;
    v[4][5]=1;
    v[6][6]=1;

    k[1][0]=(x1+2*x2)%mod;
    k[1][1]=(3*x2)%mod;
    k[1][2]=(3*x1)%mod;
    k[1][3]=3;
    k[1][4]=x2;
    k[1][5]=x1;
    k[1][6]=1;

    if (n==1)
        printf("%d",x1);
    if (n==2)
        printf("%d",k[1][0]);
    n-=2;
    if (n<=0)
        return 0;

    for (i=0;(1<<i)<=n;i++) {
        if (n&(1<<i))
            prod(k,v);
        prod(v,v);
    }
    printf("%d",k[1][0]);

    return 0;
}
