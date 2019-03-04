#include <cstdio>
#include <algorithm>
#define nmax 50005
using namespace std;
int v[nmax],st[nmax],dr[nmax];


int main()
{
    int i,j;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);

    for (i=n-1;i>=1;i--)
        st[i]=max(st[i+1]+1,dr[i]);
    for (i=2;i<=n;i++)
        dr[i]=max()

    return 0;
}
