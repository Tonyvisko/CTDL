#include<graphics.h>
#include<conio.h>
using namespace std;
int main( ){
    initwindow( 1368 , 768 , "Graphics using Dev-C++");
    setcolor(YELLOW);
    rectangle(150, 100, 1218, 660);
    line(417,100,417,660);
    line(684,100,684,660);
    line(951,100,951,660);
    line(150,150,1218,150);
    outtextxy(262,115,"Ho");
    outtextxy(262+267,115,"Ten");
    outtextxy(262+267+267,115,"Lop");
    outtextxy(262+267+267+267,115,"MSV");
    readimagefile("Logo_PTIT_University.jpg",0,0,500,500);
    getch();
    return 0;
}
