#include <string>
#include <graphics.h>
#include <ctime>
#include "KhaiBao.h"

using namespace std;

#define XMAX 1366
#define YMAX 768
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
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
  bar(10, 470, 440, 520);
  setcolor(YELLOW);
  setlinestyle(0, 0, 1);
	rectangle(10, 470, 440, 520);
	rectangle(13, 473, 437, 517);
	setbkcolor(DARKGRAY);
  setcolor(YELLOW);
  settextstyle(3, 0, 1);
	outtextxy(20, 485, "NOTI:");
  char str[50];
  strcpy(str, thongbao.c_str());
  setbkcolor(DARKGRAY);
  setcolor(RED);
  settextstyle(10, 0, 1);
  outtextxy(20+width("NOTI: "), 485, str);
  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);
}

void notice_frame2(){
  setlinestyle(0, 0, 1);
	setcolor(YELLOW);
	rectangle(160, 724, 681, 764);
	rectangle(163, 727, 678, 761);
	settextstyle(8, 0, 3);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(164, 728, YELLOW);
	setbkcolor(WHITE);
	setcolor(RED);
	outtextxy(168, 744-height("Noti: ")/2, "Noti: ");
  char str[50];
  strcpy(str, thongbao.c_str());
  setbkcolor(WHITE);
  settextstyle(8, 0, 1);
  outtextxy(180 + width("Noti: "), 744-height(thongbao)/2, str);
  settextstyle(3, 0, 1);
  setcolor(BLACK);
}
void notice_frame3(){
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
string confirm_frame(){
	setcolor(0);
	setlinestyle(0, 0, 2);
	rectangle(440, 170, 926, 350);
	line(440, 240, 926, 240);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(450, 230, BLACK);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	floodfill(460, 300, BLACK);
	setcolor(LIGHTGRAY);
	line(442, 240, 924, 240);
	
	setcolor(RED);
	setlinestyle(0, 0, 1);
	line(480, 180, 450, 230);
	line(480, 180, 510, 230);
	line(450, 230, 510, 230);
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(490, 200, RED);
	setcolor(BLACK);
	line(478, 190, 482, 190);
	line(478, 190, 479, 215);
	line(482, 190, 481, 215);
	line(480, 215, 480, 217);
	circle(480, 225, 3);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(480, 225, BLACK);
	floodfill(480, 200, BLACK);
	setbkcolor(WHITE);
	setcolor(RED);
	settextstyle(10, 0, 4);
	outtextxy(530, 200, "CAUTION !!");
	
	setcolor(BLACK);
	setbkcolor(LIGHTGRAY);
	settextstyle(8, 0, 3);
	outtextxy(450, 265, "Want to save your changes?");
	
	while(1){
		int x = mousex();
		int y = mousey();
		setcolor(DARKGRAY);
		settextstyle(8, 0, 1);
		setlinestyle(0, 0, 1);
		if((x >= 536 && x <= 636) && (y >= 310 && y <= 340)){
			setcolor(DARKGRAY);
			rectangle(536, 310, 636, 340);
			setcolor(CYAN);
			rectangle(537, 311, 635, 339);
			setfillstyle(SOLID_FILL, CYAN);
			floodfill(550, 330, CYAN);
			setcolor(WHITE);
			setbkcolor(CYAN);
			outtextxy(565, 316, "Save");
      if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
        return "Save";
      }
		}else{
			setcolor(DARKGRAY);
			rectangle(536, 310, 636, 340);
			setcolor(WHITE);
			rectangle(537, 311, 635, 339);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(550, 330, WHITE);
			setcolor(BLACK);
			setbkcolor(WHITE);
			outtextxy(565, 316, "Save");
		}
		if((x >= 656 && x <= 796) && (y >= 310 && y <= 340)){
			setcolor(DARKGRAY);
			rectangle(656, 310, 796, 340);
			setcolor(CYAN);
			rectangle(657, 311, 795, 339);
			setfillstyle(SOLID_FILL, CYAN);
			floodfill(750, 330, CYAN);
			setcolor(WHITE);
			setbkcolor(CYAN);
			outtextxy(668, 316, "Don't Save");
      if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
        return "Don't Save";
      }
		}else{
			setcolor(DARKGRAY);
			rectangle(656, 310, 796, 340);
			setcolor(WHITE);
			rectangle(657, 311, 795, 339);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(750, 330, WHITE);
			setcolor(BLACK);
			setbkcolor(WHITE);
			outtextxy(668, 316, "Don't Save");
		}
		if((x >= 816 && x <= 916) && (y >= 310 && y <= 340)){
			setcolor(DARKGRAY);
			rectangle(816, 310, 916, 340);
			setcolor(CYAN);
			rectangle(817, 311, 915, 339);
			setfillstyle(SOLID_FILL, CYAN);
			floodfill(850, 330, CYAN);
			setcolor(WHITE);
			setbkcolor(CYAN);
			outtextxy(835, 316, "Cancel");
      if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
        return "Cancel";
      }
		}else{
			setcolor(DARKGRAY);
			rectangle(816, 310, 916, 340);
			setcolor(WHITE);
			rectangle(817, 311, 915, 339);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(850, 330, WHITE);
			setcolor(BLACK);
			setbkcolor(WHITE);
			outtextxy(835, 316, "Cancel");
		}
	}
}

void Nhap(int x1, int y1, int item, string &s){
  setcolor(BLACK);
  if(item==0 || item==5){
    setbkcolor(WHITE);
  }
  else{
    setbkcolor(LIGHTGRAY);
  }
  settextstyle(3, 0, 1);
  char c, prev;
  string s2 = s + "_   ";
  char str[50];
  strcpy(str, s2.c_str());
  outtextxy(x1, y1, str);
  s2 = "_   ";
  bool isEmpty = true;
  switch(item){
    case 0:{ //MaThe
      while(1){
        if(kbhit()){
          c = getch();

          //Esc
          if(c==27){
            thongbao = "";
            s = "EXIT";
            return;
          }

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "  ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(WHITE);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==4){
              thongbao = "";
              notice_frame();
              setbkcolor(WHITE);
            }
          }

          //Numbers
          if(isdigit(c)){
            if(s.length()<5){
              s += c;
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(WHITE);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(WHITE);
            }
          }
        }
      }
      break;
    }

    case 1:{ //Ho
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==15){
              thongbao = "";
              notice_frame();
              setbkcolor(WHITE);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '){
            if(s.length()==0){
              prev = '0';
            }
            else{
              prev = s[s.length() - 1];
            }
            if(s.length()<16){
              if(prev=='0' || prev==' '){
                if(c!=' '){
                  s += toupper(c);
                }
              }
              else{
                s += tolower(c);
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              
            }
          }
        }
      }
      break;
    }

    case 2:{ //Ten
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
            }
          }

          //Backspace
          else if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==6){
              thongbao = "";
              notice_frame();
              setbkcolor(WHITE);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '){
            if(s.length()==0){
              prev = '0';
            }
            if(s.length()<7){
              if(prev=='0' || prev==' '){
                s += toupper(c);
                prev = c;
              }
              else{
                s += tolower(c);
                prev = c;
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
            }
          }


          
        }
      }
      break;
    }

    case 3:{ //Phai
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            thongbao = "";
            notice_frame();
          }

          //Letters
          if(c=='0' || c=='1'){
            if(s.length()<1){
              s += c;
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
            }
          }

          
        }
      }
      break;
    }

    case 4:{ //Trang thai the
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            thongbao = "";
            notice_frame();
          }

          //Letters
          if(c=='0' || c=='1'){
            if(s.length()<1){
              s += c;
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
            }
          }
        }
      }
      break;
    }

    case 5:{ //Ten sach
      while(1){
        if(kbhit()){
          c = getch();

          //Esc
          if(c==27){
            thongbao = "";
            s = "EXIT";
            return;
          }

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(WHITE);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==23){
              thongbao = "";
              notice_frame();
              setbkcolor(WHITE);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '||(c>='0' && c<='9')){
            if(s.length()==0){
              prev = '0';
            }
            else{
              prev = s[s.length() - 1];
            }
            if(s.length()<24){
              if(prev=='0' || prev==' '){
                if(c!=' '){
                  s += toupper(c);
                }
              }
              else{
                s += toupper(c);
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(WHITE);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(WHITE);
            }
          }
        }
      }
      break;
    }

  }
}
string Nhap2(int x, int y){
	setcolor(BLACK);
	setbkcolor(WHITE);
	settextstyle(3, 0, 1);
	
	char c;
	string s = "";
	string s2 = "_  ";
	char str [10];
	strcpy(str, "_");
	outtextxy(x, y, str);
	while(1){
		setcolor(BLACK);
		setbkcolor(WHITE);
		settextstyle(3, 0, 1);
		c = getch();
		if(c == 8 && s.length() > 0){
			s.pop_back();
			s2 = s + s2;
			strcpy(str, s2.c_str());
			outtextxy(x, y, str);
			s2 = "_   ";
		}
		if(isdigit(c)){
			if(s.length() < 5){
				s += c;
				s2 = s + s2;
				strcpy(str, s2.c_str());
				outtextxy(x, y, str);
				s2 = "_   ";
			}
		}
		if(c == 13){
			if(s.length() > 0 && stoi(s) <= 30000){
				return s;
			}else if(s.length() == 0){
				setcolor(BLACK);
				setbkcolor(WHITE);
				settextstyle(3, 0, 1);
				outtextxy(x, y, "                        ");
				
				setbkcolor(LIGHTGRAY);
				setcolor(RED);
				settextstyle(8, 0, 2);
				outtextxy(455, 435, "                              ");
				outtextxy(455, 435, "Khong duoc de trong!");
				return "-1";
			}else if(stoi(s) > 30000){
				setcolor(BLACK);
				setbkcolor(WHITE);
				settextstyle(3, 0, 1);
				outtextxy(x, y, "                        ");
				
				setbkcolor(LIGHTGRAY);
				setcolor(RED);
				settextstyle(8, 0, 2); 
				outtextxy(455, 435, "                              ");
				outtextxy(455, 435, "Ma qua lon, yeu cau nhap lai!");
				return "-1";
			}
		}
		if(c == 27){
			return "Close";
		}
	}
}

void NhapDauSach(int x1, int y1, int item, int max, int bkcolor, string &s){
  setcolor(BLACK);
  setbkcolor(bkcolor);
  settextstyle(3, 0, 1);
  char c, prev;
  string s2 = s + "_   ";
  char str[50];
  strcpy(str, s2.c_str());
  outtextxy(x1, y1, str);
  s2 = "_   ";
  bool isEmpty = true;
  switch(item){
    case 0:{ //Ten dau sach 
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '||(c>='0' && c<='9')){
            if(s.length()==0){
              prev = '0';
            }
            else{
              prev = s[s.length() - 1];
            }
            if(s.length()<max){
              if(prev=='0' || prev==' '){
                if(c!=' '){
                  s += toupper(c);
                }
              }
              else{
                s += toupper(c);
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 1:{ //ISBN
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              if(SearchISBN(DSDS,s)){
                thongbao = "ISBN da ton tai";
                notice_frame();
                setbkcolor(bkcolor);
                NhapDauSach(155, 120, 1, 4, 7, s);
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          else if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z')){
            if(s.length()<max){
              s += toupper(c);
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 2:{ //Tac gia, The loai
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '){
            if(s.length()==0){
              prev = '0';
            }
            else{
              prev = s[s.length() - 1];
            }
            if(s.length()<max){
              if(prev=='0' || prev==' '){
                if(c!=' '){
                  s += toupper(c);
                }
              }
              else{
                s += toupper(c);
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 3:{ //So trang, NXB
      int temp;
      string t = to_string(max);
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            temp = stoi(s);
            if(s.length()>0 && temp<=max){
              s2 = s + "  ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              return;
            }
            else if(s.length()==0){
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(bkcolor);
            }
            else if(temp>max){
              thongbao = "Qua gioi han";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==t.length()-1){
              thongbao = "";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Numbers
          if(isdigit(c)){
            if(s.length()<t.length()){
              s += c;
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }
  }
}
void NhapDauSach2(int x1, int y1, int item, int max, int bkcolor, string &s,int j){
  setcolor(BLACK);
  setbkcolor(bkcolor);
  settextstyle(3, 0, 1);
  char c, prev;
  string s2 = s + "_   ";
  char str[50];
  strcpy(str, s2.c_str());
  outtextxy(x1, y1, str);
  s2 = "_   ";
  bool isEmpty = true;
  switch(item){
    case 0:{ //Ten dau sach 
      while(1){
        if(kbhit()){
          c = getch();
          
          //ESC
        if(c==27){
            thongbao = "";
            s = "EXIT";
            return;
          }

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '||(c>='0' && c<='9')){
            if(s.length()==0){
              prev = '0';
            }
            else{
              prev = s[s.length() - 1];
            }
            if(s.length()<max){
              if(prev=='0' || prev==' '){
                if(c!=' '){
                  s += toupper(c);
                }
              }
              else{
                s += toupper(c);
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 1:{ //ISBN
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              if(SearchISBN2(DSDS,s,j)){
                thongbao = "ISBN da ton tai";
                notice_frame();
                setbkcolor(bkcolor);
                NhapDauSach(155, 120, 1, 4, 7, s);
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          else if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z')){
            if(s.length()<max){
              s += toupper(c);
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 2:{ //Tac gia, The loai
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '){
            if(s.length()==0){
              prev = '0';
            }
            else{
              prev = s[s.length() - 1];
            }
            if(s.length()<max){
              if(prev=='0' || prev==' '){
                if(c!=' '){
                  s += toupper(c);
                }
              }
              else{
                s += toupper(c);
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 3:{ //So trang, NXB
      int temp;
      string t = to_string(max);
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            temp = stoi(s);
            if(s.length()>0 && temp<=max){
              s2 = s + "  ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              return;
            }
            else if(s.length()==0){
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(bkcolor);
            }
            else if(temp>max){
              thongbao = "Qua gioi han";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==t.length()-1){
              thongbao = "";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Numbers
          if(isdigit(c)){
            if(s.length()<t.length()){
              s += c;
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 4:{ //Vi tri sach
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '||(c>='0' && c<='9') || c=='-'){
            if(s.length()==0){
              prev = '0';
            }
            else{
              prev = s[s.length() - 1];
            }
            if(s.length()<max){
              if(prev=='0' || prev==' '){
                if(c!=' '){
                  s += toupper(c);
                }
              }
              else{
                s += toupper(c);
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }
  }
}
void NhapDauSach3(int x1, int y1, int item, int max, int bkcolor, string &s){
  setcolor(BLACK);
  setbkcolor(bkcolor);
  settextstyle(3, 0, 1);
  char c, prev;
  string s2 = s + "_   ";
  char str[50];
  strcpy(str, s2.c_str());
  outtextxy(x1, y1, str);
  s2 = "_   ";
  bool isEmpty = true;
  switch(item){
    case 0:{ //Ten dau sach 
      while(1){
        if(kbhit()){
          c = getch();
        //ESC  
        if(c==27){
            thongbao = "";
            s = "EXIT";
            return;
          }

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '||(c>='0' && c<='9')){
            if(s.length()==0){
              prev = '0';
            }
            else{
              prev = s[s.length() - 1];
            }
            if(s.length()<max){
              if(prev=='0' || prev==' '){
                if(c!=' '){
                  s += toupper(c);
                }
              }
              else{
                s += toupper(c);
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame3();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 1:{ //ISBN
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              if(SearchISBN(DSDS,s)){
                thongbao = "ISBN da ton tai";
                notice_frame3();
                setbkcolor(bkcolor);
                NhapDauSach(155, 120, 1, 4, 7, s);
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          else if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z')){
            if(s.length()<max){
              s += toupper(c);
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame3();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 2:{ //Tac gia, The loai
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '){
            if(s.length()==0){
              prev = '0';
            }
            else{
              prev = s[s.length() - 1];
            }
            if(s.length()<max){
              if(prev=='0' || prev==' '){
                if(c!=' '){
                  s += toupper(c);
                }
              }
              else{
                s += toupper(c);
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame3();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 3:{ //So trang, NXB
      int temp;
      string t = to_string(max);
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            temp = stoi(s);
            if(s.length()>0 && temp<=max){
              s2 = s + "  ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              return;
            }
            else if(s.length()==0){
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame3();
              setbkcolor(bkcolor);
            }
            else if(temp>max){
              thongbao = "Qua gioi han";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==t.length()-1){
              thongbao = "";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }

          //Numbers
          if(isdigit(c)){
            if(s.length()<t.length()){
              s += c;
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame3();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame3();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }
  }
}


string XuLyNhapSapXep(){
  setcolor(BLACK);
  setbkcolor(WHITE);
  settextstyle(3, 0, 1);
  char c;
  string s = "";
  char str[100];
  strcpy(str,"_");
  outtextxy(100, 170-(height("_"))/2, str);
  
  while(1){
    setcolor(BLACK);
    setbkcolor(WHITE);
    settextstyle(3, 0, 1);
    c=getch();

    //Backspace
    if(c==8&&s.length()==1){
      s.pop_back();
      strcpy(str,"_");
  	outtextxy(100, 170-(height("_"))/2, str);
    }
    else{
      if(c!=8 && s.length()==0){
        if(c=='0'||c=='1'){
          s += c;
          strcpy(str, s.c_str());
          outtextxy(100, 170-height(s)/2, str);
        }
      }
    }

    //Enter
    if(c==13){
      if(s.length()>0){
        return s;
      }
      else{
        setbkcolor(DARKGRAY);
        setcolor(YELLOW);
        outtextxy(20+width("NOTI: "), 485, "Ban chua nhap che do sap xep");
      }
    }

    //Esc
    if(c==27){
      return "Close";
    }
  }
}

string XuLyNhapTimKiem(){
	setcolor(BLACK);
	setbkcolor(WHITE);
	settextstyle(3, 0, 1);
	
    char str[10];
    string s = "";
    string s2 = "_  ";
    strcpy(str, "_");
    outtextxy(100, 120-(height("_"))/2, str);
    while(1){
    setcolor(BLACK);
		setbkcolor(WHITE);
		settextstyle(3, 0, 1);
    char c = getch();
		if(c == 8 && s.length() > 0){
			s.pop_back();
			s2 = s + s2;
			strcpy(str, s2.c_str());
			outtextxy(100, 120-(height("_"))/2, str);
			s2 = "_   ";
		}
		if(isdigit(c)){
			if(s.length() < 6){
				s += c;
				s2 = s + s2;
				strcpy(str, s2.c_str());
				outtextxy(100, 120-(height("_"))/2, str);
				s2 = "_   ";
			}
		}
		if(c == 13){
			if(s.length() > 0 && stoi(s) < 30001){
				return s;
			}else if(s.length() == 0){
				setbkcolor(DARKGRAY);
       			setcolor(YELLOW);
        		outtextxy(30+width("NOTI: "), 485, "Khong duoc de trong!");	
			}
			else{
				setbkcolor(DARKGRAY);
       			setcolor(YELLOW);
        		outtextxy(30+width("NOTI: "), 485, "Ma qua lon, yeu cau nhap lai!");	
			}
		}
		if(c == 27){
			return "Close";
		}
	}
}


string XuLyNhapDocGia(TheDocGia &R){
  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);
  
  char c, prev;
  string s = "";
  string s2 = "_   ";
  char str[100];
  string A[5];
  A[0] = to_string(R.MaThe) + "  ";
  if(R.Ho!=""){
    A[1] = R.Ho;
    A[2] = R.Ten;
    A[3] = (R.Phai == "Nam") ? "0" : "1";
    A[4] = to_string(R.TrangThai);
  }
  int item = 1; //1: ho, 2: ten, 3: phai, 4: trang thai the
  int times = 0; //So lan Esc
  strcpy(str, A[0].c_str());
  outtextxy(155, 80, str);

  //strcpy(str,s2.c_str());
  // outtextxy(155, 130, str);

  int x, y;
  while(1){

    //Keyboard
    setcolor(YELLOW);
    setbkcolor(DARKGRAY);
    if(kbhit()){
      c = getch();

      //Enter
      if(c==13){ 
        if(A[item].length()>0){
          if(item<4){
            item++;
            thongbao = "                               ";
          }
        }
        else{
          thongbao = "Ban khong duoc de trong!";
        }
      }

      //Esc
      else if(c==27){
        times++;
        if(times==2){
          thongbao = "";
          return "Esc";
        }
        thongbao = "Nhan Esc lan nua de thoat nhap";
        continue;
      }

      //Backspace
      else if(c==8){
        if(A[item].length()>0){
          A[item].pop_back();
          thongbao = "                               ";
        }
      }

      //Others
      else{
        if(A[item].length()==0){
          prev = '0';
        }
        if(item==1){ //Ho
          if(A[item].length()<16){
            if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '){
              if(prev=='0' || prev==' '){
                A[item] += toupper(c);
                prev = c;
              }
              else{
                A[item] += tolower(c);
                prev = c;
              }
            }
          }
          else{
            thongbao = "Da dat gioi han ky tu";
          }
        }
        else if(item==2){ //Ten
          if(A[item].length()<7){
            if((c>='A' && c<='Z')||(c>='a'&&c<='z')){
              if(prev=='0'){
                A[item] += toupper(c);
                prev = c;
              }
              else{
                A[item] += tolower(c);
                prev = c;
              }
            }
          }
          else{
            thongbao = "Da dat gioi han ky tu";
          }
        }
        else if(item==3){ //Phai
          if(A[item].length()<1){
            if(c=='0' || c=='1'){
              A[item] += c;
            }
            else{
              thongbao = "";
            }
          }
          else{
            thongbao = "Da dat gioi han ky tu";
          }
        }
        else if(item==4){ //Trang thai the
          if(A[item].length()<1){
            if(c=='0' || c=='1'){
              A[item] += c;
            }
            else{
              thongbao = "";
            }
          }
          else{
            thongbao = "Da dat gioi han ky tu";
          }
        }
      }
      if(times>0){
        times--;
        thongbao = "                               ";
      }
    }

    //Mouse
    
    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
      x = mousex();
      y = mousey();

      //Items
      if(x>=150 && y>=130 && x<=415 && y<=150){
        item = 1;
        thongbao = "                               ";
      }
      else if(x>=150 && y>=180 && x<=415 && y<=200){
        item = 2;
        thongbao = "                               ";
      }
      else if(x>=150 && y>=230 && x<=415 && y<=250){
        item = 3;
        thongbao = "                               ";
      }
      else if(x>=150 && y>=280 && x<=415 && y<=300){
        item = 4;
        thongbao = "                               ";
      }

      //Save
      else if(x>=170 && y>=405 && x<=280 && y<=455){
        if(A[1]!="" && A[2]!="" && A[3]!="" && A[4]!=""){
          R.Ho = A[1];
          R.Ten = A[2];
          R.Phai = (A[3] == "0") ? "Nam" : "Nu";
          R.TrangThai = stoi(A[4]);
          return "Save";
        }
        else{
          thongbao = "Ban khong duoc de trong";
        }
      }
    }

    //Display
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    settextstyle(3, 0, 1);
    for (int i = 1; i <= 4;i++){
        if(i!=item){
          s = A[i] + "   ";
          strcpy(str, s.c_str());
          outtextxy(155, 80 + i * 50, str);
        }
        else{
          s2 = A[i] + s2;
          strcpy(str, s2.c_str());
          outtextxy(155, 80 + i * 50, str);
          s2 = "_   ";
        }
    }

    notice_frame();

  }
}

bool XuLyChinhSuaDocGia(NODE_TREE *&p){
  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);

  char c;
  string s, s2="_  ";
  char str[10];
  int mathe;
  string result;
  outtextxy(155, 80, "_");
  while(1){
    if(kbhit()){
      c = getch();

      //Enter
      if(c==13){
        mathe = stoi(s);
        p = search_node_tree(root, mathe);
        if(p==NULL){
          thongbao = "Khong ton tai doc gia";
          return false;
        }
        else{
          result = XuLyNhapDocGia(p->data);
          if(result=="Save"){
            return true;
          }
          else{
            return false;
          }
        }
      }

      //Esc
      if(c==27){
        return false;
      }

      //Backspace
      if(c==8 && s.length()>0){
        s.pop_back();
        s2 = s + s2;
        strcpy(str, s2.c_str());
        outtextxy(155, 80, str);
        s2 = "_   ";
      }

      //Numbers
      if(isdigit(c)){
        if(s.length()<=5){
          s += c;
          s2 = s + s2;
          strcpy(str, s2.c_str());
          outtextxy(155, 80, str);
          s2 = "_   ";
        }
        else{
          thongbao = "Da dat gioi han ky tu";
        }
      }
    }
  }
}

int NamHienTai(){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int year = 1900 + ltm->tm_year;
  return year;
}

int ThangHienTai(){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int month = 1 + ltm->tm_mon;
  return month;
}

int NgayHienTai(){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int day = ltm->tm_mday;
  return day;
}

int SoSachConLai(int i){
  NODE_SINGLY_LIST *p = DSDS.nodesDauSach[i]->dms.head;
  int count = 0;
  if(DSDS.nodesDauSach[i]->SoLuongSach!= 0){
    while(p){
      if(p->data.trangthai==0){
        count++;
      }
      p = p->next;
    }
  }
  return count;
}

int SoSachDuocNhap(DauSach *DS){
  NODE_SINGLY_LIST *p = DS->dms.head;
  int count = 0;

    while(p){
      if(p->data.trangthai!=2){
        count++;
      }
      p = p->next;
    }

  return 30-count;
}

DauSach* TimSachBangMaSach(pointerArray DSDS, string masach){
  for (int i = 0; i < DSDS.SoLuongDauSach;i++){
    if(masach.length()>DSDS.nodesDauSach[i]->ISBN.length() && masach.find(DSDS.nodesDauSach[i]->ISBN,0)==0){
      return DSDS.nodesDauSach[i];
    }
  }
  return NULL;
}

string TimTenSachBangMaSach(pointerArray DSDS, string masach){
  for (int i = 0; i < DSDS.SoLuongDauSach;i++){
    if(masach.find(DSDS.nodesDauSach[i]->ISBN,0)==0){
      return DSDS.nodesDauSach[i]->TenSach;
    }
  }
  return "";
}

bool MuonTrungSach(DauSach *DS, TheDocGia R, string masach){
  NODE_DOUBLY_LIST *p = R.DoublyList_MuonTra.head;
  while(p){
    if(p->data.MaSach.length()>DS->ISBN.length() && p->data.MaSach.find(DS->ISBN,0)==0){
      return true;
    }
    p = p->next;
  }
  return false;
}

int SoNgayMuon(int day, int month, int year){
    time_t now = time(0);
    tm ltm = *localtime(&now); 
    int currentDay = ltm.tm_mday;
    int currentMonth = 1 + ltm.tm_mon; 
    int currentYear = 1900 + ltm.tm_year; 

    tm specificTime_tm = {0, 0, 0, day, month - 1, year - 1900}; 
    time_t specificTime = mktime(&specificTime_tm); 

    time_t currentTime = mktime(&ltm); 

    double difference = difftime(currentTime, specificTime) / (60 * 60 * 24);

    return static_cast<int>(difference);
}
bool checkQuaHan(TheDocGia x){
  
	NODE_DOUBLY_LIST *p = x.DoublyList_MuonTra.head;
  while(p){
    if(p->data.TrangThai==0 && SoNgayMuon(p->data.NgayMuon.Ngay, p->data.NgayMuon.Thang, p->data.NgayMuon.Nam) > 7){
      return true;
    }
    p = p->next;
  }
  return false;
}

void NhapMuonTra(int x1, int y1, int item, int max, int bkcolor, string &s){
  setcolor(BLACK);
  setbkcolor(bkcolor);
  settextstyle(3, 0, 1);
  char c, prev;
  string s2 = s + "_   ";
  char str[50];
  strcpy(str, s2.c_str());
  outtextxy(x1, y1, str);
  s2 = "_   ";
  bool isEmpty = true;
  switch(item){
    case 0:{ //Ngay tra
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame2();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame2();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z') || c==' '||(c>='0' && c<='9')){
            if(s.length()==0){
              prev = '0';
            }
            else{
              prev = s[s.length() - 1];
            }
            if(s.length()<max){
              if(prev=='0' || prev==' '){
                if(c!=' '){
                  s += toupper(c);
                }
              }
              else{
                s += toupper(c);
              }
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame2();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame2();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 1:{ //Trang thai sach
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame2();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame2();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if(c=='1' || c=='2'){
            if(s.length()<1){
              s += c;
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame2();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame2();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

    case 2:{ //Ma sach
      while(1){
        if(kbhit()){
          c = getch();

          //Enter
          if(c==13){
            if(s.length()>0){
              s2 = s + "   ";
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              prev = s[s.length() - 1];
              if(prev==' '){
                s.pop_back();
              }
              return;
            }
            else{
              isEmpty = true;
              thongbao = "Vui long nhap";
              notice_frame2();
              setbkcolor(bkcolor);
            }
          }

          //Backspace
          else if(c==8 && s.length()>0){
            s.pop_back();
            s2 = s + s2;
            strcpy(str, s2.c_str());
            outtextxy(x1, y1, str);
            s2 = "_   ";
            if(s.length()==max-1){
              thongbao = "";
              notice_frame2();
              setbkcolor(bkcolor);
            }
          }

          //Letters
          else if((c>='A' && c<='Z')||(c>='a'&&c<='z')||(c>='1'&&c<='9')){
            if(s.length()<max){
              s += toupper(c);
              s2 = s + s2;
              strcpy(str, s2.c_str());
              outtextxy(x1, y1, str);
              s2 = "_   ";
              if(isEmpty){
                isEmpty = false;
                thongbao = "";
                notice_frame2();
                setbkcolor(bkcolor);
              }
            }
            else{
              thongbao = "Da dat gioi han ky tu";
              notice_frame2();
              setbkcolor(bkcolor);
            }
          }
        }
      }
      break;
    }

  }  
}
void newReaderPage(int &page, TheDocGia *MangDocGia, int n, int newReaderCode){
  for (int i = 0; i < n;i++){
    if(newReaderCode==MangDocGia[i].MaThe){
      page = i / 20 + 1;
    }
  }
}
