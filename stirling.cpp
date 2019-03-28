#include <fstream>
#define nmax 205
#define mod 98999
using namespace std;
ifstream f("stirling.in");
ofstream g("stirling.out");
int a[nmax][nmax],b[nmax][nmax];
int t;

int main()
{
    int i,n,m;
    a[0][0]=1;b[0][0]=1;
    for (n=1;n<nmax;n++)
        for (m=1;m<nmax;m++) {
            a[n][m]=(a[n-1][m-1]-(n-1)*a[n-1][m])%mod;
            b[n][m]=(b[n-1][m-1]+m*b[n-1][m])%mod;
        }
    for (f>>t;t;t--) {
        f>>i>>n>>m;
        if (i==1)
            g<<a[n][m]<<'\n';
        else
            g<<b[n][m]<<'\n';
    }
    return 0;
}
