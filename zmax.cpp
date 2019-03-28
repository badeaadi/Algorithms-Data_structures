#include <cstdio>
#include <fstream>
using namespace std;
FILE *f=fopen("zmax.in","r");
FILE *g=fopen("zmax.out","w");
int n,m,i,j,k,l[501][501],p[501][501],c[501][501],st;
int v[501][501],o,a,b,maxim=-10000;


int main()
{fscanf(f,"%d %d",&n,&m);
for (i=1;i<=n;i++) for (j=1;j<=m;j++) fscanf(f,"%d",&v[i][j]);
for (i=1;i<=n;i++) for (j=1;j<=m;j++)
                    l[i][j]=max(v[i][j]+v[i][j-1],l[i][j-1]+v[i][j]);
for (i=1;i<=n;i++) for (j=m;j>=1;j--)
                    p[i][j]=max(v[i][j]+v[i][j+1],v[i][j]+p[i][j+1]);

for (j=1;j<=m;j++) {a=1;b=j;
                    c[a][b]=v[a][b];
                    a++;b--;
                    while (a<=n&&b>=1)
                                 {c[a][b]=c[a-1][b+1]+v[a][b];
                                  a++;b--;
                                  }
                    }
for (i=2;i<=n;i++) {a=i;b=m;
                    c[a][b]=v[a][b];
                    a++;b--;
                    while (a<=n&&b>=1)
                                 {c[a][b]=c[a-1][b+1]+v[a][b];
                                  a++;b--;
                                  }

                    }
int l1,c1;
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++) {
        o=l[i][j]-c[i][j];
        st=min(n-i,j-1);
        a=1;
        while (a<st)  {
            if (o+p[i+a+1][j-a-1]+c[i+a][j-a]>maxim) {
                maxim=o+p[i+a+1][j-a-1]+c[i+a][j-a];
                l1=i+a+1;
                c1=j-a-1;
            }
            a++;
        }
}
fprintf(g,"%d\n",maxim);
fprintf(g,"%d %d",l1,c1);
return 0;
}
