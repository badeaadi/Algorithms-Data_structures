#include <cstdio>
#define mod 666013
using namespace std;

void euclid(int a,int b,int &x,int &y)
{
    if (b==0) {
        x=1;
        y=0;
        return;
    }
    int x0,y0;
    euclid(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
}
int im(int p)
{
    int x,y;
    euclid(p,mod,x,y);
    return (1LL*(x+mod)%mod);
}
long long comb(int n,int k)
{
    int a=1,b=1;
    int i;
    for (i=n-k+1;i<=n;i++)
        a=1LL*a*i%mod;
    for (i=1;i<=k;i++)
        b=1LL*b*i%mod;
    return 1LL*a*im(b)%mod;
}

int main()
{
    freopen("arpsohood.in","r",stdin);
    freopen("arpsohood.out","w",stdout);
    int n,k;
    scanf("%d %d",&n,&k);
    int sol=comb(n,k);
    for (int i=1;i<=n-k;i++)
        sol=1LL*sol*k%mod;
    printf("%d",sol);

    return 0;
}
