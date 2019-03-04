#include <cstdio>
#include <algorithm>
#define nmax 100005
#define bitmax 30
using namespace std;
int v[nmax],b[bitmax+5];
int n,sol;

void addmin(int x,int val)
{
    for (int i=0;x;i++)
        if (x&(1<<i)) {
            b[i]+=val;
            x^=1<<i;
        }
}
int okay(int x)
{
    int i;
    for (i=0;i<bitmax;i++)
        if (b[i]==x)
            return 1;
    return 0;
}

int main()
{
    int i,j;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    j=1;
    for (i=1;i<=n;i++) {
        addmin(v[i],1);
        while (j<=n&&okay(i-j+1)==0)
            addmin(v[j++],-1);
        if (okay(i-j+1))
            sol=max(sol,i-j+1);
    }
    printf("%d",sol);

    return 0;
}
