#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#define nmax 1005
#define umax 100005
using namespace std;
char sol[nmax][nmax],v[nmax][nmax],t[umax];
short l1[umax],c1[umax];
short l2[umax],c2[umax];
int n,m,u,q,l,c;

class instream {
    public:
        instream() {}
        instream(const char *file_name) {
            input_file=fopen(file_name,"r");
            cursor=0;
            fread(buffer,SIZE,1,input_file);
        }
        inline instream &operator >>(int &n) {
            while(buffer[cursor]<'0'||buffer[cursor]>'9') {
                advance();
            }
            n=0;
            while('0'<=buffer[cursor]&&buffer[cursor]<='9') {
                n=n*10+buffer[cursor]-'0';
                advance();
            }
            return *this;
        }
        inline instream &operator >>(short &n) {
            while(buffer[cursor]<'0'||buffer[cursor]>'9') {
                advance();
            }
            n=0;
            while('0'<=buffer[cursor]&&buffer[cursor]<='9') {
                n=n*10+buffer[cursor]-'0';
                advance();
            }
            return *this;
        }
        inline instream &operator >>(char &n) {
            while(!(buffer[cursor]>='A'&&buffer[cursor]<='Z')) {
                advance();
            }
            n=buffer[cursor];
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
    instream f("rox.in");
    ofstream g("rox.out");


int main()
{
    int i,j,k;
    f>>n>>m>>u;
    for (i=1;i<=u;i++)
        f>>l1[i]>>c1[i]>>l2[i]>>c2[i]>>t[i];
    for (k=0;k<=25;k++) {
        for (j=1;j<=u;j++)
            if (t[j]==k+'A') {
                v[l1[j]][c1[j]]^=1;
                v[l1[j]][c2[j]+1]^=1;
                v[l2[j]+1][c1[j]]^=1;
                v[l2[j]+1][c2[j]+1]^=1;
            }
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++) {
                v[i][j]^=v[i-1][j]^v[i][j-1]^v[i-1][j-1];
                sol[i][j]+=v[i][j];
            }
        memset(v,0,sizeof(v));
    }
    f>>q;
    for (i=1;i<=q;i++) {
        f>>l>>c;
        g<<int(sol[l][c])<<'\n';
    }
    return 0;
}
