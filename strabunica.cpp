#include <cstdio>
#include <fstream>
#define nmax 200005
using namespace std;
int n,v[nmax],poz;
int sth[nmax],stk[nmax],nr;
long long arie,ar;

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
    instream f("strabunica.in");
    ofstream g("strabunica.out");



int main()
{
    int i;
    f>>n;
    for (i=1;i<=n;i++)
        f>>v[i];
    for (i=1;i<=n+1;i++) {
        if (v[i]>sth[nr]) {
            nr++;
            sth[nr]=v[i];
            stk[nr]=i;
        }
        else {
            while (nr>0&&v[i]<=sth[nr]) {
                ar=1LL*(1LL*i-stk[nr])*1LL*sth[nr];
                if (ar>arie)
                    arie=ar;
                poz=stk[nr];
                nr--;
            }
            if (v[i]>0) {
                nr++;
                sth[nr]=v[i];
                stk[nr]=poz;
            }
        }
    }
    g<<arie<<'\n';
    return 0;
}
