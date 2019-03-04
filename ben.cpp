#include <fstream>
#include <algorithm>
#define nmax 30010
#define mod 32173
using namespace std;
ifstream f("ben.in");
ofstream g("ben.out");
int n,p[nmax],q[nmax],nr,sol,total;

int main()
{
    int i,j,t;
    f>>n;
    for (i=1;i<=n;i++)
        f>>p[i]>>q[i];
    sort(p+1,p+n+1);
    sort(q+1,q+n+1);

    i=1;j=1;t=0;
    while (i<=n||j<=n) {

        while (i<=n&&p[i]<=t) nr++,i++;
        while (j<=n&&q[j]<=t) nr--,j++;
        sol=max(sol,nr);
        t++;
    }
    total=1;
    i=1;j=1;t=0;
    g<<sol<<' ';
    while (i<=n||j<=n) {

        while (i<=n&&p[i]<=t) {
                total*=(sol-nr);
                total%=mod;
                nr++;
                i++;
        }
        while (j<=n&&q[j]<=t) nr--,j++;

        t++;
    }
    g<<total<<'\n';
    return 0;
}
