#include <cstdio>
#include <vector>
#define nmax 1005
#define hashing 66013
using namespace std;
int n,s,v[nmax];
int sol;
vector <int> p[hashing];


void adding(int x)
{
    p[x%hashing].push_back(x);
}
void searching(int x)
{
    int i,y=x%hashing;

    for (i=0;i<p[y].size();i++)
        if (p[y][i]==x)
            sol++;
}
void solve()
{
    int i,j,k,t;

    for (i=1;i<=n;i++) {
        for (j=i+1;j<=n;j++)
            for (k=j+1;k<=n;k++) {
                t=s-(v[i]+v[j]+v[k]);
                if (t>0)
                    searching(t);
            }
        for (j=1;j<i;j++) {
            t=v[i]+v[j];
            if (t<=s)
                adding(v[i]+v[j]);
        }
    }
    printf("%d\n",sol);

}
int main()
{
    freopen("take5.in","r",stdin);
    freopen("take5.out","w",stdout);
    int i,j;
    scanf("%d %d",&n,&s);
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    solve();

    return 0;
}
