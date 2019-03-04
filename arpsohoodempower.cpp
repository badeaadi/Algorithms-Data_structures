#include <cstdio>
#define mod 666013
#define nmax 505
using namespace std;

int explog(int a,int b)
{
    int sol=1;
    for (;b;b>>=1) {
        if (b&1)
            sol=(1LL*sol*a)%mod;
        a=1LL*a*a%mod;
    }
    return sol;
}
int sol;

int main()
{
    freopen("arpsohood.in","r",stdin);
    freopen("arpsohood.out","w",stdout);
    int n,k,i;
    scanf("%d %d",&n,&k);

    sol=explog(k,n)%mod;
    sol-=1LL*k*explog(k-1,n)%mod;
    sol=(sol+mod*10)%mod;

    printf("%d\n",sol);

    return 0;
}
