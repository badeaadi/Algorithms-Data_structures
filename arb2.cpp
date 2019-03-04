#include <fstream>
#include <vector>
#include <cstdio>
#define nmax 100015
using namespace std;
vector <pair <int,pair <int,int > > > v[nmax];
long long dp[nmax];
int n,ha[nmax],add[nmax];

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
        static const int SIZE=1<<20;
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
instream f("arb2.in");
ofstream g("arb2.out");

void dfsadd(int x,int p,int t)
{
    int i,y,d,c,q=0;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i].first;
        if (y!=t) {
            c=v[x][i].second.second;
            dfsadd(y,c,x);
            q+=add[y];
        }
    }
    if (q)
        add[x]=min(p,q);
    else
        add[x]=p;
}
void dfssolve(int x,int h,int t)
{
    int i,y,d;
    ha[x]=h;

    for (i=0;i<v[x].size();i++) {
        y=v[x][i].first;
        if (y!=t) {
            d=v[x][i].second.first;
            dfssolve(y,h+d,x);
            ha[x]=max(ha[x],ha[y]);
        }
    }
    for (i=0;i<v[x].size();i++) {
        y=v[x][i].first;
        if (y!=t)
            dp[x]+=dp[y]+1LL*(ha[x]-ha[y])*add[y];
    }
}

int main()
{
    int i,j,x,y,d,c;
    f>>n;
    for (i=1;i<n;i++) {
        f>>x>>y>>d>>c;
        v[x].push_back(make_pair(y,make_pair(d,c)));
        v[y].push_back(make_pair(x,make_pair(c,d)));
    }
    dfsadd(1,1<<29,0);
    dfssolve(1,0,0);
    g<<dp[1]<<'\n';
    return 0;
}
