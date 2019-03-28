#include <fstream>
#define nmax 1<<17+5
using namespace std;
ifstream f("vecini.in");
ofstream g("vecini.out");
int n,d,a[nmax],sn;
char s[nmax];
int bits(int x)
{
    return a[(x&(-x))];
}
int main()
{
    int i;
    f>>n;n--;
    for (i=0;i<17;i++)
        a[1<<i]=i;
    for (i=1;i<=n+1;i++) {
        s[sn++]=(d==0?1:0)+'0';
        s[sn++]=' ';
        d+=bits(n-i+1);
        d-=bits(i);
    }
    g<<s;
}
