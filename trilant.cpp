#include <cstdio>
#include <vector>
#include <set>
#define inf 1<<28
#define infll 1LL*inf*inf
#define nmax 100005
using namespace std;
long long a[3][nmax],minsum=infll,sol,sum;
int t[3][nmax];
int n,m,x,y,z;
vector <pair<int,int> > v[nmax];
vector <pair<int,int> > :: iterator it;
vector <int> k;
set <pair <long long , int > > s;


void dijkstra(int nod)
{
    s.clear();
    s.insert(make_pair(0,a[nod][0]));
    a[nod][a[nod][0]]=0;
    int i,x,y,z;
    while (!s.empty()) {
        x=s.begin()->second;
        s.erase(s.begin());
        for (it=v[x].begin();it!=v[x].end();it++) {
            y=it->first;
            z=it->second;
            if (a[nod][y]>a[nod][x]+z) {
                if (a[nod][y]!=infll)
                    s.erase(make_pair(a[nod][y],y));
                a[nod][y]=a[nod][x]+z;
                t[nod][y]=x;
                s.insert(make_pair(a[nod][y],y));
            }
        }
    }
}
int main()
{
    int i,j;
    freopen("trilant.in","r",stdin);
    freopen("trilant.out","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&a[0][0],&a[1][0],&a[2][0]);
    for (i=1;i<=m;i++) {
        scanf("%d%d%d",&x,&y,&z);
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    for (i=1;i<=n;i++)
        a[0][i]=a[1][i]=a[2][i]=infll;

    for (i=0;i<3;i++)
        dijkstra(i);
    for (j=1;j<=n;j++) {
        sum=1LL*a[0][j]+a[1][j]+a[2][j];
        if (sum<minsum) {
            minsum=sum;
            sol=j;
        }
    }
    printf("%lld\n",minsum);
    for (i=0;i<3;i++) {
        j=sol;
        while (j!=a[i][0]) {
            k.push_back(j);
            j=t[i][j];
        }
        k.push_back(j);
        printf("%d ",k.size());
        for (j=0;j<k.size();j++)
            printf("%d ",k[j]);
        printf("\n");
        k.clear();
    }
    return 0;
}
