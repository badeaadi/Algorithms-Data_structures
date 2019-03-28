#include <fstream>
#include <cstdio>
#define nmax 1000005
using namespace std;
int n,k,st,dr,v[nmax],sol;

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
instream f("stalpisori.in");
ofstream g("stalpisori.out");

int main()
{
    int i,j;
    f>>n>>k;
    for (i=1;i<=n;i++)
        f>>v[i];
    st=1;dr=k;
    sol=v[dr]-v[1];
    for (i=2;i<=n;i++) {
        if (dr<i)
            i++;
        while (dr<n&&v[dr+1]-v[i]<v[i]-v[st])
            st++,dr++;
        sol=max(sol,max(v[dr]-v[i],v[i]-v[st]));
    }
    g<<sol<<'\n';
    return 0;
}
