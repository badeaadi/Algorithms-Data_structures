#include <fstream>
#include <vector>
#define nmax 17000
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
instream f("razboi.in");
ofstream g("razboi.out");

vector <pair<int,int > > v[nmax];
int t[nmax],t1[nmax],t2[nmax],viz[nmax];
int n,sol,d1[nmax],d2[nmax],k[nmax];

void dfs(int x)
{
    int i,y,d;
    viz[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i].first;
        if (viz[y]==0) {
            t[y]=x;
            dfs(y);
            d=d1[y]+v[x][i].second;
            if (d>d1[x]) {
                d2[x]=d1[x];
                d1[x]=d;
                t1[x]=y;
            }
            else
                if (d>d2[x]) {
                    t1[x]=t2[x];
                    d2[x]=d;
                    t2[x]=y;
                }
        }
    }
}
void dfssolve(int x)
{
    int i,y,d;
    viz[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i].first;
        d=v[x][i].second;
        if (viz[y]==0) {
            if (t1[x]!=y)
                k[y]=max(k[x],d1[x])+d;
            else
                k[y]=max(k[x],d2[x])+d;
            dfssolve(y);
        }
    }
}
void solvetest(int r)
{
    g<<"Testul nr #"<<r<<'\n';
    f>>n;
    int i,a,b,c;
    for (i=1;i<n;i++) {
        f>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    dfs(1);
    for (i=1;i<=n;i++)
        viz[i]=0;
    dfssolve(1);
    for (i=1,sol=1<<30;i<=n;i++) {
        k[i]=max(k[i],d1[i]);
        if (k[i]<sol)
            sol=k[i];
    }
    for (i=1;i<=n;i++)
        if (k[i]==sol)
            g<<i<<'\n';
    for (i=1;i<=n;i++) {
        d1[i]=0;d2[i]=0;
        t1[i]=0;t2[i]=0;
        viz[i]=0;t[i]=0;
        k[i]=0;
        v[i].clear();
    }
}
int main()
{
    int t,p=0;
    for (f>>t;t;t--)
        solvetest(++p);

    return 0;
}
