
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;
#define nmax 2000005
ifstream f("strmatch.in");
ofstream g("strmatch.out");
int m,n,nr;
char a[nmax],b[nmax];
int pi[nmax],pos[1024];

void make_prefix()
{
    int i,k=0;
    pi[1]=0;
    for (i=2;i<=m;++i)
    {
        while (k&&a[k+1]!= a[i])
            k=pi[k];
        if (a[k+1] == a[i])
            ++k;
        pi[i]=k;
    }
}

int main()
{
    int i,q=0;
    f.getline(a,nmax);
    f.getline(b,nmax);
    m=strlen(a);
    n=strlen(b);


    for (i=m;i;--i) a[i] = a[i-1]; a[0] = ' ';
    for (i=n;i;--i) b[i] = b[i-1]; b[0] = ' ';

    make_prefix();

    for (i=1;i<=n;++i)
    {
        while (q&&a[q+1]!=b[i])
                 q=pi[q];
        if (a[q+1]==b[i])
            ++q;
        if (q == m)
        {
            q = pi[m];
            ++nr;
            if (nr <= 1000)
                pos[nr] = i-m;
        }
    }

    g<<nr<<'\n';
    for (i=1;i<=min(nr,1000);++i)
        g<<pos[i]<<' ';
    g<<'\n';

    return 0;
}
