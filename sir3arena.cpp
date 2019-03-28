#include <cstdio>
#include <algorithm>
#define nmax 200005
using namespace std;
int n,s,v[nmax],p[nmax];
long long sum[nmax],su;
int ans,pozfirst,pozlast;

struct ord{int a,b;} a[nmax];

int bsearch(int x)
{
    int sol=0;
    for (int bit=1<<18;bit;bit>>=1)
        if (sol+bit<=n&&x>=a[sol+bit].a)
            sol+=bit;
    if (x!=a[sol].a)
        return 0;
    return sol;
}
bool sortsir(const ord &a,const ord &b)
{
    return a.a<b.a;
}

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
instream f("sir3.in");
FILE *g=fopen("sir3.out","w");

int main()
{

    int i,j;
    f>>n>>s;
    for (i=1;i<=n;i++) {
        f>>v[i];
        a[i].a=v[i];
        a[i].b=i;
    }
    sort(a+1,a+n+1,sortsir);
    for (i=1;i<=n;i++)
        if (!p[i]) {
            p[i]=bsearch(s-v[i]);
            p[i]=a[p[i]].b;
            p[p[i]]=i;
        }
    for (i=1;i<=n;i++)
        sum[i]=sum[i-1]+p[i];
    for (i=1;i<=n;i++) {
        j=p[i];
        if (j==0)
            continue;
        su=1LL*j*(j+1)/2-1LL*(i-1)*i/2;
        if (sum[j]-sum[i-1]==su&&j-i+1>ans) {
                ans=j-i+1;
                pozfirst=i;pozlast=j;
        }
    }
    fprintf(g,"%d %d %d\n",ans,pozfirst,pozlast);
    return 0;
}
