#include <graphics.h>
#include <string>
#include <conio.h>
using namespace std;

int main(){
  initwindow(800, 600);
  setbkcolor(3);
  cleardevice();
  // setcolor(0);
  // settextstyle(0, 0, 5);
  // outtextxy(100, 100, "Hello, world!");
  // char c;
  // string s="", s2="_";
  // char str[100];
  // outtextxy(100,200,"_");
  // while(1){

  //     c=getch();

  //     if(c==8&&s.length()>0){
  //       s.pop_back();
  //       s2 = s + s2 + "  ";
  //       strcpy(str, s2.c_str());
  //       outtextxy(100, 200, str);
  //       s2 = "_";
  //     }
  //     else{
  //       if(c!=8)
  //         s += c;
  //       s2 = s + s2;
  //       strcpy(str, s2.c_str());
  //       outtextxy(100, 200, str);
  //       s2 = "_";
  //     }
    
      
  //   }

  int x,y;
  string s;
  char str[100];
  while(1){
    if(ismouseclick(WM_LBUTTONDOWN)){
      x=mousex();
      y=mousey();
      s="("+to_string(x)+","+to_string(y)+")";
      strcpy(str, s.c_str());
      setcolor(0);
      settextstyle(0, 0, 5);
      outtextxy(x, y,str);
      clearmouseclick(WM_LBUTTONDOWN);
    }
  }
  getch();
  closegraph();
  return 0;
}



