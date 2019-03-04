#include <cstdio>
#include <algorithm>
#include <cmath>
#define mie 1000
#define nmax 505
#define inf 2000000000
using namespace std;
int n,m,k,p,nr;
int sol,tot,maxim,q,qnr;
int x[nmax],y[nmax];

struct num{int v;
long long t;} v[nmax*nmax];

void first()
{
    printf("%d\n%d\n",qnr,sol);
}
bool sortcomp(const num &a,const num &b)
{
    return a.t<b.t;
}

void second()
{
    int i,j,l,c;
    for (i=1;i<=n;i++) {
        x[i]=10000;
        y[i]=-1000;}
    for (i=1;i<=qnr;i++) {
            l=(v[i].t/mie)%mie;
            c=v[i].t%mie;

            if (c<x[l]) x[l]=c;
            if (c>y[l]) y[l]=c;
        }
    for (i=1;i<=n;i++)
        if (x[i]!=10000) {
            maxim=max(maxim,abs(x[i]-y[i]));
            for (j=i+1;j<=n;j++)
                if (x[j]!=10000) {
                    maxim=max(maxim,abs(i-j)+abs(x[i]-y[j]));
                    maxim=max(maxim,abs(i-j)+abs(x[j]-y[i]));
                }
        }
    printf("%d",maxim);
}

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
            n=0;
            while('0'<=buffer[cursor]&&buffer[cursor]<='9') {
                n=n*10+buffer[cursor]-'0';
                advance();
            }
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
    instream f("rascoala.in");

int main()
{
    int i,j;
    freopen("rascoala.out","w",stdout);
    f>>p>>n>>m>>k;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            f>>v[++nr].v;
            v[nr].t=1LL*v[nr].v*mie*mie+i*mie+j;
        }
    sort(v+1,v+nr+1,sortcomp);
    v[nr+1].v=inf;
    int mijl,st=1,dr=inf;

    while (st<=dr) {
        mijl=(st+dr)>>1;
        tot=k;
        i=1;
        while (v[i].v<mijl&&tot>=0) {
            tot=tot-mijl+v[i].v;
            i++;
        }
        if (tot>=0) {
            sol=mijl;
            st=mijl+1;
        }
        else
            dr=mijl-1;
    }
    q=1;
    while (v[q].v<sol&&k>00) {
        k-=sol-v[q].v;
        v[q++].v=sol;
    }
    qnr=q-1;
    q=1;
    while (v[q].v==sol&&k>0) {
        k--;
        q++;
    }
    if (q-1>qnr)
        qnr=q-1;

    if (p==1)
        first();
    else
        second();

return 0;
}
