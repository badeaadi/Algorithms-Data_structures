#include <fstream>
#include <cstdio>
#include <cstring>
#include <bitset>
#define nmax 5050
using namespace std;
ifstream f("triopalindrom.in");
ofstream g("triopalindrom.out");
char s[nmax];
int n,cnt,nr;
bool ok;

int main()
{
    int i,j;
    f.getline(s,nmax);
    n=strlen(s);
    for (i=1;i<=n;i++) {
        cnt=0;
        for (j=0;j<n;j++)
            if (s[j]==s[j+i]) {
                cnt++;
                if (cnt>=2*i)
                    ++nr;
            }
            else
                cnt=0;
    }
    g<<nr<<'\n';
    return 0;
}
