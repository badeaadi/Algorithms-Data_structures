#include <fstream>
#include <fstream>
#define nmax 500005
using namespace std;
int v[nmax],k[nmax],p[256];
int n,a,b,c;
int base;
long long basemax;


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
instream f("algsort.in");
ofstream g("algsort.out");

inline int cif(int r)
{
    return ((r>>(8*base))&255);
}

int main()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++)
        f>>v[i];
    basemax=4;
    base=0;
    while (base<basemax) {

        for (i=0;i<=255;i++)
            p[i]=0;

        for (i=1;i<=n;i++)
            p[cif(v[i])]++;

        for (i=1;i<=255;i++)
            p[i]+=p[i-1];

        for (i=n;i>=1;i--)
            k[p[cif(v[i])]--]=v[i];

        for (i=1;i<=n;i++)
            v[i]=k[i];

        base++;
    }

    for (i=1;i<=n;i++)
        g<<v[i]<<' ';

    return 0;
}
