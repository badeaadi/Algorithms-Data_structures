//Sortare cu parsare
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#define nmax 30000057
#define parsmax 10000000
using namespace std;
ifstream f("sdo.in");
ofstream g("sdo.out");
int n,m,k,nr;
int v[nmax];
char s[parsmax+100];

void citire()
{
    int i;
    nr=1;
    f>>n>>k;f.get();
    while (nr<=n){
        i=0;
        f.get(s,parsmax);
        m=strlen(s);
        if (m==0)
            break;
        while (i<m) {
            if (s[i]==' ')
                nr++;
                else
                    v[nr]=v[nr]*10+(s[i]-'0');
            i++;
        }
    memset(s,0,m+5);
    }
}


int main()
{
    citire();
    nth_element(v+1,v+k,v+n+1);
    g<<v[k]<<'\n';

return 0;
}
