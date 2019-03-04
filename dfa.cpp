#include <fstream>
#include <vector>
#include <cstring>
#define teta 26
#define nmax 15005
using namespace std;
ifstream f("dfa.in");
ofstream g("dfa.out");
int ns, nlit, q0, qfinal, stfin[nmax];
int delta;
char s[nmax], lit[teta];
int v[nmax];
int ve[nmax][teta];


void proces()
{
    int i, j, k;
    f>>s;
    k = q0;
    for (i = 0; s[i]; i++) {
        k = ve[k][s[i]-'a'];
        if (k==-1) {
            g << "NU" << '\n';
            return;
        }
    }
    if (stfin[k]) {
        g<<"DA"<<'\n';
    }
    else
        g<<"NU"<<'\n';
    memset(s,0,sizeof(s));
}

int main()
{
    int i, j, a, b, k;
    char c;

    j = 1;
    f>>ns;
    for (i = 0; i < ns; i++)
        f>>v[i];
    f>>nlit;
    for (i = 0; i < nlit; i++)
        f>>lit[i];
    f>>q0;
    f>>qfinal;

    for (i = 0 ; i < qfinal; i++) {
        f>>a;
        stfin[a]=1;
    }
    for (i = 0 ; i < ns ; i++)
        for (j = 0; j< nlit; j++)
            ve[i][j] = -1;
    f>>delta;
    for (i = 0 ;i < delta; i++) {
        f>>a;f.get();
        f>>c;
        f>>b;
        f.get();
        ve[a][c-'a'] = b;
    }
    int nrproc;
    f>>nrproc;
    for (i = 0; i < nrproc; i++) {
        proces();
    }
    return 0;
}