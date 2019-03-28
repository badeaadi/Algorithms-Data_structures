#include <cstdio>
#include <queue>
#define nmax 505
#define qmax 30155
using namespace std;
const int dl[4]={-1,0,0,1};
const int dc[4]={0,-1,1,0};
queue <pair <int,int> > > q[qmax];
int n,t,k,v[nmax][nmax],p[nmax][nmax],l[nmax][nmax];
int tl[nmax][nmax],tc[nmax][nmax];

void buildmatrix(int z)
{
    int i,j,t,l,c,l1,c1;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            q[v[i][j]].push(make_pair(i,j));

    for (i=qmax-1;i>=1;i--)
        while (!q[i].empty()) {
            l=q[i].front().first.first;
            c=q[i].front().first.second;
            t=q[i].front().second;
            q[i].pop();
            for (j=0;j<4;j++)
                if (j!=3-t) {
                    l1=l+dl[j];
                    c1=c+dc[j];
                    if ((tl[l1][c1]!=l||tc[l1][c1]!=c)) {
                        if (!p[l1][c1]) {
                            p[l1][c1]=i-1;
                            tl[l1][c1]=tl[l][c];
                            tc[l1][c1]=tc[l][c];
                            q[i-1].push(make_pair(l1,c1));
                        }
                        if (!l[l1][c1]) {
                            l[l1][c1]=i-1;
                            q[i-1].push((make_pair(l1,c1));
                        }
                    }
                    else {
                        if (!p[l1][c1]) {
                            p[l1][c1]=i-1;
                            tl[l1][c1]=tl[l][c];
                            tc[l1][c1]=tc[l][c];
                            q[i-1].push(make_pair(make_pair(l1,c1),j));
                        }
                    }
                }
        }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            v[i][j]=z+1+((v[i][j]+z*p[i][j][0])%k);

    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            p[i][j][t]=0;
}
int main()
{
    int i,j,t,s=0;
    freopen("v2d.in","r",stdin);
    freopen("v2d.out","w",stdout);
    scanf("%d %d %d",&n,&t,&k);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            scanf("%d",&v[i][j]);
    for (i=0;i<=n+1;i++)
        for (j=0;j<=n+1;j++)
            for (t=0;t<4;t++)
                p[i][j][t]=1<<29;

    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            for (t=0;t<4;t++)
                p[i][j][t]=0;

    for (i=1;i<=t;i++)
        buildmatrix(i);

    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) {
            s+=v[i][j];
            while (s>=k)
                s-=k;
        }
    printf("%d\n",s);
    return 0;
}
