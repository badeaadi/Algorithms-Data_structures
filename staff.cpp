#include <fstream>
#include <cstdio>
#include <iostream>
using namespace std;
char s[15][10000];
char r[5];
int j;
ifstream f("staff.in");
ofstream g("staff.out");

void punesol()
{
    int i,j;
    for (i=1;i<=10;i++) s[i][4]='|';
    s[1][6]=0x5c;
    s[2][7]='}';
    s[3][6]='/';
    s[4][5]='/';
    s[5][3]='/';
    s[6][2]='/';
    s[7][1]='{';
    s[7][6]=0x5c;
    s[8][2]=0x5c;
    s[8][3]='_';
    s[8][5]='_';
    s[8][6]='/';
    s[9][5]=0x5c;
    s[10][5]='_';
    s[10][6]='}';
    s[4][9]='4';
    s[6][9]='4';

}
void incheie()
{
    int i;
    s[1][j]='+';
    for (i=2;i<=9;i++) s[i][j]='|';
    s[10][j]='+';

}


int main()
{

    int i,t,n;
    punesol();
    j=15;
    f>>n;
    for (i=1;i<=n;i++) {
        f>>r;
        if (r[0]=='C'&&r[1]!='2') {
            s[8][j]='|';
            s[9][j]='|';
            s[10][j]='|';
            s[11][j]=')';
            s[11][j-1]='@';
            s[11][j-2]='(';
            if (r[1]=='#') {
                s[11][j-3]='#';
            }
        }
        if (r[0]=='D') {
            s[7][j]='|';
            s[8][j]='|';
            s[9][j]='|';
            s[10][j]=')';
            s[10][j-1]='@';
            s[10][j-2]='(';
            if (r[1]=='#') {
                s[10][j-3]='#';
            }
        }
        if (r[0]=='E') {
            s[6][j]='|';
            s[7][j]='|';
            s[8][j]='|';
            s[9][j]=')';
            s[9][j-1]='@';
            s[9][j-2]='(';

        }
        if (r[0]=='F') {
            s[5][j]='|';
            s[6][j]='|';
            s[7][j]='|';
            s[8][j]=')';
            s[8][j-1]='@';
            s[8][j-2]='(';
            if (r[1]=='#') {
                s[8][j-3]='#';
            }
        }
        if (r[0]=='G') {
            s[4][j]='|';
            s[5][j]='|';
            s[6][j]='|';
            s[7][j]=')';
            s[8][j-1]='@';
            s[8][j-2]='(';
            if (r[1]=='#') {
                s[8][j-3]='#';
            }
        }
        if (r[0]=='A') {
            s[4][j]='|';
            s[5][j]='|';
            s[6][j]='|';
            s[7][j]=')';
            s[8][j-1]='@';
            s[8][j-2]='(';
            if (r[1]=='#') {
                s[8][j-3]='#';
            }
        }
        /*if (r[0]=='B') {
            s[4][j]='|';
            s[5][j]='|';
            s[6][j]='|';
            s[7][j]=')';
            s[8][j-1]='@';
            s[8][j-2]='(';
            if (r[1]=='#') {
                s[8][j-3]='#';
            }
        }*/
        j+=5;

    }
    incheie();



    for (i=1;i<=11;i++) {
        for (t=0;t<=j;t++){
            if (s[i][t]!=0)
                g<<s[i][t];
            else
               {if (i%2==1&&i!=11)
                    g<<'-';
                else
                    g<<' ';
            }
        }
        g<<'\n';
    }

    return 0;
}
