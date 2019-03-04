#include <fstream>
using namespace std;
ifstream f ("reuniune.in");
ofstream g ("reuniune.out");
struct drept{int sx,sy,dx,dy;} v[3],k;
drept comp(drept a,drept b)
{
    int q,w,e,r;
    q=max(a.sx,b.sx);
    w=max(a.sy,b.sy);
    e=min(a.dx,b.dx);
    r=min(a.dy,b.dy);
    if(q>e||w>r)
        q=w=e=r=0;
    drept p;
    p.sx=q;p.sy=w;p.dx=e;p.dy=r;
    return p;
}
long long sup(drept a)
{
    return (1LL*a.dx-a.sx)*(1LL*a.dy-a.sy);
}
long long per(drept a)
{
    return (1LL*a.dy-a.sy+a.dx-a.sx)<<1;
}
long long s,p;

int main()
{
    int i,j;
    for (i=0;i<=2;i++) {
        f>>v[i].sx>>v[i].sy>>v[i].dx>>v[i].dy;
        s+=sup(v[i]);
        p+=per(v[i]);
    }
    for (i=0;i<=2;i++)
        for (j=i+1;j<=2;j++) {
            k=comp(v[i],v[j]);
            s-=sup(k);
            p-=per(k);
        }
    k=comp(v[0],comp(v[1],v[2]));
    s+=sup(k);
    p+=per(k);
    g<<s<<' '<<p<<' ';
    return 0;
}
