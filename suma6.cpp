#include <fstream>
#define nmax 100005
using namespace std;
struct arb{int sol;multiset <int> s;};
multiset <int> ::iterator it;
arb aint[nmax];
int v[nmax];


void build(int nod,int st,int dr)
{
    if (st==dr) {
        s.insert(st);
        sol=0;
        return;
    }
    int mid=(st+dr)>>1;
    build(nod*2,)
}

int main()
{
    int i,j;
    f>>n>>s;
    for (i=1;i<=n;i++)
        f>>v[i];
    build(1,1,n);
    f>>q;
    for (i=1;i<=q;i++) {
        f>>a>>b;
    }


    return 0;
}
