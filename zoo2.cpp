#include <fstream>
#include <algorithm>
#include <vector>
#define nmax 16100
#define inf 2000000010
using namespace std;
FILE *f=fopen("zoo.in","r");
FILE *g=fopen("zoo.out","w");
int n,m,a1,b1,a2,b2;
int le,ri;
vector <pair<int,int> > vec;
vector <pair<int,int> > :: iterator p,q;
vector <int> aint[nmax*4];

void build(int nod,int st,int dr)
{
    aint[nod].resize(dr-st+1);
    if (st==dr) {
        aint[nod][0]=vec[st].second;
        return;
    }
    int mid=(st+dr)/2;
    build(nod*2,st,mid);
    build(nod*2+1,mid+1,dr);


    int nst=nod*2,ndr=nod*2+1;
    int lst=mid-st+1,ldr=dr-mid;
    int i=0,j=0,k=0;

    while (i<lst&&j<ldr) {
        if (aint[nst][i]<aint[ndr][j])
            aint[nod][k++]=aint[nst][i++];
        else
            aint[nod][k++]=aint[ndr][j++];
    }
    while (i<lst)
        aint[nod][k++]=aint[nst][i++];
    while (j<ldr)
        aint[nod][k++]=aint[ndr][j++];
}
int query(int nod,int st,int dr)
{
    if (dr<le||st>ri||st>dr)
        return 0;
    if (le<=st&&dr<=ri) {
        return upper_bound(aint[nod].begin(),aint[nod].end(),b2)
            -lower_bound(aint[nod].begin(),aint[nod].end(),b1);
    }
    int mid=(st+dr)>>1;
    return query(nod*2,st,mid)+query(nod*2+1,mid+1,dr);
}
int main()
{
    int i,j;
    fscanf(f,"%d",&n);
    vec.resize(n+1);
    for (i=1;i<=n;i++)
        fscanf(f,"%d %d",&vec[i].first,&vec[i].second);
    sort(vec.begin()+1,vec.end());
    build(1,1,n);
    fscanf(f,"%d",&m);
    for (;m;m--) {
        fscanf(f,"%d%d%d%d",&a1,&b1,&a2,&b2);
        p=lower_bound(vec.begin()+1,vec.end(),make_pair(a1,-inf));
        q=upper_bound(vec.begin()+1,vec.end(),make_pair(a2,inf));q--;
        le=p-vec.begin();
        ri=q-vec.begin();
        fprintf(g,"%d\n",query(1,1,n));
    }

    return 0;
}
