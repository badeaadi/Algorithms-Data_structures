#include <cstdio>
#include <fstream>
#define nmax 100005
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
instream f("soparla.in");

int n,m,q,a[nmax],b[nmax];
int k[nmax];
long long s[nmax];
int p,t;

int main()
{
    int i,j;
    f>>n>>m>>q;
    for (i=1;i<=m;i++) {
        f>>a[i]>>b[i];
    }
    for (i=1;i<=q;i++) {
        f>>p>>t;
        k[p]++;
        k[t+1]--;
    }
    for (i=1;i<=m;i++) {
        k[i]+=k[i-1];
        s[a[i]]+=1LL*k[i];
        s[b[i]+1]-=1LL*k[i];
    }
    ofstream g("soparla.out");
    for (i=1;i<=n;i++) {
        s[i]+=1LL*s[i-1];
        g<<s[i]<<'\n';
    }
    return 0;
}
