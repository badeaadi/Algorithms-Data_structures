#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#define nmax 340
using namespace std;
vector <int> v[nmax];
int k[nmax][nmax],s[nmax][nmax];
int n,m,ok=1;
bitset <nmax> uz,in;
vector <int> a[nmax];
queue <int> q;


void dfs(int x,int y)
{
    int i,j;
    uz[x]=1;uz[y]=1;

    for (i=0;i<v[x].size();i++) {
        j=v[x][i];
        if (j==y)
            continue;
        if (uz[j]) {
            if (s[x][j]==0) {
                ok=0;
                return;
            }
            if (k[y][j]==1&&s[y][j]==0) {
                ok=0;
                return;
            }
        }
        else {
            a[x].push_back(j);
            a[j].push_back(x);
            s[x][j]=s[j][x]=1;
            dfs(j,x);
        }
    }
}
int bellmanford(int x)
{
    return 1;
}
int main()
{
    freopen("tree2.in","r",stdin);
    freopen("tree2.out","w",stdout);
    scanf("%d %d",&n,&m);
    int i,j,t,p,x,y;
    for (i=1;i<=m;i++) {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
        k[x][y]=k[y][x]=1;
    }
    for (i=1;i<=n;i++) {
        for (j=0;j<v[i].size();j++) {

            uz.reset();
            for (t=1;t<=n;t++) {
                for (p=0;p<a[t].size();p++)
                    s[t][a[t][p]]=0;
                a[t].clear();
            }

            a[i].push_back(v[i][j]);
            a[v[i][j]].push_back(i);
            s[i][v[i][j]]=s[v[i][j]][i]=1;
            ok=1;
            dfs(v[i][j],i);
            if (ok==1&&bellmanford(i)) {
                for (t=1;t<=n;t++)
                    for (p=0;p<a[t].size();p++)
                        if (s[t][a[t][p]])
                            printf("%d %d\n",t,a[t][p]);
                return 0;
            }
        }
    }

    return 0;
}
