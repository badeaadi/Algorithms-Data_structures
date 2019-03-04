#include <fstream>
#define nmax 500010
using namespace std;
ifstream f("reguli.in");
ofstream g("reguli.out");
long long x[nmax];
int n,p[nmax];

int main()
{
    int i,j,l;
    f>>n;
    for (i=1;i<=n;i++)
        f>>x[i-1];
    for (i=n-1;i>=1;i--)
        x[i]-=x[i-1];
    x[0]=0;

    p[1]=0;l=0;
    for (i=2;i<n;i++) {
        while (l&&x[i]!=x[l+1])
            l=p[l];
        if (x[i]==x[l+1])
            l++;
        p[i]=l;
    }
    j=n-1-p[n-1];
    g<<j<<'\n';
    for (i=1;i<=j;i++)
        g<<x[i]<<'\n';

    return 0;
}
