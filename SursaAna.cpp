#include <bits/stdc++.h>
#define maxN 10002
#define mod 666013
#define maxD 11
#define pb push_back
using namespace std;
int n, p, x[maxN], c[maxD], sol, cod[maxN];
vector < int > V[mod];
int in_hash(int x)
{
    int i, y = x % mod, len = V[y].size();
    for (i = 0; i < len; ++ i)
        if (V[y][i] == x)
            return 1;
    return 0;
}
void solve(int i)
{
    int j;
    int cp = x[i];
    while (cp)
    {
        ++ c[cp % 10];
        cp /= 10;
        if (p == 1)
            ++ sol;
    }
    if (p == 2)
    {
        for (j = 1; j <= 9; ++ j)
        {
            while (c[j])
            {
                cod[i] = cod[i] * 10 + j;
                -- c[j];
            }
            if (cod[i])
            {
                while (c[0])
                {
                    cod[i] = cod[i] * 10;
                    -- c[0];
                }
            }
        }
        if (!in_hash(cod[i]))
        {
            V[cod[i] % mod].pb(cod[i]);
            ++ sol;
        }
    }
}
void read()
{
    int i, j;
    freopen("elevi.in", "r", stdin);
    scanf("%d", &p);
    scanf("%d", &n);
    for (i = 1; i <= n; ++ i)
    {
        cod[i] = 0;
        scanf("%d", &x[i]);
        solve(i);
    }
}
void write()
{
    freopen("elevi.out", "w", stdout);
    printf("%d", sol);
}
int main()
{
    read();
    write();
    return 0;
}
