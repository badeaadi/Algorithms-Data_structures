#include <fstream>
#include <algorithm>
#define mod 1000000007
#define cmax 500005
using namespace std;
ofstream g("vagoane.out");
long long ans=1;
int fact[cmax],put[cmax],n,m,c,c1;
struct caine{int st;int dr;};
caine v[cmax];

class InputReader {
    public:
        InputReader() {}
        InputReader(const char *file_name) {
            input_file = fopen(file_name, "r");
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
        inline InputReader &operator >>(int &n) {
            while(buffer[cursor] < '0' || buffer[cursor] > '9') {
                advance();
            }
            n = 0;
            while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
                n = n * 10 + buffer[cursor] - '0';
                advance();
            }
            return *this;
        }
    private:
        FILE *input_file;
        static const int SIZE = 1 << 17;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor == SIZE) {
                cursor = 0;
                fread(buffer, SIZE, 1, input_file);
            }
        }
};
bool boolcmp(const caine &a,const caine &b)
{
    if (a.dr!=b.dr)
        return a.dr<b.dr;
    return a.st<b.st;
}
void inmulteste(int x)
{
    ans=(1LL*ans*x)%mod;
}
void euclid(int a,int b,long long &x,long long &y)
{
    if (b==0) {
        x=1;
        y=0;
        return;
    }
    else {
        long long x0,y0;
        euclid(b,a%b,x0,y0);
        x=y0;
        y=x0-(1LL*a/b)*1LL*y0;
    }
}
void imparte(int x)
{
    if (x<=1)
        return;

    long long a=0,b=0;
    euclid(x,mod,a,b);
    a=(a+mod)%mod;
    ans=(1LL*ans*a)%mod;
}

int main()
{
    int i,j;
    InputReader cin("vagoane.in");
    cin>>n>>m>>c;
    for (i=1;i<=m;i++)
        cin>>v[i].st>>v[i].dr;

    sort(v+1,v+m+1,boolcmp);
    for (i=1;i<=m;i++)
        if (v[i].dr-v[i].st+1>c) {
            g<<0<<'\n';
            return 0;
        }
    fact[0]=1;
    for (i=1;i<cmax;i++)
        fact[i]=(1LL*fact[i-1]*i)%mod;
    put[0]=1;
    for (i=1;i<cmax;i++)
        put[i]=(1LL*put[i-1]*c)%mod;



    for (i=1;i<=m;i++) {
        if (v[i].dr==v[i-1].dr)
            continue;

        if (v[i].st>v[i-1].dr) {
                inmulteste(fact[c]);
                imparte(fact[c-(v[i].dr-v[i].st+1)]);
                inmulteste(put[v[i].st-v[i-1].dr-1]);
        }
            else {
                c1=c-(v[i-1].dr-v[i].st+1);
                inmulteste(fact[c1]);
                imparte(fact[c1-(v[i].dr-v[i-1].dr)]);
            }
    }
    int prod=0;
    if (m==0)
        prod=n;
    else
        prod=n-v[m].dr;

    while (prod>cmax) {
        inmulteste(put[cmax-1]);
        prod-=cmax-1;
    }
    inmulteste(put[prod]);

    g<<ans<<'\n';
    return 0;
}
