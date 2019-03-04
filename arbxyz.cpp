#include <cstdio>
#include <fstream>
#include <vector>
#define nmax 100005
using namespace std;
vector <int> v[nmax];
int p[nmax][3],val[3];
int n,t[nmax];
int s[nmax],sol;


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
instream f("arbxyz.in");
ofstream g("arbxyz.out");

void dfs(int a)
{
    if (sol)
        return;
    int i,j,k,b;
    s[a]=1;t[a]=1;
    for (i=0;i<v[a].size();i++) {
        b=v[a][i];
        if (!t[b]) {
            dfs(b);
            s[a]+=s[b];
            for (j=0;j<3;j++)
                p[a][j]|=p[b][j];
        }
    }
    for (j=0;j<3;j++)
        if (s[a]==val[j])
            p[a][j]=1;


    b=n-s[a];
    if (p[a][0]&&(b==val[1]||b==val[2]))
        sol=1;
    if (p[a][1]&&(b==val[0]||b==val[1]))
        sol=1;
    if (p[a][2]&&(b==val[0]||b==val[1]))
        sol=1;
}
void solvetest()
{
    int i,a,b;
    f>>n>>val[0]>>val[1]>>val[2];
    for (i=1;i<n;i++) {
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    sol=0;
    dfs(1);
    for (i=1;i<=n;i++) {
        s[i]=t[i]=0;
        p[i][0]=p[i][1]=p[i][2]=0;
    }
    if (!sol)
        dfs(2);
    for (i=1;i<=n;i++) {
        s[i]=t[i]=0;
        p[i][0]=p[i][1]=p[i][2]=0;
        v[i].clear();
    }
    g<<sol<<'\n';
}

int main()
{
    int t;
    for (f>>t;t;t--)
        solvetest();

    return 0;
}
