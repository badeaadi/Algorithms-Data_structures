#include <fstream>
#include <cstdio>
#include <cstring>
#include <vector>
#define nmax 100005
#define mmax 200010
#define inf 1<<30
using namespace std;
vector <int > v[nmax];
vector <int> ::iterator it;
long long d[nmax];
int n,m,x[mmax],y[mmax],z[mmax],t[mmax];
int h[nmax],poz[nmax],k;
int sol[mmax],nrsol;

class instream {
    public:
        instream() {}
        instream(const char *file_name) {
            input_file=fopen(file_name,"r");
            cursor=0;
            fread(buffer,SIZE,1,input_file);
        }
        inline instream &operator >>(int &n) {
            while((buffer[cursor]<'0'||buffer[cursor]>'9')&&buffer[cursor]!='-') {
                advance();
            }
            int semn=1;
            if (buffer[cursor]=='-')
                semn=-1,advance();
            n=0;
            while('0'<=buffer[cursor]&&buffer[cursor]<='9') {
                n=n*10+buffer[cursor]-'0';
                advance();
            }
            n*=semn;
            return *this;
        }
    private:
        FILE *input_file;
        static const int SIZE=1<<15;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor==SIZE) {
                cursor=0;
                fread(buffer,SIZE,1,input_file);
            }
        }
};
instream f("algoritm.in");
ofstream g("algoritm.out");



void upheap(int node)
{
    while (node>1&&d[h[node/2]]>d[h[node]])
    {
        swap(poz[h[node]],poz[h[node/2]]);
        swap(h[node],h[node/2]);
        node=node/2;
    }
}
void downheap(int node)
{
    int son;
    while (node<=k)
    {
        son=node;
        if (node*2<=k)
        {
            son=node<<1;
            if (son+1<=k&&d[h[son+1]]<d[h[son]])
                son++;
        }
        else
            return;
        if (d[h[node]]>d[h[son]])
        {
            swap(poz[h[node]],poz[h[son]]);
            swap(h[node],h[son]);
            node=son;
        }
        else
            return;
    }
}
void solve()
{
    int i,j,r,nod;
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x[i]>>y[i]>>z[i];
        v[x[i]].push_back(i);
    }
    for (i=2;i<=n;++i) {
        d[i]=inf;
        poz[i]=-1;
    }
    poz[1]=1;
    h[++k]=1;

    while (k)
    {
        nod=h[1];
        swap(poz[h[1]],poz[h[k]]);
        swap(h[1],h[k]);
        poz[h[k]]=0;
        h[k]=0;
        --k;
        downheap(1);
        for (it=v[nod].begin();it!=v[nod].end();it++) {
            r=*it;
            if (d[y[r]]>d[x[r]]+z[r]) {
                d[y[r]]=d[x[r]]+z[r];
                if (poz[y[r]]!=-1)
                    upheap(poz[y[r]]);
                else {
                    h[++k]=y[r];
                    poz[h[k]]=k;
                    upheap(k);
                }
            }
            sol[++nrsol]=r;
            t[r]=1;
        }
    }
    for (i=1;i<=m;i++)
        if (!t[i])
            sol[++nrsol]=i;
    for (i=1;i<=m;i++)
        g<<sol[i]<<' ';
    g<<'\n';

    n=0;m=0;k=0;nrsol=0;
    for (i=0;i<nmax;i++)
        v[i].clear();
    memset(d,0,sizeof(d));
    memset(h,0,sizeof(h));
    memset(poz,0,sizeof(poz));
    memset(x,0,sizeof(x));memset(y,0,sizeof(y));
    memset(z,0,sizeof(z));memset(t,0,sizeof(t));
    memset(sol,0,sizeof(sol));
}
int main()
{
    int t;
    f>>t;
    while (t) {
        t--;
        solve();
    }
    return 0;
}
