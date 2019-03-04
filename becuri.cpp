#include <fstream>
#include <vector>
#define nmax 505
using namespace std;
ifstream f("becuri.in");
ofstream g("becuri.out");
vector <pair <int,int > > s;
int n,m,v[nmax][nmax];
int l1[nmax],c1[nmax],p;
int l2[nmax],c2[nmax],q;
int sol=1<<30;

void solve(int l[],int c[])
{
    int i,j,p,q;
    for (j=1;j<=m;j++)
        if (v[1][j]!=l[1])
            c[j]=1;
        else
            c[j]=0;

    for (i=2;i<=n;i++)
        if (v[i][1]!=c[1])
            l[i]=1;
        else
            l[i]=0;

    for (i=2;i<=n;i++)
        for (j=2;j<=m;j++)
            if ((l[i]^c[j])!=v[i][j])
                return;
    for (i=1,p=0;i<=n;i++)
        p+=l[i];
    for (j=1,q=0;j<=m;j++)
        q+=c[j];

    if ((p-q)&1)
        return;
    if (max(p,q)<sol) {
        sol=max(p,q);
        s.clear();
        i=1;j=1;
        if (p&&q) {
            while (i<=n&&j<=m) {
                while (i<=n&&l[i]==0)
                    i++;
                while (j<=m&&c[j]==0)
                    j++;
                if (l[i]&&c[j]) {
                    s.push_back(make_pair(i,j));
                    i++,j++;
                }
                else
                    break;
            }
        }
        if (p<q) {
            while (j<=m) {
                while (j<=m&&c[j]==0)
                    j++;
                if (c[j])
                    s.push_back(make_pair(1,j));
                j++;
            }
        }
        else {
            while (i<=n) {
                while (i<=n&&l[i]==0)
                    i++;
                if (l[i])
                    s.push_back(make_pair(i,1));
                i++;
            }
        }
    }
}
int main()
{
    int i,j;
    f>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            f>>v[i][j];
    l1[1]=0;
    solve(l1,c1);
    l2[1]=1;
    solve(l2,c2);

    if (sol==(1<<30)) {
        g<<-1<<'\n';
        return 0;
    }
    g<<sol<<'\n';
    for (i=0;i<sol;i++)
        g<<s[i].first<<' '<<s[i].second<<'\n';
    return 0;
}
