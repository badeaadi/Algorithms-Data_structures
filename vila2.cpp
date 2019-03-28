#include <cstdio>
#include <deque>
#include <fstream>
#define nmax 100005
using namespace std;
ifstream f("vila2.in");
ofstream g("vila2.out");
deque <int> a,b;
short v[nmax];
int n,k,d;

inline int modul(int x)
{
    return (x>=0?x:-x);
}
void solve()
{
    int i,j;
    for (i=1;i<=n;i++) {
        while (!a.empty()&&v[i]>v[a.back()])
            a.pop_back();
        a.push_back(i);

        if (!a.empty()&&i-a.front()==k+1)
            a.pop_front();
        if (!a.empty())
            d=max(d,modul(v[i]-v[a.front()]));

        while (!b.empty()&&v[i]<v[b.back()])
            b.pop_back();
        b.push_back(i);

        if (!b.empty()&&i-b.front()==k+1)
            b.pop_front();
        if (!b.empty())
            d=max(d,modul(v[i]-v[b.front()]));
    }
}
int main()
{
    int i;
    f>>n>>k;
    for (i=1;i<=n;i++)
        f>>v[i];
    solve();
    g<<d<<'\n';

    return 0;
}
