#include <cstdio>
#include <fstream>
#define nmax 35
using namespace std;
ifstream f("sudoku1.in");
ofstream g("sudoku1.out");
unsigned long long v[nmax*nmax];
int a[nmax][nmax],t[4];
int main()
{int n,i,j,c1;
unsigned long long p=0,k=0;
f>>n>>k;
p=3;
for (i=1;i<=n-1;i++) p*=4;
g<<p<<'\n';
p/=3;
v[1]=k/p;v[2*n-1]=k-p*(k/p)-1;
a[1][1]=v[1]+1;


for (i=2*n-1;i>=3;i--) {v[i-1]=v[i]/2;
                        v[i]%=2;
                        }
for (i=2;i<=n;i++) {if (a[1][i-1]==1) {if (v[i]==0) a[1][i]=2;
                                              else a[1][i]=3;}
                    if (a[1][i-1]==2) {if (v[i]==0) a[1][i]=1;
                                              else a[1][i]=3;}
                    if (a[1][i-1]==3) {if (v[i]==0) a[1][i]=1;
                                              else a[1][i]=2;}
                    }
for (i=2;i<=n;i++) {if (a[i-1][1]==1) {if (v[i+n-1]==0) a[i][1]=2;
                                                  else a[i][1]=3;}
                    if (a[i-1][1]==2) {if (v[i+n-1]==0) a[i][1]=1;
                                                  else a[i][1]=3;}
                    if (a[i-1][1]==3) {if (v[i+n-1]==0) a[i][1]=1;
                                                  else a[i][1]=2;}
                    }
for (i=2;i<=n;i++) for (j=2;j<=n;j++)
{t[1]=0;t[2]=0;t[3]=0;
t[a[i-1][j]]++;
t[a[i-1][j-1]]++;
t[a[i][j-1]]++;
if (t[1]==0&&a[i-1][j]!=1&&a[i][j-1]!=1) a[i][j]=1;
       else if (t[2]==0&&a[i-1][j]!=2&&a[i][j-1]!=2) a[i][j]=2;
                         else if (t[3]==0&&a[i-1][j]!=3&&a[i][j-1]!=3) a[i][j]=3;
                                                                else a[i][j]=a[i-1][j-1];
}
for (i=1;i<=n;i++) {for (j=1;j<=n;j++) g<<a[i][j]<<' ';
                    g<<'\n';
                    }
return 0;
}
