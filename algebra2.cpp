#include <fstream>
#define mod 1000000009
using namespace std;
ifstream f("algebra2.in");
ofstream g("algebra2.out");

int explog(int n,long long k)
{
    long long i;
    int j=1,t=n;
    for (i=1;k;i<<=1,t=(1LL*t*t)%mod)
        if (k&i) {
            j=(1LL*j*t)%mod;
            k^=i;
        }
    return j;
}
int main()
{
    long long n;
    f>>n;
    if (n%2==0)
        g<<explog(explog(n%mod,(n+1)),n/2);
    else
        g<<explog(explog(n%mod,(n+1)/2),n);

    return 0;
}
