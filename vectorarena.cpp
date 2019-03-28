#include <fstream>
#include <cstdio>
#define nmax 200005
using namespace std;
FILE *f=fopen("vector.in","r");
ofstream g("vector.out");
int n,v[nmax];
int xorsum;

int main()
{
    int i,j,x;
    fscanf(f,"%d",&n);
    for (i=1;i<=n-1;i++) {
        fscanf(f,"%d",&v[i]);
        if (i%2)
            xorsum^=v[i];
    }
    if (!xorsum) {
        g<<0<<'\n';
        return 0;
    }
    g<<1<<'\n';
    for (i=1;i<=n;i++) {
        if (i%2==1) {
            x=v[i]-(xorsum^v[i]);
            if (x>=1&&x<=v[i]) {
                g<<i<<' '<<x<<'\n';
                return 0;
            }
        }
        else {
            x=(xorsum^v[i-1])-v[i-1];
            if (x>=1&&x<=v[i]) {
                g<<i<<' '<<x<<'\n';
                return 0;
            }
        }
    }
    return 0;
}
