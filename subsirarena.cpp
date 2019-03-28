#include <fstream>
#include <cstring>
#define nmax 505
#define teta 26
#define mod 666013
using namespace std;
ifstream f("subsir.in");
ofstream g("subsir.out");
int n,m,v[nmax][nmax],k[nmax][nmax][teta];
char a[nmax],b[nmax];

void dp(int &a,int &b,int x,int y)
{
    if (x>a) {
        a=x;
        b=y;
    }
    else
        if (x==a)
            b+=y;
}
int main()
{
    int i,j,t;
    f.getline(a+1,nmax);n=strlen(a+1);
    f.getline(b+1,nmax);m=strlen(b+1)
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {

            for (t=0;t<teta;t++)
                dp(v[i][j],k[i][j][t],0,1);

            for (t=0;t<teta;t++)
                dp(v[i][j],k[i][j][t],v[i-1][j],k[i-1][j][t]);

            for (t=0;t<teta;t++)
                dp(v[i][j],k[i][j][t],v[i][j-1],k[i][j-1][t]);

            if (a[i]==b[j])
                dp(v[i][j],k[i][j][t],v[i-1][j-1]+1,k[i-1][j-1][t]);

        }
    return 0;
}
