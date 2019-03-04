#include <fstream>
#include <queue>
#include <set>
#define nmax 505
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
instream f("rover.in");
ofstream g("rover.out");
queue <pair<int,int> > q;
set <pair <int,pair <int,int > > > s;
set <pair <int,pair <int,int > > > :: iterator it;
const int dl[4]= {-1,1,0,0};
const int dc[4]= {0,0,-1,1};
int n,w,v[nmax][nmax],d[nmax][nmax],c;

void solvefirst()
{
    int i,j,l,c,l1,c1;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            d[i][j]=1<<20;
    s.insert(make_pair(0,make_pair(1,1)));
    d[1][1]=0;
    while (!s.empty()) {
        it=s.begin();
        l=it->second.first;
        c=it->second.second;
        s.erase(s.begin());
        for (i=0;i<4;i++) {
            l1=l+dl[i];
            c1=c+dc[i];
            j=(v[l1][c1]<w?1:0);
            if (d[l1][c1]>d[l][c]+j) {
                it=s.find(make_pair(d[l1][c1],make_pair(l1,c1)));
                if (it!=s.end())
                    s.erase(it);
                d[l1][c1]=d[l][c]+j;
                s.insert(make_pair(d[l1][c1],make_pair(l1,c1)));
            }
        }
    }
    g<<d[n][n]<<'\n';
}
int possible(int k)
{
    int i,j,l,c,l1,c1;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            d[i][j]=0;
    while (!q.empty())
        q.pop();
    d[1][1]=1;
    q.push(make_pair(1,1));
    while (!q.empty()) {
        l=q.front().first;
        c=q.front().second;
        q.pop();
        for (i=0;i<4;i++) {
            l1=l+dl[i];
            c1=c+dc[i];
            if (v[l1][c1]<k||d[l1][c1]==1)
                continue;
            if (l1==n&&c1==n)
                return 1;
            d[l1][c1]=1;
            q.push(make_pair(l1,c1));
        }
    }
    return 0;
}
void solvesecond()
{
    int i,j;
    for (i=0,j=1<<13;j;j>>=1)
        if (possible(i+j))
            i+=j;
    g<<i<<'\n';
}
int main()
{
    int i,j;
    f>>c;
    if (c==1)
        f>>n>>w;
    else
        f>>n;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            f>>v[i][j];
    if (c==1)
        solvefirst();
    else
        solvesecond();
    return 0;
}
