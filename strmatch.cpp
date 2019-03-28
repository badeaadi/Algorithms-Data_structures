#include <fstream>
#include <cstring>
#define nmax 2000005
#define maxsol 1001
using namespace std;
ifstream f("strmatch.in");
ofstream g("strmatch.out");
int n,m,nrsol,sol[maxsol];
int p[nmax],l;
char a[nmax],b[nmax];


int main()
{
    int i,j;
    f.getline(a+1,nmax);
    f.getline(b+1,nmax);
    n=strlen(a+1);
    m=strlen(b+1);

    l=0;
    p[1]=0;
    for (i=2;i<=n;i++) {
        while (l&&a[i]!=a[l+1])
            l=p[l];
        if (a[i]==a[l+1])
            l++;
        p[i]=l;
    }
    l=0;
    for (i=1;i<=m;i++) {
        while (l&&b[i]!=a[l+1])
            l=p[l];
        if (b[i]==a[l+1])
            l++;
        if (l==n) {
            nrsol++;
            if (nrsol<maxsol)
                sol[nrsol]=i-n;
            l=p[l];
        }
    }
    g<<nrsol<<'\n';
    for (i=1;i<=nrsol&&i<maxsol;i++)
        g<<sol[i]<<' ';
    return 0;
}
