#include <fstream>
#define nmax 250
using namespace std;
FILE *f=fopen("sotron.in","r");
FILE *g=fopen("sotron.out","w");
int n,v[nmax][nmax];
int best[nmax][nmax];


int main()
{
    int i,j;
    fscanf(f,"%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            fscanf(f,"%d",&v[i][j]);

    for (j=1;j<=n;j++) {
        best[1][j]=v[1][j];
        if (j%2==0)
            best[1][j]=max(best[1][j],v[1][j]+v[1][j+1]);}
    for (i=2;i<=n;i++) {
        if ((i+n)%2==1)
            best[i][n]=v[i][n];
        else
            best[i][n]=max(v[i][n],v[i][j]+best[i-1][n]);

        for (j=n-1;j>=1;j--) {
            if ((i+j)%2==1) {
                best[i][j]=max(v[i][j],v[i][j]+v[i][j+1]+best[i-1][j+1]);
                best[i][j]=max(best[i][j],best[i][j+1]+v[i][j]);
            }
        else
            best[i][j]=max(v[i][j],v[i][j]+best[i-1][j]);
        }
    }
    int maxim=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (best[i][j]>maxim)
                maxim=best[i][j];
    fprintf(g,"%d\n",maxim);
return 0;
}
