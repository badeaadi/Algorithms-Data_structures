#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define nmax 205
using namespace std;
queue <int> q;
vector <int> s,v[nmax];
int c[nmax][nmax],f[nmax][nmax],o[nmax][nmax];
int n,m,l,w,t[nmax],sol=1<<30;

int bfs(int k)
{
    int i,j,r;
    while (!q.empty())
        q.pop();
    memset(t,0,sizeof(t));
    t[1]=1;
    q.push(1);
    while (!q.empty()) {
        i=q.front();
        q.pop();
        for (r=0;r<v[i].size();r++) {
            j=v[i][r];
            if (t[j]==0&&f[i][j]<c[i][j]) {
                t[j]=i;
                q.push(j);
            }
        }
    }
    t[1]=0;
    return t[k];
}
void dfs(int i)
{
    int j;
    for (j=1;j<=n;j++)
        if (t[j]==0&&f[i][j]<c[i][j]) {
            t[j]=1;
            dfs(j);
        }
}
int flux(int k)
{
    int i,j,r,u,w=0;
    while (bfs(k)) {
        for (r=0;r<v[k].size();r++) {
            u=v[k][r];
            if (t[u]==k||t[u]==0||c[u][k]<=f[u][k])
                continue;
            t[k]=u;
            j=1<<30;
            for (i=k;i!=1;i=t[i])
                j=min(j,c[t[i]][i]-f[t[i]][i]);
            if (j==0)
                continue;
            for (i=k;i!=1;i=t[i]) {
                f[t[i]][i]+=j;
                f[i][t[i]]-=j;
            }
            w+=j;
            if (w>sol)
                return w;
        }
    }
    return w;
}
int main()
{
    int i,j,k,x,y,z;
    freopen("sabotaj.in","r",stdin);
    freopen("sabotaj.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1;i<=m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        c[x][y]=z;
        c[y][x]=z;
        o[x][y]=i;
        o[y][x]=i;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (k=2;k<=n;k++) {
        w=flux(k);
        if (sol>w)
            sol=w,l=k;
        memset(f,0,sizeof(f));
        memset(t,0,sizeof(t));
    }
    flux(l);
    memset(t,0,sizeof(t));
    t[1]=1;
    dfs(1);
    for (i=1;i<=n;i++)
        if (t[i]) {
            for (j=1;j<=n;j++)
                if (t[j]==0&&o[i][j]&&f[i][j]==c[i][j])
                    s.push_back(o[i][j]);
        }
    printf("%d %d\n",sol,s.size());
    sort(s.begin(),s.end());
    for (i=0;i<s.size();i++)
        printf("%d\n",s[i]);
    return 0;
}
