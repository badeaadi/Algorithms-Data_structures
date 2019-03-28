#include <fstream>
#define nmax 1000005
using namespace std;
int v[nmax],x,y;;
int n,m,sol;


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
instream f("zeul.in");

int main()
{
    int i,j;
    freopen("zeul.out","w",stdout);
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        v[x]--;v[y]++;
    }
    for (i=1;i<=n;i++)
        sol+=(v[i]>=0?v[i]:-v[i]);
    printf("%d\n",sol/2);
    for (i=1,j=n;i<=n;i++) {
        while (v[i]<0) {
            while (v[j]<=0)
                j--;
            printf("%d %d\n",j,i);
            v[i]++;
            v[j]--;
        }
    }
    return 0;
}
