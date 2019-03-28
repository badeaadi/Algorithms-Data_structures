#include <fstream>
#include <unordered_map>
#include <map>
#include <cstring>
#include <iostream>
#include <fstream>
#define nmax 1005
#define lmax 40
using namespace std;
unordered_map <string,int> mymap;
map <string,int> mymap2;
int value[nmax],sol,k;
string s[nmax],p[nmax];
string ans;int ansord;

int main()
{
    ifstream f("date.in");
    int n;
    cin>>n;
    for (int i = 1 ; i <= n ; i++) {
        cin>>s[i];
        cin>>value[i];
        cin.get();
        mymap[s[i]]+=value[i];
    }
    for (auto &it : mymap)
        sol=max(sol, it.second);

    mymap.clear();

    for (int i = 1 ; i<=n ; i++) {
        mymap[s[i]]+=value[i];
        int p=mymap[s[i]];
        if (p>=sol) {
            map<string,int> :: iterator it =mymap2.find(s[i]);
            if (it==mymap2.end())
                mymap2[s[i]]=++k;
        }
    }
    ansord=1000;
    for (auto &it : mymap)
        if (it.second==sol)
            if (mymap2[it.first]<ansord) {
                ans.clear();
                ans+=it.first;
                ansord=mymap2[it.first];
            }
    cout<<ans;
    return 0;
}