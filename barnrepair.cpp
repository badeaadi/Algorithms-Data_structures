#include <fstream>
#define inf 100000
using namespace std;

ifstream f("barnrepair.in");
ofstream g("barnrepair.out");


int v[205], p[205];
int b[205], dp[55][205];
int m,s,c;

int main()
{
    int i, j, k;
    f>>m>>s>>c;
    for (i = 1; i <= c; i++) {
        f>>v[i];			//Numerele tarcurilor
        b[v[i]] = 1;			//Unde este 1 in sir
    }
    for (i = 1; i <= s; i++)
        p[i] = p[i-1] + b[i];		// Cati de 1 sunt pana la i in sir ?

    for (i = 0; i<=m; i++)
        for (j = 0; j <=c; j++)
            dp[i][j] = inf;

    dp[0][0] = 0;

    for (i = 1; i <= m; i++)
        for (j = 1; j<= c; j++) {
            //dp[i][j] { dp[i-1][k], 0 <=k < j}
            dp[i][j] = inf;
            for (k = 0; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i-1][k] + v[j] - v[k+1] + 1);
        }
    int sol = inf;

    for (i = 1; i<=m ; i++)
        sol = min(sol, dp[i][c]);

    g<<sol<<'\n';
    return 0;
}