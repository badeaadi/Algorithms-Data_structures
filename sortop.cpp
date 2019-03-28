#include <cstdio>
#include <vector>
#include <fstream>
#include <bitset>
#include <cstring>
#include <ctime>
#include <algorithm>
#define nmax 100005
using namespace std;
bitset <nmax> uz;
vector <int> v[nmax],t[nmax];
int n,m,k,p[nmax],niv[nmax];
int q[nmax],done[nmax];
int sol[nmax];


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
instream f("sortop.in");
ofstream g("sortop.out");



void dfs(int x)
{
    int i,y;
    uz[x]=1;
    q[niv[x]]++;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (uz[y]==0) {
            niv[y]=niv[x]+1;
            dfs(y);
        }
    }
}
int ver(int i)
{
    int j;
    for (j=1;j<=n;j++)
        q[j]+=q[j-1];
    for (j=1;j<=n;j++)
        if (p[j]) {
            if (niv[j])
                if (!(q[niv[j]-1]<p[j]))
                    return 0;
            if (!(p[j]<=q[niv[j]]))
                return 0;
        }
    return 1;
}
int main()
{
    int i,j,o,x,y;
    f>>n>>k;
    for (i=1;i<n;i++) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1;i<=k;i++) {
        f>>x>>y;
        p[x]=y;
        sol[y]=x;
    }
    srand(time(0));
    x=0;
    while(1) {
        i=(1LL*rand()*rand())%n+1;
        while (done[i]==1) {
            if (++i>n)
                i=1;
        }
        memset(niv,0,sizeof(niv));
        memset(q,0,sizeof(q));
        uz.reset();
        dfs(i);
        done[i]=1;
        if (ver(i)) {

            m=1;
            for (i=1;i<=n;i++)
                t[niv[i]].push_back(i);

            for (i=0;i<=n;i++) {
                for (j=0;j<t[i].size();j++) {
                    o=t[i][j];
                    if (p[o]==0) {
                        while (sol[m])
                            m++;
                        sol[m]=o;
                    }
                }


            }
            for (i=1;i<=n;i++)
                g<<sol[i]<<' ';
            return 0;
        }
        if (++x==n) {
            g<<-1<<'\n';
            return 0;
        }
    }
    return 0;
}
