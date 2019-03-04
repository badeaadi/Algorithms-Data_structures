#include <cstdio>
#include <bitset>
#include <algorithm>
#include <vector>
#define nmax 1005
#define kmax 55
using namespace std;
vector <int> v[nmax];
bitset <nmax> uz;
int n,k,p[nmax][kmax];
int st[nmax],dr[nmax];

int hopcroft(int x)
{
    int i,y;
    uz[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (dr[y]==0) {
            st[x]=y;
            dr[y]=x;
            return 1;
        }
    }
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (uz[dr[y]]==0&&hopcroft(dr[y])) {
            st[x]=y;
            dr[y]=x;
            return 1;
        }
    }
    return 0;
}
void ver(int x,int y)
{
    int i;
    for (i=1;i<=k;i++)
        if (!(p[x][i]<p[y][i]))
            return;
    v[y].push_back(x);
}
int main()
{
    int i,j,l;
    freopen("album.in","r",stdin);
    freopen("album.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (i=1;i<=n;i++) {
        for (j=1;j<=k;j++)
            scanf("%d",&p[i][j]);
        sort(p[i]+1,p[i]+k+1);
    }
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++) {
            if (p[i][1]<p[j][1])
                ver(i,j);
            if (p[j][1]<p[i][1])
                ver(j,i);
        }
    int ok;
    do
    {
        ok=0;
        uz.reset();
        for (i=1;i<=n;i++)
            if (st[i]==0&&hopcroft(i))
                ok=1;
    } while (ok);

    for (i=1,j=0;i<=n;i++)
        j+=(st[i]!=0);

    printf("%d\n",n-j);

    return 0;
}
