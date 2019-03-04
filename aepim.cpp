#include <fstream>
#include <cstring>
#define mod 9901
#define nmax 100005
#define kmax 3
using namespace std;
ifstream f("aepim.in");
ofstream g("aepim.out");
int n,m,k,t,a,b,o;
short v[nmax][kmax][kmax];
short aint[nmax*3][kmax][kmax],l[kmax][kmax];
char s[nmax*10];

void prod(short p[][kmax],short q[][kmax])
{
    int w[kmax][kmax]={0};
    int i,j,t;
    for (i=0;i<k;i++)
        for (j=0;j<k;j++)
            for (t=0;t<k;t++) {
                w[i][j]+=1LL*p[i][t]*q[t][j]%mod;
                if (w[i][j]>=mod)
                    w[i][j]-=mod;
            }
    for (i=0;i<k;i++)
        for (j=0;j<k;j++)
            p[i][j]=w[i][j];
}
void query(int nod,int st,int dr)
{
    if (a<=st&&dr<=b) {
        prod(l,aint[nod]);
        return;
    }
    int mid=(st+dr)>>1;
    if (a<=mid)
        query(nod*2,st,mid);
    if (b>=mid)
        query(nod*2+1,mid+1,dr);
}
void update(int nod,int st,int dr,int t)
{
    int i,j;
    if (st==dr) {
        for (i=0;i<k;i++)
            for (j=0;j<k;j++)
                aint[nod][i][j]=v[st][i][j];
        return;
    }
    int mid=(st+dr)>>1;
    if (t<=mid)
        update(nod*2,st,mid,t);
    else
        update(nod*2+1,mid+1,dr,t);

    for (i=0;i<k;i++)
        for (j=0;j<k;j++)
            aint[nod][i][j]=0;
    for (i=0;i<k;i++)
        aint[nod][i][i]=1;
    prod(aint[nod],aint[nod*2]);
    prod(aint[nod],aint[nod*2+1]);
}
void readmatrix(short u[][kmax])
{
    int i,j;
    for (i=0;i<k;i++)
        for (j=0;j<k;j++)
            u[i][j]=s[o++]-'0';
    o++;
}
int main()
{
    int i,j;
    f>>n>>k;f.get();
    f.getline(s,nmax*10);
    for (i=1;i<=n;i++) {
        readmatrix(v[i]);
        update(1,1,n,i);
    }
    memset(s,0,sizeof(s));
    f>>m;
    for (;m;m--) {
        f>>t;
        if (t==1) {
            f>>a>>b;
            for (i=0;i<k;i++)
                for (j=0;j<k;j++)
                    l[i][j]=0;
            for (j=0;j<k;j++)
                l[j][j]=1;
            query(1,1,n);
            for (i=0;i<k;i++)
                for (j=0;j<k;j++)
                    g<<l[i][j]<<' ';
            g<<'\n';
        }
        else {
            f>>a;f.get();
            f.get(s,10);
            o=0;
            for (i=0;i<k;i++)
                for (j=0;j<k;j++)
                    v[a][i][j]=s[o++]-'0';
            update(1,1,n,a);
        }
    }
    return 0;
}
