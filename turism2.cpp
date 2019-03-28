#include <cstdio>
#include <fstream>
#include <vector>
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
            while(buffer[cursor]<'0'||buffer[cursor]>'9')
                advance();
            n=0;
            while('0'<=buffer[cursor]&&buffer[cursor]<='9') {
                n=n*10+buffer[cursor]-'0';
                advance();
            }
            return *this;
        }
    private:
        FILE *input_file;
        static const int SIZE=1<<18;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            if(++cursor==SIZE) {
                cursor=0;
                fread(buffer,SIZE,1,input_file);
            }
        }
};
instream f("turism2.in");
ofstream g("turism2.out");
int s[nmax],d1[nmax],d2[nmax];
int c[nmax];



void solvetest()
{
    int i,a,n;
    f>>n;
    for (i=1;i<=n;i++)
        f>>c[i];
    for (i=1;i<n;i++) {
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }




}
int main()
{
    for (int t=12;t;t--)
        solvetest();

    return 0;
}
