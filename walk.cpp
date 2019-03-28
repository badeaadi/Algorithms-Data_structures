#include <fstream>
#include <vector>
#define nmax 400005
#define mod 1000000007
using namespace std;
ifstream f("walk.in");
ofstream g("walk.out");
vector <int> v[nmax];
int n,m,k[nmax],p[nmax],l[nmax];

void euclid(int a,int b,int &x,int &y)
{
    if (b==0) {
        x=1;
        y=0;
        return;
    }
    int x0,y0;
    euclid(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
}

int im(int a)
{
    int x,y;
    euclid(a,mod,x,y);
    return (x+mod)%mod;
}
void dfs(int x)
{
    int i,y;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        dfs(y);

    }
}
int main()
{
    int i,j;
    f>>n>>m;
    for (i=2;i<=n;i++) {
        f>>j;
        v[j].push_back(i);
    }
    for (p[0]=1,i=1;i<=n;i++) {
        p[i]=1LL*p[i-1]*i%mod;
        l[i]=im(p[i]);
    }
    for (i=1;i<=m;i++) {
        f>>k[i];
    dfs(1);

    return 0;
}
