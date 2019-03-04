#include <stdio.h>
#include <stdlib.h>

int * splitvector(const int *v, int n, int *m)
{
    int i;
    int * s = calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
        if (v[i] % 2==0)
            s[(*m)++] = v[i];

    return s;
}
void add(int *v, int n,int x)
{
    int i;
    for (i = 0; i < n; i++)
        v[i] += x;
}
void multiply(int *v, int n, int x)
{
    int i;
    for (i = 0 ; i< n ; i++)
        v[i] *= x;
}
int cmp(const void *a, const void *b)
{
    int va = *(int *)a;
    int vb = *(int *)b;
    if (va < vb)
        return -1;
    if (va == vb)
        return 0;
    return 1;
}
void sort(int *v,int n) {

    qsort(v, n, sizeof(int), cmp);
}
void display (int *v,int n)
{
    int i;
    for (i = 0; i< n ; i++)
        printf("%d\n", v[i]);
}
int main()
{
    int n, i, j;
    freopen("date.in","r",stdin);
    scanf("%d", &n);
    int *v = calloc(n, sizeof(int));
    for (i = 0; i < n ; i++)
        scanf("%d", &v[i]);
    int m = 0;

    multiply(v, n, -1);
    sort(v, n);
    add(v, n, 1);
    int *s = splitvector(v, n, &m);

    add (s, m, -1);
    multiply(s, m, -1);
    display(s, m);

    return 0;
}
