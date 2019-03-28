/**
  *  Worg
  */
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using std::pair;
using std::vector;

FILE *fin = freopen("turism.in", "r", stdin);
FILE *fout = freopen("turism.out", "w", stdout);

const int kMaxN = 1 + 30000;

/*-------- Input data --------*/
int N, M;
vector<int > directed_graph[kMaxN], undirected_graph[kMaxN];
/*-------- Connected components --------*/
int connected_component[kMaxN];
int crt_component;
/*-------- Degrees --------*/
int in_degree[kMaxN], out_degree[kMaxN];
int component_in[kMaxN], component_out[kMaxN];

vector<int > vec_in, vec_out, final_vec_in, final_vec_out;
/*-------- Solution --------*/
vector<pair<int, int > > solution;
/*-------- --------*/

void ReadInput() {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; i++) {
        int u, v; scanf("%d%d", &u, &v);
        directed_graph[u].push_back(v);
        out_degree[u] ++; in_degree[v] ++;
        undirected_graph[u].push_back(v); undirected_graph[v].push_back(u);
    }
}

void DFS(int node) {
    connected_component[node] = crt_component;

    for(int i = 0; i < (int)undirected_graph[node].size(); i++) {
        if(!connected_component[undirected_graph[node][i]]) {
            DFS(undirected_graph[node][i]);
        }
    }
}

void GetConnectedComponents() {
    for(int i = 1; i <= N; i++) {
        if(!connected_component[i]) {
            crt_component ++;
            DFS(i);
        }
    }
}

void BuildInOutVectors() {
    for(int i = 1; i <= N; i++) {
        if(in_degree[i] > out_degree[i]) {
            component_out[connected_component[i]] += (in_degree[i] - out_degree[i]);
            for(int j = in_degree[i] - out_degree[i]; j > 0; j--) {
                vec_out.push_back(i);
            }
        } else {
            component_in[connected_component[i]] += (out_degree[i] - in_degree[i]);
            for(int j = out_degree[i] - in_degree[i]; j > 0; j--) {
                vec_in.push_back(i);
            }
        }
    }

    ///  Verificam daca sunt componente conexe care admit ciclu eulerian, dar pe care trebuie sa le conectam cu celelalte
    for(int i = 1; i <= N; i++) {
        if(crt_component > 1 && component_in[connected_component[i]] == 0) {
            component_in[connected_component[i]] ++; component_out[connected_component[i]] ++;
            vec_in.push_back(i); vec_out.push_back(i);
        }
    }
}

void GetSolution() {
    std::sort(vec_in.begin(), vec_in.end());
    std::sort(vec_out.begin(), vec_out.end());

    for(int i = 0; i < (int)vec_in.size() - 1; i++) {
        int cc_1 = connected_component[vec_in[i]];
        int cc_2 = connected_component[vec_out[i]];
        if(cc_1 == cc_2 && component_in[cc_1] == 1 && component_out[cc_2] == 1) {
            std::swap(vec_in[i], vec_in[i + 1]);
        } else {
            component_in[cc_1] --;
            component_out[cc_2] --;
        }
    }

    if(connected_component[vec_in.back()] == connected_component[vec_out.back()] && vec_in.size() > 1 && connected_component[vec_in.back()] != connected_component[vec_in[vec_in.size() - 2]]) {
        std::swap(vec_in[vec_in.size() - 1], vec_in[vec_in.size() - 2]);
    }

    printf("%d\n", (int)vec_in.size());
    for(int i = 0; i < (int)vec_in.size(); i++) {
        printf("%d %d\n", vec_out[i], vec_in[i]);
    }
}

int main() {
    ReadInput();
    GetConnectedComponents();
    BuildInOutVectors();
    GetSolution();
    return 0;
}
