#include <fstream>
#include <iostream>
using namespace std;
int prim(long long x)
{
    int i;
    for (i = 2; 1LL*i*i<=x; i++)
        if (x%i==0)
            return 0;
    return 1;

}
int main()
{
    int i, j;
    long long a, b;
    cin>>a>>b;
    for (i = 2; i<= 20; i++)
        if (prim(i))
             if (prim((1LL<<i)-1)) {
                 long long t = 1LL<<(i-1);
                 t *= (1LL<<(i)) - 1;
                 if (a<=t && t<= b)
                    cout<<t<<'\n';
              }
    return 0;
}