#include <cstdio>
#include <fstream>
#include <cstring>
#define nmax 505
#define inf 1<<29
using namespace std;
ifstream f("zmax.in");
ofstream g("zmax.out");
int n,m,v[nmax][nmax],sol=-inf;
int a[nmax][nmax],b[nmax][nmax],c[nmax][nmax];
char s[4000];


void parsing()
{
    int i,j,k;
    bool ok;
    f>>n>>m;f.get();
    for (i=1;i<=n;i++) {
        f.getline(s,4000);
        ok=true;
        k=1;j=0;
        for (j;s[j]!=NULL;j++) {
            if (s[j]==' ') {
                if (ok==false)
                    v[i][k]=-v[i][k];
                k++;
                ok=true;
            }
            else
                if (s[j]=='-')
                    ok=false;
            else {
                v[i][k]=v[i][k]*10+s[j]-'0';
            }
        }
        if (ok==false)
            v[i][k]=-v[i][k];
        memset(s,0,sizeof(s));
    }
}
void sume()
{
    int i,j;
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++)
            a[i][j]=max(v[i][j-1],a[i][j-1])+v[i][j];
        for (j=m;j>=1;j--)
            b[i][j]=max(v[i][j+1],b[i][j+1])+v[i][j];
    }
}
int main()
{
    int i,j;
    parsing();
    sume();

    for (j=2;j<=m;j++)
        c[n-1][j]=v[n-1][j]+b[n][j-1];

    for (i=n-2;i>=1;i--) {
        c[i][2]=v[i][2]+b[i+1][1];
        for (j=3;j<=m;j++) {
            c[i][j]=max(c[i+1][j-1],b[i+1][j-1])+v[i][j];
        }
    }

    for (i=1;i<=n-2;i++)
        for (j=3;j<=m;j++)
            sol=max(sol,a[i][j]+c[i+1][j-1]);


    g<<sol<<'\n';

    return 0;
}
