#include <fstream>
#include <bitset>
#include <cstring>
#define lgmax 1010
#define inf 1<<30
#define bmax 56
using namespace std;
ifstream f("tastatura.in");
ofstream g("tastatura.out");
bitset <bmax> a[lgmax];
char s[lgmax],t[55];
int p[lgmax];
int n,m,k,d[lgmax];

int main()
{
    int i,j,l;
    f.getline(s+1,lgmax);
    m=strlen(s+1);
    f>>k;f.get();
    for (;k;k--) {
        memset(t,0,sizeof(t));
        f.getline(t+1,55);
        n=strlen(t+1);
        l=0;
        p[1]=0;
        for (i=2;i<=n;i++) {
            while (l&&t[i]!=t[l+1])
                l=p[l];
            if (t[i]==t[l+1])
                l++;
            p[i]=l;
        }
        l=0;
        for (i=1;i<=m;i++) {
            while (l&&s[i]!=t[l+1])
                l=p[l];
            if (s[i]==t[l+1])
                l++;
            if (l==n) {
                a[i][n]=1;
                l=p[l];
            }
        }
    }
    for (i=1;i<=m;i++) {
        a[i][1]=1;
        d[i]=inf;
    }
    for (i=1;i<=m;i++) {
        for (j=1;j<bmax-1;j++)
            if (a[i][j])
                d[i]=min(d[i],d[i-j]+1);
    }
    g<<d[m]<<'\n';
    return 0;
}
