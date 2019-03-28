#include <fstream>
#include <cstring>
#define lgmax 10000
#define nmax 1005
using namespace std;
ifstream f("spider.in");
ofstream g("spider.out");
int n,m,v[nmax][nmax],a[4][nmax][nmax];
const int dl[]={-1,0,1,0};
const int dc[]={0,1,0,-1};
char s[lgmax];int ns;

void getnr(int &x)
{
    while (s[ns]&&s[ns]-' ')
        x=x*10+s[ns++]-'0';
    ns++;
}
void sorttop(int i,int j)
{
    if (a[i][j])
        return;
    if (v[i][j]!=v[i-1][j]&&v[i][j]!=v[i][j-1]&&v[i][j]!=v[i+1][j]&&v[i][j]!=v[i][j+1]) {
        int l=0;,c=0;
        for (int d=0;d<4;d++)
            if (i+dl[d]!=iv||j+dc[d]!=jv)
                if (v[i+dl[d]][j+dc[d]]<=v[i][j]&&v[i+dl[d]][j+dc[d]]>v[l][c]) {
                        l=i+dl[d];
                        c=j+dc[d];
                }
        int maxx=0;
        if (l>=1&&l<=n&&c>=1&&c<=m) {
            sorttop(l,c);
            maxx=max(max(max(a[0][l][c],a[1][l][c]),a[2][l][c]),a[3][l][c]);
            ]
        a[0][i][j]=maxx+1;
        a[1][i][j]=maxx+1;
        a[2][i][j]=maxx+1;
        a[3][i][j]=maxx+1;
        }
    else {
        if (v[l][c]==v[l-1][c])
            a[0][]



    }
}
int main()
{
    int i,j;
    f>>n>>m;f.get();
    for (i=1;i<=n;i++) {
        memset(s,0,sizeof(s));
        f.getline(s,lgmax);ns=0;
        for (j=1;j<=m;j++)
            getnr(v[i][j]);
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            sorttop(i,j,0,0);


    return 0;
}
