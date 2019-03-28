#include <cstdio>
#define nmax 55
using namespace std;
int n,l,x,y,v[nmax][nmax];
int viz[nmax][nmax],sol;
int nrp,p[nmax][nmax];

void fillit(int i,int j)
{
    if (i-1>=1&&(p[i-1][j]==0)&&((v[i][j]&1)==0)) {
        p[i-1][j]=p[i][j];
        fillit(i-1,j);
    }
    if (j+1<=n+1&&(p[i][j+1]==0)&&((v[i][j]&2)==0)) {
        p[i][j+1]=p[i][j];
        fillit(i,j+1);
    }
    if (i+1<=n+1&&(p[i+1][j]==0)&&((v[i][j]&4)==0)) {
        p[i+1][j]=p[i][j];
        fillit(i+1,j);
    }
    if (j-1>=1&&(p[i][j-1]==0)&&((v[i][j]&8)==0)) {
        p[i][j-1]=p[i][j];
        fillit(i,j-1);
    }
}
int main()
{
    freopen("zona.in","r",stdin);
    freopen("zona.out","w",stdout);
    int i,j;
    scanf("%d %d %d %d",&x,&y,&n,&l);
    viz[x][y]=1;
    for (i=2;i<=l+1;i++) {
        scanf("%d",&j);
        if (j==1) {
            v[x][y]|=2;
            v[x][y+1]|=8;
            x--;
        }
        else
            if (j==2) {
                v[x][y+1]|=4;
                v[x+1][y+1]|=1;
                y++;
            }
            else
                if (j==3) {
                    v[x+1][y]|=2;
                    v[x+1][y+1]|=8;
                    x++;
                }
                else {
                    v[x][y]|=4;
                    v[x+1][y]|=1;
                    y--;
                }
        if (viz[x][y]) {
            printf("%d\n",i-viz[x][y]);
            break;
        }
        viz[x][y]=i;
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (!p[i][j]) {
                p[i][j]=++nrp;
                fillit(i,j);
            }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (p[i][j]!=p[n+1][n+1])
                sol++;
    printf("%d\n",sol);
    return 0;
}
