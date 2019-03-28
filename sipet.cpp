#include <fstream>
#include <bitset>
#define nmax 10000505
using namespace std;
ifstream f("sipet.in");
ofstream g("sipet.out");
bitset <nmax> uz;
int n,v[nmax];
int x,y,z;
int nrx,nry,nrz;

void eratosthene()
{
    int i,j;
    uz[2]=1;
    for (i=3;i<=nmax;i+=2)
        uz[i]=1;
    for (i=3;i*i<=nmax;i+=2)
        if (uz[i])
            for (j=i*i;j<=nmax;j+=2*i)
                uz[j]=0;
}
void solve()
{
    int i,j;
    f>>n>>x;
    y=x+1;
    while (!uz[y])
        y++;
    z=y+1;
    while (!uz[z])
        z++;

    v[0]=-1;
    for (i=1;i<=n;i++) {
        if (i>=x&&v[i-x])
            v[i]=x;
        else

        if (i>=y&&v[i-y])
            v[i]=y;
        else

        if (i>=z&&v[i-z])
            v[i]=z;
    }
    i=n;
    while (v[i]==0)
        i--;

    nrx=0;nry=0;nrz=0;
    while (i>0) {
        if (v[i]==x)
            nrx++;
        else

        if (v[i]==y)
            nry++;

        else

        if (v[i]==z)
            nrz++;
        i-=v[i];
    }
    g<<nrx+nry+nrz<<' '<<nrx<<' '<<nry<<' '<<nrz<<' '<<n-nrx*x-nry*y-nrz*z<<'\n';
    for (i=1;i<=n;i++)
        v[i]=0;
}
int main()
{
    int t;
    eratosthene();
    for (f>>t;t;t--)
        solve();

    return 0;
}
