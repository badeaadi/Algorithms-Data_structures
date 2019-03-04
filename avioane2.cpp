#include <cstdio>
#include <fstream>
#include <map>
#include <algorithm>
#define nmax 31005
#define inf 1<<30
using namespace std;

struct avion{int t1,t2,x,y,p;};
avion v[nmax*3];

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
instream f("avioane2.in");
ofstream g("avioane2.out");
int n,m,k;
map <int,int> s[nmax];
map <int,int> :: iterator it;

bool avioncomp(const avion &a,const avion &b)
{
    if (a.t1!=b.t1)
        return a.t1<b.t1;
    return a.t2<b.t2;
}
int main()
{
    int i,j,p,x,y;
    f>>n>>m>>k;
    for (i=1;i<=m;i++)
        f>>v[i].x>>v[i].t1>>v[i].y>>v[i].t2>>v[i].p;

    s[1][0]=0;
    sort(v+1,v+m+1,avioncomp);
    for (i=1;i<=m;i++) {
        x=v[i].x;
        p=inf;
        for (it=s[x].begin();it!=s[x].end();it++) {
            if (it->first<=v[i].t1)
                p=min(p,it->second);
            else
                break;
        }
        if (p!=inf) {
            if (s[v[i].y][v[i].t2])
                s[v[i].y][v[i].t2]=min(s[v[i].y][v[i].t2],p+v[i].p);
            else
                s[v[i].y][v[i].t2]=p+v[i].p;
        }
    }
    for (i=1;i<=k;i++) {
        f>>x>>y;
        p=inf;
        for (it=s[x].begin();it!=s[x].end();it++) {
            if (it->first<=y)
                p=min(p,it->second);
            else
                break;
        }
        if (p!=inf)
            g<<p<<'\n';
        else
            g<<-1<<'\n';
    }
    return 0;
}
