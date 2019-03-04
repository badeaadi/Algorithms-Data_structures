#include <cstdio>
#include <algorithm>
#define nmax 100005
using namespace std;
int n,a[nmax],b[nmax];
int lmax,bit=1,pre[nmax];


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
instream f("scmax.in");



int binarys(int val)
{
    int sol=0;
    if ((bit<<1)<=lmax)
        bit<<=1;
    for (int i=bit;i;i>>=1)
        if (sol+i<=lmax&&val>a[b[sol+i]])
            sol+=i;
    return sol+1;
}
void solution(int m)
{
    if (!m)
        return;
    solution(pre[m]);
    printf("%d ",a[m]);
}
int main()
{
    int i,j,poz;
    f>>n;
    for (i=1;i<=n;i++)
        f>>a[i];
    b[1]=1;lmax=1;
    for (i=2;i<=n;i++) {
        poz=binarys(a[i]);
        pre[i]=b[poz-1];
        if (poz>lmax||a[b[poz]]>a[i])
            b[poz]=i;
        lmax=max(lmax,poz);
    }
    freopen("scmax.out","w",stdout);
    printf("%d\n",lmax);
    solution(b[lmax]);
    return 0;
}
