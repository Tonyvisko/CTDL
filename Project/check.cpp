	#include <graphics.h>
//#include "XuLy.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "KhaiBao.h"
#define XMAX 1366
#define YMAX 768
using namespace std;
string thongbao = "";
int width(string s){
  char str[100];
  strcpy(str, s.c_str());
  return textwidth(str);
}

int height(string s){
  char str[100];
  strcpy(str, s.c_str());
  return textheight(str);
}
void notice_frame(){
  setfillstyle(1, DARKGRAY);
  bar(10, 710, 440, 760);
  setcolor(YELLOW);
  setlinestyle(0, 0, 1);
	rectangle(10, 710, 440, 760);
	rectangle(13, 713, 437, 757);
	setbkcolor(DARKGRAY);
  setcolor(YELLOW);
  settextstyle(3, 0, 1);
	outtextxy(20, 725, "NOTI:");
  char str[50];
  strcpy(str, thongbao.c_str());
  setbkcolor(DARKGRAY);
  setcolor(RED);
  settextstyle(10, 0, 1);
  outtextxy(20+width("NOTI: "), 725, str);
  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);
}
void LayDanhSachDauSach(pointerArray &DSDS){
	ifstream fileDauSach("inputdausach.txt");
	if (!fileDauSach.is_open()) {
        cerr << "Khong the mo tap tin inputdausach.txt" << endl;
        return;
    }
	int n,SLDS,SLDMS;
	string s;
	fileDauSach >> n;
	fileDauSach.ignore();
	SLDS = n;
	for(int i=0;i<SLDS;i++){
		DauSach *dausach = new DauSach; 
		getline(fileDauSach,s);
		istringstream ss(s);
		string token;
		getline(ss,token,',');
		dausach->TenSach = token;
		getline(ss,token,',');
		dausach->ISBN = token;
		getline(ss,token,',');
		dausach->TacGia = token;
		getline(ss,token,',');
		dausach->TheLoai = token;
		getline(ss,token,',');
		dausach->SoTrang = stoi(token);
		getline(ss,token,',');
		dausach->NamXuatBan = stoi(token);
		getline(ss,token,',');
		dausach->SoLuongSach = stoi(token);
    dausach->SoLanMuon = 0;
    dausach->dms.head = dausach->dms.tail = NULL;
	for (int j = 0; j < dausach->SoLuongSach;j++){
      DanhMucSach danhmucsach;
      getline(ss,token,',');
      danhmucsach.masach = token;
      // cout << danhmucsach.masach << endl;
      getline(ss,token,',');
      danhmucsach.trangthai = stoi(token);
      // cout << danhmucsach.trangthai << endl;
      getline(ss,token,',');
      danhmucsach.vitri = token;
      // cout << danhmucsach.vitri << endl;
      InsertLast_NodeSach(dausach->dms, danhmucsach);
    }
    InsertLastDauSach(DSDS, dausach);
  }
	fileDauSach.close();
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
void list_book(){
	setbkcolor(8);
	setfillstyle(SOLID_FILL, WHITE);

	setcolor(15);
	rectangle(2, 50, 1364, 701);
	rectangle(4, 53, 370, 93); // Dau Sach
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

void vitri(){
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
//void update_books_background(){
//  setbkcolor(8);
//  cleardevice();
//  list_book();
//
//  setfillstyle(SOLID_FILL, RED);
//  setcolor(YELLOW);
//  setbkcolor(RED);
//  settextstyle(8, 0, 3);
//  setlinestyle(0, 0, 1);
//  PREV_BUTTON(460, 5);
//  NEXT_BUTTON(620, 5);
//  BACK_BUTTON(1230, 5);
//
////  notice_frame();
//
//}
void swap_DS(DauSach* &a, DauSach* &b){
    DauSach* temp = a;
    a = b;
    b = temp;
}

void sort_DS(pointerArray &DSDS,int left,int right){
    int i=left;
    int j=right;
    string pivot=DSDS.nodesDauSach[(left+right)/2]->TheLoai;
    string pivotto=DSDS.nodesDauSach[(left+right)/2]->TenSach;
    do{
        while(DSDS.nodesDauSach[i]->TheLoai<pivot || DSDS.nodesDauSach[i]->TheLoai == pivot && DSDS.nodesDauSach[i]->TenSach<pivotto) i++;
        while(DSDS.nodesDauSach[j]->TheLoai>pivot || DSDS.nodesDauSach[j]->TheLoai == pivot && DSDS.nodesDauSach[j]->TenSach>pivotto) j--;
        if(i<=j){
            swap_DS(DSDS.nodesDauSach[i],DSDS.nodesDauSach[j]);
            i++;j--;
        }
    }while(i<=j);
    if(left<j) sort_DS(DSDS,left,j);
    if(i<right) sort_DS(DSDS,i,right);
}
void SapXepTheoTenSach(pointerArray &DSDS,int n){
    sort_DS(DSDS,0,n-1);
}
void Display_DSDS(pointerArray &DSDS, int page, int maxPage){
  string s="";
  char str[30];
  settextstyle(3, 0, 3);
  setbkcolor(DARKGRAY);
  int Books = 0;
  int maxBooksInPage = 0;
  if(page==maxPage){
    Books = DSDS.SoLuongDauSach - DSDS.SoLuongDauSach % 20;
    maxBooksInPage = DSDS.SoLuongDauSach - 1;
  }
  else{
    Books = (page - 1) * 20;
    maxBooksInPage = Books + 19;
  }
  s="PAGE "+to_string(page)+"/"+to_string(maxPage);
  strcpy(str, s.c_str());
  setcolor(WHITE);
	outtextxy(1235, 710, str);
  for (int j = Books, k=0; j <= maxBooksInPage;j++,k++){
  	char chs[10];
    s=DSDS.nodesDauSach[j]->TenSach;
  	strcpy(str, s.c_str());
  	outtextxy(17, 100 + k*30, str);
  	s=DSDS.nodesDauSach[j]->ISBN;
  	strcpy(str, s.c_str());
  	outtextxy(386, 100 + k*30, str);
  	s=DSDS.nodesDauSach[j]->TacGia;
  	strcpy(str, s.c_str());
  	outtextxy(521, 100 + k*30, str);
  	s=DSDS.nodesDauSach[j]->TheLoai;
  	strcpy(str, s.c_str());
  	outtextxy(816, 100 + k*30,str );
  	if(DSDS.nodesDauSach[j]->SoTrang > 0){
  		itoa(DSDS.nodesDauSach[j]->SoTrang, chs, 10);
  		outtextxy(1211, 100 + k*30, chs);
  	}

  	if(DSDS.nodesDauSach[j]->NamXuatBan > 0){
  		itoa(DSDS.nodesDauSach[j]->NamXuatBan, chs, 10);
  		outtextxy(1315, 100 + k*30, chs);
  	}
  }
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
void required_header_book_frame(){ //Khung nhap dau sach tien hanh cap nhap sach
	setfillstyle(SOLID_FILL, BLACK);
	bar(468, 405, 898, 505);
	setlinestyle(0, 0, 2);
	setcolor(GREEN);
	rectangle(471, 408, 895, 502);
	setcolor(WHITE);
	setlinestyle(0, 0, 1);
	rectangle(473, 410, 893, 500);
	setbkcolor(0);
	settextstyle(3, 0, 2);
	outtextxy(483, 420, "Nhap dau sach: ");
	settextstyle(3, 0, 1);
	setcolor(LIGHTGRAY);
	outtextxy(395, 445, "(Toi da 24 ky tu, bao gom chu va so)");
	
	setcolor(WHITE);
	line(498, 475, 409, 485);
	line(498, 495, 409, 485);
	line(498, 475, 399, 485);
	line(498, 495, 399, 485);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(400, 485, WHITE);
	settextstyle(4, 0, 1);
	setcolor(15);
	outtextxy(440, 475, ":");
	bar(450, 475, 878, 495);
}
void list_book_background(){
  setbkcolor(8);
  cleardevice();
  list_book();
  setfillstyle(SOLID_FILL, RED);
  setcolor(YELLOW);
  setbkcolor(RED);
  settextstyle(8, 0, 3);
  setlinestyle(0, 0, 1);
  PREV_BUTTON(10, 5);
  NEXT_BUTTON(170, 5);
  BACK_BUTTON(1230, 5);
  ADD_BUTTON(460, 710);
  SEARCH_BUTTON(600, 710);
//  book_header_button();
  notice_frame();

}
void DanhSachDauSach(pointerArray &DS, int mode){
  int n = 0; 

  SapXepTheoTenSach(DS, DS.SoLuongDauSach);


  list_book_background();

  int page = 1;
  int maxPage = (DS.SoLuongDauSach%20==0) ? DS.SoLuongDauSach/20 : DS.SoLuongDauSach/20 + 1;
//  Display_DSDS(DS, page, maxPage);
  
//  if(mode==1){
//    ARROW(445, 100, 4);
//  }
  char str[30];
  int x, y;
  char c;
  int k = 0;
//  int arrowLimit = DS.SoLuongDauSach >= 20 ? 20 : DS.SoLuongDauSach;
//  int prev;
  while(1){
    
    // Disable keyboard input
//    if(kbhit()){
//      if(mode==0){
//        getch();
//      }
//      else{
//        c = getch();
//        
//          if(c==KEY_DOWN)
//          {
//            prev = k;
//            if(k<arrowLimit-1){
//              k++;
//              ARROW(445, 100 + k * 30, 4);
//              ARROW(445, 100 + k * 30 - 30, 8);
//            }
//            else if(k==arrowLimit-1 && maxPage>1 && page<maxPage){
//              update_books_background();
//              page++;
//              Display_DSDS(DS, page, maxPage);
//              arrowLimit = (page == maxPage) ? DS.SoLuongDauSach % 20 : 20;
//              k = 0;
//              ARROW(445, 100 + k * 30, 4);
//            }
//            prev = k;
//          }
//
//          if(c==KEY_UP)
//          {
//            prev = k;
//            if(k>0 || page!=1){
//              k--;
//              ARROW(445, 100 + k * 30, 4);
//              ARROW(445, 100 + k * 30 + 30, 8);
//            }
//            if(k==-1 && page>1){
//              update_books_background();
//              page--;
//              Display_DSDS(DS, page, maxPage);
//              k = (page == maxPage) ? DS.SoLuongDauSach % 20 - 1 : 19;
//              arrowLimit = (page == maxPage) ? DS.SoLuongDauSach % 20 -1 : 20;
//              ARROW(445, 100 + k * 30, 4);
//            }
//            prev = k;
//          }
//
//          if(c==13)
//          {
//            i = (page - 1) * 20 + k;
//            TimKiemDauSach(DS.nodesDauSach[i]);
//            DanhSachDauSach(DSDS, 0);
//          }
//        }
//      }
    
    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
      x = mousex();
      y = mousey();

      //BACK
//      if(x>=1230 &&  y>=5 && x<=1365 && y<=45){
//        delete[] DS.nodesDauSach;
//        thongbao = "";
//        if(mode==0){
//          cleardevice();
//          menu();
//        }
//        else{
//          delay(100);
//          thongbao = "Thoat che do loc";
//          DanhSachDauSach(DSDS, 0);
//        }
//      }

      //PREV
       if(x>=460 &&  y>=5 && x<=600 && y<=45){
        if(page > 1){
          page--;
          list_book_background();
          Display_DSDS(DS, page, maxPage);
//          if(mode==1){
//            k = prev;
//            ARROW(445, 100 + k * 30, 4);
//            arrowLimit = (page == maxPage) ? DS.SoLuongDauSach % 20 : 20;
//          }
        }
      }

      //NEXT
      else if(x>=620 &&  y>=5 && x<=760 && y<=45){
        if(page < maxPage){
          page++;
          list_book_background();
          Display_DSDS(DS, page, maxPage);
//          if(mode==1){
//            prev = k;
//            if(page==maxPage && k>DS.SoLuongDauSach % 20 - 1){
//              k = DS.SoLuongDauSach % 20 - 1;
//            }
//            arrowLimit = (page == maxPage) ? DS.SoLuongDauSach % 20 : 20;
//            ARROW(445, 100 + k * 30, 4);
//          }
        }
      }

      //SEARCH
      else if(x >= 600 && y >= 710 && x <= 700 && y <= 760 && mode==0){
  			if(SoLuongDocGia>0){
          required_header_book_frame();
//          LocDauSach(DSDS);
        }
        else{
          thongbao = "Danh sach dau sach trong";
        }
  	  }
//
//      //ADD
      else if(x>=460 && y>=710 && x<=550 && y<=760 && mode==0){
        if(DSDS.SoLuongDauSach==MaxNodes){
          thongbao = "Da dat gioi han dau sach";
        }
        else{
          add_header_book();
//          ThemDauSach();
        }
//        DanhSachDauSach(DSDS, 0);
      }
	  }
	}
}
int main(){
	initwindow(1366,768,"The Window");
//	update_books_background();
//LayDanhSachDauSach(DSDS);
//	DanhSachDauSach(DSDS,0);
	
list_book_background();
add_header_book();
	vitri();
	getch();
}
