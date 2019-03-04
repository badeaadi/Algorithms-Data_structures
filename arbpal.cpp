#include <fstream>
#include <vector>
#define nmax 5005
using namespace std;
ifstream f("arbpal.in");
ofstream g("arbpal.out");
vector <int> v[nmax];
int n,m,sol,viz[nmax],p[nmax];
char s[nmax];

int solve()
{
    for (int i=1;i*2<=m;i++)
        if (s[p[i]]!=s[p[m-i+1]])
            return 0;
    return 1;
}

void dfs(int x)
{
    viz[x]=1;
    p[++m]=x;
    sol+=solve();
    int i,j;
    for (i=0;i<v[x].size();i++) {
        j=v[x][i];
        if (viz[j]==0)
            dfs(j);
    }
    p[m--]=0;
}

int main()
{
    int i,j,k,t,r,x,y;
    f>>n;
    for (i=1;i<n;i++) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1,f.get();i<=n;i++)
        f.get(s[i]),f.get();

    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
            viz[j]=0;
        dfs(i);
    }
    g<<sol<<'\n';
    return 0;
}
