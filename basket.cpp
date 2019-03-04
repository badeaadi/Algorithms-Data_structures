#include <fstream>
#define nmax 300
using namespace std;
ifstream f("basket.in");
ofstream g("basket.out");
int k[nmax+5][nmax+5];

int main()
{
    int i,j,t,p,n,m;
    f>>t>>p;
    k[1][1]=1;
    k[2][1]=1;k[2][2]=1;
    for (i=3;i<=nmax;i++) {
        k[i][1]=1;
        for (j=2;j<=i;j++)
            k[i][j]=(1LL*k[i-1][j]*j+1LL*k[i-1][j-1]*(i+1-j))%p;
    }
    for (i=1;i<=t;i++) {
        f>>n>>m;
        g<<k[n][m+1]<<'\n';
    }
    return 0;
}
