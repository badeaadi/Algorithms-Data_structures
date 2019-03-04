#include <fstream>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#define nmax 50005
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
        while(buffer[cursor]<'0'||buffer[cursor]>'9')
            advance();
        n=0;
        while('0'<=buffer[cursor]&&buffer[cursor]<='9')
        {
            n=n*10+buffer[cursor]-'0';
            advance();
        }
        return *this;
    }
private:
    FILE *input_file;
    static const int sizy=1<<20;
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
instream f("retele.in");
ofstream g("retele.out");

vector <int> v[nmax],p[nmax],z[nmax];
stack <int> s;
bitset <nmax> b;
int n,m,k,h[nmax];

void dfsgraph(int x)
{
    int i,y;
    b[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (b[y]==1)
            continue;
        dfsgraph(y);
    }
    s.push(x);
}
void dfstrans(int x)
{
    int i,y;
    b[x]=1;
    z[k].push_back(x);
    for (i=0;i<p[x].size();i++) {
        y=p[x][i];
        if (b[y]==1)
            continue;
        dfstrans(y);
    }
}
int compvector(const int &a,const int &b)
{
    return (z[a][0]<z[b][0]);
}
int main()
{
    int i,j,x,y;
    f>>n;f>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        v[x].push_back(y);
        p[y].push_back(x);
    }
    for (i=1;i<=n;i++)
        if (b[i]==0)
            dfsgraph(i);
    b.reset();
    while (!s.empty()) {
        i=s.top();
        s.pop();
        if (b[i]==0) {
            k++;
            dfstrans(i);
        }
    }
    for (i=1;i<=k;i++)
        sort(z[i].begin(),z[i].end());
    for (i=1;i<=k;i++)
        h[i]=i;
    sort(h+1,h+k+1,compvector);
    g<<k<<'\n';
    for (i=1;i<=k;i++) {
        g<<z[h[i]].size()<<' ';
        for (j=0;j<z[h[i]].size();j++)
            g<<z[h[i]][j]<<' ';
        g<<'\n';
    }
    return 0;
}
