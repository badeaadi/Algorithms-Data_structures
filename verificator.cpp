#include <cstdio>
#include <windows.h>
#include <ctime>
#define nmax 1005
using namespace std;
int n,v[nmax];

int main()
{
    srand(time(NULL));
    int i,j=1,a,b;

    while (j<=50) {
        n=rand()%nmax;
        FILE *g=fopen("cifra.in","w");
        fprintf(g,"%d\n",n);
        for (i=1;i<=n;i++) {
            v[i]=rand()%10000+1;
            fprintf(g,"%d\n",v[i]);
        }

        system("cifraprog.exe");
        system("cifrabrute.exe");
        FILE *f1=fopen("cifra.out","r");
        FILE *f2=fopen("cifra.ok","r");
        for (i=1;i<=n;i++) {
            fscanf(f1,"%d",&a);
            fscanf(f2,"%d",&b);
            if (a!=b)
                break;
        }
        if (a!=b) {
            printf("Test #%d :WRONG ANSWER %d!=%d\n",j);
            return 0;
        }
        else {
            printf("Test #%d :OK %d=%d\n",j);
        }
        j++;
    }
    printf("ALL TEST OK!");

    return 0;
}
