#include <fstream>
#define nmax 100005
#define ub(i) i&(-i)
using namespace std;
ifstream f("baruri.in");
ofstream g("baruri.out");
int n,m,v[nmax+5],aib[nmax+5];

int query(int i)
{
    int sum=0;
    for (;i>=1;i-=ub(i))
        sum+=aib[i];
    return sum;
}
void update(int i,int val)
{
    for (;i<=nmax;i+=ub(i))
        aib[i]+=val;
}
void solveop(int op)
{
    int x,b,b1,b2,d;
    if (op==1) {
        f>>x>>b;
        v[b]+=x;
        update(b,x);
        return;
    }
    if (op==2) {
        f>>x>>b;
        v[b]-=x;
        update(b,-x);
        return;
    }
    if (op==3) {
        f>>x>>b1>>b2;
        v[b1]-=x;
        update(b1,-x);
        v[b2]+=x;
        update(b2,x);
        return;
    }
    f>>b>>d;
    int sol;
    if (b+d<=n)
        sol=query(b+d);
    else
        sol=query(n);
    if (b-d-1>=1)
        sol-=query(b-d-1);
    g<<sol-v[b]<<'\n';
}
void solve()
{
    int i,j,op;
    f>>n;
    for (i=1;i<=n;i++) {
        f>>v[i];
        update(i,v[i]);
    }
    f>>m;
    for (i=1;i<=m;i++) {
        f>>op;
        solveop(op);
    }
    for (i=1;i<=nmax;i++) {
        v[i]=0;aib[i]=0;
    }
}
int main()
{
    int t;
    for (f>>t;t;t--)
        solve();

    return 0;
}
