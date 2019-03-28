#include <cstdio>
#define nmax 2105
#define base 10000
using namespace std;
int n,m,k,sol[nmax];
int v[nmax];

void prod(int p)
{
    int i;
    for (i=1;i<=v[0];i++)
        v[i]*=p;
    v[0]+=2;
    for (i=1;i<=v[0];i++)
        if (v[i]>=base) {
            v[i+1]+=v[i]/base;
            v[i]%=base;
        }
    while (!v[v[0]])
        v[0]--;
}
void split(int p)
{
    int i;
    for (i=v[0];i>1;i--) {
        v[i-1]+=(v[i]%p)*base;
        v[i]/=p;
    }
    v[1]/=p;
    while (!v[v[0]])
        v[0]--;
}
void sum(int a[],int b[])
{
    int i;
    for (i=1;i<=v[0];i++){
        sol[i]+=v[i];
        if (sol[i]>=base) {
            sol[i+1]+=sol[i]/base;
            sol[i]%=base;
        }
    }
}
int main()
{
    freopen("siruri2.in","r",stdin);
    freopen("siruri2.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    int i,j;
    n--;
    v[0]=v[1]=1;
    for (i=1;i<=k;i++) {
        prod(m-i+1);
        split(i);
        sum(sol,v);
        prod(n-i+1);
        split(i);
    }
    sol[0]=2000;
    for (i=1;i<=sol[0];i++)
        if (sol[i]>=base) {
            sol[i+1]+=sol[i]/base;
            sol[i]%=base;
        }
    while (!sol[sol[0]])
        sol[0]--;
    printf("%d",sol[sol[0]]);
    for (i=sol[0]-1;i>=1;i--) {
        j=base/10;
        while (j>1&&sol[i]<=j) {
            printf("0");
            j/=10;
        }
        printf("%d",sol[i]);
    }
    return 0;
}
