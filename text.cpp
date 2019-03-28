#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;
FILE *f=fopen("text.in","r");
FILE *g=fopen("text.out","w");
int nrlit,nrcuv,aux;
char c;

int cond()
{
    if (c>='a'&&c<='z')
        return 1;
    if (c>='A'&&c<='Z')
        return 1;
    return 0;

}

int main()
{
     while(c != '~'){
          c = '~';
          fscanf(f, "%c", &c);
          if(cond())
               aux ++;
          else{
               if(aux > 0)
                    nrcuv ++;
               nrlit += aux;
               aux = 0;
          }
     }
     nrlit /= nrcuv;
     fprintf(g,"%d",nrlit);
     return 0;
}
