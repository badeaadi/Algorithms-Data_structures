#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define nmax 100005
using namespace std;
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
instream f("suma6.in");
ofstream g("suma6.out");


vector < pair < pair <int,int>,int >  > v[350];
long long z,l[nmax*2];
int n,s,q,r,a[nmax];
int w[nmax*10];

int main()
{
    int i,j,k,t,o,p,e;
    f>>n>>s;
    r=sqrt(double(n));
    for (i=1;i<=n;i++)
        f>>a[i];
    f>>q;
    for (i=1,t=0;i<=q;i++) {
        f>>j>>k;
        v[j/r].push_back(make_pair(make_pair(k,j),i));
        t=max(t,j/r);
    }
    for (i=0;i<=t;i++,z=0) {
        sort(v[i].begin(),v[i].end());
        if (v[i].size()==0)
            continue;
        memset(w,0,sizeof(w));
        j=v[i][0].first.second;
        k=v[i][0].first.first;
        for (o=j,z=0;o<=k;o++) {
            if (a[o]>s)
                continue;
            z+=w[s-a[o]];
            w[a[o]]++;
        }
        l[v[i][0].second]=z;
        for (e=1;e<v[i].size();e++) {
            p=v[i][e].first.first;
            while (p>k) {
                k++;
                if (a[k]>s)
                    continue;
                z+=w[s-a[k]];
                w[a[k]]++;
            }
            p=v[i][e].first.second;
            while (p>j) {
                if (a[j]>s) {
                    j++;
                    continue;
                }
                w[a[j]]--;
                z-=w[s-a[j]];
                j++;
            }
            while (p<j) {
                j--;
                if (a[j]>s)
                    continue;
                z+=w[s-a[j]];
                w[a[j]]++;
            }
            l[v[i][e].second]=z;
        }
    }
    for (i=1;i<=q;i++)
        g<<l[i]<<'\n';
    return 0;
}
