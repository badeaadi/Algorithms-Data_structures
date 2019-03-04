#include <cstdio>
#include <bitset>
#include <cmath>
#include <vector>
#include <fstream>
#define nmax 100025
#define sqrnmax 320
using namespace std;

class inreader {
    public:
        inreader() {}
        inreader(const char *file_name) {
            input_file = fopen(file_name, "r");
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
        inline inreader &operator >>(int &n) {
            while(buffer[cursor] < '0' || buffer[cursor] > '9') {
                advance();
            }
            n = 0;
            while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
                n = n * 10 + buffer[cursor] - '0';
                advance();
            }
            return *this;
        }
    private:
        FILE *input_file;
        static const int SIZE = 1 << 16;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor == SIZE) {
                cursor = 0;
                fread(buffer, SIZE, 1, input_file);
            }
        }
};
inreader f("arbore.in");
ofstream g("arbore.out");

bitset <nmax*10> q[sqrnmax];
bitset <nmax> viz;
vector <int> v[nmax];
int n,m,s,p[nmax],np,nrs;
int st[nmax],dr[nmax];
int k[nmax],sec[nmax];



void remake(int a,int b,int x,int y)
{
    int i;
    for (i=x;i<=y;i++)
        q[a][k[i]]=0;

    for (i=x;i<=y;i++)
        k[i]+=b;
    for (i=(a-1)*s+1;i<=a*s;i++)
        if (i<=n)
            q[a][k[i]]=1;

}
void updatearb()
{
    int i,j,a,b,x,y;
    f>>a;f>>b;
    x=(st[a]-1)/s+1;
    y=(dr[a]-1)/s+1;
    remake(x,b,st[a],min(x*s,dr[a]));
    if (x!=y)
        remake(y,b,max((y-1)*s+1,st[a]),dr[a]);

    for (i=x+1;i<y;i++)
        sec[i]+=b;
}
void queryarb()
{
    int i,j,a,x;
    f>>a;
    for (i=1;i<=nrs;i++) {
        x=a-sec[i];
        if (x>=0&&q[i][x]==1)

            for (j=(i-1)*s+1;j<=i*s;j++)

                if (j<=n&&k[j]==x) {
                    g<<p[j]<<'\n';
                    return;
                }

    }
    g<<-1<<'\n';
}
void dfs(int nod)
{
    viz[nod]=1;
    p[++np]=nod;
    st[nod]=np;
    int i,j;
    for (i=0;i<v[nod].size();i++) {
        j=v[nod][i];
        if (viz[j]==0)
            dfs(j);
    }
    dr[nod]=np;
}
int main()
{
    f>>n>>m;
    s=ceil(sqrt(double(n)));
    nrs=n/s;
    if (n%s!=0)
        nrs++;
    int i,j,a,b,o;
    for (i=1;i<=n-1;i++) {
        f>>a;f>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for (i=1;i<=nrs;i++)
        q[i][0]=1;
    for (i=1;i<=m;i++) {
        f>>o;
        if (o==1)
            updatearb();
        else
            queryarb();
    }

    return 0;
}
