#include <fstream>
#define nmax 200005
using namespace std;
ifstream f("aranjare2.in");
ofstream g("aranjare2.out");
int a[nmax];//sticluta care este pe pozitia i
int v[nmax];//sticluta care ar trebui sa fie pe pozitia i
int x[nmax];//pozitia pe care se afla sticluta i
int n;

int main()
{
    int i,j,p,q;
    f>>n;
    for (i=1;i<=2*n;i++) {
        a[i]=i;x[i]=i;
        if (i%2==1)
            v[i]=i/2+1;
        else
            v[i]=n+i/2;
    }
    for (i=1;i<=2*n;i++)
        if (a[i]!=v[i]) {
            p=i;q=x[v[i]];
            g<<p<<' '<<q<<'\n';
            swap(x[a[i]],x[v[i]]);//interschimb pozitia pe care se afla a[i] cu pozitia pe care se afla v[i]
            swap(a[p],a[q]);//interschimb sticlutele
        }

    return 0;
}
