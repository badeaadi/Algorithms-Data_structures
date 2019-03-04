#include <cstdio>
#include <algorithm>
#define nmax 50005
using namespace std;
int n,v[nmax];
int sol;


int cows(int mid)
{
    int i=1,j,k=0;
    while (i<=n) {
        k++;
        j=v[i]+2*mid;
        while (i<=n&&v[i]<=j)
            i++;
    }
    return k;
}

int main()
{
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    int i,j,k;
    scanf("%d %d",&n,&k);
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    int st=0,dr=1<<30;
    int mid;
    while (st<=dr) {
        mid=(st+dr)>>1;
        if (cows(mid)<=k) {
            sol=mid;
            dr=mid-1;
        }
        else
            st=mid+1;
    }
    printf("%d",sol);
    return 0;
}
