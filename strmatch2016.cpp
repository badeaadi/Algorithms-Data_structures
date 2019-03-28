#include <bits/stdc++.h>
#define nmax 2000005
#define maxsol 1001
using namespace std;
char a[nmax],b[nmax];
int p[nmax],n;
int sol,sols[maxsol];

int main()
{
    ifstream f("strmatch.in");
    ofstream g("strmatch.out");
    int i,l;
    f.getline(a+1,nmax);
    f.getline(b+1,nmax);
    p[1]=0;l=0;
    for (i=2;a[i];i++) {
        while (l&&a[i]!=a[l+1])
            l=p[l];
        if (a[i]==a[l+1])
            l++;
        p[i]=l;
    }
    n=i-1;
    l=0;
    for (i=1;b[i];i++) {
        while (l&&b[i]!=a[l+1])
            l=p[l];
        if (b[i]==a[l+1])
            l++;
        if (l==n) {
            sol++;
            if (sol<maxsol)
                sols[sol]=i-n;
            l=p[l];
        }
    }
    g<<sol<<'\n';
    for (i=1;i<=sol&&i<maxsol;i++)
        g<<sols[i]<<' ';
    return 0;
}
