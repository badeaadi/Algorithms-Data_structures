#include <cstdio>
#include <vector>
#include <fstream>
#include <cstring>
#include <queue>
#include <bitset>
#define nmax 255
using namespace std;
const int dl[4]={0,0,1,-1};
const int dc[4]={1,-1,0,0};

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
instream f("unlock.in");
ofstream g("unlock.out");
queue <int> q;
bitset <nmax*nmax> in;
vector <pair<int,int> > p[nmax*nmax];
int n,m,k,v[nmax][nmax];
int t[nmax][nmax],compacc;
int z[nmax*nmax];


void filling(int i,int j)
{
    int l,c;
    for (int d=0;d<4;d++) {
        l=i+dl[d];
        c=j+dc[d];
        if (l<1|l>n||c<1||c>m)
            continue;
        if (v[i][j]==v[l][c]&&t[l][c]==0) {
            t[l][c]=t[i][j];
            filling(l,c);
        }
    }
}

void tieup(int x,int y)
{
    if (in[x]==0) {
        q.push(x);
        in[x]=1;
    }
    if (in[y]==0) {
        q.push(y);
        in[y]=1;
    }
    if (z[x]<z[y]) {
        z[x]+=z[y];
        z[y]=x;
    }
    else {
        z[y]+=z[x];
        z[x]=y;
    }
}
int father(int x)
{
    while (z[x]>=0)
        x=z[x];
    return x;
}
int compact=0,compram;
void fillingcoloured(int i,int j)
{
    int l,c,fath;
    for (int d=0;d<4;d++) {
        l=i+dl[d];
        c=j+dc[d];
        if (l<1|l>n||c<1||c>m)
            continue;
        if (v[i][j]==v[l][c]&&t[l][c]==0) {
            t[l][c]=t[i][j];
            fillingcoloured(l,c);
        }
        if (v[l][c]==0) {
            if (compact==0)
                compact=father(t[l][c]);
            else {
                compact=father(compact);
                fath=father(t[l][c]);
                if (fath!=compact) {
                    tieup(compact,father(t[l][c]));
                    compram--;
                }
            }
        }
    }
}
int solvecolour(int c)
{
    int a,i,j;
    compact=0;compram=compacc;
    for (a=0;a<p[c].size();a++) {
        i=p[c][a].first;
        j=p[c][a].second;
        if (t[i][j]==0) {
            t[i][j]=-1;
            fillingcoloured(i,j);
        }
    }
    while (!q.empty()) {
        z[q.front()]=-1;
        in[q.front()]=0;
        q.pop();
    }
    if (compram==1)
        return 1;
    return 0;
}
void solvetest()
{
    f>>n>>m>>k;
    int i,j,l,sol=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            f>>v[i][j];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (v[i][j]==0&&t[i][j]==0) {
                t[i][j]=++compacc;
                z[compacc]=-1;
                filling(i,j);
            }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (v[i][j])
                p[v[i][j]].push_back(make_pair(i,j));
    for (l=1;l<=k;l++) {
        sol+=solvecolour(l);
        p[l].clear();
    }
    g<<sol<<'\n';
    memset(v,0,sizeof(v));
    memset(z,0,sizeof(z));
    memset(t,0,sizeof(t));
    compacc=0;
}
int main()
{
    int t;
    for (f>>t;t;t--)
        solvetest();
    return 0;
}
