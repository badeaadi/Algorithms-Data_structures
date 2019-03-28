#include <fstream>
#define nmax 20
#define smax 1000005
using namespace std;
ifstream f("triunghi.in");
ofstream g("triunghi.out");
int n,s,p[nmax][nmax],q[nmax][nmax];
int v[smax],k[smax];

int main()
{
    int i,j;
    f>>n>>s;
    //precalcularea in O(n^2) a adaosului la incrementare in p
    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++)
            p[i][j]=p[i-1][j-1]+p[i-1][j]+1;
    //suma minima in q in O(n^2)
    for (i=1;i<=n;i++)
        q[n][i]=1;
    s-=n;
    for (i=n-1;i>=1;i--)
        for (j=1;j<=i;j++) {
            q[i][j]=q[i+1][j]+q[i+1][j+1];
            s-=q[i][j];
        }
    if (s<0) {
        g<<"imposibil\n";
        return 0;
    }
    //in s a ramas suma pe care mai trebuie sa o adaugam in O(n*s)
    v[0]=1;
    for (i=1;i<=s;i++) {
        for (j=1;j<=n/2+1;j++)
            if (i>=p[n][j]&&v[i-p[n][j]]==1) {
                v[i]=1;
                k[i]=j;
                break;
            }
    }
    //verificam existenta solutie
    if (v[s]==0) {
        g<<"imposibil\n";
        return 0;
    }
    //constructia solutie
    while (s!=0) {
        q[n][k[s]]++;
        s-=p[n][k[s]];
    }
    for (i=n-1;i>=1;i--)
        for (j=1;j<=i;j++)
            q[i][j]=q[i+1][j]+q[i+1][j+1];
    //afisarea solutiei
    for (i=1;i<=n;i++) {
        for (j=1;j<=i;j++)
            g<<q[i][j]<<' ';
        g<<'\n';
    }
    return 0;
}
