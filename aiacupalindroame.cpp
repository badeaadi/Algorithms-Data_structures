#include <fstream>
#include <vector>
#include <cstdio>
#define nmax 100005
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
instream f("aiacupalindroame.in");
ofstream g("aiacupalindroame.out");
vector <int> v[nmax];
int n,m,q,d[nmax],l[20][nmax*2];
int lg[nmax],st[nmax];
char s[nmax];

void dfs(int x)
{
    int i,y;
    viz[x]=1;
    l[0][++m]=x;
    st[x]=m;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (viz[y]==0) {
            d[y]=d[x]+1;
            dfs(y);
            l[0][++m]=x;
        }
    }
}
void rmq(int x)
{
    int i,j,x,y;
    for (i=2;i<nmax;i++)
        lg[i]=lg[i/2]+1;
    for (i=1;i<=19;i++)
        for (j=1;j<=m;j++) {
            x=v[i-1][j];
            y=v[i-1][j+(1<<(i-1)]
            if (d[x]<d[y])
                v[i][j]=x;
            else
                v[i][j]=y;
        }
}
int lca(int x,int y)
{
    x=st[x];y=st[y];
    if (x>y)
        swap(x,y);
    int w=lg[y-x+1];
    x=v[w][x];
    y=v[w][y-(1<<w)+1];
    if (d[x]<d[y])
        return x;
    return y;
}
int main()
{
    int i,j;
    f>>n>>q;
    for (i=2;i<=n;i++) {
        f>>t[i];
        v[t[i]].push_back(i);
    }
    dfs(1);
    rmq();
    f.get();
    f.getline(s,nmax);


    return 0;
}
