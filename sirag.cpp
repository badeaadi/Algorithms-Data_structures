#include <cstdio>
#include <fstream>
#include <algorithm>
#define nmax 100005
using namespace std;
int n,p,a[nmax];
long long s[nmax];


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
instream f("sirag.in");
ofstream g("sirag.out");

int binarysearch(long long x)
{
    int i;
    for (i=1;i<=p;i++)
        if (x*(p-i+1)>s[i])
            return -0;
    return 1;
}
int main()
{
    int i,j;
    f>>n>>p;
    for (i=1;i<=n;i++)
        f>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for (i=n;i>=1;i--)
        s[i]=s[i+1]+a[i];
    long long sol=0;
    for (long long i=1LL<<59;i;i>>=1)
        if (sol+i<=s[1]/p+100&&binarysearch(sol+i))
            sol+=i;

    int poz=binarysearch(sol);

    for (poz;a[poz]>sol;poz++);

    g<<sol*p+poz-1+s[poz]-sol*(p-poz+1);

    return 0;
}
