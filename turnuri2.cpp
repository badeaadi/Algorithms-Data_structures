#include <cstdio>
#include <algorithm>
#include <stack>
#define nmax 1000005
using namespace std;
int n,h[nmax],k[nmax];
int a[nmax],b[nmax];
int poz[nmax];


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
instream f("turnuri2.in");

int main()
{
    freopen("turnuri2.out","w",stdout);
    f>>n;
    int i,j;
    for (i=1;i<=n;i++)
        f>>h[i]>>k[i];
    for (i=1;i<=n;i++) {
        a[i]=k[i];
        for (j=i-1;j>0;j=poz[j]) {
            if (h[j]>h[i])
                break;
            a[i]=max(a[i],a[j]);
        }
        a[i]=max(a[i],k[j]);
        poz[i]=j ;
    }
    for (i=n;i>=1;i--) {
        b[i]=k[i];
        for (j=i+1;j<=n;j=poz[j]) {
            if (h[j]>h[i])
                break;
            b[i]=max(b[i],b[j]);
        }
        b[i]=max(b[i],k[j]);
        poz[i]=j;
    }
    for (i=1;i<=n;i++)
        printf("%d\n",max(a[i],b[i]));
    return 0;
}
