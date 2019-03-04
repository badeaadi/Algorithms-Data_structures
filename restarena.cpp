#include <fstream>
#define nmax 300005
using namespace std;
class instream
{
public:
    instream() {}
    instream(const char *file_name) {
        input_file=fopen(file_name,"r");
        cursor=0;
        fread(buffer,sizy,1,input_file);
    }
    inline instream &operator >>(int &n) {
        while((buffer[cursor]<'0'||buffer[cursor]>'9')&&(buffer[cursor]!='-'))
            advance();
        int semn=1;
        if (buffer[cursor]=='-')
            semn=-semn,advance();
        n=0;
        while('0'<=buffer[cursor]&&buffer[cursor]<='9')
        {
            n=n*10+buffer[cursor]-'0';
            advance();
        }
        n*=semn;
        return *this;
    }
private:
    FILE *input_file;
    static const int sizy=1<<16;
    int cursor;
    char buffer[sizy];
    inline void advance() {
        ++ cursor;
        if(cursor==sizy){
            cursor=0;
            fread(buffer,sizy,1,input_file);
        }
    }
};
instream f("rest.in");
ofstream g("rest.out");

int n,m,b,mod,ans,adi[nmax*4],sol;
int v[nmax],t[nmax];

void build(int nod,int st,int dr)
{
    if (st==dr) {
        adi[nod]=v[st];
        return;
    }
    int mid=(st+dr)>>1;
    build(nod*2,st,mid);
    build(nod*2+1,mid+1,dr);
    adi[nod]=(1LL*adi[nod*2]*t[(dr-mid)]+adi[nod*2+1])%mod;
}
void update(int nod,int st,int dr,int p)
{
    if (st==dr) {
        adi[nod]=v[st];
        return;
    }
    int mid=(st+dr)>>1;
    if (p<=mid)
        update(nod*2,st,mid,p);
    else
        update(nod*2+1,mid+1,dr,p);
    adi[nod]=(1LL*adi[nod*2]*t[dr-mid]+adi[nod*2+1])%mod;
}
void query(int nod,int st,int dr,int a,int b)
{
    if (a<=st&&dr<=b) {
        ans=(1LL*ans*t[dr-st+1])%mod;
        ans=(ans+adi[nod])%mod;
        return;
    }
    int mid=(st+dr)>>1;
    if (a<=mid)
        query(nod*2,st,mid,a,b);
    if (b>=mid+1)
        query(nod*2+1,mid+1,dr,a,b);
}
int main()
{
    int i,j,a,x,y;
    f>>n>>b>>mod;
    t[0]=1;
    for (i=1;i<=n;i++) {
        f>>v[i];v[i]%=mod;
        t[i]=(1LL*t[i-1]*b)%mod;
    }
    build(1,1,n);
    f>>m;
    for (i=1;i<=m;i++) {
        f>>a>>x>>y;
        if (a==1) {
            v[x]=y%mod;
            update(1,1,n,x);
        }
        else  {
            ans=0;
            query(1,1,n,x,y);
            g<<ans<<'\n';
        }
    }
    return 0;
}
