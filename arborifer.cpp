#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>

#define DIM 100100
#define RAD 320

using namespace std;
ifstream fin("arbore.in");
ofstream fout("arbore.out");
int Add[RAD];  // cat s-a adunat la fiecare numar din intervalul reprezentat de indice
int A[DIM];    // cat s-a adunat la fiecare numar, in afara de ce e in ADD (valoarea reala a numarului i este A[i] + ADD[intervalul de radical al lui i])
bitset<DIM> viz;
bitset<1000010> P[RAD];
int Begin[DIM], End[DIM], poz[DIM];
vector<int> L[DIM];
int g, n, i, j, q, x, y, t, p, s;

inline int getRad(int x) {
    return (x/RAD);
}

inline int getFirst(int r) {
    return (r*RAD);
}

inline int getLast(int r) {
    return ((r+1)*RAD-1);
}

void dfs(int nod) {
    g++;
    Begin[nod] = g;
    viz[nod] = 1;
    poz[g] = nod;
    for (int i=0;i<L[nod].size();i++) {
        if (!viz[ L[nod][i] ])
            dfs(L[nod][i]);
    }
    End[nod] = g;
}

void update(int st, int dr, int s) {
    // toate valorile dintre pozitiile st si dr vor creste cu s
    int r1 = getRad(st);
    int r2 = getRad(dr);
    for (int i=r1;i<=r2;i++) {
        if (getFirst(i) >= st && getLast(i)<=dr) {
            // fac update pe toata bucata de radical
            Add[i] += s;
            continue;
        }

        if (st <= getLast(i) || dr>= getFirst(i)) {
            int first = getFirst(i);
            int last = getLast(i);
            if (st >= first)
                first = st;

            if (dr <= last)
                last = dr;

//            P[i].reset();

            for (int j = getFirst(i); j<=getLast(i); j++) {
                P[i][A[j]] = 0;
            }

            for (int j = getFirst(i); j<=getLast(i); j++) {
                A[j] += Add[i];
                if (j >= first && j<=last)
                    A[j] += s;
                if (j<n)
                    P[i][ A[j] ] = 1;
            }
            Add[i] = 0;
            continue;
        }
    }
}

int query(int s) {
    for (int i=0;i<RAD;i++) {
        if (s-Add[i] >= 0 && P[i][s-Add[i]]) {
            for (j=getFirst(i); j<=getLast(i); j++) {
                if (A[j] + Add[i] == s) {
                    return poz[ j ];
                }
            }
        }
    }
    return -1;
}

int main() {
    fin>>n>>q;
    for (i=1;i<n;i++) {
        fin>>x>>y;
        L[x].push_back(y);
        L[y].push_back(x);
    }

    g = -1;
    dfs(1);
    for (;q--;) {
        fin>>t;
        if (t == 1) {
            fin>>p>>s;
            update(Begin[p], End[p], s);
        } else {
            fin>>s;
            fout<<query(s)<<"\n";
        }
    }

    return 0;
}
