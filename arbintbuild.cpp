#include <fstream>
#define nmax 100005
using namespace std;
ifstream f("arbint.in");
ofstream g("arbint.out");
int n,m,aint[nmax*3];
int v[nmax],p,q,x;

void build(int nod,int st,int dr)
{
    if (st==dr) {
        aint[nod]=v[st];
        return;
    }
    int mid=(st+dr)>>1;
    build(nod*2,st,mid);
    build(nod*2+1,mid+1,dr);
    aint[nod]=max(aint[nod*2],aint[nod*2+1]);

}
void update(int nod,int st,int dr)
{
    if (st==dr) {
        aint[nod]=v[st];
        return;
    }
    int mid=(st+dr)>>1;
    if (p<=mid)
        update(nod*2,st,mid);
    if (p>=mid+1)
        update(nod*2+1,mid+1,dr);
    aint[nod]=max(aint[nod*2],aint[nod*2+1]);

}
void query(int nod,int st,int dr)
{
    if (p<=st&&dr<=q) {
        x=max(x,aint[nod]);
        return;
    }
    int mid=(st+dr)>>1;
    if (mid>=p)
        query(nod*2,st,mid);
    if (mid+1<=q)
        query(nod*2+1,mid+1,dr);
}

int main()
{
    int i,j,op;
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>v[i];
    build(1,1,n);
    for (i=1;i<=m;i++) {
        f>>op;
        switch(op) {
            case 0:
                f>>p>>q;x=-(1<<30);
                query(1,1,n);
                g<<x<<'\n';
                break;
            case 1:
                f>>p>>x;
                v[p]=x;
                update(1,1,n);
                break;
        }
    }
    return 0;
}
