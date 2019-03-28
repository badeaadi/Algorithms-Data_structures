#include <cstdio>
#include <set>
#include <algorithm>
#define pmax 25005
using namespace std;
int p,n,s,a[pmax],x[pmax];
multiset <int> v;
multiset <int> ::iterator it;
int stop;

int main()
{
    freopen("sume.in","r",stdin);
    freopen("sume.out","w",stdout);
    int i,j,k;
    scanf("%d",&p);
    for (i=1;i<=p;i++)
        scanf("%d",&a[i]);
    for (n=1;n*(n-1)<2*p;n++);
    if (n*(n-1)!=2*p) {
        printf("-1\n");
        return 0;
    }
    sort(a+1,a+p+1);
    for (i=3;i<=n;i++) {
        v.clear();
        s=a[1]+a[2]+a[i];
        if (s%2)
            continue;
        s/=2;
        x[1]=s-a[i];
        x[2]=s-a[2];
        x[3]=s-a[1];
        if (x[1]<=0||x[2]<=0||x[3]<=0)
            continue;
        for (j=3;j<i;j++)
            v.insert(a[j]);
        for (j=i+1;j<=p;j++)
            v.insert(a[j]);
        stop=1;
        for (j=4;j<=n;j++) {
            x[j]=*v.begin()-x[1];
            if (x[j]<=0) {
                stop=0;
                break;
            }
            for (k=1;k<j;k++) {
                it=v.find(x[j]+x[k]);
                if (it==v.end()) {
                    stop=0;
                    break;
                }
                v.erase(it);
            }
            if (!stop)
                break;
        }
        if (!stop)
            continue;
        if (j>n) {
            printf("%d\n",n);
            for (j=1;j<=n;j++)
                printf("%d ",x[j]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
