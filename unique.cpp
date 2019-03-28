#include <cstdio>
#include <vector>
#include <fstream>
#define nmax 100005
#define ub(i) i&(-i)
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
            if(++cursor==SIZE) {
                cursor=0;
                fread(buffer,SIZE,1,input_file);
            }
        }
};
instream f("unique.in");
ofstream g("unique.out");
vector <int> v[nmax];
int n,m,aib[nmax],v[nmax],k[nmax];

void solve()
{
    int i,j,t;
    for (i=1;i<=n;i++)
        f>>v[i];
    for (i=1,j=0;i<=n;i++) {
        k[v[i]]++;
        if (k[v[i]]==1)
            aibadd(v[i],1);


    }


}
int main()
{
    int t;
    for (f>>t;t;t--,solve());


    return 0;
}
