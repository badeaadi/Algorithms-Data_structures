#include <cstdio>
#include <fstream>
#define nmax 50005
using namespace std;
int n,v[nmax],k[2][3];

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
instream f("secvente.in");
ofstream g("secvente.out");


int solve()
{
    int n,i,j,x;
    f>>n;
    for (i=0;i<=2;i++)
        k[0][i]=k[1][i]=0;
    for (i=1;i<=n;i++) {
        f>>x;x%=3;
        for (j=0;j<=2;j++)
            if (k[0][j])
                k[1][(j+x)%3]=max(k[1][(j+x)%3],k[0][j]+1);
        for (j=0;j<=2;j++)
            k[0][j]=max(k[0][j],k[1][j]);
        k[0][x%3]=max(k[0][x%3],1);
    }
    return k[0][0];
}
int main()
{
    for (int i=1;i<=3;i++)
        g<<solve()<<'\n';
    return 0;
}
