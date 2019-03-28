#include <fstream>
#include <vector>
#include <queue>
#define nmax 505
#define pmax 205
using namespace std;
ifstream f("zmeu2.in");
ofstream g("zmeu2.out");
queue <pair<unsigned char,short> > q;
char s[pmax][pmax],in[pmax][nmax];
unsigned char r[pmax][nmax];
int n,p,k,d[pmax],l[pmax],sol;

int main()
{
    int i,j,t,w;
    f>>n>>p>>k;
    for (i=1;i<=p;i++)
        f>>d[i]>>l[i];
    for (i=1;i<=k;i++) {
        f>>j>>t;
        s[j][t]=1;
    }
    for (i=1;i<=p;i++)
        for (j=1;j<=n;j++)
            r[i][j]=1<<7;
    r[1][n-l[1]]=0;

    q.push(make_pair(1,n-l[1]));
    in[1][n-l[1]]=1;

    while (!q.empty()) {
        i=q.front().first;
        j=q.front().second;
        in[i][j]=0;
        q.pop();
        for (w=1;w<=p;w++) {
            if (s[i][w]==1||i==w)
                continue;
            if (i==1&&w==p)
                continue;

            if (j>=l[w]&&r[w][j-l[w]]>r[i][j]+d[w]) {
                r[w][j-l[w]]=r[i][j]+d[w];
                if (in[w][j-l[w]]==0) {
                    q.push(make_pair(w,j-l[w]));
                    in[w][j-l[w]]=1;
                }
            }
        }
    }
    sol=1<<7;
    for (i=1;i<=n;i++)
        if (r[p][i]<sol)
            sol=r[p][i];
    if (sol==(1<<7))
        g<<-1<<'\n';
    else
        g<<sol+d[1]<<'\n';
    return 0;
}
