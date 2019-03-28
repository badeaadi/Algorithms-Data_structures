#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>
#define nmax 1300
#define inf 1<<16
using namespace std;
int v[nmax],d[nmax],o[4];
int n,m,b,k,x,q[nmax][4],r[4];



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
        static const int SIZE=1<<18;
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
instream f("ssce.in");
ofstream g("ssce.out");


int dp(int l)
{
    int i,j=10;
    for (i=0;i<b;i++) {
        r[i]=q[l][i]+o[i];
        if (r[i]<j)
            j=r[i];
    }
    for (i=0;i<b;i++) {
        if (j)
            r[i]-=j;
        if (r[i]>=k)
            return -1;
    }
    l=0;
    for (i=b-1;i>=0;i--)
        l*=k,l+=r[i];
    return l;
}

int main()
{
    int i,j,t,l;
    f>>n>>b>>k;
    k++;
    for (i=1,m=1;i<=b;i++)
        m*=k;
    for (i=1;i<m;i++)
        v[i]=d[i]=-inf;

    for (j=0;j<m;j++) {
        l=j;
        for (i=0;i<b;i++) {
            q[j][i]=l%k;
            l/=k;
        }
    }

    for (i=1;i<=n;i++) {
        f>>x;
        o[0]=o[1]=o[2]=o[3]=0;

        if (x==0)
            o[0]++;
        while (x) {
            o[x%10]++;
            x/=10;
        }

        for (j=0;j<m;j++) {
            if (v[j]==-inf)
                continue;
            t=dp(j);
            if (t!=-1)
                d[t]=max(d[t],v[j]+1);
        }
        memcpy(v,d,sizeof(v));
    }

    g<<v[0];

    return 0;
}
