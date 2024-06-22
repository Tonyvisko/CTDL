#include "DoHoa.h"
#include <iostream>
#include <string>
#include <fstream>
#include <graphics.h>
using namespace std;
#define MaxNodes 10000
#define SoNgayDuocMuon 7
#define MienGiaTriNgauNhien 30001
#define MaxSoSachDuocMuon 3
#define MaxSoSachDangMuon 3

// H�m hi?n th? th�ng tin c?a c�c cu?n s�ch c�ng v?i danh m?c s�ch c?a ch�ng
struct DanhMucSach{
	int trangthai; //0: co the muon; 1: da duoc muon; 2:da thanh ly
	string masach, vitri;
};
struct NODE_SINGLY_LIST{
	DanhMucSach data;
	NODE_SINGLY_LIST *next;
};
struct LIST_DMS
{
	NODE_SINGLY_LIST* head;
	NODE_SINGLY_LIST* tail;
};
NODE_SINGLY_LIST* CreateNodeSach(DanhMucSach &data){
	NODE_SINGLY_LIST *node = new NODE_SINGLY_LIST;
	node->data = data;
  node->next = NULL;
  return node;
}
void InsertFirst_NodeSach(LIST_DMS &DMS, DanhMucSach &sach){
	NODE_SINGLY_LIST *newNode = CreateNodeSach(sach);
	
	newNode->next = DMS.head;
	DMS.head = DMS.tail = newNode;
}

void InsertLast_NodeSach(LIST_DMS &DMS, DanhMucSach &sach){
    NODE_SINGLY_LIST *newNode = CreateNodeSach(sach);
    if(DMS.head == NULL) 
        InsertFirst_NodeSach(DMS, sach);
    else {
        DMS.tail->next = newNode;
        DMS.tail = newNode;
    }
}


void InsertAfter_NodeSach(LIST_DMS &DMS, DanhMucSach &sach){
  NODE_SINGLY_LIST *p = DMS.head;
  NODE_SINGLY_LIST *newNode;
  if(sach.masach>DMS.tail->data.masach){
    InsertLast_NodeSach(DMS, sach);
	}
}
void delete_first_singly_node(NODE_SINGLY_LIST *&head){
	if(head != NULL){
		NODE_SINGLY_LIST *p = head;
		head = p->next;
		p->next = NULL;
		delete(p);
	}
}
void delete_last_singly_node(NODE_SINGLY_LIST *&head){
	if(head != NULL){
		if(head->next == NULL){ //Danh sach co 1 phan tu
			delete_first_singly_node(head);
		}else{
			NODE_SINGLY_LIST *last;
			NODE_SINGLY_LIST *prev_last;
			while(last->next != NULL){
				prev_last = last;
				last = last->next;
			}
			prev_last->next = NULL;
			delete last;
		}
	}
}
void delete_after_singly_node(NODE_SINGLY_LIST *p){
  NODE_SINGLY_LIST *q;
  if(p == NULL || p->next == NULL){
    return;
  }else{
    q = p->next;
    p->next = q->next;
    delete q;
  }
}
//--------------------------
struct DauSach{
	string ISBN;
	string TenSach;
	int SoTrang;
	string TacGia;
	int NamXuatBan;
	string TheLoai;
  LIST_DMS dms;
  int SoLuongSach;
  int SoLanMuon;
};
struct pointerArray{
	int SoLuongDauSach=0; 
  DauSach* nodesDauSach[MaxNodes];
};
pointerArray DSDS;

void InsertLastDauSach(pointerArray &DSDS, DauSach *dausach){
	// su dung khi doc file
	if(DSDS.SoLuongDauSach > MaxNodes)
		cout<<"DSDS day"<<endl;
	else{
		DSDS.nodesDauSach[DSDS.SoLuongDauSach++] = dausach;
	}
}
//void Display_DS(DauSach *MangDauSach, int page, int maxPage){
//  string s="";
//  char str[30];
//  settextstyle(3, 0, 3);
//  setbkcolor(DARKGRAY);
//  int Books = 0;
//  int maxBooksInPage = 0;
//  if(page==maxPage){
//    Books = DSDS.SoLuongDauSach - DSDS.SoLuongDauSach % 20;
//    maxBooksInPage = DSDS.SoLuongDauSach - 1;
//  }
//  else{
//    Books = (page - 1) * 20;
//    maxBooksInPage = Books + 19;
//  }
//  s="PAGE "+to_string(page)+"/"+to_string(maxPage);
//  strcpy(str, s.c_str());
//  setcolor(WHITE);
//	outtextxy(1235, 710, str);
//  for (int j = Books, k=0; j <= maxBooksInPage;j++,k++){
//	char chs[10];
//	s=DSDS.nodesDauSach[j]->TenSach;
//	strcpy(str, s.c_str());
//	outtextxy(475, 100 + k*30, str);
//	s=DSDS.nodesDauSach[j]->ISBN;
//	strcpy(str, s.c_str());
//	outtextxy(757, 100 + k*30, str);
//	s=DSDS.nodesDauSach[j]->TacGia;
//	strcpy(str, s.c_str());
//	outtextxy(835, 100 + k*30, str);
//	s=DSDS.nodesDauSach[j]->TheLoai;
//	strcpy(str, s.c_str());
//	outtextxy(1050, 100 + k*30,str );
//	if(DSDS.nodesDauSach[j]->SoTrang > 0){
//		itoa(DSDS.nodesDauSach[j]->SoTrang, chs, 10);
//		outtextxy(1200, 100 + k*30, chs);
//	}
//
//	if(DSDS.nodesDauSach[j]->NamXuatBan > 0){
//		itoa(DSDS.nodesDauSach[j]->NamXuatBan, chs, 10);
//		outtextxy(1305, 100 + k*30, chs);
//	}
//  }
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
//void LayDanhSachDauSach(pointerArray &array) {
//	int n=0;
//    DauSach *x = new DauSach();
//    string s;
//    ifstream file("inputdausach.txt");
//    while (getline(file, s)) {
//        istringstream ss(s);
//        string token;
//        getline(ss, token,',');    
//        x->TenSach = token;
//        getline(ss, token,',');
//        x->ISBN = token;
//        getline(ss, token,',');
//        x->TacGia = token;
//        getline(ss, token,',');
//        x->TheLoai = token;
//        getline(ss, token,',');
//        x->SoTrang = stoi(token);
//        getline(ss, token,',');
//        x->NamXuatBan = stoi(token);
//        getline(ss,token,',');
//        n = stoi(token);
//        
//        for(int i=0;i<n; i++){
//        	DanhMucSach sach;
//        	getline(ss,token,',');
//        	sach.masach = token;
//        	getline(ss,token,',');
//        	sach.trangthai = stoi(token);
//        	getline(ss,token,',');
//        	sach.vitri = token;
//        	
//		}
//		
//		
//    }
//    file.close();
//}
//void DanhSachDauSach(pointerArray &array){
//  DauSach *MangDauSach = new DauSach[array.SoLuongDauSach];
//  int n = array.SoLuongDauSach; 
//  if(sortMode==1){
//    SapXepTheoTenSach(MangDauSach, n);
//
//  }
//
//  list_book_background();
//
//  int page = 1;
//  int maxPage = (array.SoLuongDauSach%20==0) ? array.SoLuongDauSach/20 : array.SoLuongDauSach/20 + 1;
//  Display_DS(MangDauSach, page, maxPage);
//  
//    int x, y;
//  while(1){
//    
//    //Disable keyboard input
//    if(kbhit()){
//      getch();
//    }
//    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
//      x = mousex();
//      y = mousey();
//
////      BACK
////      if(x>=1230 &&  y>=5 && x<=1365 && y<=45){
////        delete[] MangDauSach;
////        thongbao = "";
////        cleardevice();
////        menu();
////      }
//
//      //PREV
//       if(x>=460 &&  y>=5 && x<=600 && y<=45){
//        if(page > 1){
//          page--;
//          list_book_background();
//          Display_DS(MangDauSach, page, maxPage);
//        }
//      }
//
//      //NEXT
//      else if(x>=620 &&  y>=5 && x<=760 && y<=45){
//        if(page < maxPage){
//          page++;
//          list_book_background();
//          Display_DS(MangDauSach, page, maxPage);
//        }
//      }
//            //SORT
//      else if(x>=600 && y>=710 && x<=690 && y<=760){
//        sort_frame();
//        string s = XuLyNhapSapXep();
//        if(s=="0"){
//          thongbao = "Da sap xep theo ma doc gia";
//          sortMode = 0;
//          DanhSachDauSach(DSDS);
//        }
//        else if(s=="1"){
//          thongbao = "Da sap xep theo ho ten doc gia";
//          sortMode = 1;
//          DanhSachDauSach(DSDS);
//        }
//        else if(s=="Close"){
//          thongbao = "";
//          DanhSachDauSach(DSDS);
//        }
//      }
//
//	}
//	}
//}
void LayDanhSachDauSach(pointerArray &DSDS){
	ifstream fileDauSach("inputdausach.txt");
	if (!fileDauSach.is_open()) {
        cerr << "Kh�ng the mo tap tin inputdausach.txt" << endl;
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
		//cout<<dausach->TenSach<<endl;
		getline(ss,token,',');
		dausach->ISBN = token;
		//cout<<dausach->ISBN<<endl;
		getline(ss,token,',');
		dausach->TacGia = token;
		//cout<<dausach->TacGia<<endl;
		getline(ss,token,',');
		dausach->TheLoai = token;
		//cout<<dausach->TheLoai<<endl;
		getline(ss,token,',');
		dausach->SoTrang = stoi(token);
		//cout<<dausach->SoTrang<<endl;
		getline(ss,token,',');
		dausach->NamXuatBan = stoi(token);
		//cout<<dausach->NamXuatBan<<endl;
		getline(ss,token,',');
		dausach->SoLuongSach = stoi(token);
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
void inds(pointerArray &DSDS){
	DauSach *dausach = new DauSach;
	for(int i=0;i<DSDS.SoLuongDauSach;i++){
		cout<<i+1<<endl;
		cout<<DSDS.nodesDauSach[i]->TenSach<<endl;
		cout<<DSDS.nodesDauSach[i]->TheLoai<<endl;
	}
}
int Exit_DauSach(pointerArray &DSDS, string TenSach){
	for(int i=0;i<DSDS.SoLuongDauSach;i++){
		if(DSDS.nodesDauSach[i]->TenSach==TenSach){
			return i;
		}
	}
	return -1;
}
void DeleteDauSach(pointerArray &DSDS,string TenSach){
	int i=Exit_DauSach(DSDS,TenSach);
	cout<<i<<endl;
	if(i==-1){
		cout<<"Khong The Xoa"<<endl;
	}
	else{
		for(i;i<DSDS.SoLuongDauSach;i++){
			DSDS.nodesDauSach[i]=DSDS.nodesDauSach[i+1];
		}
		DSDS.SoLuongDauSach--;
	}	
}
void ChinhSuaDauSach(pointerArray &DSDS,string s[],string TenSach){
	int i=Exit_DS(DSDS,TenSach);
	s[0] = DSDS.nodesDauSach[i]->TenSach;
  	s[1] = DSDS.nodesDauSach[i]->ISBN;
  	s[2] = DSDS.nodesDauSach[i]->TacGia;
  	s[3] = DSDS.nodesDauSach[i]->TheLoai;
 	s[4] = to_string(DSDS.nodesDauSach[i]->SoTrang);
 	s[5] = to_string(DSDS.nodesDauSach[i]->NamXuatBan);
  //NODE_TREE *p = search_node_tree(root,stoi(s));
  update_book_function(DSDS,TenSach);
  char c;
  int times = 0;
  int x, y;

  
  while(1){

    if(kbhit()){
      c = getch();
      if(c==27){
        times++;
        if(times==2){
          thongbao = "";
          s[0] = "-1";
          return;
        }
        thongbao = "Nhan Esc lan nua de thoat nhap";
        notice_frame();
        continue;
      }
    }

    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
      x = mousex();
      y = mousey();
      
      //Ten dau sach
      if(x>=150 && y>=80 && x<=415 && y<=100){
        NhapDauSach(155, 80, 0, 24, 7, s);
      }
      //ISBN
      else if(x>=150 && y>=120 && x<=415 && y<=140){
        NhapDauSach(155, 120, 1, 4, 7, s);
      }
      //Tac gia
      else if(x>=150 && y>=160 && x<=415 && y<=180){
        NhapDauSach(155, 160, 2, 17, 7, s);
      }
      //The loai
      else if(x>=150 && y>=200 && x<=415 && y<=220){
        NhapDauSach(155, 200, 2, 11, 7, s);
      }
    	//So trang
      else if(x>=150 && y>=240 && x<=415 && y<=260){
    	NhapDauSach(155, 240, 3, 999999, 7, s);
		}
		//NXB
      else if(x>=150 && y>=280 && x<=415 && y<=300){
      	NhapDauSach(155, 280, 3, NamHienTai(), 7, s);
		}
      //Save
      else if(x>=170 && y>=405 && x<=280 && y<=455){
       
          thongbao = "Da chinh sua doc gia thanh cong";
          return;
   
        
      }
    }
  }	
	
}
int main(){
//	initwindow(1366,768,"window");
	LayDanhSachDauSach(DSDS);
	SapXepTheoTenSach(DSDS,DSDS.SoLuongDauSach);
	string TenSach;
	getline(cin,TenSach);
	cout<<Exit_DauSach(DSDS,TenSach);
//	DeleteDauSach(DSDS,TenSach);
//	inds(DSDS);
//	DanhSachDauSach(DSDS);
//	getch();
  return 0;
}
