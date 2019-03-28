#include <cstdio>
#include <queue>
#include <bitset>
#include <fstream>
#define nmax 1005
#define inf 1<<29
using namespace std;
int n,v[4][nmax][nmax];
short z[nmax][nmax];
int l1,c1,l2,c2;
int k1,k2;
int a,b,c,p;
queue <pair<short,pair<short,short> > > q;
bitset <nmax> in[4][nmax];
const int dl[4]={-1,0,0,1};
const int dc[4]={0,-1,1,0};


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
        static const int SIZE=1<<17;
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
    instream f("vis.in");
    ofstream g("vis.out");

int main()
{
    int i,j,k,i1,j1;
    f>>n>>k1>>k2>>l1>>c1>>l2>>c2;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) {
            f>>k;
            z[i][j]=k;
        }
    for (k=0;k<=3;k++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                v[k][i][j]=inf;

    q.push(make_pair(0,make_pair(1,1)));
    v[0][1][1]=1;
    while (!q.empty()) {
        a=q.front().first;
        b=q.front().second.first;
        c=q.front().second.second;
        q.pop();
        in[a][b][c]=0;

        for (i=0;i<=3;i++) {
            i1=b+dl[i];
            j1=c+dc[i];
            if (i1<1||i1>n||j1<1||j1>n)
                continue;
            p=a;
            if ((a&1)==0&&i1==l1&&j1==c1)
                p+=1;
            if ((a&2)==0&&i1==l2&&j1==c2)
                p+=2;

            if (z[i1][j1]==0||((a&1)!=0&&z[i1][j1]<=k1)||((a&2)!=0&&z[i1][j1]>=k2))
                if (v[p][i1][j1]>v[a][b][c]+1) {
                    v[p][i1][j1]=v[a][b][c]+1;
                    if (!in[p][i1][j1]) {
                        q.push(make_pair(p,make_pair(i1,j1)));
                        in[p][i1][j1]=1;
                    }
                }
        }
    }
    int sol=v[0][n][n];
    for (i=1;i<=3;i++)
        sol=min(sol,v[i][n][n]);
    g<<sol<<'\n';
    return 0;
}
