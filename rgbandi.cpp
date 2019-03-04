/**
  *  Worg
  */
#include <cstdio>
#include <vector>

using std::vector;
FILE *fin = freopen("rgb.in", "r", stdin);
FILE *fout = freopen("rgb.out", "w", stdout);

const int step = 20;

/*-------- Input data --------*/
int test_count;
int r, g, b;
/*-------- Algo data --------*/
vector<int > vr, vg, vb;
int total;
/*-------- --------*/

void BuildSolution() {
    int start = 1;
    while(r != 0 && b != 0 && g != 0) {
        if(r == g && g == b) {  //  R-G-B
            vr.push_back(start);
            vg.push_back(start + 1);
            vb.push_back(start + 2);
            r--; g--; b--;
            start += step;
        } else if(r >= g && r >= b) {  //  R-G-B-R
            vr.push_back(start);
            vg.push_back(start + 1);
            vb.push_back(start + 2);
            vr.push_back(start + 3);
            r -= 2; g--; b--;

            if(g > r && g > b) {
                vg.push_back(start + 4); g--;
            } else if(b > r && b > g) {
                vb.push_back(start - 1); b--;
            }

            start += step;
        } else if(g >= r && g >= b) {  //  G-R-B-G
            vg.push_back(start);
            vr.push_back(start + 1);
            vb.push_back(start + 2);
            vg.push_back(start + 3);
            r --; g -= 2; b--;

            if(r > g && r > b) {
                vr.push_back(start + 4); r--;
            } else if(b > r && b > g) {
                vb.push_back(start - 1); b--;
            }

            start += step;
        } else {  //  B-R-G-B
            vb.push_back(start);
            vr.push_back(start + 1);
            vg.push_back(start + 2);
            vb.push_back(start + 3);
            r --; g --; b -= 2;

            if(r > b && r > g) {
                vr.push_back(start + 4); r--;
            } else if(g > r && g > b) {
                vg.push_back(start - 1); g--;
            }
            start += step;
        }
    }
}

void WriteOutput() {
    if((int)vr.size() + (int)vg.size() + (int)vb.size() != total) {
        printf("-1\n");
    } else {
        for(int x : vr) {
            printf("%d ", x);
        }
        printf("\n");
        for(int x : vg) {
            printf("%d ", x);
        }
        printf("\n");
        for(int x : vb) {
            printf("%d ", x);
        }
        printf("\n");
    }

    vr.clear(); vg.clear(); vb.clear();
}

int main() {
    for(scanf("%d", &test_count); test_count > 0; test_count--) {
        scanf("%d%d%d", &r, &g, &b);
        total = r + g + b;
        BuildSolution();
        WriteOutput();
    }
}
