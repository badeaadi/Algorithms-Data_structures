#include <cstdio>
using namespace std;
FILE *f=fopen("raze.in","r");
FILE *g=fopen("raze.out","w");
int v[136][136],maxmax=0,p[136][136];
int main()
{int i,j,o,nr,t,n,m,x,y;


    freopen("raze.in","r",stdin);
    freopen("raze.out","w",stdout);
    scanf("%d",&t);
    for (;t;t--) {
        scanf("%d %d",&n,&m);
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                scanf("%d",&v[i][j]);
        for (i=1;i<=n;i++) {
            x=i-1;y=2;
            while (x>1&&y<m&&v[x][y]==0)
                p[x--][y++]++;
            x=i+1;y=2;
            while (x<n&&y<m&&v[x][y]==0)
                p[x++][y++]++;
        }
        for (i=1;i<=n;i++) {
            x=i-1;y=m-1;
            while (x>1&&y>1&&v[x][y]==0)
                p[x--][y--]++;
            x=i+1;y=m-1;
            while (x<n&&y>1&&v[x][y]==0)
                p[x++][y--]++;
        }
        for (j=2;j<m;j++) {
            x=2;y=j-1;
            while (x<n&&y>1&&v[x][y]==0)
                p[x++][y--]++;
            x=2;y=j+1;
            while (x<n&&y<m&&v[x][y]==0)
                p[x++][y++]++;
        }
        for (j=2;j<m;j++) {
            x=n-1;y=j-1;
            while (x>1&&y>1&&v[x][y]==0)
                p[x--][y--]++;
            x=n-1;y=j+1;
            while (x>1&&y<m&&v[x][y]==0)
                p[x--][y++]++;
            }

        for (i=2;i<n;i++)
            for (j=2;j<m;j++)
                if (v[i][j]==0) {
                    if (p[i][j]>maxmax){
                        maxmax=p[i][j];
                        nr=1;
                    }
                    else
                        if (p[i][j]==maxmax)
                            nr++;
                }
    printf("%d %d\n",maxmax,nr);
    maxmax=0;nr=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        p[i][j]=0;
    }


return 0;
}
