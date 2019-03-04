#include <fstream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <set>
#define nmax 100005
using namespace std;
set <string> v[nmax];
string s;
int n, m[nmax];
int sol[nmax];


unsigned int xorshift32(unsigned int last)
{
    unsigned int x = last;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}
int* createsequence(int n) {

    int i, j;
    int *v = new int[n];

    unsigned int ra = n/2;

    for (i = 0; i < n ; i++)
        v[i] = i;

    for (i = 1; i < n; i++) {
        ra = xorshift32(ra);
        swap(v[i], v[ra % i]);
    }
    return v;
}
int comb(int a,int b)
{
    int i, j;
    int c = 0;
    for (auto it = v[a].begin(); it != v[a].end(); it++)  {
        if (v[b].find((*it)) != v[b].end())
            c++;
    }
    return min(m[a] - c, min(m[b] - c, c));
}
int pos[nmax], posnr;

int main()
{
    int i, j, t;
    clock_t start_time = clock();

    char ch;
    ifstream f("slideshow.in");
    f>>n;
    for (i = 0, t = 0; i< n; i++, t++) {
        f>>ch;
        f>>m[i];
        f.get();

        if (ch == 'V') {

            for (j = 0; j < m[i]; j++) {
                f >> s;
                s.clear();
            }
            n --, i--;
            continue;
        }
        pos[i] = t;
        for (j = 0; j < m[i]; j++) {
            f>>s;
            v[i].insert(s);

            s.clear();
        }
    }

    long long intsol = 0, inte;

    // while ((double)(clock() -  start_time)/CLOCKS_PER_SEC < 180) {
    srand(clock());
    inte = 0 ;
    int * p = createsequence(n);
    int w, o;

    for (i = 0; i + 1 < n ; i++) {

        for (j = i + 1; j < n  ; j++) {
            w = comb(p[i], p[j]);
            o = comb(p[i], p[i+1]);
            if (w > o)
                swap(p[i + 1], p[j]);
            if (w >= 1)
                break;
        }

        inte += comb(p[i], p[i + 1]);
        printf("%d\n", i);
    }


    if (inte > intsol) {
        intsol = inte;
        for (j = 0; j< n ; j++)
            sol[j] = p[j];
    }
    //}

    freopen("slideshow.out","w",stdout);
    printf("%d\n",n);
    for (i = 0; i < n ; i++)
        printf("%d\n", pos[sol[i]]);
    printf("%d\n", intsol);
    return 0;
}


