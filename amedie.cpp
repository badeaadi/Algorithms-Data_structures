#include <fstream>
#include <cstdio>
#include <algorithm>
#define nmax 640005
#define mmax 805
using namespace std;
int n,m,q,l,amedie;
int val[mmax][mmax],r[mmax][mmax],poz[mmax][mmax];
int st,dr;

struct num{int x;int l;int c;} v[nmax];

bool sortnum(const num &a,const num &b)
{
    return a.x<b.x;
}
void erasing(int val)
{
    if (l%2==0&&val<=amedie) {
            amedie++;
            while (r[v[amedie].l][v[amedie].c])
                amedie++;
        }
    if (l%2==1&&val>=amedie) {
            amedie--;
            while (r[v[amedie].l][v[amedie].c])
                amedie--;
        }
    l--;
}
class instream {
    public:
        instream() {}
        instream(const char *file_name) {
            input_file=fopen(file_name,"r");
            cursor=0;
            fread(buffer,SIZE,1,input_file);
        }
        inline instream &operator >>(int &n) {
            while((buffer[cursor]<'0'||buffer[cursor]>'9')&&buffer[cursor]!='L'&&buffer[cursor]!='R') {
                advance();
            }
            if (buffer[cursor]=='L'&&buffer[cursor]=='R') {
                n=buffer[cursor];
                return *this;
            }
            n=0;
            while('0'<=buffer[cursor]&&buffer[cursor]<='9') {
                n=n*10+buffer[cursor]-'0';
                advance();
            }
            return *this;
        }
        inline instream &operator >>(char &n) {
            while(!((buffer[cursor]>='0'&&buffer[cursor]<='9')||buffer[cursor]=='L'||buffer[cursor]=='Q'||buffer[cursor]=='C')) {
                advance();
            }
            if (buffer[cursor]=='L'||buffer[cursor]=='Q'||buffer[cursor]=='C') {
                n=buffer[cursor];
                advance();
                return *this;
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
    instream f("amedie.in");
    ofstream g("amedie.out");

int main()
{
    int i,j,k,p;
    char chr;
    f>>n>>m>>q;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            f>>v[++l].x;
            val[i][j]=v[l].x;
            v[l].l=i;v[l].c=j;
            poz[i][j]=l;
        }
    sort(v+1,v+l+1,sortnum);
    amedie=l/2+l%2;

    for (k=1;k<=q;k++) {
        f>>chr;
        if (chr=='L') {
            f>>p;
            for (j=1;j<=m;j++)
                if (!r[p][j]){
                    r[p][j]=1;
                    erasing(poz[p][j]);
                }
            }
    else
        if (chr=='C') {
            f>>p;
            for (i=1;i<=n;i++)
                if (!r[i][p]) {
                    r[i][p]=1;
                    erasing(poz[i][p]);
                }
            }
    else
        g<<v[amedie].x<<'\n';
    }
    return 0;
}
