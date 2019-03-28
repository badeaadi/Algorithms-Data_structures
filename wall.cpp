#include <fstream>
#include <algorithm>
#define nmax 100005
using namespace std;

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
instream f("wall.in");
ofstream g("wall.out");

struct cet{int x;int p;} v[nmax];

int comp(const cet &a,const cet &b)
{
    return a.x>b.x;
}
int main()
{
    int i,j,n,m=0,z;
    f>>n>>z;
    for (i=1;i<=n;i++) {
        f>>v[i].x;
        v[i].p=i;
        if (v[i].x<z)
            m++;
    }
    g<<m<<'\n';
    sort(v+1,v+n+1,comp);
    for (i=1,j=1;i<=n;i++)
        if (v[i].x<z)
            g<<v[i].p<<' '<<(j==0?1:z)<<'\n',j^=1;
    for (i=1;i<=n;i++)
        if (v[i].x>=z)
            g<<v[i].p<<" 1\n";
}
