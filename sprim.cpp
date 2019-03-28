#include <cstdio>
#include <algorithm>
#include <fstream>
#define nmax 1000500
using namespace std;
long long sol;
int p[nmax/10];
int n,v[nmax],k[nmax];

int good(int x)
{
    while (x!=1) {
        if (v[k[x]])
            return 0;
        x/=k[x];
    }
    return 1;
}
void add(int x,int val)
{
    while (x!=1) {
        v[k[x]]+=val;
        x/=k[x];
    }
}
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
            n=0;
            while('0'<=buffer[cursor]&&buffer[cursor]<='9') {
                n=n*10+buffer[cursor]-'0';
                advance();
            }
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
instream f("sprim.in");
ofstream g("sprim.out");

int main()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++)
        f>>p[i];

    k[1]=1;
    for (i=2;i<nmax;i+=2)
        k[i]=2;
    for (i=3;i*i<nmax;i+=2)
        if (k[i]==0)
            for (j=i*i;j<nmax;j+=2*i)
                if (k[j]==0)
                    k[j]=i;
    for (i=2;i<nmax;i++)
        if (k[i]==0)
            k[i]=i;

    add(p[1],1);
    for (i=1,j=1;i<=n;i++) {
        while (j<n&&good(p[j+1]))
            add(p[++j],1);

        sol+=1LL*(j-i);
        add(p[i],-1);
    }
    g<<sol<<'\n';

    return 0;
}
