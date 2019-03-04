/**
  *  Worg
  */
#include <set>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>

using std::set;
using std::pair;

FILE *fin = freopen("rangemode.in", "r", stdin);
FILE *fout = freopen("rangemode.out", "w", stdout);

const int kMaxN = 1 + 100000;
const int kMaxM = 1 + 100000;
const int kMaxValue = 1 + 100000;
const int kBlockSize = 310;

/*-------- Structures --------*/
struct Query {
    int left, right, index;
    Query() {}
    Query(const int left, const int right, const int index) {
        this->left = left; this->right = right; this->index = index;
    }
};
/*-------- Input data --------*/
int N, M;
int seq[kMaxN];
Query query[kMaxM];
/*-------- Mo algorithm --------*/
int count[kMaxValue];
int most_frequent;
/*-------- Solution --------*/
int query_answer[kMaxM];
/*-------- --------*/

void ReadInput() {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &seq[i]);
    }
    for(int i = 1; i <= M; i++) {
        scanf("%d%d", &query[i].left, &query[i].right);
        query[i].index = i;
    }
}

bool comp(Query a, Query b) {
    if(a.left / kBlockSize != b.left / kBlockSize) {
        return a.left / kBlockSize < b.left / kBlockSize;
    } else {
        return a.right < b.right;
    }
}

void AddInterval(int left, int right, int sign) {
    for(int i = left; i <= right; i++) {
		count[seq[i]] += sign;
        if(count[seq[i]] > count[most_frequent] || (count[seq[i]] == count[most_frequent] && seq[i] < most_frequent)) {
			most_frequent = seq[i];
        }
    }
}

void RunMoAlgorithm() {
    int last_block = -1, last_added;

    for(int i = 1; i <= M; i++) {
		if(query[i].left / kBlockSize > last_block) {  //  Resetam contoarele, trecem la un bloc nou
			for(int j = 1; j < kMaxValue; j++) {
				count[j] = 0;
			}
			most_frequent = 0;
			last_block = query[i].left / kBlockSize;
			last_added = (last_block + 1) * kBlockSize - 1;
		}
		AddInterval(last_added + 1, query[i].right, +1);
		last_added = std::max(last_added, query[i].right);
		int aux_most_frequent = most_frequent;

        AddInterval(query[i].left, std::min(query[i].right, (last_block + 1)  * kBlockSize - 1), +1);
        query_answer[query[i].index] = most_frequent;
        AddInterval(query[i].left, std::min(query[i].right, (last_block + 1)  * kBlockSize - 1), -1);
        most_frequent = aux_most_frequent;
    }
}

void WriteOutput() {
    for(int i = 1; i <= M; i++) {
        printf("%d\n", query_answer[i]);
    }
}

int main() {
    ReadInput();
    std::sort(query + 1, query + M + 1, comp);  //  Sortam query-urile dupa block-ul in care se afla capatul din stanga, iar apoi dupa capatul din dreapta crescator
    RunMoAlgorithm();
    WriteOutput();
    return 0;
}
