#include <bits/stdc++.h>
#define inf 2000000002
#define e 0.00000000001
#define nmax 1002
using namespace std;
int n,k,nr,sol,m;
struct nod
{double x,y;} v[nmax];

double s[nmax*nmax/2];


int main()
{
    int i,j;
    freopen("trapez.in","r",stdin);
    freopen("trapez.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%lf %lf",&v[i].x,&v[i].y);
    for (i=1;i<n;i++)
        for (j=i+1;j<=n;j++)
            if (v[i].x-v[j].x)
                s[++nr]=(v[i].y-v[j].y)/(v[j].x-v[i].x);
            else
                s[++nr]=inf;
    sort(s+1,s+nr+1);
    for (i=2;i<=nr;i++)
        if (fabs(s[i]-s[i-1])<=e)
            m++;
        else {
            sol=sol+(m*(m + 1)/2);
            m=0;
        }
    printf("%d",sol);
    return 0;
}
