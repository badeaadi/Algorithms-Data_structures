#include <fstream>
using namespace std;
ifstream f("sticle.in");
ofstream g("sticle.out");

int main()
{
    int t,n,i;
    for (f>>t;t;t--) {
        for (f>>n,i=0;(1<<i)<n;i++);
        g<<i<<'\n';
    }
    return 0;
}
