#include <windows.h>
#define speep(n) sleep(n*1000)
int main() {
    int i; for(i=0;i<2;i++) {
        Beep(494,120*2);
        Beep(0,140);
        Beep(330,120*2);
        Beep(0,120*2);
        Beep(415,120*2);
        Beep(0,120*2);
        Beep(494,120*2);
        Beep(0,120*2);
        Beep(523,120*2);
        Beep(0,140);
        Beep(330,120*2);
        Beep(0,120*2);
        Beep(659,120*2);
        Beep(0,120*2);
        Beep(622,120*2);
        Beep(0,120*2);
        Beep(659,120*2);
        Beep(0,120*2);
        Beep(622,120*2);
        Beep(0,120*2);
        Beep(659,120*2);
        Beep(0,12*2);
        Beep(494,120*2);
        Beep(0,120*2);
        Beep(587,120*2);
        Beep(0,120*2);
        Beep(523,120*2);
        Beep(0,120*2);
        Beep(440,120*2);
        Beep(0,140);
        Beep(262,120*2);
        Beep(0,120*2);
        Beep(330,120*2);
        Beep(0,120*2);
        Beep(440,120*2);
        Beep(0,120*2);
        Beep(494,120*2);
        Beep(0,140);
        Beep(330,120*2);
        Beep(0,120*2);
        Beep(523,120*2);
        Beep(0,120*2);
        Beep(494,120*2);
        Beep(0,140);
        Beep(440,120*4);
        Sleep(800);
        }
    return 0; }
