#include <cstdio>
#define nmax 1005
#define inf 1000000000
using namespace std;
int n,v[nmax];

void genbkt(int n,int p)
{
    if (p==0) {}

    for (i=1;i)




    genbkt(n-1,p);
}
int main()
{
    int i,j;
    for (n=2;(n-1)*n*(n+1)<=inf;n++)
        v[n]=(n-1)*n*(n+1);
    scanf("%d",&m);
    for (i=1;i<=m;i++) {
        scanf("%d",&j);
        genbkt(n-1,j);
    }
    return 0;
}
