#include <iostream>
#define nmax 6
using namespace std;
int nr;

int main()
{
    int i,j;
    for (i=1;i<=nmax;i++) {

        for (j=1;j<i;j++)
            if (i!=j)
                if (min(i,j)<=(i^j)&&(i^j)<=max(i,j))
                    cout<<i<<' '<<j<<'\n',nr++;
    }
    cout<<"Sunt in total: "<<nr<<"perechi\n";

    return 0;
}
