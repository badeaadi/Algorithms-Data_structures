#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define nmax 3000005
using namespace std;
int n,k,v[nmax];


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



int part(int a[],int st,int dr)
{
    int i= st , j= dr ;
    int p1= st+ rand()%(dr- st + 1);
    int p2= st+ rand()%(dr- st + 1);
    int p3= st+ rand()%(dr- st + 1);
    int p;
    if (p1 <= p3 && p3<=p2)
        p = p3;
    else
    if (p1 <= p2 && p2 <= p3)
        p = p2;
    else
        p = p1;
    swap(a[st],a[p]);

    while(1) {
        if (a[i]>a[j]) {
            swap(a[j],a[i+1]);
            swap(a[i],a[i+1]);
            i++;
        }
        else
            j--;
        if (i>=j)
            break;
    }
    return i;
}
int sel(int a[], int st, int dr, int k)
{
    if (st == dr)
        return  a[st];
    int q= part(a, st, dr);
    int t= q - st +1;
    if (t >= k)
        sel(a, st, q, k);
    else
        sel(a, q+1, dr, k-t);
}
int main()
{
    instream f("sdo.in");
    freopen("sdo.out","w",stdout);
    srand(time(NULL));
    f>>n>>k;
    for (int i = 1; i<=n; i++)
        f>>v[i];

    printf("%d",sel(v,1,n,k));

    return 0;
}