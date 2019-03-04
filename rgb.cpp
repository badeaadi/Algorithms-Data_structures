#include <fstream>
#include <vector>
#define nmax 4
using namespace std;
ifstream f("rgb.in");
ofstream p("rgb.out");
vector <int> v[nmax];
int r,g,b,x;

void solvetest()
{
    int i,j;
    f>>r>>g>>b;
    x=0;
    for (i=0;i<=2;i++)
        v[i].clear();

    while (r>0&&g>0&&b>0) {
        if (r==g&&r==b) {
            r--;g--;b--;
            x+=10;
            v[0].push_back(++x);
            v[1].push_back(++x);
            v[2].push_back(++x);
            continue;
        }
        if (r>=g&&r>=b) {
            x+=20;
            r-=2;g--;b--;
            v[0].push_back(++x);
            v[1].push_back(++x);
            v[2].push_back(++x);
            v[0].push_back(++x);
            if (g>r&&g>b)
                v[1].push_back(++x),g--;
            else
                if (b>r&&b>g)
                    v[2].push_back(x-4),b--;
            continue;
        }
        if (g>=r&&g>=b) {
            x+=20;
            r--;g-=2;b--;
            v[1].push_back(++x);
            v[0].push_back(++x);
            v[2].push_back(++x);
            v[1].push_back(++x);
            if (r>b&&r>g)
                v[0].push_back(++x),r--;
            else
                if (b>r&&b>g)
                    v[2].push_back(x-4),b--;
            continue;
        }
        if (b>=r&&b>=g) {
            x+=20;
            r--;g--;b-=2;
            v[2].push_back(++x);
            v[0].push_back(++x);
            v[1].push_back(++x);
            v[2].push_back(++x);
            if (r>g&&r>b)
                v[0].push_back(++x),r--;
            else
                if (g>r&&g>b)
                    v[1].push_back(x-4),g--;
            continue;
        }
        break;
    }
    if (g||b||r) {
        p<<-1<<'\n';
        return;
    }
    for (i=0;i<=2;i++) {
        for (j=0;j<v[i].size();j++)
            p<<v[i][j]<<' ';
        p<<'\n';
    }
}
int main()
{
    int t;
    for (f>>t;t;t--)
        solvetest();

    return 0;
}
