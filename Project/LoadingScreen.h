#include <graphics.h>
#include <string>

using namespace std;

void loadingScreen(){
  setbkcolor(3);
  cleardevice();
  settextstyle(10, 0, 8);
  int width=textwidth("QUAN LY THU VIEN");
  int height=textheight("QUAN LY THU VIEN");
  outtextxy(1366/2-width/2, 768/2-height/2-200, "QUAN LY THU VIEN");

  
  string loading = "Loading...";
  string loading2;
  char loadingCharArray[50];
  int fill = 0;
  setcolor(GREEN);
  setfillstyle(SOLID_FILL, GREEN);
  rectangle(1366/2-400, 768/2+50, 1366/2+400, 768/2+90);
  setcolor(WHITE);
  for (int i = 0; i <= 100;i++){
    to_string(i);
    loading2=loading+to_string(i)+"%";
    strcpy(loadingCharArray, loading2.c_str());
    settextstyle(10, 0, 4);
    width=textwidth(loadingCharArray);
    height=textheight(loadingCharArray);
    outtextxy(1366/2-width/2, 768/2-height/2, loadingCharArray);
    bar(1366/2-400, 768/2+50, 1366/2-400+fill, 768/2+90);
    fill += 8;
    delay(10);
  }

  width=textwidth("Nhan nut bat ky de tiep tuc");
  height=textheight("Nhan nut bat ky de tiep tuc");
  setfillstyle(SOLID_FILL, 3);
  while(1){
    if(kbhit()){
      getch();
      break;
    }
    outtextxy(1366/2-width/2, 768/2-height/2+200, "Nhan nut bat ky de tiep tuc");
    delay(500);
    bar(1366/2-width/2, 768/2-height/2+200, 1366/2+width/2, 768/2+height/2+200);
    delay(500);
  }
  clearmouseclick(WM_LBUTTONDOWN);
  cleardevice();
}