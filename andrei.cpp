#include <fstream>
#include <vector>
#include <stack>
#define nmax 200005
using namespace std;
ifstream f("andrei.in");
ofstream g("andrei.out");
vector <int> v[nmax],t[nmax];
stack <int> s;
int n,m,k,is[nmax],viz[nmax],sol[nmax];
int niv[nmax],low[nmax];

int opus(int x)
{
    if (x<=n)
        return x+n;
    return x-n;
}
void addedge(int x,int y)
{
    v[opus(x)].push_back(y);
    t[y].push_back(opus(x));
    v[opus(y)].push_back(x);
    t[x].push_back(opus(y));
}
void dfs(int x)
{
    viz[x]=1;
    int i,y;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (!viz[y])
            dfs(y);
    }
    s.push(x);
}
void dft(int x)
{

    if (sol[x]) {
        sol[0]=-1;
        return ;
    }
    int i,y;
    sol[opus(x)]=1;
    viz[x]=0;
    for (i=0;i<t[x].size();i++) {
        y=t[x][i];
        if (viz[y]==1)
            dft(y);
    }
}
int main()
{
    int i,j,a,b,c;
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>a>>b>>c;
        if (c==0)
            addedge(a,b);
        else
            if (c==1)
                addedge(opus(a),opus(b));
        else {
            addedge(opus(a),b);
            addedge(a,opus(b));
        }
    }
    for (i=1;i<=2*n;i++)
        if (!viz[i])
            dfs(i);
    while (!s.empty()) {
        i=s.top();
        s.pop();
        if (viz[i]&&viz[opus(i)])
            dft(i);
    }
    for (i=1;i<=n;i++)
        g<<sol[i]<<' ';
    return 0;
}
