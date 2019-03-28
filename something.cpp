#include <fstream>
#include <vector>
#define nmax 100005
using namespace std;
ifstream f("something.in");
ofstream g("something.out");
vector <int> v[nmax];
int n,m,viz[nmax],col[nmax],a,b,c;


void dfs(int x,int t)
{
    int i,y;
    viz[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (y==t)
            continue;
        if (a)
            return;
        if (viz[y])
            a=x,b=y,c=t;
        dfs(y,x);
    }
}
void color(int x)
{
    int i,y;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (col[y]==0) {
            col[y]=col[x];
            color(y);
        }
    }
}
int main()
{
    int i,j,x,y;
    f>>n;
    for (f>>m;m;m--) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    if (a==0) {
        g<<-1<<'\n';
        return 0;
    }
    col[a]=1;col[b]=2;col[c]=3;
    color(a);color(b);color(c);
    for (i=1;i<=n;i++)
        g<<col[i]<<' ';

    return 0;
}
