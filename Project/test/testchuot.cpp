#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include <string>
#define XMAX 1366
#define YMAX 768
using namespace std;
int main(){
	initwindow(1366,768,"The Window");
	setbkcolor(3);
  cleardevice();
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
}
