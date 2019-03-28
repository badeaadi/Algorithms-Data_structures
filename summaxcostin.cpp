#include<bits/stdc++.h>

using namespace std;

int INF = 2000000000, N, st, dr, type, *a[2009], *cnt[2009], stk[2009];
long long dp[2][2009];
bitset < 2001 > Lh[2001], Rh[2001];

int add (int x, int y) {int s = x + y; if (x > INF - y) s = INF + 1; return s;}

void solve (int x, int y, int st, int dr)
{
    stk[x] = y;
    if (x == N)
    {
        for (int i=1; i<=N; i++)
            printf ("%d ", stk[i]);
        printf ("\n");
        return ;
    }
    if (!Lh[x][y]) solve (x + 1, y + 1, st, dr);
    else
    {
        if (cnt[x + 1][y] >= dr) solve (x + 1, y, st, dr);
        else
        if (cnt[x + 1][y] < st) solve (x + 1, y + 1, st - cnt[x + 1][y], dr - cnt[x + 1][y]);
        else solve (x + 1, y, st, cnt[x + 1][y]), solve (x + 1, y + 1, 1, dr - cnt[x + 1][y]);
    }
}

int main ()
{
freopen ("summax.in", "r", stdin);
freopen ("summax.out", "w", stdout);

scanf ("%d\n%d %d %d", &type, &N, &st, &dr);
for (int i=1; i<=N; i++)
{
    a[i] = new int[i + 1];
    for (int j=1; j<=i; j++)
        scanf ("%d", &a[i][j]);
}
for (int i=N; i>=1; i--)
{
    cnt[i] = new int[i + 1];
    if (i == N)
    {
        for (int j=1; j<=i; j++)
            dp[i & 1][j] = a[i][j], cnt[i][j] = 1;
    }
    else
    {
        for (int j=1; j<=i; j++)
        {
            long long L = dp[(i & 1) ^ 1][j], R = dp[(i & 1) ^ 1][j + 1];
            if (L == R) dp[i & 1][j] = L + a[i][j], cnt[i][j] = add (cnt[i + 1][j], cnt[i + 1][j + 1]);
            else
            if (L < R) dp[i & 1][j] = R + a[i][j], cnt[i][j] = cnt[i + 1][j + 1];
            else dp[i & 1][j] = L + a[i][j], cnt[i][j] = cnt[i + 1][j];
            Lh[i][j] = (dp[i & 1][j] == L + a[i][j]);
            Rh[i][j] = (dp[i & 1][j] == R + a[i][j]);
        }
    }
}
if (type == 1)
{
    printf ("%d\n", cnt[1][1]);
    return 0;
}
solve (1, 1, st, dr);
return 0;
}
