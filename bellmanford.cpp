#include <fstream>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#define nmax 50005
using namespace std;
ifstream f("bellmanford.in");
ofstream g("bellmanford.out");
int n,m,nr[nmax],d[nmax];
vector <pair <int , int > > v[nmax];
bitset <nmax> in;
queue <int> q;


int main()
{
    int i,j,x,y,z;
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
    }
    q.push(1);
    in[1]=1;
    for (i=2;i<=n;i++)
        d[i]=1<<30;
    while (!q.empty()) {
        x=q.front();
        q.pop();
        in[x]=0;
        for (i=0;i<v[x].size();i++) {
            y=v[x][i].first;
            z=v[x][i].second;
            if (d[y]>d[x]+z) {
                d[y]=d[x]+z;
                if (!in[y]) {
                    nr[y]++;
                    if (nr[y]==n) {
                        g<<"Ciclu negativ!";
                        return 0;
                    }

                    q.push(y);
                    in[y]=1;
                }
            }
        }
    }
    for (i=2;i<=n;i++)
        g<<d[i]<<' ';

    return 0;
}
