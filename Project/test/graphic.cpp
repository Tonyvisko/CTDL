#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <bits/stdc++.h>
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
void selection_button(){
	setfillstyle(SOLID_FILL, RED);
	settextstyle(8, 0, 3);
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
	
	bar(890, 710, 990, 760);
	rectangle(893, 713, 987, 757);
	outtextxy(896, 723, "SEARCH");
	
	bar(1040, 710, 1130, 760);
	rectangle(1043, 713, 1127, 757);
	outtextxy(1055, 723, "SORT");
	
	bar(460, 5, 600, 45);
	rectangle(463, 8, 597, 42);
	outtextxy(465, 13, "<-- PREV");
	
	bar(620, 5, 760, 45);
	rectangle(623, 8, 757, 42);
	outtextxy(635, 13, "NEXT -->");
	
	
//	bar(1060, 710, 1200, 760);
//	rectangle(1063, 713, 1197, 757);
//	outtextxy(1065, 723, "<-- PREV");
//	
//	bar(1220, 710, 1360, 760);
//	rectangle(1223, 713, 1357, 757);
//	outtextxy(1235, 723, "NEXT -->");
	
//	bar(170, 405, 280, 455);
//	rectangle(173, 408, 277, 452);
//	outtextxy(195, 420, "SAVE");
	
	bar(1230, 5, 1365, 45);
	rectangle(1233, 8, 1362, 42);
	outtextxy(1240, 13, "BACK"); //BACK: width 60 height 60
	setlinestyle(0, 0, 1);
	rectangle(1310, 20, 1340, 30);
	line(1340, 15, 1360, 25);
	line(1340, 35, 1360, 25);
	line(1340, 15, 1340, 35);
	setcolor(15);
	line(1340, 20, 1340, 30);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1320, 25, YELLOW);
}
void update_frame1(){
	setfillstyle(SOLID_FILL, WHITE);
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
	outtextxy(35, 80, "Ma Doc Gia ");
	outtextxy(35, 130, "Ho Doc Gia ");
	outtextxy(35, 180, "Ten Doc Gia ");
	outtextxy(35, 230, "Phai [0, 1] ");
	outtextxy(35, 280, "TT The [0, 1] ");
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	int k = 5; int i = 0;
	while(k--){
		settextstyle(4, 0, 2);
		outtextxy(140, 80 + i, ":");
		bar(150, 80 + i, 415, 100 + i);
		i += 50;
	}
	
	setfillstyle(SOLID_FILL, RED);
	settextstyle(8, 0, 3);
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	setbkcolor(RED);
	bar(170, 405, 280, 455);
	rectangle(173, 408, 277, 452);
	outtextxy(195, 420, "SAVE");
}
void update_frame2(){
	setfillstyle(SOLID_FILL, WHITE);
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
	
	setfillstyle(SOLID_FILL, RED);
	settextstyle(8, 0, 3);
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	setbkcolor(RED);
	bar(170, 405, 280, 455);
	rectangle(173, 408, 277, 452);
	outtextxy(195, 420, "SAVE");
	
}
void notice_frame(){
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	rectangle(10, 470, 440, 520);
	rectangle(13, 473, 437, 517);
	setbkcolor(DARKGRAY);
	settextstyle(3, 0, 1);
	outtextxy(20, 485, "NOTI:");
}
void guide_frame1(){
	setfillstyle(SOLID_FILL, BLACK);
	bar(10, 530, 440, 755);
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(15, 535, 435, 750);
	setcolor(WHITE);
	line(125, 560, 340, 560);
	line(145, 565, 320, 565);
	setcolor(GREEN);
	setbkcolor(BLACK);
	settextstyle(4, 0, 1);
	outtextxy(145, 540, "HUONG DAN");
	settextstyle(3, 0, 1);
	outtextxy(20, 590, "MA DOC GIA  ");
	outtextxy(20, 620, "HO DOC GIA  ");
	outtextxy(20, 650, "TEN DOC GIA  ");
	outtextxy(20, 680, "PHAI  ");
	outtextxy(20, 710, "TRANG THAI THE  ");
	outtextxy(160, 590, "  Chuong trinh lay ngau nhien");
	outtextxy(160, 620, "  Toi da 16 ky tu, chi nhan ky tu chu");
	outtextxy(160, 650, "  Toi da 7 ky tu, chi nhan ky tu chu");
	outtextxy(160, 680, "  0 = NAM; 1 = NU");
	outtextxy(160, 710, "  0 = The bi khoa; 1 = The hoat dong ");
	outtextxy(160, 730, " binh thuong");
	settextstyle(4, 0, 1);
	outtextxy(155, 590, ":");
	outtextxy(155, 620, ":");
	outtextxy(155, 650, ":");
	outtextxy(155, 680, ":");
	outtextxy(155, 710, ":");
}
void guide_frame2(){
	setfillstyle(SOLID_FILL, BLACK);
	bar(10, 530, 440, 740);
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(15, 535, 435, 735);
	setcolor(GREEN);
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
	settextstyle(4, 0, 1);
	outtextxy(155, 560, ":");
	outtextxy(155, 590, ":");
	outtextxy(155, 620, ":");
	outtextxy(155, 650, ":");
	outtextxy(155, 680, ":");
	outtextxy(155, 710, ":");
}
void list_book(){
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
	setcolor(WHITE);
	outtextxy(1235, 710, "PAGE 1/1");
}
void list_reader(){
	setcolor(15);
	rectangle(460, 50, 1364, 701);
	rectangle(462, 53, 612, 93); // MA DOC GIA
	rectangle(616, 53, 866, 93);
	rectangle(870, 53, 1054, 93);
	rectangle(1058, 53, 1208, 93);
	rectangle(1212, 53, 1361, 93);
	
	setlinestyle(2, 1, 1);
	line(614, 94, 614, 701);
	line(868, 94, 868, 701);
	line(1056, 94, 1056, 701);
	line(1210, 53, 1210, 701);
	
	setcolor(YELLOW);
	settextstyle(8, 0, 3);
	setbkcolor(DARKGRAY);
	outtextxy(500, 63, "MA DG");
	outtextxy(665, 63, "HO DOC GIA");
	outtextxy(880, 63, "TEN DOC GIA");
	outtextxy(1105, 63, "PHAI");
	outtextxy(1240, 63, "TT THE");
	setcolor(WHITE);
	outtextxy(1235, 710, "PAGE 1/1");
}
void sort_frame(){
	setfillstyle(SOLID_FILL, BLACK);
	bar(10, 50, 440, 200);
	setlinestyle(0, 0, 2);
	setcolor(GREEN);
	rectangle(13, 53, 437, 197);
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(15, 55, 435, 195);
	settextstyle(4, 0, 1);
	setbkcolor(0);
	outtextxy(170, 53, "SAP XEP");
	
	settextstyle(3, 0, 1);
	outtextxy(35, 80, "Nhap lua chon [0, 1]: ");
	outtextxy(55, 100, "0 : Sap xep theo thu tu ma doc gia tang dan");
	outtextxy(55, 130, "1 : Sap xep theo thu tu ho ten doc gia tang dan");
	
	setlinestyle(0, 0, 1);
	line(40, 160, 54, 170);
	line(40, 180, 54, 170);
	line(40, 160, 44, 170);
	line(40, 180, 44, 170);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(45, 170, WHITE);
	settextstyle(4, 0, 1);
	setcolor(15);
	outtextxy(85, 160, ":");
	bar(95, 160, 420, 180);
}
void search_frame(){
	setfillstyle(SOLID_FILL, BLACK);
	bar(10, 50, 440, 150);
	setlinestyle(0, 0, 2);
	setcolor(GREEN);
	rectangle(13, 53, 437, 147);
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(15, 55, 435, 145);
	settextstyle(4, 0, 1);
	setbkcolor(0);
	outtextxy(170, 53, "TIM KIEM");
	settextstyle(8, 0, 1);
	outtextxy(20, 80, "Nhap ma doc gia:  ");
	setlinestyle(0, 0, 1);
	line(48, 110, 60, 120);
	line(48, 130, 60, 120);
	line(48, 110, 50, 120);
	line(48, 130, 50, 120);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(51, 120, WHITE);
	settextstyle(4, 0, 1);
	setcolor(15);
	outtextxy(85, 110, ":");
	bar(95, 110, 420, 130);
	
}
void result_frame(){
	setfillstyle(SOLID_FILL, WHITE);
	bar(10, 190, 440, 430);
	setlinestyle(0, 0, 1);
	setcolor(0);
	rectangle(13, 193, 437, 427);
	setlinestyle(0, 0, 1);
	rectangle(15, 195, 435, 425);
	settextstyle(4, 0, 1);
	setbkcolor(15);
	setcolor(0);
	outtextxy(70, 194, "THONG TIN DOC GIA");
	settextstyle(3, 0, 2);
	setbkcolor(15);
	setcolor(0);
	outtextxy(20, 235, "MA ");
	outtextxy(20, 275, "HO DOC GIA ");
	outtextxy(20, 315, "TEN DOC GIA");
	outtextxy(20, 355, "PHAI [0, 1]");
	outtextxy(20, 395, "TT THE [0, 1]");
	settextstyle(4, 0 , 2);
	outtextxy(165, 235, ":");
	outtextxy(165, 275, ":");
	outtextxy(165, 315, ":");
	outtextxy(165, 355, ":");
	outtextxy(165, 395, ":");
	setfillstyle(SOLID_FILL, BROWN);
	bar(175, 237, 420, 257);
	bar(175, 277, 420, 297);
	bar(175, 317, 420, 337);
	bar(175, 357, 420, 377);
	bar(175, 397, 420, 417);
	line(70, 213, 365, 213);
	line(70, 215, 365, 215);
}
int main(){

	initwindow(1366, 768, "PROJECT");
	setbkcolor(8);
	cleardevice();
	setlinestyle(3, 2, 2);
	line(450, 0, 450, 768);
	setlinestyle(0, 2, 2);

//UPDATE FRAME
//	update_frame1();
//	update_frame2();

//NOTICE FRAME
	notice_frame();
	
//GUIDE FRAME
	guide_frame1();
//	guide_frame2();
	
//LIST
//	list_book();
	list_reader();
	
//SELECTION BUTTON
	selection_button();

//SEARCH FRAME
//	search_frame();
	
//INFO FRAME
//	result_frame();
	
//SORT FRAME
	sort_frame();
//	showXY();
	getch();
	closegraph();
	return 0;
}