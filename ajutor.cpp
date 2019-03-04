#include <fstream>
#include <algorithm>
#include <set>
#define nmax 405
#define distmax 32005
using namespace std;

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
instream f("ajutor.in");
ofstream g("ajutor.out");

struct punct{int x,y;} v[nmax],t;
set <int> s;
set <int> :: iterator it;
int l[nmax][nmax],l1[nmax][nmax],l2[nmax][nmax],l3[nmax][nmax],l4[nmax][nmax];
int a[nmax],b[nmax],va[distmax],vb[distmax];;
int n,m,p,q,x,y,xp,yp,sol;

inline int boolcomp(const punct &a,const punct &b)
{
    return (a.x==b.x?a.y<b.y:a.x<b.x);
}

inline int modul(int a)
{
    return (a<0?-a:a);
}
void dp(int xe,int ye)
{
    if (xe>=1&&xe<=p&&ye>=1&&ye<=q)
        sol=min(sol,l[xe][ye]+modul(x-a[xe])+modul(y-b[ye]));
}
int main()
{
    int i,j,k;
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>v[i].x>>v[i].y;

    for (i=1;i<=n;i++)
        s.insert(v[i].x);
    for (it=s.begin();it!=s.end();it++)
        a[++p]=*it;
    s.clear();
    for (i=1;i<=n;i++)
        s.insert(v[i].y);
    for (it=s.begin();it!=s.end();it++)
        b[++q]=*it;

    for (i=0;i<=p+1;i++)
        for (j=0;j<=q+1;j++)
            l1[i][j]=l2[i][j]=l3[i][j]=l4[i][j]=1<<20;

    sort(v+1,v+n+1,boolcomp);
    for (i=1;i<=p;i++) {
        k=1;
        t.x=a[i];
        for (j=1;j<=q;j++) {
            t.y=b[j];
            while (k<=n&&(v[k].x<t.x||(v[k].x==t.x&&v[k].y<t.y)))
                k++;
            if (v[k].x==t.x&&v[k].y==t.y) {
                l1[i][j]=0;l2[i][j]=0;l3[i][j]=0;l4[i][j]=0;
            }
            l1[i][j]=min(l1[i][j],min(l1[i-1][j]+modul(a[i]-a[i-1]),l1[i][j-1]+modul(b[j]-b[j-1])));
        }
    }
    for (i=1;i<=p;i++) {
        k=1;
        for (j=q;j>=1;j--)
            l2[i][j]=min(l2[i][j],min(l2[i-1][j]+modul(a[i]-a[i-1]),l2[i][j+1]+modul(b[j]-b[j+1])));
    }
    for (i=p;i>=1;i--) {
        k=1;
        for (j=1;j<=q;j++)
            l3[i][j]=min(l3[i][j],min(l3[i+1][j]+modul(a[i]-a[i+1]),l3[i][j-1]+modul(b[j]-b[j-1])));
    }
    for (i=p;i>=1;i--) {
        k=1;
        for (j=q;j>=1;j--)
            l4[i][j]=min(l4[i][j],min(l4[i+1][j]+modul(a[i]-a[i+1]),l4[i][j+1]+modul(b[j]-b[j+1])));
    }
    for (i=1;i<=p;i++)
        for (j=1;j<=q;j++)
            l[i][j]=min(min(l1[i][j],l2[i][j]),min(l3[i][j],l4[i][j]));

    for (i=1;i<=p;i++)
        va[a[i]]=i;
    va[0]=1;
    for (i=1;i<distmax;i++)
        if (va[i]==0)
            va[i]=va[i-1];

    for (i=1;i<=q;i++)
        vb[b[i]]=i;
    vb[0]=1;
    for (i=1;i<distmax;i++)
        if (vb[i]==0)
            vb[i]=vb[i-1];

    for (;m;m--) {
        sol=1<<20;
        f>>x>>y;
        xp=va[x];
        yp=vb[y];
        for (i=0;i<=1;i++)
            for (j=0;j<=1;j++)
                dp(xp+i,yp+j);
        g<<sol<<'\n';
    }
    return 0;
}
