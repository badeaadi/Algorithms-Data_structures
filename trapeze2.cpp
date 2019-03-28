#include <fstream>
using namespace std;
ifstream f("trapeze2.in");
ofstream g("trapeze2.out");
long long p,q,l,sol,amax;
int x1,d1,n1,x2,d2,n2,drept;

void findit(int i,int j,int q,long long &a,long long &b,int k)
{
    int o=min(i-1,q-1-j);
    i-=o;j+=o;
    b=(j-i)/2;
    a=(k-i+1)/2;
}
int main()
{
    long long a1,b1,a2,b2;
    int i,j;
    f>>x1>>d1>>n1;
    f>>x2>>d2>>n2;
    p=x1;q=x2;
    i=1;j=1;
    while (i<n1*2&&j<n2*2) {
        while (i<n1*2&&j<n2*2&&p!=q) {
            while (p<q) {
                p+=d1;
                i++;
            }
            while (p>q) {
                q+=d2;
                j++;
            }
        }
        if (i<n1*2&&j<n2*2) {
            if (i%2==0&&j%2==0)
                drept++;

            if (i%2==1)
                findit(i,i,2*n1,a1,b1,i);
            else
                findit(i-1,i+1,2*n1,a1,b1,i);
            if (j%2==1)
                findit(j,j,2*n2,a2,b2,j);
            else
                findit(j-1,j+1,2*n2,a2,b2,j);

            if (a1&&a2) {
                b1*=d1;b2*=d2;
                amax=max(amax,1LL*b1+b2);
                sol+=1LL*a1*a2;
            }
        }
        else
            break;
        i++;j++;
        p+=d1;q+=d2;
    }
    g<<sol-1LL*drept*1LL*(drept-1)/2<<'\n'<<amax+max(x1-x2,x2-x1)<<'\n';
    return 0;
}
/*
//Cazacu Alexandru
#include<cstdio>
#include<algorithm>
using namespace std;

long long x1, d1, n1;
long long x2, d2, n2, perp;
long long max_area;

long long get_area(int up, int down, int num1, int num2) {
	long long b1 = 2.0 * (long long)(up-1) * d1 + d1;
	long long b2 = 2.0 * (long long)(down-1) * d2 + d2;

	if(num1 % 2 == 0)
		b1+= d1;
	if(num2 % 2 == 0)
		b2+= d2;

	if(b1 != b2)
		return b1 + b2;
	return max(b1 - 2*d1 + b2, b1 + b2 - 2*d2);
}

long long count() {

	long long number = 0;
	long long i = 2 * x1;
	long long j = 2 * x2;
	long long dist1 = d1;
	long long dist2 = d2;
	long long num1 = 0, num2 = 0;

	for(;num1 / 2 + 1 <= n1 && num2 / 2 + 1 <= n2;) {
		if(i == j) {
			if(num1 % 2 == 0 && num2 % 2 == 0)
				perp++;

			long long left = num1 / 2 + 1;
            		long long right = n1 - left;
			if(num1 % 2 == 0)
				left--;
 			long long up = min(left, right);

			left = num2 / 2 + 1;
			right = n2 - left;
			if(num2 % 2 == 0)
				left--;
			long long down = min(left, right);

			number+= (long long)up * (long long)down;
			max_area = max(max_area, get_area(up, down, num1, num2));
    		}

		if(i <= j)
			num1++, i+= dist1;
		else
			num2++, j+= dist2;
	}

	return number;
}

void solve() {

	long long result = count();
	printf("%lld\n", result - (long long)perp * (long long) (perp - 1) / (long long)2);
	printf("%lld", max_area);
}

void read_data() {
	scanf("%lld %lld %lld", &x1, &d1, &n1);
	scanf("%lld %lld %lld", &x2, &d2, &n2);
}

int main() {

	freopen("trapeze2.in", "r", stdin);
	freopen("trapeze2.out", "w", stdout);

	read_data();
	solve();

	return 0;
}*/

