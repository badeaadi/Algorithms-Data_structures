#include <fstream>
#define nmax 500005
using namespace std;
ifstream f("algsort.in");
ofstream g("algsort.out");
int n,v[nmax],k[nmax],p[256];
int base,basemax,ns;

inline int rest(int k)
{
    return (k>>(8*base))&255;
}
int main()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++)
        f>>v[i];

    base=0;
    basemax=4;
    while (base<basemax) {

        for (i=0;i<=255;i++)
            p[i]=0;

        for (i=1;i<=n;i++)
            p[rest(v[i])]++;

        for (i=1;i<=255;i++)
            p[i]+=p[i-1];

        for (i=n;i>=1;i--)
            k[p[rest(v[i])]--]=v[i];

        for (i=1;i<=n;i++)
            v[i]=k[i];

        base++;
    }
    for (i=1;i<=n;i++)
        g<<v[i]<<' ';

    return 0;
}
