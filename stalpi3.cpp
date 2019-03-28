#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define kmax 105
using namespace std;
vector <pair <int,int > > v[2][kmax];
double sol;
int sl[kmax],sc[kmax];
int n,d,k,dist[kmax];

void test(int i,int l,int c,int p)
{
    if (p<dist[i]) {
        dist[i]=p;
        sl[i]=l;
        sc[i]=c;
    }
}
int main()
{
    freopen("stalpi2.in","r",stdin);
    freopen("stalpi2.out","w",stdout);
    int i,j,t,x,y;
    scanf("%d %d",&n,&d);
    for (i=1;i<=n;i++) {
        scanf("%d %d",&x,&y);
        v[0][y].push_back(make_pair(x,i));
    }
    for (i=1;i<=n;i++) {
        scanf("%d %d",&x,&y);
        v[1][y].push_back(make_pair(x,i));
    }
    for (i=1;i<kmax;i++)
        if (v[0][i].size()) {
            sort(v[0][i].begin(),v[0][i].end());
            sort(v[1][i].begin(),v[1][i].end());
            dist[i]=1<<30;
            t=0;k=i;
            for (j=0;j<v[0][i].size();j++) {
                while (t+2<v[1][i].size()&&v[1][i][t+1].first<=v[0][i][j].first)
                    t++;
                if (t<v[1][i].size())
                    test(i,v[0][i][j].second,v[1][i][t].second,abs(v[0][i][j].first-v[1][i][t].first));
                if (t+1<v[1][i].size())
                    test(i,v[0][i][j].second,v[1][i][t+1].second,abs(v[0][i][j].first-v[1][i][t+1].first));
            }
        }
    for (i=1;i<=k;i++)
        sol+=sqrt(dist[i]*dist[i]+d*d);
    printf("%.3lf\n",sol);
    for (i=1;i<=k;i++)
        printf("%d %d\n",sl[i],sc[i]);
    return 0;
}

