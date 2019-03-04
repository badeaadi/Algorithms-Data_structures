#include <iostream>
#include <cstdio>
#include <algorithm>
#define nmax 200010
using namespace std;

int n,k,x;
int v[nmax],st[nmax],dr[nmax];
long long s,t=1,sol;

int main()
{
    int i,j;
    scanf("%d %d %d",&n,&k,&x);
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);

    for (;k;k--,t=1LL*t*x);

    for (i=1;i<=n;i++)
        st[i]=st[i-1]|v[i];
    for (i=n;i>=1;i--)
        dr[i]=dr[i+1]|v[i];

    for (i=1;i<=n;i++)
        sol=max(sol,st[i-1]|(v[i]*t)|dr[i+1]);

    cout<<sol;

    return 0;
}
