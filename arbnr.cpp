#include <fstream>
#include <vector>
#define nmax 10005
#define mod 9907
#define tmax 42
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
        static const int SIZE=1<<16;
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
instream f("arbnr.in");
ofstream g("arbnr.out");
vector <int> v[nmax];
int n,t,w,k[tmax],e[tmax],ok[tmax],in;
int nr[nmax],dp[nmax],pad[nmax],pi[nmax*2];
char s[tmax][nmax*2];

void dfs(int x)
{
    int i,y;
    s[w][++e[w]]='(';
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        dfs(y);
    }
    s[w][++e[w]]=')';
}
int main()
{
    int i,j,l,q;
    f>>n>>t;
    for (w=1;w<=t;w++) {
        f>>k[w];
        for (j=2;j<=k[w];j++) {
            f>>l;
            v[l].push_back(j);
        }
        dfs(1);
        for (j=1;j<=k[w];j++)
            v[j].clear();
    }
    for (i=1;i<=t;i++)
        if (ok[i]==0) {
            l=0;
            pi[1]=0;
            for (q=2;q<=e[i];q++) {
                while (l&&s[i][l+1]!=s[i][q])
                    l=pi[l];
                if (s[i][l+1]==s[i][q])
                    l++;
                pi[q]=l;
            }
            for (j=1;j<=t;j++)
                if (i!=j&&ok[j]==0&&e[i]<=e[j]) {
                    l=0;
                    for (q=1;q<=e[j];q++) {
                        while (l&&s[i][l+1]!=s[j][q])
                            l=pi[l];
                        if (s[i][l+1]==s[j][q])
                            l++;
                        if (l>=e[i]) {
                            ok[j]=1;
                            l=pi[l];
                        }
                    }
                }
        }
    for (i=1;i<=t;i++)
        if (ok[i]==0)
            nr[k[i]]++;
    dp[0]=1;
    pad[0]=1;
    for (i=1;i<=n;i++) {
        dp[i]=pad[i-1]-nr[i];
        if (dp[i]<0)
            dp[i]+=mod;
        for (j=1;j<=i;j++) {
            pad[i]+=dp[j]*pad[i-j]%mod;
        }
        pad[i]%=mod;
    }
    g<<dp[n]<<'\n';
    return 0;
}
