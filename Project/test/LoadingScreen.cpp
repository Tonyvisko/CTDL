#include <graphics.h>

int main(){
  initwindow(1366, 768, "Project");
  setbkcolor(3);
  //cleardevice();
  settextstyle(10, 0, 8);
  int width=textwidth("QUAN LY THU VIEN");
  int height=textheight("QUAN LY THU VIEN");
  outtextxy(1366/2-width/2, 768/2-height/2, "QUAN LY THU VIEN");
  delay(2000);
  closegraph();
}
