#include <fstream>
#include <stack>
#include <cstring>
#define nmax 1000005
using namespace std;
ifstream f("trompeta.in");
ofstream g("trompeta.out");
stack <char> p;
char s[nmax];
int n,m;

int main()
{
    int i,j;
    f>>n>>m;f.get();
    f.getline(s,nmax);
    for (i=0;i<n;i++) {
        while (!p.empty()&&s[i]>p.top()&&(n-i-1)+p.size()>=m)
            p.pop();
        p.push(s[i]);
    }
    while (p.size()>m)
        p.pop();
    memset(s,0,sizeof(s));
    for (i=m-1;i>=0;i--) {
        s[i]=p.top();
        p.pop();
    }
    g<<s<<'\n';
    return 0;
}
