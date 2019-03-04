#include <cstdio>
#include <cstring>
#include <fstream>
#define nmax 280
using namespace std;
ifstream f("apel.in");
ofstream g("apel.out");
char s[nmax],k[nmax],v[nmax];
int val[nmax/10],i,j;
char func[nmax/10][nmax];

int functie();
int termen();
int evalfunctie(int var[]);
int termenfunctie(int var[]);
int factorfunctie(int var[]);

int evalfunctie(int var[])
{
    int t=termenfunctie(var);
    while (s[j]=='+'||s[j]=='-') {
        if (s[j++]=='+')
            t+=termenfunctie(var);
        else
            t-=termenfunctie(var);
    }
    return t;
}
int termenfunctie(int var[])
{
    int t=factorfunctie(var);
    while (s[j]=='*') {
        j++;
        t*=factorfunctie(var);
    }
    return t;
}
int factorfunctie(int var[])
{
    int t;
    if (s[j]=='(') {
        j++;
        t=evalfunctie(var);
        j++;
        return t;
    }
    else {
        if (s[j]>='a'&&s[j]<='z')
            return var[s[j++]-'a'];
        t=0;
        while (s[j]>='0'&&s[j]<='9')
            t=t*10+s[j++]-'0';
        return t;
    }
}

int functie()
{
    int var[nmax/10]={0};
    int ord=0;
    int fu=v[i]-'A';
    i++;
    while (v[i++]!=')')
        var[ord++]=termen();
    memcpy(s,func[fu],sizeof(func[fu]));
    j=0;
    return evalfunctie(var);
}
int termen()
{
    if (v[i]>='0'&&v[i]<='9') {
        int o=v[i++]-'0';
        while (v[i]>='0'&&v[i]<='9')
            o=o*10+v[i++]-'0';
        return o;
    }
    if (v[i]>='a'&&v[i]<='z')
        return val[v[i++]-'a'];
    return functie();
}
int main()
{
    int i,j;
    char *p;
    f.getline(v,nmax);
    do
    {
        memset(k,0,sizeof(k));
        f.getline(k,nmax);
        if (k[0]>='a'&&k[0]<='z') {
            i=2;
            while (k[i])
                val[k[0]-'a']=val[k[0]-'a']*10+k[i++]-'0';
        }
        else
            if (k[0]>='A'&&k[0]<='Z') {
                p=strchr(k,'=')+1;
                i=k[0]-'A';
                for (j=0;p[j];j++)
                    func[i][j]=p[j];
            }
    } while (k[0]);

    i=0;
    g<<functie();

    return 0;
}
