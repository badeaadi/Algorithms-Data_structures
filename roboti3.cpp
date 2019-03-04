#include <fstream>
#include <algorithm>
#define nmax 100005
using namespace std;
ifstream f("roboti3.in");
ofstream g("roboti3.out");
int n,p,v[nmax*2];
int m,s[nmax];


int main()
{
    int i,j,k;
    f>>p>>n;
    for (i=1;i<=n;i++)
        f>>v[i];
    if (p==1) {
        for (i=n+1;i<=2*n;i++)
            v[i-n]=v[i];
        j=1;k=1;
        for (i=2;i<=n;i++)
            if (v[i]>v[i-1])
                j++,k=max(k,j);
            else
                j=0;
        g<<k<<'\n';
        return 0;
    }
    sort(v+1,v+n+1);
    s[1]=v[1];
    j=1;
    for (i=2;i<=n;i+=2)
        s[++j]=v[i];
    i=n;
    if (i%2==0)
        i--;
    for (;i>=1;i-=2)
        s[++j]=v[i];
    for (i=1;i<=n;i++)
        g<<s[i]<<' ';

    return 0;
}
