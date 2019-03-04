#include <fstream>
#include <vector>
#define nmax 100005
using namespace std;
int v[nmax][2], lev[nmax];
int p[nmax];
unsigned long long cost, ans=1LL<<62;

void dfs(int x)
{
    if (v[x][0]) {
        lev[v[x][0]] = lev[x] + 1;
        dfs(v[x][0]);
    }
    if (v[x][1]) {
        lev[v[x][1]] = lev[x] + 1;
        dfs(v[x][1]);
    }
}
int main()
{
    ifstream f("avele.in");
    ofstream g("avele.out");
    int i, j, k, n, cost_add, cost_rem;
    f>>n>>cost_add>>cost_rem;
    lev[1] = 1;

    for (i = 1; i<=n ; i++) {
        f>>v[i][0]>>v[i][1];
    }
    dfs(1);
    for (i = 1; i<=n ; i++)
        p[lev[i]]++;
    for (int niv = 1; niv <=30; niv ++) {
        j = (1<<niv)-1;
        k = 0;
        for (i = 1; i<= niv; i++) {
            k += p[i];
        }
        cost = static_cast<unsigned long long int>(1LL * cost_add * (j-k));
        cost += (n- k - p[niv+1]) * cost_rem;
        ans = min(ans, cost);
    }
    g<<0<<'\n';
    /*g<<ans<<'\n';*/

    return 0;
}