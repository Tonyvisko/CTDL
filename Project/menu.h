#include "TheDocGia.h"
//#include "QuanLyDauSach.h"
using namespace std;


void menu();
void QuanLyDauSach();
void DanhSachDauSach(pointerArray &DSDS, int mode);
void DanhSachDocGia(NODE_TREE *&root);
void DanhSachDocGiaMuonQuaHan();
void Top10DauSachDuocMuonNhieuNhat();
void MuonTraSach();
void CapNhatDanhMucSach(pointerArray &DSDS);
void LocDauSach(pointerArray DSDS);

void quanLiDocGia(){
	setcolor(0);
	setlinestyle(0, 0, 2);
	rectangle(403, 284, 963, 484);
	line(403, 329, 963, 329);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(410, 310, BLACK);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	floodfill(410, 350, BLACK);
	setcolor(LIGHTGRAY);
	line(405, 329, 961, 329);
	settextstyle(8, 0, 4);
	setbkcolor(15);
	setcolor(0);
	outtextxy(410, 290, "HIEN THI THEO:");
	
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	line(684, 409, 664, 414);
	line(684, 409, 704, 414);
	line(684, 419, 664, 414);
	line(684, 419, 704, 414);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(690, 414, DARKGRAY);
	line(684, 359, 679, 379);
	line(684, 359, 689, 379);
	line(684, 399, 679, 379);
	line(684, 399, 689, 379);
	floodfill(685, 379, DARKGRAY);
	line(684, 429, 679, 449);
	line(684, 429, 689, 449);
	line(684, 469, 679, 449);
	line(684, 469, 689, 449);
	floodfill(685, 449, DARKGRAY);
	while(1){
		int x = mousex();
		int y = mousey();
		if((x >= 919 && x <= 961) && (y >= 286 && y <= 327)){ //nut X ben goc phai
			setlinestyle(0, 0, 2);
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
			rectangle(920, 287, 960, 326);
			floodfill(930, 300, RED);
			setcolor(WHITE);
			line(930, 297, 950, 316);
			line(950, 297, 930, 316);
			if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
				menu();
			}
		}else{
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, WHITE);
			rectangle(919, 286, 960, 326);
			floodfill(930, 300, WHITE);
			setcolor(BLACK);
			line(930, 297, 950, 316);
			line(950, 297, 930, 316);
		}
		if((x >= 420 && x <= 630) && (y >= 359 && y <= 469)){
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			rectangle(420, 359, 630, 469);
			setcolor(DARKGRAY);
			rectangle(421, 360, 629, 468);
			setfillstyle(SOLID_FILL, DARKGRAY);
			floodfill(430, 400, DARKGRAY);
			settextstyle(10, 0, 3);
			setcolor(WHITE);
			setbkcolor(DARKGRAY);
			// outtextxy(430, 380, "DANH SACH DOC");
			// outtextxy(430, 405, "GIA HOP LE");
			// outtextxy(430, 430, "HIEN TAI");
      outtextxy(525-width("DANH SACH")/2, 390, "DANH SACH");
      outtextxy(525-width("DOC GIA")/2, 415, "DOC GIA");
      setlinestyle(0, 0, 1);
			setcolor(WHITE);
			line(430, 369, 620, 369);
			line(420, 359, 430, 369);
			line(630, 359, 620, 369);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(450, 365, WHITE);
			if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
				DanhSachDocGia(root);
			}
		}else{
			setlinestyle(0, 0, 1);
			setcolor(DARKGRAY);
			rectangle(420, 359, 630, 469);
			setcolor(WHITE);
			rectangle(421, 360, 629, 468);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(430, 400, WHITE);
			settextstyle(8, 0, 3);
			setcolor(0);
			setbkcolor(15);
			// outtextxy(430, 380, "DANH SACH DOC");
			// outtextxy(430, 405, "GIA HOP LE");
			// outtextxy(430, 430, "HIEN TAI");
      outtextxy(525-width("DANH SACH")/2, 390, "DANH SACH");
      outtextxy(525-width("DOC GIA")/2, 415, "DOC GIA");
			setlinestyle(0, 0, 1);
			setcolor(DARKGRAY);
			line(430, 369, 620, 369);
			line(420, 359, 430, 369);
			line(630, 359, 620, 369);
			setfillstyle(SOLID_FILL, DARKGRAY);
			floodfill(450, 365, DARKGRAY);
		}
		if((x >= 738 && x <= 948) && (y >= 359 && y <= 469)){
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			rectangle(738, 359, 948, 469);
			setcolor(DARKGRAY);
			rectangle(739, 360, 947, 468);
			setfillstyle(SOLID_FILL, DARKGRAY);
			floodfill(748, 400, DARKGRAY);
			settextstyle(10, 0, 3);
			setcolor(WHITE);
			setbkcolor(DARKGRAY);
			outtextxy(748, 380, "DANH SACH DOC");
			outtextxy(748, 405, "GIA MUON SACH");
			outtextxy(748, 430, "QUA HAN");
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			line(748, 369, 938, 369);
			line(738, 359, 748, 369);
			line(948, 359, 938, 369);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(768, 365, WHITE);
			if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
        cleardevice();
        DanhSachDocGiaMuonQuaHan();
      }
		}else{
			setlinestyle(0, 0, 1);
			setcolor(DARKGRAY);
			rectangle(738, 359, 948, 469);
			setcolor(WHITE);
			rectangle(739, 360, 947, 468);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(748, 400, WHITE);
			settextstyle(8, 0, 3);
			setcolor(0);
			setbkcolor(15);
			outtextxy(748, 380, "DANH SACH DOC");
			outtextxy(748, 405, "GIA MUON SACH");
			outtextxy(748, 430, "QUA HAN");
			setlinestyle(0, 0, 1);
			setcolor(DARKGRAY);
			line(748, 369, 938, 369);
			line(738, 359, 748, 369);
			line(948, 359, 938, 369);
			setfillstyle(SOLID_FILL, DARKGRAY);
			floodfill(768, 365, DARKGRAY);
		}
	}
}
void quanLiSach(){
	setcolor(BLACK);
	rectangle(432, 282, 934, 484);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(433, 283, 933, 483);
	setfillstyle(SOLID_FILL, WHITE);
	bar(433, 283, 933, 313);
	settextstyle(8, 0, 3);
	setbkcolor(WHITE);
	outtextxy(440, 288, "QUAN LI SACH: ");
	setfillstyle(6, DARKGRAY);
	bar(433, 314, 933, 317);
	
	settextstyle(4, 0, 7);
	setcolor(WHITE);
	setbkcolor(LIGHTGRAY);
	int w = width(":"); int h = height(":");
	outtextxy((453 + 913 - w) / 2, (363 + 463 - h) / 2, ":");
	int x, y;
	while(1){
		x = mousex();
		y = mousey();
		if((x >= 906 && x <= 930) && (y >= 286 && y <= 310)){
			setlinestyle(0, 0, 1);
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
			rectangle(906, 286, 930, 310);
			rectangle(907, 287, 929, 309);
			floodfill(908, 288, RED);
			setlinestyle(0, 0, 2);
			setcolor(WHITE);
			line(912, 291, 926, 305);
			line(926, 291, 912, 305);
			if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
				menu();
			}
		}else{
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, WHITE);
			rectangle(906, 286, 930, 310);
			rectangle(907, 287, 929, 309);
			floodfill(908, 288, WHITE);
			setcolor(BLACK);
			line(912, 291, 926, 305);
			line(926, 291, 912, 305);
		}
		if((x >= 453 && x <= 653) && (y >= 363 && y <= 463)){
			setlinestyle(0, 0, 1);
			setcolor(DARKGRAY);
			setfillstyle(SOLID_FILL, WHITE);
			rectangle(453, 363, 653, 463);
			setcolor(WHITE);
			rectangle(454, 364, 652, 462);
			floodfill(650, 460, WHITE);
			
			setcolor(DARKGRAY);
			rectangle(458, 368, 648, 378);
			setfillstyle(SOLID_FILL, DARKGRAY);
			rectangle(459, 369, 647, 377);
			floodfill(460, 370, DARKGRAY);
			setcolor(DARKGRAY);
			setbkcolor(WHITE);
			settextstyle(10, 0, 3);
			outtextxy(480, 415, "MUON - TRA");
			if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
				MuonTraSach();
			}
		}else{
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, DARKGRAY);
			rectangle(453, 363, 653, 463);
			setcolor(DARKGRAY);
			rectangle(454, 364, 652, 462);
			floodfill(650, 460, DARKGRAY);
			
			setcolor(WHITE);
			rectangle(458, 368, 648, 378);
			setfillstyle(SOLID_FILL, WHITE);
			rectangle(459, 369, 647, 377);
			floodfill(460, 370, WHITE);
			setcolor(WHITE);
			setbkcolor(DARKGRAY);
			settextstyle(10, 0, 3);
			outtextxy(480, 415, "MUON - TRA");
		}
		if((x >= 713 && x <= 913) && (y >= 363 && y <= 463)){
			setcolor(DARKGRAY);
			setfillstyle(SOLID_FILL, WHITE);
			rectangle(713, 363, 913, 463);
			setcolor(WHITE);
			rectangle(714, 364, 912, 462);
			floodfill(910, 460, WHITE);
			
			setcolor(DARKGRAY);
			rectangle(718, 368, 908, 378);
			setfillstyle(SOLID_FILL, DARKGRAY);
			rectangle(719, 369, 907, 377);
			floodfill(720, 370, DARKGRAY);
			setcolor(DARKGRAY);
			setbkcolor(WHITE);
			settextstyle(10, 0, 3);
			outtextxy(785, 400, "MUON");
			outtextxy(740, 425, "NHIEU NHAT");
			if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
				cleardevice();
				Top10DauSachDuocMuonNhieuNhat();
			}
		}else{
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, DARKGRAY);
			rectangle(713, 363, 913, 463);
			setcolor(DARKGRAY);
			rectangle(714, 364, 912, 462);
			floodfill(910, 460, DARKGRAY);
			
			setcolor(WHITE);
			rectangle(718, 368, 908, 378);
			setfillstyle(SOLID_FILL, WHITE);
			rectangle(719, 369, 907, 377);
			floodfill(720, 370, WHITE);
			setcolor(WHITE);
			setbkcolor(DARKGRAY);
			settextstyle(10, 0, 3);
			outtextxy(785, 400, "MUON");
			outtextxy(740, 425, "NHIEU NHAT");
		}
	}
}

void quanLiDauSach(){
	
	setcolor(0);
	setlinestyle(0, 0, 2);
	rectangle(403, 284, 963, 484);
	line(403, 329, 963, 329);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(410, 310, BLACK);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	floodfill(410, 350, BLACK);
	setcolor(LIGHTGRAY);
	line(405, 329, 961, 329);
	settextstyle(8, 0, 4);
	setbkcolor(15);
	setcolor(0);
	outtextxy(410, 290, "LUA CHON: ");
	
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	line(684, 409, 664, 414);
	line(684, 409, 704, 414);
	line(684, 419, 664, 414);
	line(684, 419, 704, 414);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(690, 414, DARKGRAY);
	line(684, 359, 679, 379);
	line(684, 359, 689, 379);
	line(684, 399, 679, 379);
	line(684, 399, 689, 379);
	floodfill(685, 379, DARKGRAY);
	line(684, 429, 679, 449);
	line(684, 429, 689, 449);
	line(684, 469, 679, 449);
	line(684, 469, 689, 449);
	floodfill(685, 449, DARKGRAY);
	while(1){
		int x = mousex();
		int y = mousey();
		if((x >= 919 && x <= 961) && (y >= 286 && y <= 327)){ //nut X ben goc phai
			setlinestyle(0, 0, 2);
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
			rectangle(920, 287, 960, 326);
			floodfill(930, 300, RED);
			setcolor(WHITE);
			line(930, 297, 950, 316);
			line(950, 297, 930, 316);
			if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
				menu();
			}
		}else{
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, WHITE);
			rectangle(919, 286, 960, 326);
			floodfill(930, 300, WHITE);
			setcolor(BLACK);
			line(930, 297, 950, 316);
			line(950, 297, 930, 316);
		}
		if((x >= 420 && x <= 630) && (y >= 359 && y <= 469)){
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			rectangle(420, 359, 630, 469);
			setcolor(DARKGRAY);
			rectangle(421, 360, 629, 468);
			setfillstyle(SOLID_FILL, DARKGRAY);
			floodfill(430, 400, DARKGRAY);
			settextstyle(10, 0, 3);
			setcolor(WHITE);
			setbkcolor(DARKGRAY);
			outtextxy(470, 390, "HIEN THI");
			outtextxy(470, 420, "DAU SACH");
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			line(430, 369, 620, 369);
			line(420, 359, 430, 369);
			line(630, 359, 620, 369);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(450, 365, WHITE);
			if((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0){
				DanhSachDauSach(DSDS,0);
			}
		}else{
			setlinestyle(0, 0, 1);
			setcolor(DARKGRAY);
			rectangle(420, 359, 630, 469);
			setcolor(WHITE);
			rectangle(421, 360, 629, 468);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(430, 400, WHITE);
			settextstyle(8, 0, 3);
			setcolor(0);
			setbkcolor(15);
			outtextxy(465, 390, "HIEN THI");
			outtextxy(465, 420, "DAU SACH");
			setlinestyle(0, 0, 1);
			setcolor(DARKGRAY);
			line(430, 369, 620, 369);
			line(420, 359, 430, 369);
			line(630, 359, 620, 369);
			setfillstyle(SOLID_FILL, DARKGRAY);
			floodfill(450, 365, DARKGRAY);
		}
		if((x >= 738 && x <= 948) && (y >= 359 && y <= 469)){
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			rectangle(738, 359, 948, 469);
			setcolor(DARKGRAY);
			rectangle(739, 360, 947, 468);
			setfillstyle(SOLID_FILL, DARKGRAY);
			floodfill(748, 400, DARKGRAY);
			settextstyle(10, 0, 3);
			setcolor(WHITE);
			setbkcolor(DARKGRAY);
			outtextxy(785, 390, "CAP NHAT");
			outtextxy(753, 420, "DANH MUC SACH");
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			line(748, 369, 938, 369);
			line(738, 359, 748, 369);
			line(948, 359, 938, 369);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(768, 365, WHITE);
			if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
        CapNhatDanhMucSach(DSDS);
      }
		}else{
			setlinestyle(0, 0, 1);
			setcolor(DARKGRAY);
			rectangle(738, 359, 948, 469);
			setcolor(WHITE);
			rectangle(739, 360, 947, 468);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(748, 400, WHITE);
			settextstyle(8, 0, 3);
			setcolor(0);
			setbkcolor(15);
			outtextxy(780, 390, "CAP NHAT");
			outtextxy(748, 420, "DANH MUC SACH");
			setlinestyle(0, 0, 1);
			setcolor(DARKGRAY);
			line(748, 369, 938, 369);
			line(738, 359, 748, 369);
			line(948, 359, 938, 369);
			setfillstyle(SOLID_FILL, DARKGRAY);
			floodfill(768, 365, DARKGRAY);
		}
	}
}

void Thoat(){
  setfillstyle(SOLID_FILL, BLACK);
  bar(XMAX/2-350, YMAX/2-150, XMAX/2+350, YMAX/2+150);
  setcolor(GREEN);
  setlinestyle(0, 0, 2);
  rectangle(XMAX/2-345, YMAX/2-145, XMAX/2+345, YMAX/2+145);
  setcolor(WHITE);
  setlinestyle(0, 0, 1);
  rectangle(XMAX/2-342, YMAX/2-142, XMAX/2+342, YMAX/2+142);
  settextstyle(8, 0, 4);
  int width=textwidth("Ban co chac chan muon thoat?");
  int height=textheight("Ban co chac chan muon thoat?");
  setbkcolor(BLACK);
  outtextxy(XMAX/2-width/2, YMAX/2-height/2-50, "Ban co chac chan muon thoat?");
  outtextxy(XMAX/2-200, YMAX/2-height/2+50, "Co");
  outtextxy(XMAX/2+100, YMAX/2-height/2+50, "Khong");
  setcolor(RED);
  rectangle(XMAX/2-218, YMAX/2+25, XMAX/2-143, YMAX/2+75);
  rectangle(XMAX/2+80, YMAX/2+25, XMAX/2+220, YMAX/2+75);
  int x, y;
  while(1){
    x=mousex();
    y=mousey();
    
    //CO
    if(x >= XMAX/2-218 && x <= XMAX/2-143 && y >= YMAX/2+25 && y <= YMAX/2+75){
      setcolor(RED);
      setfillstyle(SOLID_FILL, RED);
      rectangle(XMAX/2-218, YMAX/2+25, XMAX/2-143, YMAX/2+75);
      floodfill(XMAX/2-180, YMAX/2+50, RED);
      setbkcolor(RED);
      setcolor(WHITE);
      outtextxy(XMAX/2-200, YMAX/2-height/2+50, "Co");
      if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
        closegraph();
        exit(0);
      }
    }
    else{
      setcolor(RED);
      setfillstyle(SOLID_FILL, BLACK);
      rectangle(XMAX/2-218, YMAX/2+25, XMAX/2-143, YMAX/2+75);
      floodfill(XMAX/2-180, YMAX/2+50, BLACK);
      setbkcolor(BLACK);
      setcolor(WHITE);
      outtextxy(XMAX/2-200, YMAX/2-height/2+50, "Co");
    }

    //KHONG
    if(x >= XMAX/2+80 && x <= XMAX/2+220 && y >= YMAX/2+25 && y <= YMAX/2+75){
      setcolor(RED);
      setfillstyle(SOLID_FILL, RED);
      rectangle(XMAX/2+80, YMAX/2+25, XMAX/2+220, YMAX/2+75);
      floodfill(XMAX/2+150, YMAX/2+50, RED);
      setbkcolor(RED);
      setcolor(WHITE);
      outtextxy(XMAX/2+100, YMAX/2-height/2+50, "Khong");
      if(ismouseclick(WM_LBUTTONDOWN)){
        clearmouseclick(WM_LBUTTONDOWN);
        delay(100);
        menu();
      }
    }
    else{
      setcolor(RED);
      setfillstyle(SOLID_FILL, BLACK);
      rectangle(XMAX/2+80, YMAX/2+25, XMAX/2+220, YMAX/2+75);
      floodfill(XMAX/2+150, YMAX/2+50, BLACK);
      setbkcolor(BLACK);
      setcolor(WHITE);
      outtextxy(XMAX/2+100, YMAX/2-height/2+50, "Khong");
    }

    clearmouseclick(WM_LBUTTONDOWN);
  }  
}
//void booksBackground(){
//  setbkcolor(8);
//	cleardevice();
//  setlinestyle(3, 2, 2);
//  setcolor(WHITE);
//  line(450, 0, 450, 768);
//	setlinestyle(0, 2, 2);
//  notice_frame();
//  list_book();
//  selection_button();
//}
//void DanhSachDauSach(pointerArray *&root){
//	DauSach *MangDauSach = new DauSach[SoLuongDauSach];
//	int n=0;
//	ChuyenCayThanhMang2(root, MangDauSach, n);
//  
////  if(sortMode==1){
////    SapXepTheoHoTen(MangDocGia, SoLuongDocGia);
////
////  }
//
//  booksBackground();
//
//  int page = 1;
//  int maxPage = (SoLuongDauSach%20==0) ? SoLuongDauSach/20 : SoLuongDauSach/20 + 1;
//  Display2(MangDauSach, page, maxPage);
//	
//
//	
//}
void menu(){
  setbkcolor(DARKGRAY);
  cleardevice();
  int x, y;

  settextstyle(6, 0, 8);

  int width=textwidth("QUAN LY THU VIEN");
  int height=textheight("QUAN LY THU VIEN");
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  bar(110, 50, 1265, 180);
  setbkcolor(LIGHTGRAY);
  setcolor(3);
  outtextxy(XMAX/2-width/2, 100-height/2 + 15, "QUAN LY THU VIEN");
  setlinestyle(0, 0, 3);
  setfillstyle(SOLID_FILL, DARKGRAY);
  bar(110, 50, 135, 70);
  bar(1240, 50, 1265, 70);
  bar(110, 170, 210, 180);
  bar(1165, 170, 1265, 180);
  setcolor(15);
  line(210, 181, 1165, 181);
  line(110, 171, 210, 171);
  line(210, 171, 210, 181);
  line(1165, 171, 1265, 171);
  line(1165, 171, 1165, 181);
  line(110, 71, 110, 171);
  line(1265, 71, 1265, 171);
  line(110, 70, 134, 70);
  line(1241, 70, 1265, 70);
  line(134, 50, 134, 70);
  line(1241, 50, 1241, 70);
  line(134, 50, 1241, 50);
  setcolor(15);
  setlinestyle(3, 0, 2);
  rectangle(10, 10, XMAX-10, YMAX-10);
  
  setlinestyle(0, 0, 1);
  line(683, 210, 676, 225);
  line(683, 210, 690, 225);
  line(676, 225, 683, 240);
  line(690, 225, 683, 240);
  setfillstyle(SOLID_FILL, WHITE);
  floodfill(680, 225, WHITE);
  setcolor(DARKGRAY);
  line(683, 213, 688, 225);
  line(688, 225, 683, 237);

  setcolor(15);
  setlinestyle(0, 0, 1);
  line(683, 670, 676, 685);
  line(683, 670, 690, 685);
  line(676, 685, 683, 700);
  line(690, 685, 683, 700);
  setfillstyle(SOLID_FILL, WHITE);
  floodfill(680, 685, WHITE);
  setcolor(DARKGRAY);
  line(683, 673, 688, 685);
  line(688, 685, 683, 697);

  setcolor(15);
  settextstyle(8, 0, 1);
  setbkcolor(DARKGRAY);
  width = textwidth("Van Minh Tan - N22DCCN175");
  height = textheight("Van Minh Tan - N22DCCN175");
  outtextxy(XMAX/2-width/2 + 530, YMAX-height/2-80, "Van Minh Tan - N22DCCN175");
  width = textwidth("Huynh Phat Tai - N22DCCN171");
  height = textheight("Huynh Phat Tai - N22DCCN171");
  outtextxy(XMAX/2-width/2 + 520, YMAX-height/2-60, "Huynh Phat Tai - N22DCCN171");
  width = textwidth("Trieu Viet Thanh - N22DCCN177");
  height = textheight("Trieu Viet Thanh - N22DCCN177");
  outtextxy(XMAX/2-width/2 + 508, YMAX-height/2-40, "Trieu Viet Thanh - N22DCCN177"); 
  
  //Kiem tra vi tri chuot
  while(1){
  	setlinestyle(0, 0, 1);
    x = mousex();
    y = mousey();
    //Quan ly sach
    if((x >= XMAX/2-230 && x <= XMAX/2+230) && (y >= 255 && y <= 340 )){
      setcolor(10);
      setfillstyle(SOLID_FILL, 10);
      rectangle(XMAX/2-230, 255, XMAX/2+230, 340);
      floodfill(XMAX / 2, 335, 10);
      settextstyle(8, 0, 5);
      setbkcolor(10);
      setcolor(WHITE);
      width=textwidth("Quan ly sach");
      height=textheight("Quan ly sach");
      outtextxy(XMAX/2-width/2, 300-height/2, "Quan ly sach");
      if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
			quanLiSach();
	  }
    }
    else{
      setcolor(GREEN);
      setfillstyle(SOLID_FILL, GREEN);
      rectangle(XMAX/2-230, 255, XMAX/2+230, 340);
      floodfill(XMAX / 2, 335, GREEN);
      settextstyle(8, 0, 5);
      setbkcolor(GREEN);
      setcolor(WHITE);
      width=textwidth("Quan ly sach");
      height=textheight("Quan ly sach");
      outtextxy(XMAX/2-width/2, 300-height/2, "Quan ly sach");
    }

    //Quan ly dau sach
    if(x >= XMAX/2-230 && x <= XMAX/2+230 && y >= 360 && y <= 445 ){
      setcolor(10);
      setfillstyle(SOLID_FILL, 10);
      rectangle(XMAX/2-230, 360, XMAX/2+230, 445);
      floodfill(XMAX / 2, 440, 10);
      settextstyle(8, 0, 5);
      setbkcolor(10);
      setcolor(WHITE);
      width=textwidth("Quan ly dau sach");
      height=textheight("Quan ly dau sach");
      outtextxy(XMAX/2-width/2, 405-height/2, "Quan ly dau sach");
      if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
        delay(100);
        DanhSachDauSach(DSDS,0);
      }
    }
    else{
      setcolor(GREEN);
      setfillstyle(SOLID_FILL, GREEN);
      rectangle(XMAX/2-230, 360, XMAX/2+230, 445);
      floodfill(XMAX / 2, 440, GREEN);
      settextstyle(8, 0, 5);
      setbkcolor(GREEN);
      setcolor(WHITE);
      width=textwidth("Quan ly dau sach");
      height=textheight("Quan ly dau sach");
      outtextxy(XMAX/2-width/2, 405-height/2, "Quan ly dau sach");
    }

    //Quan ly doc gia
    if(x >= XMAX/2-230 && x <= XMAX/2+230 && y >= 465 && y <= 550 ){
      setcolor(10);
      setfillstyle(SOLID_FILL, 10);
      rectangle(XMAX/2-230, 465, XMAX/2+230, 550);
      floodfill(XMAX / 2, 540, 10);
      settextstyle(8, 0, 5);
      setbkcolor(10);
      setcolor(WHITE);
      width=textwidth("Quan ly doc gia");
      height=textheight("Quan ly doc gia");
      outtextxy(XMAX/2-width/2, 510-height/2, "Quan ly doc gia");
      if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
        delay(100);
        quanLiDocGia();
	  }
    }
    else{
      setcolor(GREEN);
      setfillstyle(SOLID_FILL, GREEN);
      rectangle(XMAX/2-230, 465, XMAX/2+230, 550);
      floodfill(XMAX / 2, 540, GREEN);
      settextstyle(8, 0, 5);
      setbkcolor(GREEN);
      setcolor(WHITE);
      width=textwidth("Quan ly doc gia");
      height=textheight("Quan ly doc gia");
      outtextxy(XMAX/2-width/2, 510-height/2, "Quan ly doc gia");
    }

    //Thoat
    if(x >= XMAX/2-230 && x <= XMAX/2+230 && y >= 570 && y <= 655 ){
      setcolor(10);
      setfillstyle(SOLID_FILL, 10);
      rectangle(XMAX/2-230, 570, XMAX/2+230, 655);
      floodfill(XMAX / 2, 640, 10);
      settextstyle(8, 0, 5);
      setbkcolor(10);
      setcolor(WHITE);
      width=textwidth("Thoat");
      height=textheight("Thoat");
      outtextxy(XMAX/2-width/2, 615-height/2, "Thoat");
      if(ismouseclick(WM_LBUTTONDOWN)){
        clearmouseclick(WM_LBUTTONDOWN);
        break;
      }
    }
    else{
      setcolor(GREEN);
      setfillstyle(SOLID_FILL, GREEN);
      rectangle(XMAX/2-230, 570, XMAX/2+230, 655);
      floodfill(XMAX / 2, 640, GREEN);
      settextstyle(8, 0, 5);
      setbkcolor(GREEN);
      setcolor(WHITE);
      width=textwidth("Thoat");
      height=textheight("Thoat");
      outtextxy(XMAX/2-width/2, 615-height/2, "Thoat");
    }
    clearmouseclick(WM_LBUTTONDOWN);
  }
  Thoat();
}
void DanhSachDauSach(pointerArray &DS, int mode){
  int n = 0; 

  SapXepTheoTenSach(DS, DS.SoLuongDauSach);


  list_book_background();

  int page = 1;
  int maxPage = (DS.SoLuongDauSach%20==0) ? DS.SoLuongDauSach/20 : DS.SoLuongDauSach/20 + 1;
  Display_DSDS(DS, page, maxPage);
  
  if(mode==1){
    ARROW(5, 100, 4);
  }
  char str[30];
  int x, y;
  char c;
  int k = 0;
  int arrowLimit = DS.SoLuongDauSach >= 20 ? 20 : DS.SoLuongDauSach;
  int prev;
  while(1){
    
    // Disable keyboard input
    if(kbhit()){
      if(mode==0){
        getch();
      }
      else{
        c = getch();
        
          if(c==KEY_DOWN)
          {
            prev = k;
            if(k<arrowLimit-1){
              k++;
              ARROW(5, 100 + k * 30, 4);
              ARROW(5, 100 + k * 30 - 30, 8);
            }
            else if(k==arrowLimit-1 && maxPage>1 && page<maxPage){
              update_books_background();
              page++;
              Display_DSDS(DS, page, maxPage);
              arrowLimit = (page == maxPage) ? DS.SoLuongDauSach % 20 : 20;
              k = 0;
              ARROW(5, 100 + k * 30, 4);
            }
            prev = k;
          }

          if(c==KEY_UP)
          {
            prev = k;
            if(k>0 || page!=1){
              k--;
              ARROW(5, 100 + k * 30, 4);
              ARROW(5, 100 + k * 30 + 30, 8);
            }
            if(k==-1 && page>1){
              update_books_background();
              page--;
              Display_DSDS(DS, page, maxPage);
              k = (page == maxPage) ? DS.SoLuongDauSach % 20 - 1 : 19;
              arrowLimit = (page == maxPage) ? DS.SoLuongDauSach % 20 -1 : 20;
              ARROW(5, 100 + k * 30, 4);
            }
            prev = k;
          }

          if(c==13)
          {
            i = (page - 1) * 20 + k;
            TimKiemDauSach(DS.nodesDauSach[i]);
            DanhSachDauSach(DSDS, 0);
          }
        }
      }
    
    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
      x = mousex();
      y = mousey();

      //BACK
      if(x>=1230 &&  y>=5 && x<=1365 && y<=45){
        delete[] DS.nodesDauSach;
        thongbao = "";
        if(mode==0){
          cleardevice();
          menu();
        }
        else{
          delay(100);
          thongbao = "Thoat che do loc";
          DanhSachDauSach(DSDS, 0);
        }
      }

      //PREV
       else if(x>=32 &&  y>=5 && x<=172 && y<=45){
        if(page > 1){
          page--;
          list_book_background();
          Display_DSDS(DS, page, maxPage);
          if(mode==1){
            k = prev;
            ARROW(5, 100 + k * 30, 4);
            arrowLimit = (page == maxPage) ? DS.SoLuongDauSach % 20 : 20;
          }
        }
      }

      //NEXT
      else if(x>=192 &&  y>=5 && x<=332 && y<=45){
        if(page < maxPage){
          page++;
          list_book_background();
          Display_DSDS(DS, page, maxPage);
          if(mode==1){
            prev = k;
            if(page==maxPage && k>DS.SoLuongDauSach % 20 - 1){
              k = DS.SoLuongDauSach % 20 - 1;
            }
            arrowLimit = (page == maxPage) ? DS.SoLuongDauSach % 20 : 20;
            ARROW(5, 100 + k * 30, 4);
          }
        }
      }

      //SEARCH
      else if(x >= 600 && y >= 710 && x <= 700 && y <= 760 && mode==0){
  			if(DS.SoLuongDauSach>0){
          required_header_book_frame();
          LocDauSach(DSDS);
        }
        else{
          thongbao = "Danh sach dau sach trong";
        }
  	  }

      //ADD
      else if(x>=460 && y>=710 && x<=550 && y<=760 && mode==0){
        if(DSDS.SoLuongDauSach==MaxNodes){
          thongbao = "Da dat gioi han dau sach";
        }
        else{
          add_header_book();
          ThemDauSach();
        }
        DanhSachDauSach(DSDS, 0);
      }
	  }
	}
}

void LocDauSach(pointerArray DSDS){
  string s;
  NhapDauSach3(545, 165, 0, 24, 15, s);
  if(s=="EXIT"){
    DanhSachDauSach(DSDS,0);
  }
  int index, k=0;
  pointerArray temp;
  bool isEmpty = true;
  for (int i = 0; i < DSDS.SoLuongDauSach;i++){
    index = DSDS.nodesDauSach[i]->TenSach.find(s, 0);
    if(index!=-1){
      temp.nodesDauSach[k++] = DSDS.nodesDauSach[i];
      isEmpty = false;
    }
  }
  temp.SoLuongDauSach = k;
  thongbao = "Loc theo " + s;
  if(!isEmpty){
    DanhSachDauSach(temp, 1);
  }
  else{
    thongbao = "Khong tim thay dau sach";
    DanhSachDauSach(DSDS, 0);
  }
}


void readersBackground(){
  setbkcolor(8);
	cleardevice();
  setlinestyle(3, 2, 2);
  setcolor(WHITE);
  line(450, 0, 450, 768);
	setlinestyle(0, 2, 2);
  notice_frame();
  list_reader();
  readers_button();
}

void DanhSachDocGia(NODE_TREE *&root){
  TheDocGia *MangDocGia = new TheDocGia[SoLuongDocGia];
  int n = 0, sortMode = 0; //0: sap xep theo ma doc gia, 1: sap xep theo ho ten
  ChuyenCayThanhMang(root, MangDocGia, n);
  
  readersBackground();

  int page = 1;
  int maxPage = (SoLuongDocGia%20==0) ? SoLuongDocGia/20 : SoLuongDocGia/20 + 1;
  Display(MangDocGia, page, maxPage);
  //abc(root);
  int newReaderCode;
  int x, y;
  while(1){
    
    //Disable keyboard input
    if(kbhit()){
      getch();
    }
    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
      x = mousex();
      y = mousey();

      //BACK
      if(x>=1230 &&  y>=5 && x<=1365 && y<=45){
        delete[] MangDocGia;
        thongbao = "";
        cleardevice();
        menu();
      }

      //PREV
      else if(x>=460 &&  y>=5 && x<=600 && y<=45){
        if(page > 1){
          page--;
          readersBackground();
          Display(MangDocGia, page, maxPage);
        }
      }

      //NEXT
      else if(x>=620 &&  y>=5 && x<=760 && y<=45){
        if(page < maxPage){
          page++;
          readersBackground();
          Display(MangDocGia, page, maxPage);
        }
      }

      //SORT
      else if(x>=600 && y>=710 && x<=690 && y<=760){
        sort_frame();
        string s = XuLyNhapSapXep();
        if(s=="0"){
          thongbao = "Da sap xep theo ma doc gia";
          n = 0;
          ChuyenCayThanhMang(root, MangDocGia, n);
          sortMode = 0;
          // DanhSachDocGia(root);
        }
        else if(s=="1"){
          thongbao = "Da sap xep theo ho ten doc gia";
          SapXepTheoHoTen(MangDocGia, SoLuongDocGia);
          sortMode = 1;
          // DanhSachDocGia(root);
        }
        else if(s=="Close"){
          thongbao = "";
          // DanhSachDocGia(root);
        }
        readersBackground();
        page = 1;
        Display(MangDocGia, page, maxPage);
      }

      //ADD
      else if(x>=460 && y>=710 && x<=550 && y<=760){
        if(SoLuongDocGia==MienGiaTriNgauNhien){
          thongbao = "Da dat gioi han doc gia";
        }
        else{
          add_reader_function();
          ThemDocGia(newReaderCode);
          delete[] MangDocGia;
          MangDocGia = new TheDocGia[SoLuongDocGia];
          n = 0;
          ChuyenCayThanhMang(root, MangDocGia, n);
          if(sortMode==1){
            SapXepTheoHoTen(MangDocGia, SoLuongDocGia);
          }
          newReaderPage(page, MangDocGia, SoLuongDocGia, newReaderCode);
        }
        readersBackground();
        Display(MangDocGia, page, maxPage);
      }
        
    

      //EDIT
//      else if(x>=750 && y>=710 && x<=840 && y<=760){
//        if(SoLuongDocGia>0){
//          search_frame();
//          ChinhSuaDocGia();
//        }
//        else{
//          thongbao = "Danh sach doc gia trong";
//        }
//        DanhSachDocGia(root);
//      }

      //SEARCH
      else if(x >= 740 && y >= 710 && x <= 830 && y <= 760){
  			if(SoLuongDocGia>0){
          search_frame();
          TimKiemDocGia();
        }
        else{
          thongbao = "Danh sach doc gia trong";
        }
        readersBackground();
        Display(MangDocGia, page, maxPage);
  	  }
      
      //DELETE
//      else if(x >= 600 && y >= 710 && x <= 700 && y <= 760){
//      	if(SoLuongDocGia>0){
//      		delete_frame();
//          TimKiemDocGia2();
//        }
//        else{
//          thongbao = "Danh sach doc gia trong";
//        }
//        DanhSachDocGia(root);
//	  }
    }
  }
  getch();
}
void DanhSachDocGiaMuonQuaHan(){
  expired_reader_frame();
  QuaHan *quahan;
  int n = 0;
  if(SoLuongDocGia>0){
    setcolor(WHITE);
    setbkcolor(DARKGRAY);
    settextstyle(8, 0, 2);
    int k = 0;
    char str[30];
    quahan = new QuaHan[SoLuongDocGia * 3];
    CaySangMangQuaHan(root, quahan, n);
    sort_QuaHan(quahan, 0, n - 1);
    NODE_TREE *t;
    NODE_DOUBLY_LIST *mt;
    string s;
    for (int i = 0; i < n;i++){
      t = search_node_tree(root, quahan[i].mathe);
      mt = t->data.DoublyList_MuonTra.head;
      while(mt){
        if(mt->data.MaSach==quahan[i].masach){
          break;
        }
        mt = mt->next;
      }
    int page =  1;
    int maxPage = (n % 15 == 0 && n > 0) ? n / 15 : n / 15 + 1;
      //Ma the
      strcpy(str, to_string(quahan[i].mathe).c_str());
      outtextxy((142 - width(str)) / 2, 175 + k, str);
      //Ho ten
      s = t->data.Ho + " " + t->data.Ten;
      strcpy(str, s.c_str());
      outtextxy(200, 175 + k, str);
      //Ma sach
      strcpy(str, quahan[i].masach.c_str());
      outtextxy(480, 175 + k, str);
      //Ten sach
      s = TimTenSachBangMaSach(DSDS, quahan[i].masach);
      strcpy(str, s.c_str());
      outtextxy(610, 175 + k, str);
      //Ngay muon
      s = to_string(mt->data.NgayMuon.Ngay) + "/" + to_string(mt->data.NgayMuon.Thang) + "/" + to_string(mt->data.NgayMuon.Nam);
      strcpy(str, s.c_str());
      outtextxy(950, 175 + k, str);
      //So ngay qua han
      strcpy(str, to_string(quahan[i].songayquahan).c_str());
      outtextxy(1230, 175 + k, str);

      k += 34;
    }
  }

  int x, y;
  while(1){
    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
      x = mousex();
      y = mousey();
      if(x>=5 && y>=724 && x<=140 && y<=764){
        cleardevice();
        menu();
      }
    }
  }
  getch();
} 
void Top10DauSachDuocMuonNhieuNhat(){
  DauSach *DS[DSDS.SoLuongDauSach];
  Top10(DS);
  top_10_borrowing_books(DS);
	int x, y;
	while(1){
		if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){	
			x = mousex();
			y = mousey();
			if(x>=5 && y>=724 && x<=140 && y<=764){
        	cleardevice();
        	menu();
      	    }
		}
	}

}

void MuonTraSach(){
	required_id_reader_frame();
	int x, y;
  char c;
  int k;
  while(1){
		string s = Nhap2(555, 332);
		if(s == "Close"){
			cleardevice();
			menu();
		}
		if(s == "-1"){
			s = Nhap2(555, 332);
		}
		NODE_TREE *p = search_node_tree(root, stoi(s));
		if(p == NULL){
			setcolor(BLACK);
			setbkcolor(WHITE);
			settextstyle(3, 0, 1);
			outtextxy(555, 332, "                        ");
			
			setbkcolor(LIGHTGRAY);
			setcolor(RED);
			settextstyle(8, 0, 2);
			outtextxy(455, 435, "                              ");
			outtextxy(455, 435, "Khong tim thay doc gia!");
		}else{
			reader_information_function3(p->data);
      list_borrowing_book1(p->data, -1);
      notice_frame2();
      while(1){
        if(kbhit()){
          getch();
        }
				if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){	
					x = mousex();
					y = mousey();
					if(x >= 5 && y >= 724 && x <=140 && y <=764){
            thongbao = "";
            cleardevice();
        		MuonTraSach();
      		}
  				if(x >= 701 && x <= 1001 && y >= 724 && y <= 764){
  					// background_borrow_return();
  					// reader_information_function3(p->data);
  					list_borrowing_book1(p->data, 0);
            thongbao = "Lua chon sach de tra";
            notice_frame2();
            if(p->data.SoSachDangMuon!=0){
              TraSach(p->data);
            }
            else{
              thongbao = "Khong co sach de tra";
            }
            reader_information_function3(p->data);
            list_borrowing_book1(p->data, -1);
            notice_frame2();
          }
					if(x >= 1061 && x <= 1361 && y >= 724 && y <= 764){
            if(!checkQuaHan(p->data) && p->data.SoSachDangMuon<3){
              MuonSach(p->data);
            }
            else if(checkQuaHan(p->data)){
              thongbao = "Khong duoc muon sach vi qua han";
            }
            else if(p->data.SoSachDangMuon==3){
              thongbao = "Khong duoc muon qua 3 cuon sach";
            }
            reader_information_function3(p->data);
            list_borrowing_book1(p->data, -1);
            notice_frame2();
					}
				}
			}
		}	
	}
	getch();
}

//void QuanLyDauSach(){
//  list_book_background();
//  int x, y;
//  while(1){
//    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
//      x = mousex();
//		  y = mousey();
//
//      //BACK
//			if(x>=1230 &&  y>=5 && x<=1365 && y<=45){
//        thongbao = "";
//        cleardevice();
//        menu();
//      }
//    }
//  }
//  getch();
//}
//void QuanLyDauSach(){
//  list_book_background();
//  int x, y;
//  while(1){
//    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
//      x = mousex();
//		  y = mousey();
//
//      //BACK
//			if(x>=1230 &&  y>=5 && x<=1365 && y<=45){
//        thongbao = "";
//        cleardevice();
//        menu();
//      }
//    }
//  }
//  getch();
//}

void CapNhatDanhMucSach(pointerArray &DSDS){


  SapXepTheoTenSach(DSDS, DSDS.SoLuongDauSach);


  update_books_background();
  ARROW(445, 100, 15);

  int page = 1;
  int maxPage = (DSDS.SoLuongDauSach%20==0) ? DSDS.SoLuongDauSach/20 : DSDS.SoLuongDauSach/20 + 1;
  Display_DSDS(DSDS, page, maxPage);

  char c;
  int k = 0;
  int arrowLimit=DSDS.SoLuongDauSach>=20?20:DSDS.SoLuongDauSach;
  int x, y, i;
  while(1){
    if(kbhit()){
      c = getch();
      switch(c){
        case KEY_DOWN:
        { 
          if(k<arrowLimit){
            k++;
            ARROW(445, 100 + k * 30, 15);
            ARROW(445, 100 + k * 30 - 30, 8);
          }
          if(k==arrowLimit && maxPage>1 && page<maxPage){
            update_books_background();
            page++;
            Display_DSDS(DSDS, page, maxPage);
            arrowLimit = (page == maxPage) ? DSDS.SoLuongDauSach % 20 -1 : 20;
            k = 0;
            ARROW(445, 100 + k * 30, 15);
          }
          break;
        }

        case KEY_UP:
        {

          if(k>0 || page!=1){
            k--;
            ARROW(445, 100 + k * 30, 15);
            ARROW(445, 100 + k * 30 + 30, 8);
          }
          if(k==-1 && page>1){
            update_books_background();
            page--;
            Display_DSDS(DSDS, page, maxPage);
            k = (page == maxPage) ? DSDS.SoLuongDauSach % 20 - 1 : 19;
            arrowLimit = (page == maxPage) ? DSDS.SoLuongDauSach % 20 -1 : 20;
            ARROW(445, 100 + k * 30, 15);
          }
          break;
        }

        case 13:
        {
          i = (page - 1) * 20 + k;
          //update_books_function(i,page,maxPage);

          getch();
        }
      }
    }

    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
      x = mousex();
      y = mousey();

      //BACK
      if(x>=1230 &&  y>=5 && x<=1365 && y<=45){
        delete[] DSDS.nodesDauSach;
        thongbao = "";
        cleardevice();
        menu();
      }

      //PREV
       else if(x>=460 &&  y>=5 && x<=600 && y<=45){
        if(page > 1){
          page--;
          update_books_background();
          Display_DSDS(DSDS, page, maxPage);
          arrowLimit = (page == maxPage) ? DSDS.SoLuongDauSach % 20 -1 : 20;
          ARROW(445, 100 + k * 30, 15);
        }
      }

      //NEXT
      else if(x>=620 &&  y>=5 && x<=760 && y<=45){
        if(page < maxPage){
          page++;
          update_books_background();
          Display_DSDS(DSDS, page, maxPage);
          arrowLimit = (page == maxPage) ? DSDS.SoLuongDauSach % 20 -1 : 20;
          if(k>DSDS.SoLuongDauSach%20){
            k = (page == maxPage) ? DSDS.SoLuongDauSach % 20 - 1 : 19;
          }
          ARROW(445, 100 + k * 30, 15);
        }
      }
    }
  }
}
