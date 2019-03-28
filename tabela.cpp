#include <cstdio>
using namespace std;
int solve(int l,int c)
{
    if (l==c)
        return 0;
    if (l>c)
        return solve(c,l);
    if (l==1)
        return c;


}
int main()
{
    freopen("tabela.in","r",stdin);
    freopen("tabela.out","w",stdout);
    int l,c;
    scanf("%d %d",&l,&c);
    printf("%d",solve(l,c));

    return 0;
}
