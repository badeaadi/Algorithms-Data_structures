#include <fstream>
#include <algorithm>
#define sinus 0.8660254
#define cosinus 0.5
#define nmax 1505
#define eps 0.0001
using namespace std;
ifstream f("triang.in");
ofstream g("triang.out");
pair <double,double> v[nmax];
double x,y,a,b;
int sol,n;

int egal(double a,double b)
{
    double dif=a-b;
    if (dif>=-eps&&dif<=eps)
        return 1;
    return 0;
}
int searching(int start,double x,double y)
{
    int st=start,dr=n;
    while (st<=dr) {
        int mid=(st+dr)>>1;
        if (egal(v[mid].first,x)&&egal(v[mid].second,y))
            return 1;

        if (v[mid].first<x||(egal(v[mid].first,x)&&v[mid].second<y))
            st=mid+1;
        else
            dr=mid-1;
    }
    return 0;
}
int main()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++)
        f>>v[i].first>>v[i].second;
    sort(v+1,v+n+1);
    for (i=1;i<n;i++)
        for (j=i+1;j<n;j++) {
            x=v[j].first-v[i].first;
            y=v[j].second-v[i].second;

            a=v[i].first+x*cosinus-y*sinus;
            b=v[i].second+x*sinus+y*cosinus;
            sol+=searching(j+1,a,b);

            a=v[i].first+x*cosinus+y*sinus;
            b=v[i].second-x*sinus+y*cosinus;
            sol+=searching(j+1,a,b);
        }
    g<<sol<<'\n';
    return 0;
}
