#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#define nmax 610
#define inf 1<<30
using namespace std;
vector <int> v[nmax];
int f[nmax][nmax],c[nmax][nmax],z[nmax][nmax];
int n,k,a,b,dest,sol;
int d[nmax],t[nmax];
bitset <nmax> uz;
queue <int> q;


int modul(int x)
{
    if (x<0)
        return -x;
    return x;
}
void createcuplaj(int x,int y,int r,int t)
{
    v[x].push_back(y);
    v[y].push_back(x);
    c[x][y]=r;
    z[x][y]=t;z[y][x]=-t;
}
int cuplaj()
{
    int x,y,i;
    for (i=0;i<=dest;i++)
        d[i]=inf;
    d[0]=0;
    uz.reset();
    q.push(0);
    uz[0]=1;
    while (!q.empty()) {
        x=q.front();
        q.pop();
        uz[x]=0;
        for (i=0;i<v[x].size();i++) {
            y=v[x][i];
            if (d[y]>d[x]+z[x][y]&&f[x][y]<c[x][y]) {
                d[y]=d[x]+z[x][y];
                t[y]=x;
                if (uz[y]==0) {
                    uz[y]=1;
                    q.push(y);
                }
            }
        }
    }
    if (d[dest]==inf)
        return 0;
    return 1;
}
inline int number(int j)
{
    return n+1+j-a;
}
int x[nmax];

int main()
{
    freopen("smen.in","r",stdin);
    freopen("smen.out","w",stdout);
    scanf("%d %d %d %d",&n,&k,&a,&b);
    int i,j;
    for (i=1;i<=n;i++) {
        scanf("%d",&x[i]);
        for (j=a;j<=b;j++)
            createcuplaj(i,number(j),1,modul(x[i]-j));
    }
    for (i=1;i<=n;i++)
        createcuplaj(0,i,1,0);
    dest=n+1+b-a+3;
    for (i=a;i<=b;i++)
        createcuplaj(number(i),dest-1,1,0);
    createcuplaj(dest-1,dest,k,0);

    while (cuplaj()) {
        sol+=d[dest];
        for (i=dest;i;i=t[i]) {
            f[t[i]][i]++;
            f[i][t[i]]--;
        }
    }
    printf("%d\n",sol);
    for (i=1;i<=n;i++) {
        for (j=a;j<=b;j++)
            if (f[i][number(j)]==c[i][number(j)]) {
                printf("%d ",j);
                break;
            }
        if (j>b)
            printf("%d ",x[i]);
    }

    return 0;
}
