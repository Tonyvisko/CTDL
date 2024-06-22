#include <graphics.h>
#include <conio.h>
#include <dos.h>
main()
{

    initwindow(500,500);
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
      rectangle(50,100,240,200);
      floodfill(51,101, RED);
    getch();
    closegraph();
    return 0;
}

