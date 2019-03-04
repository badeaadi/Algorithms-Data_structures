#include <fstream>
#define nmax 100005
using namespace std;
ifstream f("aemi.in");
ofstream g("aemi.out");
int n,m,t,a,b,sol,v[nmax];
int aint[nmax*3];

void build(int nod,int st,int dr)
{
    if (st==dr) {
        aint[nod]=v[st];
        return;
    }
    int mid=(st+dr)>>1;
    build(nod*2,st,mid);
    build(nod*2+1,mid+1,dr);
    aint[nod]=min(aint[nod*2],aint[nod*2+1]);
}
void query(int nod,int st,int dr,int a,int b)
{
    if (a<=st&&dr<=b) {
        sol=min(sol,aint[nod]);
        return;
    }
    int mid=(st+dr)>>1;
    if (a<=mid)
        query(nod*2,st,mid,a,b);
    if (b>mid)
        query(nod*2+1,mid+1,dr,a,b);
}
void update(int nod,int st,int dr,int a)
{
    if (st==dr) {
        aint[nod]=v[a];
        return;
    }
    int mid=(st+dr)>>1;
    if (a<=mid)
        update(nod*2,st,mid,a);
    else
        update(nod*2+1,mid+1,dr,a);
    aint[nod]=min(aint[nod*2],aint[nod*2+1]);
}
int main()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++)
        f>>v[i];
    build(1,1,n);
    f>>m;
    for (i=1;i<=m;i++) {
        f>>t>>a>>b;
        if (t==1) {
            sol=1<<30;
            query(1,1,n,a,b);
            g<<sol<<'\n';
        }
        else {
            v[a]=b;
            update(1,1,n,a);
        }
    }
    return 0;
}
