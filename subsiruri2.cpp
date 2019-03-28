#include <cstdio>
#include <cstring>
#include <fstream>
#include <queue>
#define nmax 42
using namespace std;
queue <pair <int,int > > q[2];
char s[nmax];
long long sol;
int n,d[nmax][nmax],v[nmax];

int main()
{
    int i,j,t,k,c;
    freopen("subsiruri2.in","r",stdin);
    freopen("subsiruri2.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",&s);
    for (i=0;i<n;i++)
        v[i+1]=s[i]-'a';

    for (i=0;i<(1<<(n/2));i++) {
        if (v[1]!=(i&1))
            continue;

        d[0][0]=1;
        q[1].push(make_pair(0,0));

        for (j=1;j<=n;j++)
            while (!q[j&1].empty()) {
                t=q[j&1].front().first;
                k=q[j&1].front().second;
                q[j&1].pop();

                if (!(t<=n/2&&k<=n/2))
                    continue;

                if ((v[j])==(((i&(1<<t))!=0))) {
                    if (d[t+1][k]==0)
                        q[(j+1)&1].push(make_pair(t+1,k));
                    d[t+1][k]+=d[t][k];
                }
                if ((v[j])==(((i&(1<<k))!=0))) {
                    if (d[t][k+1]==0)
                        q[(j+1)&1].push(make_pair(t,k+1));
                    d[t][k+1]+=d[t][k];
                }
            }

        sol+=d[n/2][n/2];
        memset(d,0,sizeof(d));
    }
    printf("%lld",sol);
    return 0;
}
