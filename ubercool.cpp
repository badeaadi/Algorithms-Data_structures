#include <fstream>
#include <cmath>
#include <iostream>
#include <bitset>
#include <vector>
#include <set>
#include <unordered_set>
#define milion 1000000
using namespace std;
ifstream f("ubercool.in");
ofstream g("ubercool.out");
const long long maxim=1LL*milion*milion*milion;
unsigned long long x,y;
int t;
vector <int> v;
unordered_set <unsigned long long> uber;
bitset <milion+5> ciur;

void eratosthene()
{
    int i,j;
    ciur[2]=1;
    for (i=3;i<=milion;i+=2)
        ciur[i]=1;
    for (i=3;i*i<=milion;i+=2)
        if (ciur[i])
            for (j=i*i;j<=milion;j+=i)
                ciur[j]=0;
    for (i=2;i<=milion;i++)
        if (ciur[i])
            v.push_back(i);
}
int prim(unsigned long long y)
{
    int i;
    if (y==2)
        return 1;
    for (i=0;i<v.size();i++)
        if (y%v[i]==0)
            return 0;
        else
            if (1LL*v[i]*v[i]>y)
                return 1;

}
int solve()
{
    f>>x;
    long double d=x;
    y=sqrt(d);
    if (1LL*y*y==x&&prim(y))
        return 1;
    if (uber.count(x))
        return 1;
    return 0;
}


int main()
{
    eratosthene();
    int i;
    unsigned long long x;
    for (i=0;i<v.size();i++) {
        x=1LL*v[i]*v[i];

        while (x<=maxim/v[i]) {
            x=x*v[i];
            uber.insert(x);
        }
    }
    for (f>>t;t;t--) {
        if (solve())
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}
