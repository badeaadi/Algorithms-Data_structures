#include <fstream>
#include <cstring>
#include <algorithm>
#define nmax 1000005
using namespace std;
ifstream f("aparitii2.in");
ofstream g("aparitii2.out");
int n,m,za[nmax<<1],zb[nmax<<1],s[nmax];
char a[nmax<<1],b[nmax<<1],p[nmax<<1];

void zalg(char p[],int q[],int k)
{
    int i,l=0,r=0;
    for (i=2;i<=k;i++) {
        if (r>=i)
            q[i]=min(q[i-l+1],r-i+1);

        while (i+q[i]<=k&&p[i+q[i]]==p[1+q[i]])
            q[i]++;

        if (i+q[i]-1>r) {
            r=i+q[i]-1;
            l=i;
        }
    }
}
int main()
{
    int i,j;
    f>>p+1>>b+1;
    n=strlen(p+1);
    m=strlen(b+1);
    strcat(a+1,b+1);
    strcat(a+1,p+1);
    reverse(b+1,b+m+1);
    reverse(p+1,p+n+1);
    strcat(b+1,p+1);

    zalg(a,za,n+m);
    zalg(b,zb,n+m);

    for (i=m+1,j=n+1;i-1<=n;i++,j--)
        za[i]=min(m/2,min(za[i],zb[j]));

    for (i=m+1;i<=n+m;i++)
        if (i+za[i]<=n+m)
            s[za[i]]++;

    for (i=m/2;i>=1;i--)
        s[i]+=s[i+1];
    for (i=1;i<=m/2;i++)
        g<<s[i]<<'\n';

    return 0;
}
