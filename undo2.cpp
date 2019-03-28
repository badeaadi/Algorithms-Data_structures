#include <fstream>
#include <vector>
#define nmax 200005
using namespace std;
ifstream f("undo2.in");
ofstream g("undo2.out");
vector <int> v[nmax];
int m,k,p[nmax];

void eraseit(int a,int b)
{
    int i,j;
    for (i=b;i>=a;i--) {
        j=p[i];
        v[j].erase(v[j].end()-1);
        p[i]=0;
    }
}
int main()
{
    int i,j,t,a,b;
    f>>m;
    for (t=0;m;m--) {
        f>>i>>j;
        if (i==1) {
            if (t) {
                eraseit(t,k);
                k=t-1;
                t=0;
            }
            p[++k]=j;
            v[j].push_back(k);
        }
        if (i==2) {
            if (t) {
                eraseit(t,k);
                k=t-1;
            }
            t=k-j+1;
        }
        if (i==3) {
            eraseit(t+j,k);
            k=t+j-1;
            t=0;
        }
        if (i==4) {
            if (t==0)
                a=v[j].size();
            else
                for (a=0,b=1<<17;b;b>>=1)
                    if (a+b<v[j].size()&&v[j][a+b]<t)
                        a+=b;
            if (a<v[j].size()&&v[j][a]<t)
                a++;
            g<<a<<'\n';
        }
    }
    return 0;
}
