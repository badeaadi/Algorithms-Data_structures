#include <fstream>
using namespace std;
ifstream f("xerox.in");
ofstream g("xerox.out");
int t,n,m,dx,dy;
int xorsum;

int main()
{
    int i,j,k,x,y;
    f>>t;
    for (i=1;i<=t;i++) {
        f>>n>>dx>>dy;
        xorsum=0;
        for (k=1;k<=n;k++) {
            f>>m;
            xorsum^=m;
            for (j=1;j<=m;j++)
                f>>x>>y;
            }
        g<<(xorsum!=0)<<'\n';
    }

    return 0;
}
