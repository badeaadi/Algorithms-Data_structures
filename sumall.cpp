#include <fstream>
#include <cstring>
#include <algorithm>
#define nmax 35
#define cmax 10
using namespace std;
ifstream f("sumall.in");
ofstream g("sumall.out");
char s[nmax];
int n,m,c[cmax];
long long v[nmax],p;

long long comb(int n,int k)
{
    int i;
    long long s=1;
    k=min(k,n-k);
    for (i=n-k+1;i<=n;i++)
        s*=i;
    for (i=2;i<=k;i++)
        s/=i;
    return s;
}
int main()
{
    int i,j;
    f.getline(s,nmax);
    n=strlen(s);
    for (i=0;i<n;i++)
        c[s[i]-'0']++;
    for (i=1;i<=9;i++)
        if (c[i]) {
            c[i]--;
            m=n-1;
            for (j=1,p=1;j<=9;j++) {
                p*=comb(m,c[j]);
                m-=c[j];
            }
            for (j=1;j<=n;j++)
                v[j]+=p*i;
            c[i]++;
        }
    for (i=1;i<nmax;i++)
        if (v[i]>9) {
            v[i+1]+=v[i]/10;
            v[i]%=10;
        }
    for (n=nmax-1;!v[n];n--);
    for (i=n;i>=1;i--)
        g<<v[i];

    return 0;
}
