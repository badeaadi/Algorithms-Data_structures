#include <fstream>
#include <vector>
#include <cstring>
#define nmax 100005
#define mod 666013
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
instream f("arbore4.in");
ofstream g("arbore4.out");

vector <int> v[nmax];
int n,viz[nmax],fact[nmax],inv[nmax];
int w[nmax],s[nmax];

void euclid(int a,int b , long long &x , long long &y)
{

    if (b==0) {
        x=1;
        y=0;
        return;
    }
    long long x0,y0;
    euclid(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
}
int inversmodular(int k)
{
    long long x,y;
    euclid(k,mod,x,y);
    return 1LL*(x%mod+mod)%mod;
}
int comb(int n,int k) {

    if (n<k)
        return 0;
    return (1LL*fact[n]%mod*inv[k]%mod*inv[n-k])%mod;

}
void dfs(int x)
{
    int i,y;
    viz[x]=1;
    w[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (viz[y])
            continue;
        dfs(y);
        w[x]+=w[y];
    }
}
void dfssolve(int x)
{
    int i,y,l=w[x]-1;
    viz[x]=1;
    s[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (viz[y])
            continue;
        dfssolve(y);
        s[x]=1LL*s[x]*s[y]%mod*comb(l,w[y])%mod;
        l-=w[y];
    }
}

int main()
{
    int i,a,b;
    f>>n;
    for (i=1;i<n;i++) {
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    fact[0]=1;fact[1]=1;
    inv[0]=1;inv[1]=1;
    for (i=2;i<=n;i++) {
        fact[i]=1LL*fact[i-1]*i%mod;
        inv[i]=inversmodular(fact[i]);
    }
    dfs(1);
    memset(viz,0,sizeof(viz));
    dfssolve(1);
    g<<s[1]<<'\n';
    return 0;
}
