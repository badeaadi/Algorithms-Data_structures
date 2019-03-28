#include <fstream>
#include <vector>
using namespace std;
ifstream f("transformari.in");
ofstream g("transformari.out");
int s=1<<30;
void cmmdc(int i,int j,int &k)
{
    if (i==1||j==1) {
        if (i==1&&j==1)
            k=0;
        else
            k=max(i-1,j-1);
        return;
    }
    cmmdc(j,i%j,k);
    k+=i/j;
}
int cmmdc2(int i,int j)
{
    if (j==0)
        return i;
    return cmmdc2(j,i%j);
}

int main()
{
    int i,j,p,n;
    f>>n;
    for (i=1;i<=n;i++) {
        j=cmmdc2(i,n);
        if (j!=1)
            continue;
        p=0;
        cmmdc(i,n,p);
        s=min(s,p);
    }
    g<<s<<'\n';
    return 0;
}
