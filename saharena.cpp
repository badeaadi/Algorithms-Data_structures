#include <fstream>
#define nmax 1005
using namespace std;
ifstream f("sah.in");
ofstream g("sah.out");
int n,k=1,v[nmax][nmax];

int main()
{
    int i,j,c;
    freopen("sah.in","r",stdin);
    freopen("sah.out","w",stdout);
    scanf("%d",&n);
    for (j=1;j<=n;j++)
        v[1][j]=v[2][j]=1;

    for (i=3,c=1;i<=n;i+=2) {
        k++;
        for (j=1;j<=c;j++)
            v[i][j]=k,v[i+1][j]=k;
        k++;
        for (j=c+1;j<=n;j++)
            v[i][j]=k,v[i+1][j]=k;
        c++;
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
            printf("%d ",v[i][j]);
        printf("\n");
    }
    return 0;
}
