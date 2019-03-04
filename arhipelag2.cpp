#include <fstream>
#define nmax 1005
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
        static const int SIZE=1<<16;
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
instream f("arhipelag2.in");
ofstream g("arhipelag2.out");
int n,m;
short v[nmax][nmax];
short r[nmax[[nmax];

int main()
{
    int i,j,p,q;
    f>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            f>>v[i][j];
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++)
            if (r[i][j]==1) {
                p=i;
                while (v[p+1][j]==0) {}

            }
        p=i;
        while
    }
    for (i=1;i<=n;i++) {
        st=1;
    }

    return 0;
}
