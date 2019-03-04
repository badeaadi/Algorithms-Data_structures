#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <queue>
#define nmax 10005
#define bitmax 32
using namespace std;
vector <pair<int,int > > p[nmax];
queue <int> q;
long long sol[nmax];
int n,m,v[nmax];
int x,y,z;

int solve()
{
    int i,j,k,t,r,l;

    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++) {
        p[i].clear();
        v[i]=sol[i]=0;
    }
    for (i=1;i<=m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        p[x].push_back(make_pair(y,z));
        p[y].push_back(make_pair(x,z));
    }
    for (t=0;t<bitmax;t++) {
        for (i=1;i<=n;i++)
            if (v[i]==0) {
                v[i]=2;
                q.push(i);
                while (!q.empty()) {
                    k=q.front();
                    q.pop();
                    for (j=0;j<p[k].size();j++) {
                        l=p[k][j].first;
                        r=p[k][j].second;
                        r&=1<<t;
                        if (r) {
                            if (v[l]) {
                                if (v[l]==v[k])
                                    return 0;
                            }
                            else {
                                v[l]=3-v[k];
                                q.push(l);
                            }
                        }
                        else {
                            if (v[l]) {
                                if (v[l]!=v[k])
                                    return 0;
                            }
                            else {
                                v[l]=v[k];
                                q.push(l);
                            }
                        }
                    }
                }
            }
        for (i=1;i<=n;i++) {
            if (v[i]!=2)
                sol[i]|=1<<t;
            v[i]=0;
        }
    }
    return 1;
}
int main()
{
    int t;
    freopen("bazaconii.in","r",stdin);
    freopen("bazaconii.out","w",stdout);
    for (scanf("%d",&t);t;t--) {
        if (solve())
            for (int i=1;i<=n;i++)
                printf("%lld ",sol[i]);
        else
            printf("-1\n");
    }
    return 0;
}
