#include <cstdio>
#include <vector>
#define nmax 2005
#define tmax 1005
using namespace std;
int n,t;
short d[nmax][tmax],v[nmax][nmax+tmax],uz[nmax]
vector <int> p[nmax],k[nmax];
void dfs(int x)
{
    int i,j;
    uz[x]=1;
    for (i=0;i<v[x].size();i++) {
        j=v[x][i];
        if (uz[j]) {
            p[x].push_back(j);
            dfs(j);
        }
    }
}
void dynamic(int x)
{
    int i,j;


}
int main()
{
    int i,j,a,b;
    freopen("date.in","r",stdin);
    scanf("%d %d",&n,&t);
    for (i=1;i<n;i++) {
        scanf("%d %d",&a,&b);
        p[a].push_back(b);
        p[b].push_back(a);
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=t;j++) {
            scanf("%d",&v[i][j]);
        }
    dfs(1);
    printf("%d\n",d[1][0]);
    return 0;
}
