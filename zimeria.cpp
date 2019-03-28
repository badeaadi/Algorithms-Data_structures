#include <cstdio>
#include <cstring>
#include <fstream>
#define lgmax 400005
using namespace std;
ifstream f("zimeria.in");
ofstream g("zimeria.out");
int n,c[27],l[13],v[lgmax+5];
char p[7],chr;

void solvea()
{
    int i,j;
    int nr=0;
    for (i=lgmax-1;i>=1;i--)
        if (v[i]!=0)
            nr++;
    g<<nr<<'\n';

}
void solveb()
{
    int i,j,t,put;
    for (i=1;i<=400000;i++)
        if (v[i]) {
            fill(p,p+7,0);
            put=13*13*13*13;
            t=i;
            for (j=0;j<=4;j++) {
                p[j]=l[t/put]+'a'-1;
                t%=put;
                put/=13;
            }
            while (v[i]) {
                g<<p<<'\n';
                v[i]--;
            }
        }
}


int main()
{
    int i,j,t,cer,put;
    f>>cer;
    f>>n;f.get();
    for (i=1;i<=12;i++) {
        f.get(chr);
        c[chr-'a'+1]=i;
        l[i]=chr-'a'+1;
    }
    f.get();
    for (i=1;i<=n;i++) {
        memset(p,0,sizeof(p));
        f.getline(p,7);
        put=1;t=0;
        for (j=4;j>=0;j--) {
            t+=put*c[p[j]-'a'+1];
            put*=13;
        }
        v[t]++;
    }
    if (cer==1)
        solvea();
    else
        solveb();

return 0;
}
