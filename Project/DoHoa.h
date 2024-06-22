#include <graphics.h>
#include "XuLy.h"
void info_status();
void info_borrow_reader(TheDocGia R);

void coverBackground(int x1, int x2, int y1, int y2, int color){
  setcolor(color);
  bar(x1, y1, x2, y2);
}

void ARROW(int x1, int y1, int color){
  setcolor(color);
	// line(40, 120, 54, 130);
	// line(40, 140, 54, 130);
	// line(40, 120, 44, 130);
	// line(40, 140, 44, 130);
  line(x1, y1, x1 + 14, y1 + 10);
  line(x1, y1 + 20, x1 + 14, y1 + 10);
  line(x1, y1, x1 + 4, y1 + 10);
  line(x1, y1 + 20, x1 + 4, y1 + 10);
  setfillstyle(SOLID_FILL, color);
  // floodfill(45, 130, WHITE);
  floodfill(x1 + 5, y1 + 10, color);
}

void ADD_BUTTON(int x, int y){
  // bar(460, 710, 550, 760);
  // rectangle(463, 713, 547, 757);
  // outtextxy(483, 723,"ADD");
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
  bar(x, y, x + 90, y + 50);
  rectangle(x + 3, y + 3, x + 87, y + 47);
  outtextxy(x + 23, y + 13, "ADD");
}

void DELETE_BUTTON(int x, int y){
  // bar(600, 710, 700, 760);
  // rectangle(603, 713, 697, 757);
  // outtextxy(606, 723, "DELETE");
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
  bar(x, y, x + 100, y + 50);
  rectangle(x + 3, y + 3, x + 97, y + 47);
  outtextxy(x + 6, y + 13, "DELETE");
}

void EDIT_BUTTON(int x, int y){
  // bar(750, 710, 840, 760);
  // rectangle(753, 713, 837, 757);
  // outtextxy(765, 723, "EDIT");
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
  bar(x, y, x + 90, y + 50);
  rectangle(x + 3, y + 3, x + 87, y + 47);
  outtextxy(x + 15, y + 13, "EDIT");
}

void SORT_BUTTON(int x, int y){
  // bar(600, 710, 690, 760);
  // rectangle(603, 713, 687, 757);
  // outtextxy(615, 723, "SORT");
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
  bar(x, y, x + 90, y + 50);
  rectangle(x + 3, y + 3, x + 87, y + 47);
  outtextxy(x + 15, y + 13, "SORT");
}
void SEARCH_BUTTON(int x, int y){
  // bar(740, 710, 840, 760);
  // rectangle(743, 713, 837, 757);
  // outtextxy(746, 723, "SEARCH");
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
  bar(x, y, x + 100, y + 50);
  rectangle(x + 3, y + 3, x + 97, y + 47);
  outtextxy(x + 6, y + 13, "SEARCH");
}

void PREV_BUTTON(int x, int y){
  // bar(460, 5, 600, 45);
  // rectangle(463, 8, 597, 42);
  // outtextxy(465, 13, "<-- PREV");
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
  bar(x, y, x + 140, y + 40);
  rectangle(x + 3, y + 3, x + 137, y + 37);
  outtextxy(x + 5, y + 8, "<-- PREV");
}

void NEXT_BUTTON(int x, int y){
  // bar(620, 5, 760, 45);
  // rectangle(623, 8, 757, 42);
  // outtextxy(635, 13, "NEXT -->");
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
  bar(x, y, x + 140, y + 40);
  rectangle(x + 3, y + 3, x + 137, y + 37);
  outtextxy(x + 15, y + 8, "NEXT -->");
}

void BACK_BUTTON(int x, int y){
  // bar(1230, 5, 1365, 45);
  // rectangle(1233, 8, 1362, 42);
  // outtextxy(1240, 13, "BACK");
  // setlinestyle(0, 0, 1);
  // rectangle(1310, 20, 1340, 30);
  // line(1340, 15, 1360, 25);
  // line(1340, 35, 1360, 25);
  // line(1340, 15, 1340, 35);
  // setcolor(15);
  // line(1340, 20, 1340, 30);
  // setfillstyle(SOLID_FILL, WHITE);
  // floodfill(1320, 25, YELLOW);
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  bar(x, y, x + 135, y + 40);
  rectangle(x + 3, y + 3, x + 132, y + 37);
  outtextxy(x + 10, y + 8, "BACK");
  setlinestyle(0, 0, 1);
  rectangle(x + 80, y + 15, x + 110, y + 25);
  line(x + 110, y + 10, x + 130, y + 20);
  line(x + 110, y + 30, x + 130, y + 20);
  line(x + 110, y + 10, x + 110, y + 30);
  setcolor(15);
  line(x + 110, y + 15, x + 110, y + 25);
  setfillstyle(SOLID_FILL, WHITE);
  floodfill(x + 90, y + 20, YELLOW);
}
void SAVE_BUTTON(int x, int y){
  setfillstyle(SOLID_FILL, RED);
	settextstyle(8, 0, 3);
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	setbkcolor(RED);
  bar(x, y, x + 110, y + 50);
  rectangle(x + 3, y + 3, x + 107, y + 47);
  outtextxy(x + 25, y + 15, "SAVE");
}
void readers_button(){
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
	
  ADD_BUTTON(460, 710);
  SEARCH_BUTTON(740, 710);
  SORT_BUTTON(600, 710);
  PREV_BUTTON(460, 5);
  NEXT_BUTTON(620, 5);
  BACK_BUTTON(1230, 5);
}
void book_header_button(){
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
	
  ADD_BUTTON(460, 710);
  SEARCH_BUTTON(600, 710);
    SEARCH_BUTTON(750, 710);
  PREV_BUTTON(32, 5);
  NEXT_BUTTON(192, 5);
  BACK_BUTTON(1230, 5);
}

void add_reader_frame(){
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
	outtextxy(225-width("THEM")/2, 35, "THEM");
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

void add_reader_guide(){
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

void add_reader_function(){
  add_reader_frame();
  add_reader_guide();
}

void update_reader_frame(){
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
	outtextxy(225-width("Cap Nhat")/2, 35, "Cap Nhat");
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

  setfillstyle(SOLID_FILL, DARKGRAY);
  bar(10, 405, 440, 460);

  setfillstyle(SOLID_FILL, RED);
	settextstyle(8, 0, 3);
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	setbkcolor(RED);
	bar(170, 405, 280, 455);
	rectangle(173, 408, 277, 452);
	outtextxy(195, 420, "SAVE");
}
void update_reader_guide(){
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
	outtextxy(160, 590, "  Nhap vao ma doc gia 1 - 30000");
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
void update_reader_function(TheDocGia R){
  update_reader_frame();
  update_reader_guide();
  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);
  
  string s;
  char str[20];

  strcpy(str, to_string(R.MaThe).c_str());
  outtextxy(155, 80, str);
  strcpy(str, R.Ho.c_str());
  outtextxy(155, 130, str);
  strcpy(str, R.Ten.c_str());
  outtextxy(155, 180, str);
  s = (R.Phai == "Nam") ? "0" : "1";
  strcpy(str, s.c_str());
  outtextxy(155, 230, str);
  strcpy(str, to_string(R.TrangThai).c_str());
  outtextxy(155, 280, str);
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
	setfillstyle(SOLID_FILL, DARKGRAY);
  	bar(10, 405, 440, 460);
	

  SAVE_BUTTON(170, 405);
}

void guide_frame(){
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
void guide_frame2(){
	setfillstyle(SOLID_FILL, BLACK);
	bar(468, 480, 898, 690);
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(473, 485,893, 685);
	setcolor(GREEN);
	setbkcolor(BLACK);
	settextstyle(4, 0, 1);
	outtextxy(603, 490, "HUONG DAN");
	settextstyle(3, 0, 1);
	outtextxy(478, 510, "TEN SACH ");
	outtextxy(478, 540, "ISBN  ");
	outtextxy(478, 570, "TAC GIA  ");
	outtextxy(478, 600, "THE LOAI  ");
	outtextxy(478, 630, "SO TRANG  ");
	outtextxy(478, 660, "NAM XUAT BAN  ");
	outtextxy(618, 510, "  Toi da 24 ky tu, bao gom chu va so");
	outtextxy(618, 540, "  Toi da 4 ky tu, chi nhan ky tu chu");
	outtextxy(618, 570, "  Toi da 17 ky tu, chi nhan ky tu chu");
	outtextxy(618, 600, "  Toi da 20 ky tu, chi nhan ky tu chu");
	outtextxy(618, 630, "  So trang khong qua 999999");
	outtextxy(618, 660, "  Nam XB khong lon hon nam hien tai");
	settextstyle(4, 0, 1);
	outtextxy(613, 510, ":");
	outtextxy(613, 540, ":");
	outtextxy(613, 570, ":");
	outtextxy(613, 600, ":");
	outtextxy(613, 630, ":");
	outtextxy(613, 660, ":");
}
void update_book_function(pointerArray &DSDS,string TenSach){
	update_frame2();
	guide_frame();
	setcolor(BLACK);
	setbkcolor(LIGHTGRAY);
	settextstyle(3, 0, 1);
	int i=Exist_DS(DSDS,TenSach);
	char str[20];
	strcpy(str,DSDS.nodesDauSach[i]->TenSach .c_str());
 	outtextxy(155, 80, str);
  	strcpy(str, DSDS.nodesDauSach[i]->ISBN.c_str());
  	outtextxy(155, 130, str);
  	strcpy(str, DSDS.nodesDauSach[i]->TacGia.c_str());
  	outtextxy(155, 180, str);
  	strcpy(str, DSDS.nodesDauSach[i]->TheLoai.c_str());
  	outtextxy(155, 230, str);
  	strcpy(str, to_string(DSDS.nodesDauSach[i]->SoTrang).c_str());
  	outtextxy(155, 280, str);
  	strcpy(str, to_string(DSDS.nodesDauSach[i]->NamXuatBan).c_str());
  	outtextxy(155, 330, str);
}
void book_information_frame(){
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
	outtextxy(140, 35, "THONG TIN ");
	setbkcolor(15);
	setcolor(0);
	settextstyle(3, 0, 1);
	outtextxy(35, 80, "Ten sach: ");
	outtextxy(35, 120, "ISBN: ");
	outtextxy(35, 160, "Tac gia: ");
	outtextxy(35, 200, "The loai: ");
	outtextxy(35, 240, "So trang: ");
	outtextxy(35, 280, "Nam xuat ban: ");
  outtextxy(35, 320, "Tong so sach cua dau sach: ");
  outtextxy(35, 360, "So sach con trong thu vien: ");
  setfillstyle(SOLID_FILL, LIGHTGRAY);
	int k = 8; int i = 0;
	while(k--){
		settextstyle(4, 0, 2);

    if(k>1){
		  bar(150, 80 + i, 415, 100 + i);
    }
    else{
		  bar(250, 80 + i, 415, 100 + i);
    }
		
    i += 40;
	}
	
}

void list_book(){
	setbkcolor(8);
	setfillstyle(SOLID_FILL, WHITE);

	setcolor(15);
	rectangle(32, 50, 1364, 701);
	rectangle(34, 53, 370, 93); // Dau Sach
	rectangle(373, 53, 505, 93); // ISBN
	rectangle(508, 53, 800, 93);  // Tac gia
	rectangle(803, 53, 1194, 93); // The loai
	rectangle(1198, 53, 1298, 93);  // So Trang
	rectangle(1302, 53, 1361, 93); // NXB
	
	setlinestyle(2, 1, 1);
	line(373, 94, 373, 701);
	line(508, 94, 508, 701);
	line(803, 94, 803, 701);
	line(1196, 94, 1196, 701);
	line(1300, 94, 1300, 701);
	line(1363, 94, 1363, 701);
	
	setcolor(YELLOW);
	settextstyle(8, 0, 3);
	setbkcolor(DARKGRAY);
	outtextxy(100, 63, "DAU SACH");
	outtextxy(405, 63, "ISBN");
	outtextxy(585, 63, "TAC GIA");
	outtextxy(935, 63, "THE LOAI");
	outtextxy(1215, 63, "SO TR");
	outtextxy(1310, 63, "NXB");
//	setcolor(WHITE);
//	outtextxy(1235, 710, "PAGE 1/1");
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
void delete_frame(){
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
	outtextxy(20, 80, "Nhap ma doc gia muon xoa:");
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
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	arc(305, 90, 130, 230, 10);
	settextstyle(8, 0, 1);
	line(316, 89, 323, 85);
	line(316, 89, 323, 93);
	line(316, 92, 323, 96);
	outtextxy(330, 80, "30000");
	arc(385, 90, -50, 50, 10);
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
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	arc(220, 90, 130, 230, 10);
	settextstyle(8, 0, 1);
	line(225, 89, 232, 85);
	line(225, 89, 232, 93);
	line(225, 92, 232, 96);
	outtextxy(239, 80, "30000");
	arc(300, 90, -50, 50, 10);
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

void reader_information_frame(){
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
	outtextxy(225-width("THONG TIN")/2, 35, "THONG TIN");
	setbkcolor(15);
	setcolor(0);
	settextstyle(3, 0, 1);
	outtextxy(35, 80, "Ma Doc Gia ");
	outtextxy(35, 130, "Ho Doc Gia ");
	outtextxy(35, 180, "Ten Doc Gia ");
	outtextxy(35, 230, "Phai ");
	outtextxy(35, 280, "TT The ");
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	int k = 5; int i = 0;
	while(k--){
		settextstyle(4, 0, 2);
		outtextxy(140, 80 + i, ":");
		bar(150, 80 + i, 415, 100 + i);
		i += 50;
	}
	
}

void reader_information_function(TheDocGia R){
  reader_information_frame();
  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);
  
  string s;
  char str[20];

  strcpy(str, to_string(R.MaThe).c_str());
  outtextxy(155, 80, str);
  strcpy(str, R.Ho.c_str());
  outtextxy(155, 130, str);
  strcpy(str, R.Ten.c_str());
  outtextxy(155, 180, str);
  strcpy(str, R.Phai.c_str());
  outtextxy(155, 230, str);
  s = (R.TrangThai == 1) ? "Binh thuong" : "Khoa";
  strcpy(str, s.c_str());
  outtextxy(155, 280, str);
  
	setfillstyle(SOLID_FILL, RED);
	settextstyle(8, 0, 3);
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	setbkcolor(RED);
	bar(280,410,390,460);
	rectangle(283, 413, 387, 457);
	outtextxy(290, 425, "DELETE");
	
	setfillstyle(SOLID_FILL, RED);
	settextstyle(8, 0, 3);
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	setbkcolor(RED);
	bar(50,410,160,460);
	rectangle(53, 413, 157, 457);
	outtextxy(75, 425, "EDIT");

  thongbao = "Da hien thi doc gia";
  notice_frame();
}
void reader_information_function2(TheDocGia R){
  reader_information_frame();
  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);
  
  string s;
  char str[20];

  strcpy(str, to_string(R.MaThe).c_str());
  outtextxy(155, 80, str);
  strcpy(str, R.Ho.c_str());
  outtextxy(155, 130, str);
  strcpy(str, R.Ten.c_str());
  outtextxy(155, 180, str);
  strcpy(str, R.Phai.c_str());
  outtextxy(155, 230, str);
  s = (R.TrangThai == 1) ? "Binh thuong" : "Khoa";
  strcpy(str, s.c_str());
  outtextxy(155, 280, str);
  
	setfillstyle(SOLID_FILL, RED);
	settextstyle(8, 0, 3);
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	setbkcolor(RED);
	bar(170, 405, 280, 455);
	rectangle(173, 408, 277, 452);
	outtextxy(180, 420, "DELETE");

  thongbao = "Da hien thi doc gia";
  notice_frame();
}
void reader_information_function3(TheDocGia R){
	info_status();
	setcolor(BLACK);
	setbkcolor(LIGHTGRAY);
	settextstyle(3, 0, 1);
	string s;
	char str[20];
  //Ten
	strcpy(str, (R.Ho + " " + R.Ten).c_str());
	outtextxy(670, 192, str);
  //Ma the
  s = to_string(R.MaThe);
  strcpy(str, s.c_str());
  outtextxy(670, 232, str);
  //Trang thai
  s = (R.TrangThai == 1) ? "Binh thuong" : "Khoa";
	strcpy(str, s.c_str()); 
	outtextxy(670, 272, str);
  //Gioi tinh
	s = (R.Phai == "1") ? "Nu" : "Nam";
	strcpy(str, s.c_str()); 
	outtextxy(670, 312, str);
  //So sach da muon
  strcpy(str,to_string(R.SoSachDaMuon).c_str());
  outtextxy(670, 352, str);
  //So sach dang muon
  strcpy(str, to_string(R.SoSachDangMuon).c_str());
  outtextxy(670, 392, str);
}
void reader_information_function4(TheDocGia R){
	info_borrow_reader(R);
	setcolor(BLACK);
	setbkcolor(LIGHTGRAY);
	settextstyle(3, 0, 1);
	string s;
	char str[20];
	strcpy(str, (R.Ho + " " + R.Ten).c_str());
	outtextxy(160, 192, str);
	s = (R.TrangThai == 1) ? "Binh thuong" : "Khoa";
	strcpy(str, s.c_str());
	outtextxy(245, 232, str);
	s = (R.Phai == "1") ? "Nu" : "Nam";
	strcpy(str, s.c_str()); 
	outtextxy(245, 272, str);
  strcpy(str,to_string(R.SoSachDaMuon).c_str());
  outtextxy(245, 312, str);
  strcpy(str, to_string(R.SoSachDangMuon).c_str());
  outtextxy(245, 352, str);
}
void expired_reader_frame(){
	setfillstyle(9, LIGHTGRAY);
	bar(0, 0, XMAX, 120);
	bar(0, 720, XMAX, YMAX);
	setfillstyle(9, WHITE);
	bar(0, 110, XMAX, 120);
	bar(0, 0, XMAX, 10);
	bar(0, 0, 10, 120);
	bar(XMAX - 10, 0, XMAX, 120);
	bar(0, 710, XMAX, 720);
	setlinestyle(3, 0, 2);
	setcolor(BLACK);
	line(11, 11, XMAX - 11, 11);
	line(11, 11, 11, 109);
	line(11, 109, XMAX - 11, 109);
	line(XMAX - 11, 11, XMAX - 11, 109);
	
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(XMAX / 2 - 450, 30, XMAX / 2 + 450, 90);
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(235, 32, 1131, 88);
	setcolor(YELLOW);
	settextstyle(6, 0, 4);
	outtextxy(275, 45, "DANH SACH DOC GIA MUON QUA HAN");
	
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(3, 123, 1363, 680);
	rectangle(6, 126, 136, 166); // MA DOC GIA
	rectangle(140, 126, 440, 166); //HO TEN DOC GIA
	rectangle(444, 126, 594, 166); //MA SACH
	rectangle(598, 126, 898, 166); //TEN SACH
	rectangle(902, 126, 1116, 166); //NGAY MUON
	rectangle(1120, 126, 1360, 166); //SO NGAY QUA HAN
	settextstyle(8, 0, 3);
	setcolor(YELLOW);
	setbkcolor(DARKGRAY);
	outtextxy(24, 136, "MA THE");
	outtextxy(180, 136, "HO TEN DOC GIA");
	outtextxy(464, 136, "MA SACH");
	outtextxy(688, 136, "TEN SACH");
	outtextxy(942, 136, "NGAY MUON");
	outtextxy(1130, 136, "SO NGAY QUA HAN");
	
	setlinestyle(2, 1, 1);
	setcolor(WHITE);
	line(138, 167, 138, 680);
	line(442, 167, 442, 680);
	line(596, 167, 596, 680);
	line(900, 167, 900, 680);
	line(1118, 167, 1118, 680);
	
	settextstyle(10, 0, 2);
	setcolor(WHITE);
	outtextxy(1260, 685, "PAGE 1/1");
	
	setfillstyle(SOLID_FILL, RED);
	setcolor(YELLOW);
	setbkcolor(RED);
	setlinestyle(0, 0, 1);
	settextstyle(8, 0, 3);
	bar(1221, 724, 1361, 764); //NEXT
	rectangle(1224, 727, 1358, 761);
	outtextxy(1236, 732, "NEXT -->");
	bar(1061, 724, 1201, 764); //PREV
	rectangle(1064, 727, 1198, 761);
	outtextxy(1066, 732, "<-- PREV");
	bar(5, 724, 140, 764); //BACK
	rectangle(8, 727, 137, 761);
	setlinestyle(0, 0, 1);
	line(10, 744, 30, 734);
	line(10, 744, 30, 754);
	line(30, 734, 30, 754);
	rectangle(30, 739, 60, 749);
	outtextxy(70, 732, "BACK");
	setcolor(WHITE);
	line(30, 739, 30, 749);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(20, 744, YELLOW);
}	
void required_id_reader_frame(){
	setbkcolor(DARKGRAY);
	cleardevice();
	setfillstyle(9, LIGHTGRAY);
	bar(0, 0, XMAX, 120);
	bar(0, 720, XMAX, YMAX);
	setfillstyle(9, WHITE);
	bar(0, 110, XMAX, 120);
	bar(0, 0, XMAX, 10);
	bar(0, 0, 10, 120);
	bar(XMAX - 10, 0, XMAX, 120);
	bar(0, 710, XMAX, 720);
	setlinestyle(3, 0, 2);
	setcolor(BLACK);
	line(11, 11, XMAX - 11, 11);
	line(11, 11, 11, 109);
	line(11, 109, XMAX - 11, 109);
	line(XMAX - 11, 11, XMAX - 11, 109);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(XMAX / 2 - 300, 30, XMAX / 2 + 300, 90);
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(385, 32, 981, 88);
	setcolor(YELLOW);
	settextstyle(6, 0, 4);
	outtextxy(530, 45, "QUAN LI SACH");
	
	
	setfillstyle(SOLID_FILL, BLACK);
	bar(433, 283, 933, 483);
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(436, 286, 930, 480);
	setcolor(GREEN);
	settextstyle(8, 0, 2);
	setbkcolor(BLACK);
	outtextxy(450, 300, "Nhap ma doc gia: (         )");
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	line(680, 310, 690, 305);
	line(680, 310, 690, 315);
	line(680, 313, 690, 318);
	outtextxy(700, 300, "30000");
	setfillstyle(SOLID_FILL, WHITE);
	bar(550, 330, 916, 355);
	settextstyle(4, 0, 1);
	outtextxy(540, 333, ":");
	line(510, 343, 490, 333);
	line(510, 343, 490, 353);
	line(495, 343, 490, 333);
	line(495, 343, 490, 353);
	floodfill(505, 343, WHITE);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(450, 426, 916, 466);
	settextstyle(8, 0, 2);
	setcolor(CYAN);
	outtextxy(540, 365, "(  ESC: Thoat ve MENU  )");
	settextstyle(8, 0, 2);
	setcolor(YELLOW);
	outtextxy(450, 395, "Notification: ");
}
void info_return_reader(){
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar(383, 133, 983, 423);
	setcolor(CYAN);
	setlinestyle(0, 0, 2);
	rectangle(388, 138, 978, 418);
	line(530, 160, 835, 160);
	settextstyle(4, 0, 2);
	setcolor(BLUE);
	setbkcolor(WHITE);
	outtextxy(530, 137, "THONG TIN DOC GIA");
	
	settextstyle(8, 0, 3);
	setcolor(BLACK);
	outtextxy(395, 190, "HO VA TEN        :");
	outtextxy(395, 230, "TT THE           :");
	outtextxy(395, 270, "GIOI TINH        :");
	outtextxy(395, 310, "SO SACH DA MUON  :");
	outtextxy(395, 350, "SO SACH CHUA TRA :");
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(665, 192, 965, 212);
	bar(665, 232, 965, 252);
	bar(665, 272, 965, 292);
	bar(665, 312, 965, 332);
	bar(665, 352, 965, 372);
	
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(11, 500, 1355, 700);
	rectangle(15, 504, 365, 544);
	rectangle(369, 504, 469, 544);
	rectangle(473, 504, 643, 544);
	rectangle(647, 504, 817, 544);
	rectangle(821, 504, 1011, 544);
	rectangle(1015, 504, 1215, 544);
	rectangle(1219, 504, 1351, 544);
	setlinestyle(2, 1, 1);
	line(367, 545, 367, 700);
	line(471, 545, 471, 700);
	line(645, 545, 645, 700);
	line(819, 545, 819, 700);
	line(1013, 545, 1013, 700);
	line(1217, 545, 1217, 700);
	settextstyle(8, 0, 2);
	setcolor(YELLOW);
	setbkcolor(DARKGRAY);
	outtextxy(140, 515, "TEN SACH");
	outtextxy(377, 515, "MA SACH");
	outtextxy(505, 515, "NGAY MUON");
	outtextxy(683, 515, "NGAY TRA");
	outtextxy(825, 515, "SO NGAY DA MUON");
	outtextxy(1050, 515, "VI TRI SACH");
	outtextxy(1223, 515, "TRANG THAI");
	
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(468, 450, 908, 500);
	rectangle(472, 454, 904, 496);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	floodfill(473, 455, WHITE);
	setfillstyle(8, BLACK);
	floodfill(473, 452, WHITE);
	settextstyle(8, 0, 3);
	setbkcolor(LIGHTGRAY);
	setcolor(BLACK);
	outtextxy(500, 465, "DANH SACH SACH DANG MUON");
}
void display_list_header_book(){
  
  setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(424, 133, 1360, 680);
	rectangle(428, 137, 668, 177); //DAU SACH
	rectangle(672, 137, 742, 177); //ISBN
	rectangle(746, 137, 926, 177); //TAC GIA
	rectangle(930, 137, 1110, 177); //THE LOAI
	rectangle(1114, 137, 1244, 177); //SO TRANG
	rectangle(1248, 137, 1356, 177); //NAM XUAT BAN
	
	int w, h;
	setcolor(YELLOW);
	setbkcolor(DARKGRAY);
	settextstyle(8, 0, 2);
	w = width("DAU SACH"); h = height("DAU SACH");
	outtextxy((428 + 668 - w) / 2, (137 + 177 - h) / 2, "DAU SACH");
	w = width("ISBN"); h = height("ISBN");
	outtextxy((672 + 742 - w) / 2, (137 + 177 - h) / 2, "ISBN");
	w = width("TAC GIA"); h = height("TAC GIA");
	outtextxy((746 + 926 - w) / 2, (137 + 177 - h) / 2, "TAC GIA");
	w = width("THE LOAI"); h = height("THE LOAI");
	outtextxy((930 + 1110 - w) / 2, (137 + 177 - h) / 2, "THE LOAI");
	w = width("SO TRANG"); h = height("SO TRANG");
	outtextxy((1114 + 1244 - w) / 2, (137 + 177 - h) / 2, "SO TRANG");
	w = width("NXB"); h = height("NXB");
	outtextxy((1248 + 1356 - w) / 2, (137 + 177 - h) / 2, "NXB");
	
	setlinestyle(2, 1, 1);
	setcolor(WHITE);
	line(670, 178, 670, 680);
	line(744, 178, 744, 680);
	line(928, 178, 928, 680);
	line(1112, 178, 1112, 680);
	line(1246, 178, 1246, 680);
	
	setlinestyle(0, 0, 1); 
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, RED);
	bar(1330, 685, 1360, 705); //NEXT PAGE BUTTON
	bar(1170, 685, 1200, 705); //PREVIOUS PAGE BUTTON
	setcolor(WHITE);
	settextstyle(10, 0, 2);
	w = width("PAGE 1/1"); h = height("PAGE 1/1");
	outtextxy((1200 + 1330 - w) / 2, (685 + 705 - h) / 2, "PAGE 1/1");
	settextstyle(10, 0, 1);
	setbkcolor(RED);
	w = width(">"); h = height(">");
	outtextxy((1330 + 1360 - w) / 2, (685 + 705 - h) / 2, ">");
	outtextxy((1170 + 1200 - w) / 2, (685 + 705 - h) / 2, "<");
	settextstyle(8, 0, 1);
	setcolor(LIGHTCYAN);
	setbkcolor(DARKGRAY);
	h = height("ESC");
	outtextxy(424, (685 + 705 - h) / 2, "ESC: Tro lai   ENTER: Chon   Mui ten ^ - v: Di chuyen");
}
void display_list_books(){
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(824, 133, 1360, 680);
	rectangle(828, 137, 958, 177); //MA SACH
	rectangle(962, 137, 1142, 177); //TRANG THAI
	rectangle(1146, 137, 1356, 177); //VI TRI SACH
	setlinestyle(2, 1, 1);
	line(960, 178, 960, 680);
	line(1146, 178, 1146, 680);
	int w, h;
	setcolor(YELLOW);
	setbkcolor(DARKGRAY);
	settextstyle(8, 0, 2);
	w = width("MA SACH"); h = height("MA SACH");
	outtextxy((828 + 958 - w)  / 2, (137 + 177 - h) / 2, "MA SACH");
	w = width("TRANG THAI"); h = height("TRANG THAI");
	outtextxy((962 + 1142 -  w) / 2, (137 + 177 - h) / 2, "TRANG THAI");
	w = width("VI TRI"); h = height("VI TRI");
	outtextxy((1146 + 1356 - w) / 2, (137 + 177 - h) / 2, "VI TRI");
	setlinestyle(0, 0, 1); 
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, RED);
	bar(1330, 685, 1360, 705); //NEXT PAGE BUTTON
	bar(1170, 685, 1200, 705); //PREVIOUS PAGE BUTTON
	setcolor(WHITE);
	settextstyle(10, 0, 2);
	w = width("PAGE 1/1"); h = height("PAGE 1/1");
	outtextxy((1200 + 1330 - w) / 2, (685 + 705 - h) / 2, "PAGE 1/1");
	settextstyle(10, 0, 1);
	setbkcolor(RED);
	w = width(">"); h = height(">");
	outtextxy((1330 + 1360 - w) / 2, (685 + 705 - h) / 2, ">");
	outtextxy((1170 + 1200 - w) / 2, (685 + 705 - h) / 2, "<");
	settextstyle(8, 0, 1);
	setcolor(LIGHTCYAN);
	setbkcolor(DARKGRAY);
	h = height("ESC");
	outtextxy(424, (685 + 705 - h) / 2, "ESC: Tro lai   ENTER: Chon   Mui ten ^ - v: Di chuyen");
}
void info_borrow_reader(TheDocGia R){
	//THONG TIN DOC GIA MUON SACH
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar(13, 133, 413, 423);
	setcolor(CYAN);
	setlinestyle(0, 0, 2);
	rectangle(18, 138, 408, 418);
	line(60, 160, 366, 160);
	settextstyle(4, 0, 2);
	setcolor(BLUE);
	setbkcolor(WHITE);
	outtextxy(60, 137, "THONG TIN DOC GIA");
	
	settextstyle(8, 0, 2);
	setcolor(BLACK);
	outtextxy(21, 190, "HO VA TEN :");
	outtextxy(21, 230, "TT THE           :");
	outtextxy(21, 270, "GIOI TINH        :");
	outtextxy(21, 310, "SO SACH DA MUON  :");
	outtextxy(21, 350, "SO SACH CHUA TRA :");
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(155, 192, 400, 212);
	bar(240, 232, 400, 252);
	bar(240, 272, 400, 292);
	bar(240, 312, 400, 332);
	bar(240, 352, 400, 372);
	//CAC SACH DANG MUON
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(60, 450, 366, 490);
	rectangle(65, 455, 361, 485);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	floodfill(66, 456, WHITE);
	setfillstyle(8, BLACK);
	floodfill(61, 451, WHITE);
	settextstyle(8, 0, 2);
	setcolor(BLACK);
	setbkcolor(LIGHTGRAY);
	outtextxy(95, 460, "CAC SACH DANG MUON");
	
	setcolor(WHITE);
	rectangle(13, 495, 413, 705);
	rectangle(17, 499, 267, 539);
	rectangle(271, 499, 409, 539);
	setlinestyle(2, 1, 1);
	line(269, 540, 269, 705);
	setlinestyle(2, 0, 2);
	line(418, 120, 418, 710);
	
	settextstyle(8, 0, 2);
	setcolor(YELLOW);
	setbkcolor(DARKGRAY);
	outtextxy(95, 510, "TEN SACH");
	outtextxy(285, 510, "NGAY MUON");

  //Hien thi sach dang muon
  settextstyle(3, 0, 1);
  setcolor(WHITE);
  char str[30];
  string s;
  NODE_DOUBLY_LIST *p = R.DoublyList_MuonTra.head;
  int k = 0;
  while(p && p->data.TrangThai==0){
    //Hien thi ten sach dang muon
    s = TimTenSachBangMaSach(DSDS, p->data.MaSach);
    strcpy(str, s.c_str());
    outtextxy(18, 550 + k, str);

    //Hien thi ngay muon sach dang muon
    s = to_string(p->data.NgayMuon.Ngay) + "/" + to_string(p->data.NgayMuon.Thang) + "/" + to_string(p->data.NgayMuon.Nam);
    strcpy(str, s.c_str());
    outtextxy(519 - width(s) / 2, 550 + k, str);

    k += 30;
  }

  //NOTI
	
	
	//DANH SACH DAU SACH TIEN HANH MUON
//	display_list_header_book();
	//DANH SACH NHUNG CUON SACH THUOC DAU SACH DA CHON
//	display_list_books();
}
void book_management_gui(){
	setbkcolor(DARKGRAY);
	cleardevice();
	setfillstyle(9, LIGHTGRAY);
	bar(0, 0, XMAX, 120);
	bar(0, 720, XMAX, YMAX);
	setfillstyle(9, WHITE);
	bar(0, 110, XMAX, 120);
	bar(0, 0, XMAX, 10);
	bar(0, 0, 10, 120);
	bar(XMAX - 10, 0, XMAX, 120);
	bar(0, 710, XMAX, 720);
	setlinestyle(3, 0, 2);
	setcolor(BLACK);
	line(11, 11, XMAX - 11, 11);
	line(11, 11, 11, 109);
	line(11, 109, XMAX - 11, 109);
	line(XMAX - 11, 11, XMAX - 11, 109);
	
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(XMAX / 2 - 300, 30, XMAX / 2 + 300, 90);
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(385, 32, 981, 88);
	setcolor(YELLOW);
	settextstyle(6, 0, 4);
	outtextxy(530, 45, "QUAN LI SACH");
		
	setfillstyle(SOLID_FILL, RED);
	setcolor(YELLOW);
	setbkcolor(RED);
	setlinestyle(0, 0, 1);
	settextstyle(8, 0, 3);
	bar(5, 724, 140, 764); //BACK
	rectangle(8, 727, 137, 761);
	setlinestyle(0, 0, 1);
	line(10, 744, 30, 734);
	line(10, 744, 30, 754);
	line(30, 734, 30, 754);
	rectangle(30, 739, 60, 749);
	outtextxy(70, 732, "BACK");
	setcolor(WHITE);
	line(30, 739, 30, 749);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(20, 744, YELLOW);
	
	setfillstyle(SOLID_FILL, RED);
	setcolor(YELLOW);
	setbkcolor(RED);
	settextstyle(8, 0, 3);
	setlinestyle(0, 0, 1);
	settextstyle(8, 0, 3);
	bar(701, 724, 1001, 764); //TRA SACH
	rectangle(704, 727, 998, 761);
	outtextxy(791, 732, "TRA SACH");
	bar(1061, 724, 1361, 764); //MUON SACH
	rectangle(1064, 727, 1358, 761);
	outtextxy(1154, 732, "MUON SACH");
	
}
void top_10_borrowing_books(DauSach *DS[]){
	setbkcolor(DARKGRAY);
	cleardevice();
	setfillstyle(9, LIGHTGRAY);
	bar(0, 0, XMAX, 120);
	bar(0, 720, XMAX, YMAX);
	setfillstyle(9, WHITE);
	bar(0, 110, XMAX, 120);
	bar(0, 0, XMAX, 10);
	bar(0, 0, 10, 120);
	bar(XMAX - 10, 0, XMAX, 120);
	bar(0, 710, XMAX, 720);
	setlinestyle(3, 0, 2);
	setcolor(BLACK);
	line(11, 11, XMAX - 11, 11);
	line(11, 11, 11, 109);
	line(11, 109, XMAX - 11, 109);
	line(XMAX - 11, 11, XMAX - 11, 109);
	
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(XMAX / 2 - 430, 30, XMAX / 2 + 430, 90);
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(255, 32, 1111, 88);
	setcolor(YELLOW);
	settextstyle(6, 0, 4);
	outtextxy(260, 45, "10 DAU SACH DUOC MUON NHIEU NHAT");
	
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(205, 150, 1161, 625);
	rectangle(209, 154, 269, 194); //STT
	rectangle(273, 154, 690, 194); //TEN SACH
	rectangle(694, 154, 1157, 194); //SO LUOT MUON SACH CUA DAU SACH
	setcolor(YELLOW);
	settextstyle(8, 0, 3);
	outtextxy(217, 164, "STT");
	outtextxy(420, 164, "TEN SACH");
	outtextxy(703, 164, "SO LUOT MUON SACH CUA DAU SACH");
	
	setcolor(WHITE);
	setlinestyle(2, 1, 1);
	line(271, 195, 271, 625);
	line(692, 195, 692, 625);
	line(1159, 195, 1159, 195);
	
	settextstyle(10, 0, 3);
  char str[30];
  for (int i = 0, j=0; i < 10;i++,j+=40){
    strcpy(str, to_string(i + 1).c_str());
    outtextxy(230, 219+j, str);

    strcpy(str,DS[i]->TenSach.c_str());
    outtextxy(280 , 219 + j, str);

    strcpy(str, to_string(DS[i]->SoLanMuon).c_str());
    outtextxy(925 - width(to_string(DS[i]->SoLanMuon)) / 2, 219 + j, str);
  }
	
	setfillstyle(SOLID_FILL, RED);
	setcolor(YELLOW);
	setbkcolor(RED);
	setlinestyle(0, 0, 1);
	settextstyle(8, 0, 3);
	bar(5, 724, 140, 764); //BACK
	rectangle(8, 727, 137, 761);
	setlinestyle(0, 0, 1);
	line(10, 744, 30, 734);
	line(10, 744, 30, 754);
	line(30, 734, 30, 754);
	rectangle(30, 739, 60, 749);
	outtextxy(70, 732, "BACK");
	setcolor(WHITE);
	line(30, 739, 30, 749);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(20, 744, YELLOW);
	
}
void info_status(){ //Thong tin hien ra sau khi nhap ma 
 	setbkcolor(DARKGRAY);
	cleardevice();
	setfillstyle(9, LIGHTGRAY);
	bar(0, 0, XMAX, 120);
	bar(0, 720, XMAX, YMAX);
	setfillstyle(9, WHITE);
	bar(0, 110, XMAX, 120);
	bar(0, 0, XMAX, 10);
	bar(0, 0, 10, 120);
	bar(XMAX - 10, 0, XMAX, 120);
	bar(0, 710, XMAX, 720);
	setlinestyle(3, 0, 2);
	setcolor(BLACK);
	line(11, 11, XMAX - 11, 11);
	line(11, 11, 11, 109);
	line(11, 109, XMAX - 11, 109);
	line(XMAX - 11, 11, XMAX - 11, 109);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(XMAX / 2 - 300, 30, XMAX / 2 + 300, 90);
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(385, 32, 981, 88);
	setcolor(YELLOW);
	settextstyle(6, 0, 4);
	outtextxy(530, 45, "QUAN LI SACH");
 	
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar(383, 133, 983, 423);
	setcolor(CYAN);
	setlinestyle(0, 0, 2);
	rectangle(388, 138, 978, 418);
	line(530, 160, 835, 160);
	settextstyle(4, 0, 2);
	setcolor(BLUE);
	setbkcolor(WHITE);
	outtextxy(530, 137, "THONG TIN DOC GIA");
	
	settextstyle(8, 0, 3);
	setcolor(BLACK);
	outtextxy(395, 190, "HO VA TEN        :");
  outtextxy(395, 230, "MA THE          :");
  outtextxy(395, 270, "TT THE           :");
	outtextxy(395, 310, "GIOI TINH        :");
	outtextxy(395, 350, "SO SACH DA MUON  :");
	outtextxy(395, 390, "SO SACH DANG MUON:");
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(665, 192, 965, 212);
	bar(665, 232, 965, 252);
	bar(665, 272, 965, 292);
	bar(665, 312, 965, 332);
	bar(665, 352, 965, 372);
  bar(665, 392, 965, 412);
	
	setfillstyle(SOLID_FILL, RED);
	setcolor(YELLOW);
	setbkcolor(RED);
	setlinestyle(0, 0, 1);
	settextstyle(8, 0, 3);
	bar(5, 724, 140, 764); //BACK
	rectangle(8, 727, 137, 761);
	setlinestyle(0, 0, 1);
	line(10, 744, 30, 734);
	line(10, 744, 30, 754);
	line(30, 734, 30, 754);
	rectangle(30, 739, 60, 749);
	outtextxy(70, 732, "BACK");
	setcolor(WHITE);
	line(30, 739, 30, 749);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(20, 744, YELLOW);
	setfillstyle(SOLID_FILL, RED);
	setcolor(YELLOW);
	setbkcolor(RED);
	settextstyle(8, 0, 3);
	setlinestyle(0, 0, 1);
	settextstyle(8, 0, 3);
	bar(701, 724, 1001, 764); //TRA SACH
	rectangle(704, 727, 998, 761);
	outtextxy(791, 732, "TRA SACH");
	bar(1061, 724, 1361, 764); //MUON SACH
	rectangle(1064, 727, 1358, 761);
	outtextxy(1154, 732, "MUON SACH");
 }
 
 void list_borrowing_book1(TheDocGia x, int index){
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(11, 500, 1355, 700);
  rectangle(15, 504, 85, 544);//stt
  rectangle(89, 504, 539, 544);//ten sach
	rectangle(543, 504, 643, 544);//ma sach
	rectangle(647, 504, 817, 544);//ngay muon
	// rectangle(647, 504, 817, 544);//ngay tra
	rectangle(821, 504, 1011, 544);//so ngay da muon
	rectangle(1015, 504, 1215, 544);//vi tri
	rectangle(1219, 504, 1351, 544);//trang thai
	setlinestyle(2, 1, 1);
	line(87, 545, 87, 700);
	line(541, 545, 541, 700);
	line(645, 545, 645, 700);
	line(819, 545, 819, 700);
	line(1013, 545, 1013, 700);
	line(1217, 545, 1217, 700);
	settextstyle(8, 0, 2);
	setcolor(YELLOW);
	setbkcolor(DARKGRAY);
  outtextxy(50 - width("STT") / 2, 515, "STT");
  outtextxy(314 - width("TEN SACH") / 2, 515, "TEN SACH");
  outtextxy(593 - width("MA SACH") / 2, 515, "MA SACH");
  outtextxy(732 - width("NGAY MUON") / 2, 515, "NGAY MUON");
  outtextxy(916 - width("SO NGAY DA MUON") / 2, 515, "SO NGAY DA MUON");
  outtextxy(1115 - width("VI TRI SACH") / 2, 515, "VI TRI SACH");
  outtextxy(1285 - width("TRANG THAI") / 2, 515, "TRANG THAI");

  NODE_DOUBLY_LIST *p = x.DoublyList_MuonTra.head;
  DauSach *DS;
  NODE_SINGLY_LIST *q;
  char str[30];
  string s;
  int k = 0;
  int i = 0;
  setcolor(WHITE);
  settextstyle(10, 0, 2);

  while(p){
    if(i==index){
      setcolor(RED);
    }
    else{
      setcolor(WHITE);
    }
    if(p->data.TrangThai==0){
      //STT
      s = to_string(i + 1);
      strcpy(str, s.c_str());
      outtextxy(50 - width(s) / 2, 560 + k, str);

      //Ten sach
      DS = TimSachBangMaSach(DSDS, p->data.MaSach);
      strcpy(str, DS->TenSach.c_str());
      outtextxy(95, 560 + k, str);

      //Ma sach
      strcpy(str,p->data.MaSach.c_str());
      outtextxy(593 - width(p->data.MaSach) / 2, 560 + k, str);

      //Ngay muon
      s = to_string(p->data.NgayMuon.Ngay) + "/" + to_string(p->data.NgayMuon.Thang) + "/" + to_string(p->data.NgayMuon.Nam);
      strcpy(str, s.c_str());
      outtextxy(732 - width(s) / 2, 560 + k, str);

      //So ngay da muon
      s = to_string(SoNgayMuon(p->data.NgayMuon.Ngay, p->data.NgayMuon.Thang, p->data.NgayMuon.Nam));
      strcpy(str, s.c_str());
      outtextxy(916 - width(s) / 2, 560 + k, str);

      //Vi tri sach
      q = Search_NodeSach(DS->dms, p->data.MaSach);
      strcpy(str, q->data.vitri.c_str());
      outtextxy(1115 - width(q->data.vitri) / 2, 560 + k, str);

      //Trang thai
      if(SoNgayMuon(p->data.NgayMuon.Ngay, p->data.NgayMuon.Thang, p->data.NgayMuon.Nam)<=7){
        s = "Dang muon";
      }
      else{
        s = "Qua han 7d";
      }
      strcpy(str, s.c_str());
      outtextxy(1285 - width(s) / 2, 560 + k, str);

      k += 50;
      i++;
    }
    p = p->next;
  }

  setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(468, 450, 908, 500);
	rectangle(472, 454, 904, 496);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	floodfill(473, 455, WHITE);
	setfillstyle(8, BLACK);
	floodfill(473, 452, WHITE);
	settextstyle(8, 0, 3);
	setbkcolor(LIGHTGRAY);
	setcolor(BLACK);
	outtextxy(500, 465, "DANH SACH SACH DANG MUON");
}
void background_borrow_return(){
	setbkcolor(DARKGRAY);
	cleardevice();
	setfillstyle(9, LIGHTGRAY);
	bar(0, 0, XMAX, 120);
	bar(0, 720, XMAX, YMAX);
	setfillstyle(9, WHITE);
	bar(0, 110, XMAX, 120);
	bar(0, 0, XMAX, 10);
	bar(0, 0, 10, 120);
	bar(XMAX - 10, 0, XMAX, 120);
	bar(0, 710, XMAX, 720);
	setlinestyle(3, 0, 2);
	setcolor(BLACK);
	line(11, 11, XMAX - 11, 11);
	line(11, 11, 11, 109);
	line(11, 109, XMAX - 11, 109);
	line(XMAX - 11, 11, XMAX - 11, 109);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(XMAX / 2 - 300, 30, XMAX / 2 + 300, 90);
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	rectangle(385, 32, 981, 88);
	setcolor(YELLOW);
	settextstyle(6, 0, 4);
	outtextxy(530, 45, "QUAN LI SACH");
	
	setfillstyle(SOLID_FILL, RED);
	setcolor(YELLOW);
	setbkcolor(RED);
	setlinestyle(0, 0, 1);
	settextstyle(8, 0, 3);
	bar(5, 724, 140, 764); //BACK
	rectangle(8, 727, 137, 761);
	setlinestyle(0, 0, 1);
	line(10, 744, 30, 734);
	line(10, 744, 30, 754);
	line(30, 734, 30, 754);
	rectangle(30, 739, 60, 749);
	outtextxy(70, 732, "BACK");
	setcolor(WHITE);
	line(30, 739, 30, 749);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(20, 744, YELLOW);
	// setfillstyle(SOLID_FILL, RED);
	// setcolor(YELLOW);
	// setbkcolor(RED);
	// settextstyle(8, 0, 3);
	// setlinestyle(0, 0, 1);
	// settextstyle(8, 0, 3);
	
  // // SEARCH_BUTTON(950, 720);
  // bar(950, 724, 1050, 764);
  // rectangle(953, 727, 1047, 761);
  // outtextxy(1000 - width("SEARCH") / 2, 744 - height("SEARCH") / 2, "SEARCH");


}

void list_book_background(){
  setbkcolor(8);
  cleardevice();
  list_book();
  book_header_button();
  notice_frame3();

}

void list_books(){ //HIEN THI DACH MUC SACH THUOC MOT DAU SACH
	setbkcolor(8);
	setfillstyle(SOLID_FILL, WHITE);
	cleardevice();
	setcolor(15);
	rectangle(750, 50, 1364, 701);
	rectangle(753, 53, 893, 93); // MA SACH
	rectangle(897, 53, 1097, 93);  // TRANG THAI
	rectangle(1101, 53, 1361, 93); // VI TRI
	
	setlinestyle(2, 1, 1);
	line(895, 94, 895, 701);
	line(1099, 94, 1099, 701);
	
	setcolor(YELLOW);
	settextstyle(8, 0, 3);
	setbkcolor(DARKGRAY);
	int w; //y = 63
	w = width("MA SACH");
	outtextxy((753 + 893 - w) / 2, 63, "MA SACH");
	w = width("TRANG THAI");
	outtextxy((897 + 1097 - w)/ 2, 63, "TRANG THAI");
	w = width("VI TRI");
	outtextxy((1101 + 1361 - w) / 2, 63, "VI TRI");
}
void guide_frame3(){ //HUONG DAN CAP NHAT DANH MUC SACH
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
	outtextxy(20, 560, "MA SACH ");
	outtextxy(20, 590, "TRANG THAI  ");
	outtextxy(20, 670, "VI TRI  ");
	outtextxy(160, 560, "  Duoc danh tu dong");
	outtextxy(160, 590, "  0 - Cho muon duoc");
	outtextxy(160, 615, "  1 - Da duoc muon");
	outtextxy(160, 640, "  2 - Da thanh ly");
	outtextxy(160, 670, "  Toi da 17 ky tu, chi nhan ky tu chu, ");
	outtextxy(160, 695, "  ky tu so va dau gach ngang");
	settextstyle(4, 0, 1);
	outtextxy(155, 560, ":");
	outtextxy(155, 590, ":");
	outtextxy(155, 670, ":");
}
void info_header_book_frame(){ //BANG THONG TIN DAU SACH
	setfillstyle(SOLID_FILL, WHITE);
	bar(10, 10, 440, 320);
	setlinestyle(0, 3, 2);
	setcolor(0);
	rectangle(20, 20, 430, 310);
	setlinestyle(0, 1, 1);
	rectangle(25, 25, 425, 305);
	setcolor(RED);
	setbkcolor(WHITE);
	settextstyle(4, 0, 2);
	outtextxy(50, 30, "THONG TIN DAU SACH");
	setcolor(0);
	settextstyle(8, 0, 1);
	outtextxy(35, 80, "Ten sach: ");
	outtextxy(35, 120, "Tac gia: ");
	outtextxy(35, 160, "The loai: ");
	outtextxy(35, 200, "NXB: ");
	outtextxy(35, 240, "ISBN: ");
	outtextxy(35, 280, "Tong so sach cua dau sach: ");
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(150, 80, 415, 100);
	bar(150, 120, 415, 140);
	bar(150, 160, 415, 180);
	bar(150, 200, 415, 220);
	bar(150, 240, 415, 260);
	bar(330, 280, 415, 300);
}
void add_books_function(DauSach *DS, int SoSachCanNhap, int SoSachChuaNhap, int index, string Sach[][3]){ //BANG THEM DANH MUC SACH
	setfillstyle(SOLID_FILL, WHITE);
	bar(10, 10, 440, 250);
	setlinestyle(0, 3, 2);
	setcolor(0);
	rectangle(20, 20, 430, 240);
	setlinestyle(0, 1, 1);
	rectangle(25, 25, 425, 235);
	setbkcolor(YELLOW);
	setcolor(RED);
	settextstyle(4, 0, 2);
	outtextxy(140, 35, "THEM");
	setbkcolor(15);
	setcolor(0);
	settextstyle(3, 0, 1);
	outtextxy(35, 80, "Ma Sach");
	outtextxy(35, 130, "Trang Thai");
	outtextxy(35, 180, "Vi tri ");
	setfillstyle(SOLID_FILL, LIGHTGRAY);

  char str[20];
	for(int k=0, i=0;k<3;k++,i+=50){
    setbkcolor(WHITE);
    settextstyle(4, 0, 2);
		outtextxy(140, 80 + i, ":");
		bar(150, 80 + i, 415, 100 + i);
    strcpy(str, Sach[index][k].c_str());
    setbkcolor(LIGHTGRAY);
    settextstyle(3, 0, 1);
    outtextxy(155, 80 + i, str);
	}
	
  SAVE_BUTTON(170, 405);
  
      setfillstyle(SOLID_FILL, WHITE);
	bar(10, 270, 300, 310);
	setcolor(BLACK);
	setlinestyle(0, 0, 2);
	rectangle(15, 275, 295, 305);
	setcolor(BLUE);
	settextstyle(8, 0, 2);
	setbkcolor(WHITE);
	outtextxy(20, 280, "SO SACH MUON THEM: ");
  strcpy(str, to_string(SoSachCanNhap).c_str());
  outtextxy(20 + width("SO SACH MUON THEM: "), 280, str);

  
  

  //SO LUONG CAN NHAP
//	setfillstyle(SOLID_FILL, WHITE);
//	bar(10, 270, 270, 310);
//	setcolor(BLACK);
//	setlinestyle(0, 0, 2);
//	rectangle(15, 275, 265, 305);
//	setcolor(BLUE);
//	settextstyle(8, 0, 2);
//	setbkcolor(WHITE);
//	outtextxy(20, 280, "SO SACH CAN NHAP: ");
//  strcpy(str, to_string(SoSachCanNhap).c_str());
//  outtextxy(20 + width("SO SACH CAN NHAP: "), 280, str);
//
//  //SO LUONG CHUA NHAP
//  setfillstyle(SOLID_FILL, WHITE);
//	bar(10, 330, 280, 370);
//	setcolor(BLACK);
//	setlinestyle(0, 0, 2);
//	rectangle(15, 335, 275, 365);
//	setcolor(BLUE);
//	settextstyle(8, 0, 2);
//	setbkcolor(WHITE);
//	outtextxy(20, 340, "SO SACH CHUA NHAP: ");
//  strcpy(str, to_string(SoSachChuaNhap).c_str());
//  outtextxy(20 + width("SO SACH CHUA NHAP: "), 340, str);
}

void book_code_info(DanhMucSach DMS){ //BANG CAP NHAT DANH MUC SACH
  setfillstyle(SOLID_FILL, DARKGRAY);
  setfillstyle(SOLID_FILL, WHITE);
	bar(10, 10, 440, 250);
	setlinestyle(0, 3, 2);
	setcolor(0);
	rectangle(20, 20, 430, 240);
	setlinestyle(0, 1, 1);
	rectangle(25, 25, 425, 235);
	setbkcolor(YELLOW);
	setcolor(RED);
	settextstyle(4, 0, 2);
	outtextxy(140, 35, "THONG TIN");
	setbkcolor(15);
	setcolor(0);
	settextstyle(3, 0, 1);
	outtextxy(35, 80, "Ma Sach");
	outtextxy(35, 130, "Trang Thai");
	outtextxy(35, 180, "Vi tri ");
	setfillstyle(SOLID_FILL, LIGHTGRAY);

  char str[20];
	for(int k=0, i=0;k<3;k++,i+=50){
    setbkcolor(WHITE);
    settextstyle(4, 0, 2);
		outtextxy(140, 80 + i, ":");
		bar(150, 80 + i, 415, 100 + i);
	}
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);

  strcpy(str, DMS.masach.c_str());
  outtextxy(155, 80, str);
  if(DMS.trangthai==0){
    outtextxy(155, 130, "Cho muon duoc");
  }
  else if(DMS.trangthai==1){
    outtextxy(155, 130, "Da duoc muon");
  }
  else{
    outtextxy(155, 130, "Da thanh ly");
  }
  strcpy(str, DMS.vitri.c_str());
  outtextxy(155,180,str);

  DELETE_BUTTON(280, 270);
  EDIT_BUTTON(50, 270);
}

void update_book_code(DanhMucSach DMS){ //BANG CAP NHAT DANH MUC SACH
  setfillstyle(SOLID_FILL,DARKGRAY);
  bar(10, 10, 440, 400);
  setfillstyle(SOLID_FILL, WHITE);
	bar(10, 10, 440, 250);
	setlinestyle(0, 3, 2);
	setcolor(0);
	rectangle(20, 20, 430, 240);
	setlinestyle(0, 1, 1);
	rectangle(25, 25, 425, 235);
	setbkcolor(YELLOW);
	setcolor(RED);
	settextstyle(4, 0, 2);
	outtextxy(140, 35, "CAP NHAT ");
	setbkcolor(15);
	setcolor(0);
	settextstyle(3, 0, 1);
	outtextxy(35, 80, "Ma Sach");
	outtextxy(35, 130, "Trang Thai");
	outtextxy(35, 180, "Vi tri ");
	setfillstyle(SOLID_FILL, LIGHTGRAY);

  char str[20];
	for(int k=0, i=0;k<3;k++,i+=50){
    setbkcolor(WHITE);
    settextstyle(4, 0, 2);
		outtextxy(140, 80 + i, ":");
		bar(150, 80 + i, 415, 100 + i);
	}
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);

  strcpy(str, DMS.masach.c_str());
  outtextxy(155, 80, str);
  strcpy(str, to_string(DMS.trangthai).c_str());
  outtextxy(155, 130, str);
  strcpy(str, DMS.vitri.c_str());
  outtextxy(155,180,str);

  SAVE_BUTTON(170, 270);
}

void required_quantity_frame(){ //Khung nhap so luong sach can them vao 1 dau sach
	setfillstyle(SOLID_FILL, BLACK);
	bar(10, 50, 440, 150);
	setlinestyle(0, 0, 2);
	setcolor(GREEN);
	rectangle(13, 53, 437, 147);
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(15, 55, 435, 145);
	setbkcolor(0);
	settextstyle(3, 0, 2);
	outtextxy(25, 60, "Nhap so luong sach");
  outtextxy(25, 85, "So luong sach co the nhap: ");

  setlinestyle(0, 0, 1);
	line(40, 120, 54, 130);
	line(40, 140, 54, 130);
	line(40, 120, 44, 130);
	line(40, 140, 44, 130);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(45, 130, WHITE);
	settextstyle(4, 0, 1);
	setcolor(15);
	outtextxy(85, 120, ":");
	bar(95, 120, 420, 140);
}
void required_header_book_frame(){ //Khung nhap dau sach tien hanh cap nhap sach
	setfillstyle(SOLID_FILL, BLACK);
	bar(468, 95, 898, 195);
	setlinestyle(0, 0, 2);
	setcolor(GREEN);
	rectangle(471, 98, 895, 192);
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(473, 100, 893, 190);
	setbkcolor(0);
	settextstyle(3, 0, 2);
	outtextxy(483, 110, "Nhap dau sach: ");
	settextstyle(3, 0, 1);
	setcolor(LIGHTGRAY);
	outtextxy(498, 135, "(Toi da 24 ky tu, bao gom chu va so)");
	
	setcolor(WHITE);
	line(498, 165, 512, 175);
	line(498, 185, 512, 175);
	line(498, 165, 502, 175);
	line(498, 185, 502, 175);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(503, 175, WHITE);
	settextstyle(4, 0, 1);
	setcolor(15);
	outtextxy(543, 165, ":");
	bar(553, 165, 878, 185);
}


void add_header_book_frame(){ //BANG THEM DAU SACH
	setfillstyle(SOLID_FILL,WHITE);
	bar(468,405,898,480);
	setfillstyle(SOLID_FILL, WHITE);
	bar(468, 95, 898, 405);
	setlinestyle(0, 3, 2);
	setcolor(0);
	rectangle(478, 105, 888, 395);
	setlinestyle(0, 1, 1);
	rectangle(483, 110, 883, 390);
	setcolor(RED);
	setbkcolor(WHITE);
	settextstyle(4, 0, 2);
	outtextxy(683-width("THEM DAU SACH")/2, 115, "THEM DAU SACH");
	setcolor(0);
	settextstyle(8, 0, 1);
	outtextxy(493, 165, "Ten sach: ");
  outtextxy(493, 205, "ISBN: ");
	outtextxy(493, 245, "Tac gia: ");
	outtextxy(493, 285, "The loai: ");
  outtextxy(493, 325, "So trang: ");
  outtextxy(493, 365, "NXB: ");
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(608, 165, 873, 185);
	bar(608, 205, 873, 225);
	bar(608, 245, 873, 265);
	bar(608, 285, 873, 305);
	bar(608, 325, 873, 345);
  bar(608, 365, 873, 385);


  setfillstyle(SOLID_FILL, RED);
	settextstyle(8, 0, 3);
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	setbkcolor(RED);
	bar(628, 415, 738, 470);
	rectangle(631, 418, 735, 467);
	outtextxy(653, 430, "SAVE");
}

void add_header_book(){
  add_header_book_frame();
  guide_frame2();
}
void Display_DMS(pointerArray &DSDS,int page,int maxPage,int i){
  string s="";
  char str[30];
  settextstyle(10, 0, 2);
  setbkcolor(DARKGRAY);
  int books = 0;
  int maxBooksInPage = 0;
  if(page==maxPage){
    books = DSDS.nodesDauSach[i]->SoLuongSach - DSDS.nodesDauSach[i]->SoLuongSach % 20;
    maxBooksInPage = DSDS.nodesDauSach[i]->SoLuongSach - 1;
  }
  else{
    books = (page - 1) * 20;
    maxBooksInPage = books + 19;
  }
  s="PAGE "+to_string(page)+"/"+to_string(maxPage);
  strcpy(str, s.c_str());
  setcolor(WHITE);
	outtextxy(1235, 710, str);
  setbkcolor(DARKGRAY);
  setcolor(WHITE);
  settextstyle(10,0,2);

  NODE_SINGLY_LIST *p = DSDS.nodesDauSach[i]->dms.head;
  if(page>1){
    for (int i = 0; i < books;i++){
      p = p->next;
    }
  }
  int k = 0, w;
	for (int j = books, k=0; j <= maxBooksInPage;j++){
      //Ma sach
      strcpy(str, p->data.masach.c_str());
      w = width(p->data.masach);
      outtextxy((753 + 893 - w) / 2, 100+k, str);

      //Trang thai
      if(p->data.trangthai==0){
        s = "Co the muon";
      }
      else if(p->data.trangthai==1){
        s = "Da duoc muon";
      }
      else if(p->data.trangthai==2){
        s = "Da thanh ly";
      } 
      strcpy(str,s.c_str());
      w = width(s);
      outtextxy((897 + 1097 - w) / 2, 100+k, str);

      //Vi tri
      strcpy(str, p->data.vitri.c_str());
      w = width(p->data.vitri);
      outtextxy((1101 + 1361 - w) / 2, 100+k, str);

      k += 30;
      p = p->next;
    }
  }
void book_information_function(pointerArray &DSDS,string TenSach,int page,int maxPage){
  list_books();
  book_information_frame();
	setcolor(BLACK);
	setbkcolor(LIGHTGRAY);
	settextstyle(3, 0, 1);
  int i=Exist_DS(DSDS,TenSach);
	char str[30];

  //Thong tin dau sach
	strcpy(str,DSDS.nodesDauSach[i]->TenSach .c_str());
 	outtextxy(155, 80, str);
	strcpy(str, DSDS.nodesDauSach[i]->ISBN.c_str());
	outtextxy(155, 120, str);
	strcpy(str, DSDS.nodesDauSach[i]->TacGia.c_str());
	outtextxy(155, 160, str);
	strcpy(str, DSDS.nodesDauSach[i]->TheLoai.c_str());
	outtextxy(155, 200, str);
	strcpy(str, to_string(DSDS.nodesDauSach[i]->SoTrang).c_str());
	outtextxy(155, 240, str);
	strcpy(str, to_string(DSDS.nodesDauSach[i]->NamXuatBan).c_str());
	outtextxy(155, 280, str);
  strcpy(str, to_string(DSDS.nodesDauSach[i]->SoLuongSach).c_str());
  outtextxy(255, 320, str);
  strcpy(str, to_string(SoSachConLai(i)).c_str());
  outtextxy(255, 360, str);

  string s;
  settextstyle(10, 0, 2);
  setbkcolor(DARKGRAY);
  s = "PAGE " + to_string(page) + "/" + to_string(maxPage);
  strcpy(str, s.c_str());
  setcolor(WHITE);
  outtextxy(1235, 710, str);

  DELETE_BUTTON(280, 410);
  EDIT_BUTTON(50, 410);
  PREV_BUTTON(750, 5);
	NEXT_BUTTON(910, 5);
	BACK_BUTTON(1230, 5);
  ADD_BUTTON(750, 710);
  SEARCH_BUTTON(890, 710);

  //Danh muc sach
  if(DSDS.nodesDauSach[i]->SoLuongSach!=0){
  	Display_DMS(DSDS,page,maxPage,i);
  }
  else{
    thongbao = "Dau sach nay trong";
  }
  notice_frame();
}

void update_books_background(){
  setbkcolor(8);
  cleardevice();
  list_book();

  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
  PREV_BUTTON(460, 5);
  NEXT_BUTTON(620, 5);
  BACK_BUTTON(1230, 5);

  notice_frame3();

}

// void update_books_function(int i, int page, int maxPage){
//   list_books();
//   setfillstyle(SOLID_FILL, RED);
//   setcolor(YELLOW);
//   setbkcolor(RED);
//   settextstyle(8, 0, 3);
//   setlinestyle(0, 0, 1);
//   PREV_BUTTON();
//   NEXT_BUTTON();
//   BACK_BUTTON();

//   Display_DMS(DSDS, page, maxPage, i);
// }

void search_book_code_frame(){ //Khung nhap dau sach tien hanh cap nhap sach
	setfillstyle(SOLID_FILL, BLACK);
	bar(10, 50, 440, 150);
	setlinestyle(0, 0, 2);
	setcolor(GREEN);
	rectangle(13, 53, 437, 147);
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(15, 55, 435, 145);
	setbkcolor(0);
	settextstyle(3, 0, 2);
	outtextxy(25, 65, "Nhap ma sach: ");
	settextstyle(3, 0, 1);
	setcolor(LIGHTGRAY);
	outtextxy(40, 90, "(Toi da 7 ky tu, bao gom chu va so)");
	
	setcolor(WHITE);
	line(40, 120, 54, 130);
	line(40, 140, 54, 130);
	line(40, 120, 44, 130);
	line(40, 140, 44, 130);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(45, 130, WHITE);
	settextstyle(4, 0, 1);
	setcolor(15);
	outtextxy(85, 120, ":");
	bar(95, 120, 420, 140);

}

void book_return_confirmation(NODE_DOUBLY_LIST *p,string s[]){
  setfillstyle(SOLID_FILL, WHITE);
	bar(383, 133, 983, 423);
	setcolor(CYAN);
	setlinestyle(0, 0, 2);
	rectangle(388, 138, 978, 418);
	line(683-textwidth("TRA SACH")/2 - 45, 160, 683+textwidth("TRA SACH")/2 + 45, 160);
	settextstyle(4, 0, 2);
	setcolor(BLUE);
	setbkcolor(WHITE);
	outtextxy(683-textwidth("TRA SACH")/2, 137, "TRA SACH");
	
	settextstyle(8, 0, 3);
	setcolor(BLACK);
	outtextxy(395, 190, "NGAY THUC HIEN   :");
	outtextxy(395, 250, "TRANG THAI SACH  :");

	settextstyle(8,0,1);
	outtextxy(683-textwidth("1: TRA SACH, 2: LAM MAT SACH")/2, 285, "(1: TRA SACH, 2: LAM MAT SACH)");
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(665, 192, 965, 212);
	bar(665, 252, 965, 272);

  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);
  char str[20];

  s[0] = to_string(NgayHienTai()) + "/" + to_string(ThangHienTai()) + "/" + to_string(NamHienTai());
  strcpy(str,s[0].c_str());
  outtextxy(670, 192, str);

  setfillstyle(SOLID_FILL,CYAN);	
	bar(503,340,623,390);
	bar(743,340,863,390);
	
	setcolor(WHITE);
	setbkcolor(CYAN);
	settextstyle(8,0,3);
	outtextxy(563-textwidth("SAVE")/2,365-textheight("SAVE")/2,"SAVE");
	outtextxy(803-textwidth("CANCEL")/2,365-textheight("CANCEL")/2,"CANCEL");
}

void book_borrowing_confirmation(){
  setfillstyle(SOLID_FILL, WHITE);
	bar(383, 133, 983, 423);
	setcolor(CYAN);
	setlinestyle(0, 0, 2);
	rectangle(388, 138, 978, 418);
	line(683-textwidth("MUON SACH")/2 - 45, 160, 683+textwidth("MUON SACH")/2 + 45, 160);
	settextstyle(4, 0, 2);
	setcolor(BLUE);
	setbkcolor(WHITE);
	outtextxy(683-textwidth("MUON SACH")/2, 137, "MUON SACH");
	
	settextstyle(8, 0, 3);
	setcolor(BLACK);
	outtextxy(395, 180, "MA SACH          :");
	outtextxy(395, 220, "TEN SACH         :");
  outtextxy(395, 260, "NGAY MUON:       :");
  outtextxy(395, 300, "VI TRI:          :");
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(665, 182, 965, 202);
	bar(665, 222, 965, 242);
  bar(665, 262, 965, 282);
  bar(665, 302, 965, 322);

  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);
  char str[20];

  setfillstyle(SOLID_FILL,CYAN);	
	bar(503,340,623,390);
	bar(743,340,863,390);
	
	setcolor(WHITE);
	setbkcolor(CYAN);
	settextstyle(8,0,3);
	outtextxy(563-textwidth("SAVE")/2,365-textheight("SAVE")/2,"SAVE");
	outtextxy(803-textwidth("CANCEL")/2,365-textheight("CANCEL")/2,"CANCEL");
}
