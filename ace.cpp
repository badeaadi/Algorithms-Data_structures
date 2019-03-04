#include <fstream>
#include <cmath>
#define nmax 1005
#define eps 0.000001
using namespace std;
int p,n,m,v[nmax][nmax];
int sol,viz[nmax][nmax];
double d,e;

class instream
{
public:
    instream() {}
    instream(const char *file_name)
    {
        input_file=fopen(file_name,"r");
        cursor=0;
        fread(buffer,sizy,1,input_file);
    }
    inline instream &operator >>(int &n)
    {
        while((buffer[cursor]<'0'||buffer[cursor]>'9')&&buffer[cursor]!='-')
        {
            advance();
        }
        int semn=1;
        if (buffer[cursor]=='-')
            semn=-1,advance();
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
    static const int sizy=1<<20;
    int cursor;
    char buffer[sizy];
    inline void advance()
    {
        ++ cursor;
        if(cursor==sizy)
        {
            cursor=0;
            fread(buffer,sizy,1,input_file);
        }
    }
};
instream f("ace.in");
ofstream g("ace.out");

void solve(int i,int j)
{
    int l,c;
    l=n-i;
    c=m-j;
    d=0;
    while (i>=1&&j>=1) {
        viz[i][j]=1;
        e=sqrt(double((n-i)*(n-i)+(m-j)*(m-j)));
        if (1.0*v[i][j]/e>d+eps)
            d=v[i][j]/e,sol++;
        i-=l;
        j-=c;
    }
}
int main()
{
    int i,j,l,c;
    f>>p;
    f>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            f>>v[i][j];
    for (i=n-1,d=0;i>=1;i--)
        if (1.0*v[i][m]/(n-i)>d+eps)
            d=1.0*v[i][m]/(n-i),sol++;

    for (j=m-1,d=0;j>=1;j--)
        if (1.0*v[n][j]/(m-j)>d+eps)
            d=1.0*v[n][j]/(m-j),sol++;
    if (p==1) {
        g<<sol<<'\n';
        return 0;
    }
    for (i=n-1;i>=1;i--)
        for (j=m-1;j>=1;j--)
            if (viz[i][j]==0)
                solve(i,j);

    g<<sol<<'\n';
    return 0;
}
