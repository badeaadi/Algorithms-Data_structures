#include <fstream>
#include <cstring>
#define nmax 2000050
using namespace std;
ifstream f("strmatch.in");
ofstream g("strmatch.out");
char a[nmax<<1],b[nmax];
int n,m,z[nmax<<1];
int s[nmax],sol;

int main()
{
    int i,l,r;
    f>>a+1>>b;
    m=strlen(a+1);
    strcat(a+1,b);
    l=0,r=0;
    n=strlen(a+1);
    for (i=2;i<=n;i++) {
        if (r>=i)
            z[i]=min(z[i-l+1],r-i+1);

        while (i+z[i]<=n&&a[i+z[i]]==a[1+z[i]])
            z[i]++;

        if (r<i+z[i]-1) {
            r=i+z[i]-1;
            l=i;
        }
    }
    for (i=m+1;i<=n;i++)
        if (z[i]>=m) {
            ++sol;
            s[sol]=i-m-1;
        }
    g<<sol<< "\n";
    for (i=1;i<=sol&&i<=1000;i++)
        g<<s[i]<<" ";
    return 0;
}
