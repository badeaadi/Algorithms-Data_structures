#include <cstdio>
#include <fstream>
#include <cstring>
#define mod 1000003
#define nmax 205
#define inf 1<<29
using namespace std;
int n,nc,m,v[nmax][nmax];
int voc,t[nmax][nmax];
char s[nmax],sol[nmax][22];

int vocala(char c)
{
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
        return 1;
    return 0;
}

int main()
{
    ifstream f("text.in");
    ofstream g("text.out");
    int i,j,k;
    f.getline(s+1,nmax);
    m=strlen(s+1);
    f>>n;nc=n;
    v[0][0]=1;
    for (i=0;i<=m;i++) {
        voc=0;
        for (j=i+1;j<=m&&j-i<=20;j++) {
            voc+=vocala(s[j]);
            if (voc>=1)
                for (k=0;k<m;k++)
                    if (v[i][k]) {
                        v[j][k+1]+=v[i][k];
                        if (v[j][k+1]>mod)
                            v[j][k+1]-=mod;
                    }
        }
    }
    g<<v[m][n]<<'\n';
    for (i=0;i<=m;i++)
        for (j=0;j<=m;j++)
            v[i][j]=inf;
    v[0][0]=0;

    for (i=0;i<=m;i++) {
        voc=0;
        for (j=i+1;j<=m&&j-i<=20;j++) {
            voc+=vocala(s[j]);
            if (voc>=1)
                for (k=0;k<m;k++)
                    if (v[i][k]+(j-i)*(j-i)<v[j][k+1]) {
                        v[j][k+1]=v[i][k]+(j-i)*(j-i);
                        t[j][k+1]=j-i;
                    }
        }
    }
    g<<v[m][n]<<'\n';
    while (m>0) {
        strncpy(sol[n],s+m-t[m][n]+1,t[m][n]);
        m-=t[m][n];n--;
    }
    for (i=1;i<nc;i++)
        g<<sol[i]<<' ';
    g<<sol[nc]<<'\n';
    return 0;
}
