#include <fstream>
#include <vector>
#include <bitset>
#include <cstring>
#define nmax 105
using namespace std;
ifstream f("senat.in");
ofstream g("senat.out");
vector <int> v[nmax];
bitset <nmax> uz;
int st[nmax],dr[nmax],n,m;
char s[500];

int hopcroft(int x)
{
    int i,y;
    uz[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (!dr[y]) {
            st[x]=y;
            dr[y]=x;
            return 1;
        }
    }
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (uz[dr[y]]==0&&hopcroft(dr[y])) {
            st[x]=y;
            dr[y]=x;
            return 1;
        }
    }
    return 0;

}

int main()
{
    int i,j,x;
    f>>n>>m;f.get();
    for (i=1;i<=m;i++) {
        memset(s,0,sizeof(s));
        f.getline(s,500);
        j=0;x=0;
        while (s[j]&&s[j]!='\n') {
            while (s[j]&&s[j]!=' '&&s[j]!='\n')
                x=x*10+s[j++]-'0';
            j++;
            v[i].push_back(x);
            x=0;
        }
    }
    int ok;
    do {
        ok=0;
        uz.reset();
        for (i=1;i<=n;i++)
            if (st[i]==0&&hopcroft(i))
                ok=1;
    } while (ok);
    for (i=1;i<=m;i++)
        if (st[i]==0) {
            g<<"0\n";
            return 0;
        }
    for (i=1;i<=m;i++)
        g<<st[i]<<'\n';
    return 0;
}
