#include <fstream>
#include <vector>
#define nmax 150005
using namespace std;
ifstream f("treap.in");
ofstream g("treap.out");
vector <int> v[nmax],r[nmax];
int n,k[nmax],p[nmax],d[nmax];
int viz[nmax],minval[nmax],maxval[nmax];


void dfs(int x)
{
    int i,y,z;
    viz[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (viz[y]==0) {
            dfs(y);
            r[x].push_back(y);
        }
    }
    d[x]=1;
    minval[x]=k[x];
    maxval[x]=k[x];
    if (r[x].size()>2) {
        d[x]=0;
        return;
    }
    if (r[x].size()==0)
        return;

    if (r[x].size()==1) {
        y=r[x][0];
        if (d[y]==0||p[x]<p[y]) {
            d[x]=0;
            return;
        }
        if (maxval[y]<=k[x]||minval[y]>k[x]) {
            minval[x]=min(minval[x],minval[y]);
            maxval[x]=max(maxval[x],maxval[y]);
            return;
        }
        else
            d[x]=0;
    }
    if (r[x].size()==2) {
        y=r[x][0];
        z=r[x][1];
        if (d[y]==0||d[z]==0||p[x]<p[y]||p[x]<p[z]) {
            d[x]=0;
            return;
        }
        if ((maxval[y]<=k[x]&&minval[z]>k[x])||(maxval[z]<=k[x]&&minval[y]>k[x])) {
            minval[x]=min(minval[x],min(minval[y],minval[z]));
            maxval[x]=max(maxval[x],max(maxval[y],maxval[z]));
        }
        else
            d[x]=0;
    }
}
int main()
{
    int i,j,x,y;
    f>>n;
    for (i=1;i<n;i++) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1;i<=n;i++)
        f>>k[i];
    for (i=1;i<=n;i++)
        f>>p[i];
    dfs(1);
    for (i=1;i<=n;i++)
        g<<d[i]<<' ';
    return 0;
}
