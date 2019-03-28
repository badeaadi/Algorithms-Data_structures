#include <cstdio>
#include <algorithm>
#include <fstream>
#define nmax 200005
using namespace std;
int n,a,b,c,x;
int sol;

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
        static const int SIZE=1<<12;
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
instream f("suma2.in");
ofstream g("suma2.out");



int main()
{
    f>>n;
    if (n==1) {
        f>>a;
        g<<max(a,0);
        return 0;
    }
    f>>a>>b;
    sol=max(a,b);
    for (int i=3;i<=n;i++) {
        f>>x;
        c=max(x,max(b,a+x));
        sol=max(sol,c);
        a=b;b=c;
    }
    g<<max(sol,0);
}
