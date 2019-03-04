#include <cmath>
#include <cstring>
#include <cfloat>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 410;
const double eps = 1.e-14;

struct Point {
    double x, y;
};

int  a [2 * N], b [2 * N], c [2 * N + 2][2 * N + 2], father [2 * N + 2], f [2 * N + 2][2 * N + 2];
bool used [2 * N];
double d [2 * N][2 * N], l [2 * N + 2];
vector <int> graph [2 * N + 2];
Point S [N], D [N];
int n;

const int inf = (1ll << 31) - 1;

double dist (const Point &A, const Point &B) {
    return sqrt ((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

bool cupleaza (int x) {
    vector <int> :: iterator it;

    if (used [x] == 1)
        return 0;
    used [x] = 1;
    for (it = graph [x].begin (); it != graph [x].end (); ++ it)
        if (!b [*it]) {
            b [*it] = x;
            a [x] = *it;
            return 1;
        }
    for (it = graph [x].begin (); it != graph [x].end (); ++ it)
        if (b [*it]) {
            if (cupleaza (b [*it]) && b [*it] != x) {
                a [x] = *it;
                b [*it] = x;
                return 1;
            }
        }
    return 0;
}

int cuplaj () {
    int i, flag = 1, ans = 0;

    memset (a, 0, sizeof (a));
    memset (b, 0, sizeof (b));

    while (flag) {
        flag = 0;
        memset (used, 0, sizeof (used));
        for (i = 1; i <= n; i ++)
            if (!a [i])
                if (cupleaza (i)) {
                    flag = 1;
                    ++ ans;
                }
    }
    return ans;
}

void make_graph (double dmax, int capacitati) {
    int i, j, lim = 2 * n;

    for (i = 1; i <= n; i ++) {
        graph [i].clear ();
        for (j = n + 1; j <= lim; j ++)
            if (d [i][j] <= dmax) {
                graph [i].push_back (j);
                if (capacitati == 1) {
                    graph [j].push_back (i);
                    c [i][j] = 1;
                }
            }
    }
}

bool ok (double dmax) {
    make_graph (dmax, 0);
    if (cuplaj () == n)
        return 1;
    return 0;
}

bool bellmanford (int sursa, int destinatie) {
    int i, x, flag = 0;
    vector <int> :: iterator it;
    queue <int> q;

    for (i = 0; i <= destinatie; i ++)
        l [i] = 1.0 * inf;
    memset (used, 0, sizeof (used));
    q.push (sursa);
    l [sursa] = 0;
    used [sursa] = 1;
    while (!q.empty ()) {
        x = q.front ();
        q.pop ();
        used [x] = 0;
        for (it = graph [x].begin (); it != graph [x].end (); ++ it)
            if (c [x][*it] - f [x][*it] > 0)
                if (l [*it] > l [x] + d [x][*it]) {
                    l [*it] = l [x] + d [x][*it];
                    father [*it] = x;
                    if (*it == destinatie)
                        flag = 1;
                    if (used [*it] == 0) {
                        q.push (*it);
                        used [*it] = 1;
                    }
            }
    }
    return flag;
}

double fmcm (int sursa, int destinatie) {
    int minflow, i;
    double ans = 0;

    while (bellmanford (sursa, destinatie)) {
        minflow = (1ll << 31) - 1;
        for (i = destinatie; i != sursa; i = father [i])
            minflow = min (minflow, c [father [i]][i] - f [father [i]][i]);
        if (minflow == 0)
            continue;
        for (i = destinatie; i != sursa; i = father [i]) {
            f [father [i]][i] += minflow;
            f [i][father [i]] -= minflow;
        }
        ans = ans + 1.0 * l [destinatie] * minflow;
    }
    return ans;
}

int main () {
    int i, j, sursa, destinatie, g, lim;
    double ans, k, dmax = 0.0, st, dr, m, last;

    freopen ("adapost.in", "r", stdin);
    freopen ("adapost.out", "w", stdout);

    scanf ("%d", &n);
    lim = n << 1;
    for (i = 1; i <= n; i ++)
        scanf ("%lf%lf", &S [i].x, &S [i].y);
    for (i = 1; i <= n; i ++)
        scanf ("%lf%lf", &D [i].x, &D [i].y);

    for (i = 1; i <= n; i ++)
        for (j = 1; j <= n; j ++) {
            k = dist (S [i], D [j]);
            d [i][j + n] = k;
            d [j + n][i] = - d [i][j + n];
            if (k - dmax > eps)
                dmax = k;
        }

    st = 0;
    dr = dmax;
    for (i = 1; i <= 30; i ++) {
        m = (st + dr) / 2;
        if (ok (m)) {
            dr = m;
            last = m;
        }
        else st = m;
    }
    printf ("%lf", last);
    make_graph (last, 1);
    sursa = 0;
    destinatie = 2 * n + 1;
    for (i = 1; i <= n; i ++) {
        graph [sursa].push_back (i);
        graph [i].push_back (sursa);
        c [sursa][i] = 1;
    }
    for (i = n + 1; i <= lim; i ++) {
        graph [i].push_back (destinatie);
        graph [destinatie].push_back (i);
        c [i][destinatie] = 1;
    }
    ans = fmcm (sursa, destinatie);
    printf (" %.15lf\n", ans);
    return 0;
}
