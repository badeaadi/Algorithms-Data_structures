/**
  *  Worg
  */
#include <cstdio>
#include <vector>

using namespace std;
FILE *fin = freopen("arbxyz.in", "r", stdin);
FILE *fout = freopen("arbxyz.out", "w", stdout);

const int MAX_N = 1 + 100000;
const int bufferDim = 100000;

class inputReader {

private:
        char buffer[bufferDim];
        int pos = 0;

        bool digit(char c) {

            return('0' <= c && c <= '9');
        }
public:

        void getBuffer() {

            fread(buffer, 1, bufferDim, stdin);
            pos = 0;
        }

        void getInt(int &nr) {

            nr = 0;
            while(!digit(buffer[pos]))
                if(++pos == bufferDim)
                    getBuffer();
            while(digit(buffer[pos])) {

                nr = nr * 10 + buffer[pos] - '0';
                if(++pos == bufferDim)
                    getBuffer();
            }
        }
} cin;

vector <int> G[MAX_N];
int N, X, Y, Z;

bool solved;
bool marked[MAX_N], possible[MAX_N][3];
int subTree[MAX_N];

void readData() {
    cin.getInt(N); cin.getInt(X); cin.getInt(Y); cin.getInt(Z);
    for(int i = 1; i < N; ++i) {
        int u, v;
        cin.getInt(u); cin.getInt(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void DFS(int node) {
    if(solved) {
        return;
    }
    marked[node] = true;
    subTree[node] = 1;

    for(vector <int>::iterator it = G[node].begin(); it != G[node].end(); ++it) {
        if(!marked[*it]) {
            DFS(*it);
            subTree[node] += subTree[*it];
            for(int i = 0; i < 3; ++i) {
                possible[node][i] |= possible[*it][i];
            }
        }
    }

    if(subTree[node] == X) {
        possible[node][0] = true;
    }
    if(subTree[node] == Y) {
        possible[node][1] = true;
    }
    if(subTree[node] == Z) {
        possible[node][2] = true;
    }

    if(possible[node][0] && (N - subTree[node] == Y || N - subTree[node] == Z)) {
        solved = true;
    }
    if(possible[node][1] && (N - subTree[node] == X || N - subTree[node] == Z)) {
        solved = true;
    }
    if(possible[node][2] && (N - subTree[node] == Y || N - subTree[node] == X)) {
        solved = true;
    }
    if(possible[node][0] && possible[node][1] && subTree[node] >= X + Y) {
        solved = true;
    }
    if(possible[node][0] && possible[node][2] && subTree[node] >= X + Z) {
        solved = true;
    }
    if(possible[node][1] && possible[node][2] && subTree[node] >= Y + Z) {
        solved = true;
    }
}

void Reset() {
    for(int i = 1; i <= N; ++i) {
        G[i].clear();
        marked[i] = false; subTree[i] = 0;
        for(int j = 0; j < 3; ++j) {
            possible[i][j] = false;
        }
    }
}

int main() {
    cin.getBuffer();
    int T;
    for(cin.getInt(T); T; T--) {
        readData();
        solved = false;
        DFS(1);
        printf("%d\n", solved);

        Reset();
    }
}
