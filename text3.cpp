#include <bits/stdc++.h>
#define nmax 20005
#define teta 27
#define lmax 21
using namespace std;
ifstream f("text3.in");
ofstream g("text3.out");
char s[nmax][lmax],lit;
short sol[nmax],last[nmax];
short solbun[nmax],u[teta];
int n,solnr;

int main()
{
    int i,j;
    while (f>>s[++n]);
        g<<--n<<'\n';
    for (i=1;i<=n;i++) {
        if (u[s[i][0]-'a']) {
            sol[i]=sol[u[s[i][0]-'a']]+1;
            last[i]=u[s[i][0]-'a'];
        }
        else
            sol[i]=1;
        lit=s[i][strlen(s[i])-1]-'a';
        if (sol[i]>sol[u[lit]])
            u[lit]=i;
    }
    solnr=0;
    for (i=1;i<=n;i++)
        if (sol[i]>solnr)
            solnr=sol[i];
    g<<n-solnr<<'\n';
    for (i=1;i<=n;i++)
        if (sol[i]==solnr) {
            j=i;
            break;
        }
    solbun[solnr]=j;
    for (i=solnr-1;i>=1;i--) {
        j=last[j];
        solbun[i]=j;
        }
    for (i=1;i<=solnr;i++)
        g<<s[solbun[i]]<<'\n';
return 0;
}
