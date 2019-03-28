#include <fstream>
#include <cmath>
#include <cstdio>
#include <iomanip>
#define nmax 100005
#define eps 1e-7
#define pi 3.141592
using namespace std;

class instream {
    public:
        instream() {}
        instream(const char *file_name) {
            input_file=fopen(file_name,"r");
            cursor=0;
            fread(buffer,SIZE,1,input_file);
        }
        inline instream &operator >>(int &n) {
            while((buffer[cursor]<'0'||buffer[cursor]>'9')&&buffer[cursor]!='-') {
                advance();
            }
            int semn=1;
            if (buffer[cursor]=='-')
                semn=-1,advance();
            n=0;
            while('0'<=buffer[cursor]&&buffer[cursor]<='9') {
                n=n*10+buffer[cursor]-'0';
                advance();
            }
            n*=semn;
            return *this;
        }
    private:
        FILE *input_file;
        static const int SIZE=1<<16;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor==SIZE) {
                cursor=0;
                fread(buffer,SIZE,1,input_file);
            }
        }
};
instream f("tarc.in");
ofstream g("tarc.out");
int n,x[nmax],y[nmax];

int sign(const double &x)
{
    if (x>eps)
        return 1;
    if (x<-eps)
        return -1;
    return 0;
}
double minx,miny,maxx,maxy,c,s,a,b;

void rotating (const double &x,const double &y)
{
    a=x*c-y*s;
    if (sign(a)==0)
        a=0;
    b=x*s+y*c;
    if (sign(b)==0)
        b=0;
}
double checking(double alpha)
{
    minx=1<<30,miny=1<<30;
    maxx=-(1<<30),maxy=-(1<<30);
    c=cos(alpha),s=sin(alpha);
    int i;
    for (i=1; i<=n; i++)
    {
        rotating(1.0*x[i],1.0*y[i]);
        if (a<minx)
            minx=a;
        if (a>maxx)
            maxx=a;
        if (b<miny)
            miny=b;
        if (b>maxy)
            maxy=b;
    }
    return (maxx-minx)-(maxy-miny);
}
void solvetest()
{
    double st,dr,mid;
    double sl,sm;
    int i;
    f>>n;
    for (i=1;i<=n;i++)
        f>>x[i]>>y[i];
    st=0;
    dr=pi/2;
    sl=checking(st);
    for (i=0; i<=70&&sign(sl); i++)
    {
        mid=(st+dr)/2;
        sm=checking(mid);
        if (sign(sm)==0)
        {
            st=mid;
            break;
        }
        if (sign(sm)==sign(sl))
            st=mid;
        else
            dr=mid;
    }
    c=cos(-st);
    s=sin(-st);
    rotating(minx,miny);
    g<<setprecision(7)<<fixed<<a<<' '<<b<<'\n';
    rotating(minx,maxy);
    g<<setprecision(7)<<fixed<<a<<' '<<b<<'\n';
    rotating(maxx,maxy);
    g<<setprecision(7)<<fixed<<a<<' '<<b<<'\n';
    rotating(maxx,miny);
    g<<setprecision(7)<<fixed<<a<<' '<<b<<'\n';
}
int main()
{
    int t;
    for (f>>t; t; t--)
        solvetest();
    return 0;
}
