#include <cstdio>
#include <algorithm>
#define nmax 5000
using namespace std;
int n,m,s[nmax];
int v[nmax];

void adding(int a[],int b[])
{
    int i;
    a[0]=max(a[0],b[0]);
    for (i=1;i<=b[0];i++)
        a[i]+=b[i];
    a[0]+=2;
    for (i=1;i<=a[0];i++)
        if (a[i]>9) {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    while (a[a[0]]==0)
        a[0]--;
}
void prodvect(int val)
{
    int i;
    for (i=1;i<=v[0];i++)
            v[i]*=val;
    v[0]+=10;
    for (i=1;i<=v[0];i++)
        if (v[i]>9) {
            v[i+1]+=v[i]/10;
            v[i]%=10;
        }
    while (v[v[0]]==0)
        v[0]--;
}
void prod(int n)
{
    int i,j;
    while (n>=20) {
        prodvect(1<<20);
        n-=20;
    }
    while (n) {
        prodvect(2);
        n--;
    }
}
int main()
{
    int i;
    freopen("aladdin2.in","r",stdin);
    freopen("aladdin2.out","w",stdout);
    scanf("%d %d",&n,&m);
    if (n>m)
        i=n,n=m,m=i;
    v[0]=v[1]=1;
    s[0]=1;s[1]=-2;
    prod(n);
    adding(s,v);
    prod(m-n);
    adding(s,v);
    for (i=s[0];i>=1;i--)
        printf("%d",s[i]);
    return 0;
}
