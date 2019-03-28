#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define pii pair<int,int>
#define inf 1<<29
#define nmax 62
#define kmax 11
using namespace std;
const int dl[4]={-1,1,0,0};
const int dc[4]={0,0,-1,1};

int n,m,k,v[nmax][nmax][kmax][kmax];
short in[nmax][nmax][kmax][kmax];
char s[nmax][nmax],cuv[kmax];
queue <pair <pii,pii> > q;

void solvefirst()
{
    int i,j;
    int lmin=inf,lmax=-inf,cmin=inf,cmax=-inf;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (s[i][j]>='A'&&s[i][j]<='Z') {
                lmin=min(lmin,i);
                cmin=min(cmin,j);
                lmax=max(lmax,i);
                cmax=max(cmax,j);
            }
    printf("%d",(lmax-lmin+1)*(cmax-cmin+1));
}
void dynamics(int i,int j,int t,int r,int val)
{

    if (v[i][j][t][r]>val) {
        v[i][j][t][r]=val;
        if (in[i][j][t][r]==0) {
            q.push(make_pair(make_pair(i,j),make_pair(t,r)));
            in[i][j][t][r]=1;
        }
    }
}
void solvesecond()
{
    int i,j,t,r,d;

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            for (t=0;t<k;t++)
                for (r=0;r<k;r++)
                    if (s[i][j]=='_'||(s[i][j]>='A'&&s[i][j]<='Z'))
                        v[i][j][t][r]=inf;

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (s[i][j]>='A'&&s[i][j]<='Z')

                for (t=0;t<k;t++)
                    if (s[i][j]==cuv[t]) {
                        v[i][j][t][t]=0;
                        q.push(make_pair(make_pair(i,j),make_pair(t,t)));
                        in[i][j][t][t]=1;
                        break;
                    }

    while (!q.empty()) {
        i=q.front().first.first;
        j=q.front().first.second;
        t=q.front().second.first;
        r=q.front().second.second;
        in[i][j][t][r]=0;
        q.pop();
        for (d=t-1;d>=0;d--)
            dynamics(i,j,d,r,v[i][j][d][t-1]+v[i][j][t][r]);
        for (d=r+1;d<k;d++)
            dynamics(i,j,t,d,v[i][j][t][r]+v[i][j][r+1][d]);
        for (d=0;d<4;d++)
            dynamics(i+dl[d],j+dc[d],t,r,v[i][j][t][r]+1);
    }
    int sol=inf;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (s[i][j]=='_'||(s[i][j]>='A'&&s[i][j]<'Z'))
                sol=min(sol,v[i][j][0][k-1]);
    if (sol==inf)
        printf("-1");
    else
        printf("%d",sol);
}
int main()
{
    int i,j,p;
    freopen("miting.in","r",stdin);
    freopen("miting.out","w",stdout);
    scanf("%d %d %d\n",&p,&n,&m);
    scanf("%s\n",&cuv);
    k=strlen(cuv);
    for (i=1;i<=n;i++) {
        scanf("%s\n",&s[i]);
        for (j=m;j>=1;j--) {
            s[i][j]=s[i][j-1];
            s[i][j-1]=0;
        }
    }
    if (p==1)
        solvefirst();
    else
        solvesecond();

    return 0;
}
