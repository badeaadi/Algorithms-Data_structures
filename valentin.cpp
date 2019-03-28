#include <cstdio>
#include <fstream>
#define inf 1000000000
#define nmax 600005
using namespace std;
long long sum[2][2],pos[2][2];
int n,v[nmax];

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
    instream f("valentin.in");
    ofstream g("valentin.out");

void possible(long long &x,long long &p,long long y,long long posi)
{
    if (y>x) {
        x=y;
        p=posi;
    }
    else
        if (y==x)
            p+=posi;
}
int main()
{
    int i,j,k,p;
    f>>p>>n;
    for (i=1;i<=n;i++)
        f>>v[i];
    for (j=0;j<2;j++)
        sum[0][j]=sum[1][j]=-inf;

    for (i=1;i<=n;i++) {
        for (j=0;j<2;j++)
            if (sum[0][j]!=-inf) {
                k=(j+v[i])%2;
                k+=2;k%=2;
                possible(sum[1][k],pos[1][k],sum[0][j]+v[i],pos[0][j]);
        }
        k=v[i]%2;
        k+=2;k%=2;
        possible(sum[1][k],pos[1][k],v[i],1);

        for (j=0;j<2;j++) {
            possible(sum[0][j],pos[0][j],sum[1][j],pos[1][j]);
            sum[1][j]=-inf;
            pos[1][j]=0;
        }
    }
    if (p==1)
        g<<sum[0][0];
    else
        g<<pos[0][0];

    return 0;
}
