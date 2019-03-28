#include <fstream>
#include <cstdio>
#include <vector>
#define nmax 1005
#define kmax 5
using namespace std;
vector <pair <int,int> > t[kmax*kmax*2*nmax];
int n,m,l0,c0,l1,c1;
int v[nmax][nmax];
int p[nmax][nmax],viz[nmax][nmax];
int dl[8]={-1,-1,0,1,1,1,0,-1};
int dc[8]={0,1,1,1,0,-1,-1,-1};

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
    instream f("taxa.in");
    ofstream g("taxa.out");

int main()
{
    int i,j,d,cost;
    int l0,c0,l1,c1,l,c,lx,cx;
    f>>n>>m>>l0>>c0>>l1>>c1;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            f>>v[i][j];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            p[i][j]=1<<30;
    p[l0][c0]=0;
    t[0].push_back(make_pair(l0,c0));
    for (i=0;!viz[l1][c1];i++)
        for (j=0;j<t[i].size();j++)
            if (viz[t[i][j].first][t[i][j].second]==0) {
                l=t[i][j].first;
                c=t[i][j].second;
                viz[l][c]=1;
                for (d=0;d<8;d++) {
                    cost=p[l][c];
                    lx=l+dl[d];cx=c+dc[d];

                    if (v[lx][cx]!=v[l][c])
                        cost+=v[l][c]*v[lx][cx];
                    if (p[lx][cx]>cost) {
                        p[lx][cx]=cost;
                        t[cost].push_back(make_pair(lx,cx));
                    }
                }
            }
    g<<p[l1][c1];

    return 0;
}
