#include <cstdio>
#include <queue>
#define nmax 200
using namespace std;
int v[nmax][nmax];
int n,m;
queue <pair <int , int > > q;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int a1,b1,a2,b2;

int main()
{
    int i,j,a,b,x,y;
    freopen("alee.in","r",stdin);
    freopen("alee.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            v[i][j]=1<<20;
    for (i=1;i<=m;i++) {
        scanf("%d %d",&a,&b);
        v[a][b]=-1;
    }
    scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
    v[a1][b1]=1;
    q.push(make_pair(a1,b1));
    while (!q.empty()) {
        a=q.front().first;
        b=q.front().second;
        q.pop();
        for (i=0;i<4;i++) {
            x=a+dx[i];
            y=b+dy[i];
            if (v[x][y]>v[a][b]+1) {
                q.push(make_pair(x,y));
                v[x][y]=v[a][b]+1;
            }
        }
    }
    printf("%d",v[a2][b2]);
    return 0;
}
