#include <cstdio>
#include <fstream>
#define nmax 2000005
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
        static const int SIZE=1<<20;
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
instream f("raliu.in");
ofstream g("raliu.out");
int n,v[nmax];

int main()
{
    int i,j,t,sol;
    long long s;
    for (f>>t;t;t--) {
        f>>n;
        for (i=1;i<=n;i++)
            f>>v[i];
        for (i=1;i<=n;i++) {
            f>>j;
            v[i]-=j;
            v[i+n]=v[i];
        }
        sol=0;
        s=-1;

        for (i=1;i<=2*n;i++) {
            if (s<0) {
                s=v[i];
                j=i;
            }
            else
                s+=v[i];
            if (s>=0&&i-j+1>=n) {
                sol=j;
                break;
            }
        }
        sol==0?g<<"NU\n":g<<"DA\n"<<sol<<'\n';
    }
    return 0;
}
