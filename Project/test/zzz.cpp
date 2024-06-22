#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <string>
using namespace std;
void showXY(){
	int x,y;
  	string s;
  	char str[100];
 	 while(1){
    	if(ismouseclick(WM_LBUTTONDOWN)){
      x=mousex();
      y=mousey();
      s="("+to_string(x)+","+to_string(y)+")";
      strcpy(str, s.c_str());
      setcolor(15);
      settextstyle(0, 0, 1);
      outtextxy(x, y,str);
      clearmouseclick(WM_LBUTTONDOWN);
    }
  }
}
int main(){

	initwindow(1366, 768, "PROJECT");
	
//UPDATE FRAME
	setbkcolor(8);
	cleardevice();
	setlinestyle(3, 2, 2);
	line(450, 0, 450, 768);
	setlinestyle(0, 2, 2);
	line(453, 0, 453, 768);
	bar(10, 10, 440, 400);
	setlinestyle(0, 3, 2);
	setcolor(0);
	rectangle(20, 20, 430, 390);
	setlinestyle(0, 1, 1);
	rectangle(25, 25, 425, 385);
	setbkcolor(YELLOW);
	setcolor(RED);
	settextstyle(4, 0, 2);
	outtextxy(140, 35, "CAP NHAT ");
	setbkcolor(15);
	setcolor(0);
	settextstyle(3, 0, 1);
	outtextxy(35, 80, "Ten sach ");
	outtextxy(35, 130, "ISBN ");
	outtextxy(35, 180, "Tac gia ");
	outtextxy(35, 230, "The loai ");
	outtextxy(35, 280, "So trang ");
	outtextxy(35, 330, "Nam xuat ban ");
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	int k = 6; int i = 0;
	while(k--){
		settextstyle(4, 0, 2);
		outtextxy(140, 80 + i, ":");
		bar(150, 80 + i, 415, 100 + i);
		i += 50;
	}
	
//NOTICE FRAME
	setcolor(YELLOW);
	rectangle(10, 470, 440, 520);
	rectangle(13, 473, 437, 517);
	setbkcolor(DARKGRAY);
	settextstyle(3, 0, 1);
	outtextxy(20, 485, "NOTI:");
	
//GUIDE FRAME
	setfillstyle(SOLID_FILL, BLACK);
	bar(10, 530, 440, 740);
	setcolor(GREEN);
	rectangle(15, 535, 435, 735);
	setbkcolor(BLACK);
	settextstyle(4, 0, 1);
	outtextxy(145, 540, "HUONG DAN");
	settextstyle(3, 0, 1);
	outtextxy(20, 560, "TEN SACH ");
	outtextxy(20, 590, "ISBN  ");
	outtextxy(20, 620, "TAC GIA  ");
	outtextxy(20, 650, "THE LOAI  ");
	outtextxy(20, 680, "SO TRANG  ");
	outtextxy(20, 710, "NAM XUAT BAN  ");
	outtextxy(160, 560, "  Toi da 24 ky tu, bao gom chu va so");
	outtextxy(160, 590, "  Toi da 4 ky tu, chi nhan ky tu chu");
	outtextxy(160, 620, "  Toi da 17 ky tu, chi nhan ky tu chu");
	outtextxy(160, 650, "  Toi da 11 ky tu, chi nhan ky tu chu");
	outtextxy(160, 680, "  So trang khong qua 999999");
	outtextxy(160, 710, "  Nam XB khong lon hon nam hien tai");
	k = 6, i = 0;
	settextstyle(4, 0, 1);
	while(k--){
		outtextxy(155, 560 + i, ":");
		i += 30;
	}
	
//LIST
	setcolor(15);
	rectangle(460, 50, 1364, 701);
	rectangle(462, 53, 752, 93); // Dau Sach
	rectangle(756, 53, 826, 93); // ISBN
	rectangle(830, 53, 1040, 93);  // Tac gia
	rectangle(1044, 53, 1194, 93); // The loai
	rectangle(1198, 53, 1298, 93);  // So Trang
	rectangle(1302, 53, 1361, 93); // NXB
	
	setlinestyle(2, 1, 1);
	line(754, 94, 754, 701);
	line(828, 94, 828, 701);
	line(1042, 94, 1042, 701);
	line(1196, 94, 1196, 701);
	line(1300, 94, 1300, 701);
	line(1363, 94, 1363, 701);
	
	
	
	setcolor(YELLOW);
	settextstyle(8, 0, 3);
	setbkcolor(DARKGRAY);
	outtextxy(560, 63, "DAU SACH");
	outtextxy(760, 63, "ISBN");
	outtextxy(890, 63, "TAC GIA");
	outtextxy(1070, 63, "THE LOAI");
	outtextxy(1215, 63, "SO TR");
	outtextxy(1310, 63, "NXB");
	
//SELECTION BUTTON
	setfillstyle(SOLID_FILL, RED);
	bar(460, 710, 550, 760);
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	rectangle(463, 713, 547, 757);
	setbkcolor(RED);
	outtextxy(483, 723,"ADD");
	
	bar(600, 710, 700, 760);
	rectangle(603, 713, 697, 757);
	outtextxy(606, 723, "DELETE");
	
	bar(750, 710, 840, 760);
	rectangle(753, 713, 837, 757);
	outtextxy(765, 723, "EDIT");
	
	bar(890, 710, 1030, 760);
	rectangle(893, 713, 1027, 757);
	outtextxy(896, 723, "<-- PREV");
	
	bar(1050, 710, 1190, 760);
	rectangle(1053, 713, 1187, 757);
	outtextxy(1065, 723, "NEXT -->");
	
	bar(1270, 710, 1360, 760);
	rectangle(1273, 713, 1357, 757);
	outtextxy(1285, 723, "BACK");
	
	bar(170, 405, 280, 455);
	rectangle(173, 408, 277, 452);
	outtextxy(195, 420, "SAVE");
	
//	showXY();
	_getch();
	closegraph();
	return 0;
}