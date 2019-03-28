#include <vector>
#include <fstream>
#include <algorithm>
#define nmax 30005
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
class otstream{
    public:
        otstream() {};
        otstream(const char *file_name){
            output_file.open(file_name,ios::out | ios::binary);
            output_file.sync_with_stdio(false);
            index=0;}
        inline otstream &operator <<(int target){
            aux=0;
            n=target;
            if (!n)
                nr[aux++]='0';
            for (;n;n/=10)
                nr[aux++]=n%10+'0';
            for(;aux;inc())
                buffer[index]=nr[--aux];
            return *this;
        }
        inline otstream &operator <<(const char *target){
            aux=0;
            while (target[aux])
                buffer[index]=target[aux++],inc();
            return *this;}
        ~otstream(){
            output_file.write(buffer,index);
        output_file.close();}
    private:
        fstream output_file;
        static const int SIZE=0x200000;
        int index=0,aux,n;
        char buffer[SIZE],nr[24];
        inline void inc(){
            if(++index==SIZE)
                index=0,output_file.write(buffer,SIZE);}
};




instream f("turism.in");
otstream g("turism.out");
vector <int> v[nmax],p,q;
int n,m,k,viz[nmax],a[nmax],b[nmax],la[nmax],lb[nmax];
int t[nmax],comp;

void dfs(int x,int d)
{
    int i,y;
    viz[x]=1;
    t[x]=d;
    while (a[x]<b[x]) {
        p.push_back(x);
        la[d]++;
        a[x]++;
        k=1;
    }
    while (b[x]<a[x]) {
        q.push_back(x);
        lb[d]++;
        b[x]++;
        k=1;
    }
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (viz[y]==0)
            dfs(y,d);
    }
}
int main()
{
    int i,j,x,y;
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        a[x]++;b[y]++;
    }
    for (i=1;i<=n;i++)
        if (viz[i]==0) {
            comp++;
            k=0;
            dfs(i,i);
            if (k==0)
                t[i]=-1;
        }
    if (comp!=1) {
        for (i=1;i<=n;i++)
            if (t[i]==-1) {
                p.push_back(i);
                la[i]++;
                q.push_back(i);
                lb[i]++;
                t[i]=i;
            }
    }
    g<<p.size()<<"\n";

    sort(p.begin(),p.end());
    sort(q.begin(),q.end());
    for (i=0;i<p.size()-1;i++) {
        if (p[i]==q[i])
            swap(q[i],q[i+1]);
        x=t[p[i]];
        y=t[q[i]];
        if (x==y&&la[x]==1&&lb[x]==1)
            swap(q[i],q[i+1]);
        else
            la[x]--;lb[y]--;
    }
    if  (t[q.back()]==t[p.back()]&&q.size()>1&&t[q.back()]!=t[q[q.size()-2]])
            swap(q[q.size()-1],q[q.size()-2]);

    for (i=0;i<p.size();i++)
        g<<p[i]<<" "<<q[i]<<"\n";


    return 0;
}
