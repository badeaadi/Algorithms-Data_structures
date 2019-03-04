#include <fstream>
#include <stack>
#define nmax 16000013
#define xo 8192
using namespace std;
ifstream f("secv6.in");
ofstream g("secv6.out");
stack <int> s;
int n,k,i,j,sol,x[xo];
int v[nmax];

int main()
{
    f>>n;
    for (i=0;i<min(n,xo);i++)
        f>>x[i];
    for (i=0;i<n;i++)
        v[i]=i+(x[i%xo]^x[i/xo]);
    for (i=0;i<n;i++) {
        while (!s.empty()&&v[s.top()]<v[i]) {
            sol++;
            s.pop();
        }
        if (!s.empty()) {
            sol++;
            if (v[s.top()]==v[i])
                s.pop();
        }
        s.push(i);
    }
    g<<sol;
}
