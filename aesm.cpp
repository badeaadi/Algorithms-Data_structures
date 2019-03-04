#include <fstream>
#define inf 1<<30
#define nmax 100005
using namespace std;
ifstream f("aesm.in");
ofstream g("aesm.out");
int n,m,v[nmax];
int aint[nmax*3],nr[nmax*3];

void update(int nod,int st,int dr,int poz,int on)
{
    if (st==dr) {
        aint[nod]=v[st];
        nr[nod]=on;
        return;
    }
    int mid=(st+dr)>>1;
    update(nod*2,st,mid,poz,on);
    update(nod*2+1,mid+1,dr,poz,on);
    aint[nod]=min(aint[nod*2],aint[nod*2+1]);
    nr[nod]=nr[nod*2]+nr[nod*2+1];
}
void querymin(int nod,int st,int dr)
{
    if (st==dr) {
        aint[nod]=inf;
        nr[nod]=0;
        return;
    }
    int mid=(st+dr)>>1;
    if (aint[nod*2]<=aint[nod*2+1])
        querymin(nod*2,st,mid);
    else
        querymin(nod*2+1,mid+1,dr);
    aint[nod]=min(aint[nod*2],aint[nod*2+1]);
    nr[nod]=nr[nod*2]+nr[nod*2+1];
}
void searchpoz(int nod,int st,int dr,int k,int t)
{
    if (st==dr) {
        v[st]=t;
        aint[nod]=v[st];
        nr[nod]=0;
        return;
    }
    int mid=(st+dr)>>1;
    if (k<=nr[nod*2])
        searchpoz(nod*2,st,mid,k,t);
    else
        searchpoz(nod*2+1,mid+1,dr,k-nr[nod*2],t);

    aint[nod]=min(aint[nod*2],aint[nod*2+1]);
    nr[nod]=nr[nod*2]+nr[nod*2+1];
}
int main()
{
    int i,j,k,t;
    f>>n;
    for (i=1;i<=n;i++) {
        f>>v[i];
        update(1,1,n,i,1);
    }
    f>>m;
    for (i=1;i<=m;i++) {
        f>>j;
        if (j==1)
            querymin(1,1,n);
        else {
            f>>k>>t;
            searchpoz(1,1,n,k-1,t);
        }
    }
    return 0;
}
