#include <cstdio>
#include <algorithm>
#include <set>
#define nmax 50010
#define inf 1<<30
#define mod 5010
using namespace std;
int minim,minsol;
int n,v[nmax];
int z[nmax];
set <pair <int,int > > s;
pair <int,int> p;

void dijsktra()
{
    int i,j,k;
    z[0]=0;
    s.insert(make_pair(0,0));
    while (!s.empty()) {
        p=*s.begin();
        s.erase(s.begin());
        i=p.second;
        for (j=1;j<=n;j++) {
            k=(i+v[j])%minim;
            if (z[k]>z[i]+v[j]) {
                s.erase(make_pair(z[k],k));
                z[k]=z[i]+v[j];
                s.insert(make_pair(z[k],k));
            }
        }
    }
}

int main()
{
    int i,j;
    freopen("banuti.in","r",stdin);
    freopen("banuti.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    minim=v[1];
    for (i=1;i<minim;i++)
        z[i]=inf;

    dijsktra();

    for (i=0;i<minim;i++)
        if (z[i]==inf) {
            printf("-1\n");
            return 0;
        }
    for (i=1;i<minim;i++)
        minsol=max(minsol,z[i]);

    printf("%d\n",minsol-minim);

    return 0;
}
