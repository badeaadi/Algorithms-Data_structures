#include <fstream>
#define nmax 2805
#define mod 64997
using namespace std;
ifstream f("robot1.in");
ofstream g("robot1.out");
int n,k,v[nmax];

int main()
{
    int i,j;
    f>>n>>k;
    v[1]=1;
    for (i=k;i<n;i++)
        for (j=1;j+1<i;j++) {
            v[j+1]+=v[j];
            if (v[j+1]>=mod)
                v[j+1]-=mod;
        }
    for (i=0,j=1;j<=n;j++)
        i+=v[j];
    g<<i%mod<<'\n';

    return 0;
}
