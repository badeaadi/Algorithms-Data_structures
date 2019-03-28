#include <fstream>
#define nmax 1000005
#define mod 666013
using namespace std;
ifstream f("unuzero.in");
ofstream g("unuzero.out");
int v[nmax];
int n,p,q,s;


int main()
{
    int i,j;
    f>>n>>p>>q;
    v[1]=1;
    for (i=2;i<=n+2;i++) {
        //v[i] reprezinta numarul de siruri care se termina cu 0 si au inainte intre p si q cifre de 1
        if (i-p-1>=1)
            s+=v[i-p-1];
        s=(s+mod)%mod;
        v[i]=(v[i-1]+s)%mod;
        if (i-q-1>=1)
            s-=v[i-q-1];
    }
    s=v[n+2]-1;
    s=(s+mod)%mod;
    g<<s<<'\n';
    return 0;
}
