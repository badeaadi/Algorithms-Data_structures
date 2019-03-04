#include <fstream>
#include <cstdio>
#include <algorithm>
#define nmax 100005
using namespace std;
struct query{int q;int p;} l[nmax],v[nmax];
int n,q,k,t[nmax],s[nmax];

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
instream f("secvmax.in");
ofstream g("secvmax.out");

int sortcomp(const query &a,const query &b)
{
    return (a.q<b.q);
}
int tata(int x)
{
    int y=x,z;
    while (t[x]>=0)
        x=t[x];
    while (t[y]>=0) {
        z=t[y];
        t[y]=x;
        y=z;
    }
    return x;
}
void tieup(int x,int y)
{
    if (t[x]>t[y])
        swap(x,y);
    t[x]+=t[y];
    t[y]=x;
}
void addit(int p)
{
    int i;
    t[p]=-1;
    if (p>1&&t[p-1])
        tieup(tata(p-1),tata(p));
    if (p<n&&t[p+1])
        tieup(tata(p+1),tata(p));
    k=max(k,-t[tata(p)]);
}
int main()
{
    int i,j;
    f>>n>>q;
    for (i=1;i<=n;i++) {
        f>>v[i].q;
        v[i].p=i;
    }
    for (i=1;i<=q;i++) {
        f>>l[i].q;
        l[i].p=i;
    }
    sort(v+1,v+n+1,sortcomp);
    sort(l+1,l+q+1,sortcomp);
    for (i=1,j=1;j<=q;j++) {
        while (i<=n&&l[j].q>=v[i].q)
            addit(v[i++].p);
        s[l[j].p]=k;
    }
    for (i=1;i<=q;i++)
        g<<s[i]<<'\n';

    return 0;
}
