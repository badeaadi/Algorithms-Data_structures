#include <cstdio>
#include <algorithm>
#include <fstream>
#define nmax 10005
#define mmax 100005
using namespace std;
int n,m,q,sol,ans,s,r,nrk;
struct muchie{int x;int y;int c;};
muchie p[mmax],k[nmax];

bool compmuchie(const muchie &a,const muchie &b)
{
    return a.c<b.c;
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
        static const int SIZE=1<<18;
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
instream f("apm2.in");
ofstream g("apm2.out");

int t[nmax];
void unite(int x,int y)
{
    if (t[x]<t[y]) {
        t[x]+=t[y];
        t[y]=x;
    }
    else {
        t[y]+=t[x];
        t[x]=y;
    }
}
int father(int x)
{
    int y=x,aux;
    while (t[x]>=0)
        x=t[x];
    while (t[y]>=0) {
        aux=t[y];
        t[y]=x;
        y=aux;
    }
    return x;
}
int kruskalgraf()
{
    int i,t1,t2;
    r=n;s=0;
    for (int i=1;i<=m;i++) {
        t1=father(p[i].x);
        t2=father(p[i].y);
        if (t1!=t2) {
            k[++nrk]=p[i];
            s+=p[i].c;
            unite(t1,t2);
            if (--r==1)
                return s;
        }
    }
    return s;
}
int kruskalapm()
{
    int i,t1,t2;
    r=n;s=0;
    for (int i=1;i<n;i++) {
        t1=father(k[i].x);
        t2=father(k[i].y);
        if (t1!=t2) {
            s+=k[i].c;
            unite(t1,t2);
            if (--r==1)
                return s;
        }
    }
    return s;
}

int main()
{
    int i,j,x,y;
    f>>n>>m>>q;
    for (i=1;i<=m;i++)
        f>>p[i].x>>p[i].y>>p[i].c;
    sort(p+1,p+m+1,compmuchie);
    for (i=1;i<=n;i++)
        t[i]=-1;
    sol=kruskalgraf();
    for (;q;q--) {
        for (i=1;i<=n;i++)
            t[i]=-1;
        f>>x>>y;
        unite(x,y);
        ans=sol-kruskalapm()-1;
        g<<(ans>=0?ans:0)<<'\n';
    }
    return 0;
}
