#include <cstdio>
#include <algorithm>
using namespace std;
#define nmax 10005
#define teta 12
int n,m,t,p,v[nmax];
int c[teta];

void solveone()
{
    printf("%d",m);
}
void solvesecond()
{
    sort(v+1,v+n+1);
    for (int i=1;i<=n;i++)
        if (i==1||v[i]!=v[i-1])
            t++;
    printf("%d",t);
}
int main()
{
    freopen("elevi.in","r",stdin);
    freopen("elevi.out","w",stdout);
    int i,j;
    scanf("%d %d",&p,&n);
    for (i=1;i<=n;i++) {
        scanf("%d",&v[i]);
        while (v[i]) {
            c[v[i]%10]++;
            v[i]/=10;
            m++;
        }
        for (j=9;j>=0;j--)
            while (c[j]) {
                v[i]=v[i]*10+j;
                c[j]--;
            }
    }
    if (p==1)
        solveone();
    else
        solvesecond();

    return 0;
}
