#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "DoHoa.h"
#include <string>
using namespace std;


int RandomArray[MienGiaTriNgauNhien];
int i = 0;
int STT=0;

//DAUSACH
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
  	outtextxy(35, 100 + k*30, str);
  	s=DSDS.nodesDauSach[j]->ISBN;
  	strcpy(str, s.c_str());
  	outtextxy(400, 100 + k*30, str);
  	s=DSDS.nodesDauSach[j]->TacGia;
  	strcpy(str, s.c_str());
  	outtextxy(521, 100 + k*30, str);
  	s=DSDS.nodesDauSach[j]->TheLoai;
  	strcpy(str, s.c_str());
  	outtextxy(816, 100 + k*30,str );
  	if(DSDS.nodesDauSach[j]->SoTrang > 0){
  		itoa(DSDS.nodesDauSach[j]->SoTrang, chs, 10);
  		outtextxy(1215, 100 + k*30, chs);
  	}

  	if(DSDS.nodesDauSach[j]->NamXuatBan > 0){
  		itoa(DSDS.nodesDauSach[j]->NamXuatBan, chs, 10);
  		outtextxy(1310, 100 + k*30, chs);
  	}
  }
}
void swap_DS(DauSach &a, DauSach &b){
    DauSach temp = a;
    a = b;
    b = temp;
}

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

void writeReader(NODE_TREE *p, ostream &out){
  if(p!=NULL){
    out << p->data.MaThe << "," << p->data.Ho << " " << p->data.Ten << "," << p->data.Phai << "," << p->data.TrangThai << endl;
    writeReader(p->left, out);
    writeReader(p->right, out);
  }
}

void LuuDanhSachDocGia(NODE_TREE *root){
	ofstream file("inputdocgia.txt");
  writeReader(root, file);
  file.close();
}

void LuuDanhSachDauSach(pointerArray DSDS){
  ofstream file("inputdausach.txt");
  if (!file.is_open()) {
        cerr << "Khong the mo tap tin inputdausach.txt" << endl;
        return;
    }
  file << DSDS.SoLuongDauSach << endl;
  NODE_SINGLY_LIST *p;
  for (int i = 0; i < DSDS.SoLuongDauSach;i++){
    file << DSDS.nodesDauSach[i]->TenSach << "," << DSDS.nodesDauSach[i]->ISBN << "," << DSDS.nodesDauSach[i]->TacGia << "," << DSDS.nodesDauSach[i]->TheLoai << "," << DSDS.nodesDauSach[i]->SoTrang << "," << DSDS.nodesDauSach[i]->NamXuatBan << "," << DSDS.nodesDauSach[i]->SoLuongSach;
    p = DSDS.nodesDauSach[i]->dms.head;
    while(p){
      file << "," << p->data.masach << "," << p->data.trangthai << "," << p->data.vitri;
      p = p->next;
    }
    file << endl;
  }
    file.close();
}

void writeBookBorrowing(NODE_TREE *p, ostream &out){
  if(p!=NULL){
    if(p->data.SoSachDaMuon!=0){
      out << p->data.MaThe << "," << p->data.SoSachDaMuon;
      NODE_DOUBLY_LIST *q = p->data.DoublyList_MuonTra.head;
      while(q){
        out << "," << q->data.MaSach << "," << q->data.NgayMuon.Ngay << "/" << q->data.NgayMuon.Thang << "/" << q->data.NgayMuon.Nam << "," << q->data.NgayTra.Ngay << "/" << q->data.NgayTra.Thang << "/" << q->data.NgayTra.Nam << "," << q->data.TrangThai;
        q = q->next;
      }
      out << endl;
    }
    writeBookBorrowing(p->left, out);
    writeBookBorrowing(p->right, out);
  }
}

void LuuDanhSachMuonTra(NODE_TREE *root){
  ofstream file("inputDanhSachMuonTra.txt");
  if (!file.is_open()) {
    cerr << "Khong the mo tap tin inputDanhSachMuonTra.txt" << endl;
    return;
  }
  writeBookBorrowing(root, file);
  file.close();
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
//DOCGIA
void LayDanhSachDocGia(NODE_TREE *&root){
  TheDocGia x;
  int mathe;
  string ho,ten,phai, hovaten;
  int trangthai;
  string s;
  char c;
  ifstream file("inputdocgia.txt");
  while(getline(file, s)){
    istringstream ss(s);
    string token;
    getline(ss, token, ',');
    x.MaThe = stoi(token);
    RandomArray[x.MaThe] = -1;
    getline(ss, token, ',');
    hovaten = token;
    for(int i = hovaten.length()-1; i >= 0; i--){
      if(hovaten[i] == ' '){
        x.Ho = hovaten.substr(0, i);
        x.Ten = hovaten.substr(i+1, hovaten.length()-i-1);
        break;
      }
    }
    getline(ss, token, ',');
    x.Phai = token;
    getline(ss, token, ',');
    x.TrangThai = stoi(token);
    x.SoSachDangMuon = x.SoSachDaMuon = 0;
    x.DoublyList_MuonTra.head = x.DoublyList_MuonTra.tail = NULL;
    insert_node_tree(root, x);
    SoLuongDocGia++;
  }
  file.close();
}

void LayDanhSachMuonTra(NODE_TREE *&root){
  ifstream file("inputDanhSachMuonTra.txt");
	if (!file.is_open()) {
        cerr << "Khong the mo tap tin inputDanhSachMuonTra.txt" << endl;
        return;
  }
  NODE_TREE *p;
  string s;
  int mathe;
  MuonTra x;
  int i;
  DauSach *DS;
  NODE_SINGLY_LIST *q;
  while(getline(file,s)){
    istringstream ss(s);
    string token;
    getline(ss, token, ',');
    mathe = stoi(token);
    p = search_node_tree(root, mathe);

    getline(ss, token, ',');
    p->data.SoSachDaMuon = stoi(token);

    for (int i = 0; i < p->data.SoSachDaMuon;i++){
      getline(ss, x.MaSach, ',');
      DS = TimSachBangMaSach(DSDS, x.MaSach);
      DS->SoLanMuon++;

      getline(ss, token, '/');
      x.NgayMuon.Ngay = stoi(token);
      getline(ss, token, '/');
      x.NgayMuon.Thang = stoi(token);
      getline(ss, token, ',');
      x.NgayMuon.Nam = stoi(token);

      getline(ss, token, '/');
      x.NgayTra.Ngay = stoi(token);
      getline(ss, token, '/');
      x.NgayTra.Thang = stoi(token);
      getline(ss, token, ',');
      x.NgayTra.Nam = stoi(token);

      getline(ss, token, ',');
      x.TrangThai = stoi(token);

      q = DS->dms.head;
      while(q){
        if(q->data.masach==x.MaSach){
          if(x.TrangThai==0){
            q->data.trangthai = 1;
          }
          else if(x.TrangThai==1){
            q->data.trangthai = 0;
          }
          else{
            q->data.trangthai = 2;
          }
          break;
        }
        q = q->next;
      }

      if(x.TrangThai==0){
        p->data.SoSachDangMuon++;
      }
      add_last_doubly_list(p->data.DoublyList_MuonTra, x);
      
      if(p->data.TrangThai==1 && checkQuaHan(p->data)){
        p->data.TrangThai = 0;
        LuuDanhSachDocGia(root);
      }
    }
  }
}


//void XoaDuLieuDocGia(string maThe){
//    ifstream fileInput("inputdocgia.txt");
//    vector<TheDocGia> danhSachDocGia;
//    TheDocGia docGia;
//    
//    while (getline(fileInput, docGia.MaThe, ',')) {
//        getline(fileInput, docGia.Ho, ',');
//        getline(fileInput, docGia.Phai, ',');
//        getline(fileInput, docGia.TrangThai);
//        danhSachDocGia.push_back(docGia);
//    }
//    
//    fileInput.close();
//    for (auto it = danhSachDocGia.begin(); it != danhSachDocGia.end(); ++it) {
//        if (it->MaThe == maThe) {
//            danhSachDocGia.erase(it);
//            break;
//        }
//    }
//    
//    ofstream fileOutput("inputdocgia.txt");
//    for (const auto& docGia : danhSachDocGia) {
//        fileOutput << docGia.MaThe << "," << docGia.Ho << "," << docGia.Phai << "," << docGia.TrangThai << endl;
//    }
//    
//    fileOutput.close();
//}

void swap(TheDocGia &a, TheDocGia &b) {
    TheDocGia temp = a;
    a = b;
    b = temp;
}

void ChuyenCayThanhMang(NODE_TREE *root, TheDocGia *MangDocGia, int &n){
  if(root!=NULL){
    ChuyenCayThanhMang(root->left, MangDocGia, n);
    MangDocGia[n++] = root->data;
    ChuyenCayThanhMang(root->right, MangDocGia, n);
  }
}

void CaySangMangQuaHan(NODE_TREE *p, QuaHan *quahan, int &n){
  if(p){
    CaySangMangQuaHan(p->left, quahan, n);
    NODE_DOUBLY_LIST *q = p->data.DoublyList_MuonTra.head;
    while(q){
      if(q->data.TrangThai==0 && SoNgayMuon(q->data.NgayMuon.Ngay,q->data.NgayMuon.Thang,q->data.NgayMuon.Nam)>7){
        quahan[n].mathe = p->data.MaThe;
        quahan[n].masach = q->data.MaSach;
        quahan[n++].songayquahan = SoNgayMuon(q->data.NgayMuon.Ngay,q->data.NgayMuon.Thang,q->data.NgayMuon.Nam) - 7;
      }
      q = q->next;
    }
    CaySangMangQuaHan(p->right, quahan, n);
  }
}

void sort_QuaHan(QuaHan *Array,int left,int right){
    int i=left;
    int j=right;
    int pivot=Array[(left+right)/2].songayquahan;
    do{
        while(Array[i].songayquahan>pivot) i++;
        while(Array[j].songayquahan<pivot) j--;
        if(i<=j){
            swap(Array[i],Array[j]);
            i++;j--;
        }
    }while(i<=j);
    if(left<j) sort_QuaHan(Array,left,j);
    if(i<right) sort_QuaHan(Array,i,right);
}



void sort(TheDocGia Array[],int left,int right){
    int i=left;
    int j=right;
    string pivot=Array[(left+right)/2].Ten;
    string pivotto=Array[(left+right)/2].Ho;
    do{
        while(Array[i].Ten<pivot || Array[i].Ten == pivot && Array[i].Ho<pivotto) i++;
        while(Array[j].Ten>pivot || Array[j].Ten == pivot && Array[j].Ho>pivotto) j--;
        if(i<=j){
            swap(Array[i],Array[j]);
            i++;j--;
        }
    }while(i<=j);
    if(left<j) sort(Array,left,j);
    if(i<right) sort(Array,i,right);
}
void SapXepTheoHoTen(TheDocGia Array[],int n){
    sort(Array,0,n-1);
}

void Display(TheDocGia *MangDocGia, int page, int maxPage){
  string s="";
  char str[30];
  settextstyle(10, 0, 2);
  setbkcolor(DARKGRAY);
  int readers = 0;
  int maxReadersInPage = 0;
  if(page==maxPage){
    readers = SoLuongDocGia - SoLuongDocGia % 20;
    maxReadersInPage = SoLuongDocGia - 1;
  }
  else{
    readers = (page - 1) * 20;
    maxReadersInPage = readers + 19;
  }
  s="PAGE "+to_string(page)+"/"+to_string(maxPage);
  strcpy(str, s.c_str());
  setcolor(WHITE);
	outtextxy(1235, 710, str);
  for (int j = readers, k=0; j <= maxReadersInPage;j++,k++){
    s = to_string(MangDocGia[j].MaThe);
    strcpy(str, s.c_str());
    outtextxy(537-width(s)/2, 100 + k*30, str);
    s=MangDocGia[j].Ho;
    strcpy(str, s.c_str());
    outtextxy(665, 100 + k*30, str);
    s=MangDocGia[j].Ten;
    strcpy(str, s.c_str());
    outtextxy(962-width(s)/2, 100 + k*30, str);
    s=MangDocGia[j].Phai;
    strcpy(str, s.c_str());
    outtextxy(1133-width(s)/2, 100 + k*30, str);
    if(MangDocGia[j].TrangThai==1) s="Binh thuong";
    else s="Khoa";
    strcpy(str, s.c_str());
    outtextxy(1286-width(s)/2, 100 + k*30, str);
  }
}
void TaoMangNgauNhien(){
  srand(time(NULL));
  for (int j = 0;j<MienGiaTriNgauNhien;j++){
    if(RandomArray[j] != -1){
      RandomArray[j] = j;
    }
  }
  for (int j = 0; j < MienGiaTriNgauNhien; j++) {
    int k = rand() % (MienGiaTriNgauNhien - j) + j ; //k tu j den max-1
    int temp = RandomArray[j];
    RandomArray[j] = RandomArray[k];
    RandomArray[k] = temp;
  }
}

int MaDocGiaTuDong(){
  
  int x;
  while(RandomArray[STT]==-1 && STT<MienGiaTriNgauNhien){
    STT++;
  }
  if(STT==MienGiaTriNgauNhien){
    STT=0;
    TaoMangNgauNhien();
  }
  x = RandomArray[STT++];
  
  //RandomArray[STT] = -1;
  return x;
}

void ThemDocGia(int &newReaderCode){
  TheDocGia R;
  R.MaThe = MaDocGiaTuDong();
  R.Phai = "";
  R.TrangThai = 1;
  string s=to_string(R.MaThe);
  string s2=to_string(R.TrangThai);
  char str[20];
  char str1[20];
  char c;
  bool flag[3] = {0, 0, 0};
  int times = 0;
  int x, y;

  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);
  strcpy(str, s.c_str());
  strcpy(str1, s2.c_str());
  outtextxy(155, 80, str);
  outtextxy(155,280,str1);
  s = "";
  while(1){

    if(kbhit()){
      c = getch();
      if(c==27){
        times++;
        if(times==2){
          thongbao = "";
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
      
      //Ho
      if(x>=150 && y>=130 && x<=415 && y<=150){
        s = R.Ho;
        Nhap(155, 130, 1, s);
        R.Ho = s;
        s = "";
        flag[0] = 1;
      }
      else if(x>=150 && y>=180 && x<=415 && y<=200){
        s = R.Ten;
        Nhap(155, 180, 2, s);
        R.Ten = s;
        s = "";
        flag[1] = 1;
      }
      else if(x>=150 && y>=230 && x<=415 && y<=250){
        if(R.Phai==""){
          s = R.Phai;
        }
        else{
          s = (R.Phai == "Nam") ? "0" : "1";
        }
        Nhap(155, 230, 3, s);
        R.Phai = (s == "0") ? "Nam" : "Nu";
        s = "";
        flag[2] = 1;
      }
//      else if(x>=150 && y>=280 && x<=415 && y<=300){
//        s = (R.TrangThai==-1)?"":to_string(R.TrangThai);
//        Nhap(155, 280, 4, s);
//        R.TrangThai = stoi(s);
//        s = "";
//        flag[3] = 1;
//      }

      //Save
      else if(x>=170 && y>=405 && x<=280 && y<=455){
        if(flag[0] && flag[1] && flag[2]){
          insert_node_tree(root, R);
          SoLuongDocGia++;
          newReaderCode = R.MaThe;
          thongbao = "Da them doc gia thanh cong";
          LuuDanhSachDocGia(root);
          return;
        }
        else{
          thongbao = "Vui long nhap";
          notice_frame();
        }
      }
    }
  }
}


void ChinhSuaDocGia(NODE_TREE *p, string s[]){

  s[0] = to_string(p->data.MaThe);
  s[1] = p->data.Ho;
  s[2] = p->data.Ten;
  s[3] = (p->data.Phai == "Nam") ? "0" : "1";
  s[4] = to_string(p->data.TrangThai);
  //NODE_TREE *p = search_node_tree(root,stoi(s));
  update_reader_function(p->data);
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
      
      //Ho
      if(x>=150 && y>=130 && x<=415 && y<=150){
        Nhap(155, 130, 1, s[1]);
      }
      //Ten
      else if(x>=150 && y>=180 && x<=415 && y<=200){
        Nhap(155, 180, 2, s[2]);
      }
      //Phai
      else if(x>=150 && y>=230 && x<=415 && y<=250){
        Nhap(155, 230, 3, s[3]);
      }
      //Trang thai
      else if(x>=150 && y>=280 && x<=415 && y<=300){
        Nhap(155, 280, 4, s[4]);
      }

      //Save
      else if(x>=170 && y>=405 && x<=280 && y<=455){
       
          thongbao = "Da chinh sua doc gia thanh cong";
          LuuDanhSachDocGia(root);
          return;
   
        
      }
    }
  }	
}
 void XoaDocGia(NODE_TREE *&root, int mathe){
   TheDocGia temp;
   temp.MaThe = mathe;
   delete_node_tree(root, temp);
   SoLuongDocGia--;
   LuuDanhSachDocGia(root);
 }

void TimKiemDocGia(){
  string s;
  Nhap(100, 110, 0, s);
  if(s=="EXIT"){
    return;
  }
  NODE_TREE *p = search_node_tree(root, stoi(s));
  if(p==NULL){
    thongbao = "Khong tim thay doc gia";
    return;
  }

  reader_information_function(p->data);
  while(1){
    if(kbhit()){
      char c = getch();
      if(c==27){
        thongbao = "";
        return;
      }
    }
    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
    	int x,y;
    	x = mousex();
    	y = mousey();
    	if(x>=280 && y>=410 && x<=390 && y<=460){
        if(p->data.SoSachDaMuon==0){
          XoaDocGia(root,stoi(s));
  			  thongbao = "Da xoa doc gia thanh cong";
        }
  			else{
          thongbao = "Khong the xoa";
        }
        return;
  		}
  		else if(x>=50 && y>=410 && x<=160 && y<=460){
        string *R = new string[5];
        ChinhSuaDocGia(p,R);
        if (R[0] != "-1")
        {
          p->data.Ho = R[1];
          p->data.Ten = R[2];
          p->data.Phai = (R[3] == "0") ? "Nam" : "Nu";
          p->data.TrangThai = stoi(R[4]);
          }
        delete[] R;
        return;
        //			update_reader_function(p->data);
        //			char str[20];
        //			char c;
        //			bool flag[5] = {1, 1, 1, 1};
        //			int times = 0;
        //			int x, y;
        //
        //
        //			while(1){
        //
        //			    if(kbhit()){
        //			    	c = getch();
        //			    	if(c==27){
        //			        	times++;
        //			        	if(times==2){
        //			          		thongbao = "";
        //			          		return;
        //			        	}
        //					    thongbao = "Nhan Esc lan nua de thoat nhap";
        //					    notice_frame();
        //					    continue;
        //			      	}
        //			    }
        //
        //			    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
        //			      x = mousex();
        //			      y = mousey();
        //
        //			      //Ho
        //			      if(x>=150 && y>=130 && x<=415 && y<=150){
        //			        s = p->data.Ho;
        //			        Nhap(155, 130, 1, s);
        //			        p->data.Ho = s;
        //			        s = "";
        //			      }
        //			      else if(x>=150 && y>=180 && x<=415 && y<=200){
        //			        s = p->data.Ten;
        //			        Nhap(155, 180, 2, s);
        //			        p->data.Ten = s;
        //			        s = "";
        //			      }
        //			      else if(x>=150 && y>=230 && x<=415 && y<=250){
        //			        if(p->data.Phai==""){
        //			          s = p->data.Phai;
        //			        }
        //			        else{
        //			          s = (p->data.Phai == "Nam") ? "0" : "1";
        //			        }
        //			        Nhap(155, 230, 3, s);
        //			        p->data.Phai = (s == "0") ? "Nam" : "Nu";
        //			        s = "";
        //			      }
        //			      else if(x>=150 && y>=280 && x<=415 && y<=300){
        //			        s = (p->data.TrangThai==-1)?"":to_string(p->data.TrangThai);
        //			        Nhap(155, 280, 4, s);
        //			        p->data.TrangThai = stoi(s);
        //			        s = "";
        //			      }
        //
        //			      //Save
        //			      else if(x>=170 && y>=405 && x<=280 && y<=455){
        //
        //			          thongbao = "Da chinh sua doc gia thanh cong";
        //			          return;
        //
        //
        //			      }
        //			    }
        //			  }	
		  }
  	}
  }

}

void TimKiemDocGia2(){
  string s;
  Nhap(100, 110, 0, s);
  NODE_TREE *p = search_node_tree(root, stoi(s));
  if(p==NULL){
    thongbao = "Khong tim thay doc gia";
    return;
  }

  reader_information_function2(p->data);
  while(1){
    if(kbhit()){
    	char c = getch();
      if(c==27){
        thongbao = "";
        return;
      }
    } 

    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
    	int x,y;
    	x = mousex();
    	y = mousey();
    	if(x>=170 && y>=405 && x<=280 && y<=455){
  			XoaDocGia(root,stoi(s));
  			thongbao = "Da xoa doc gia thanh cong";
          	return;
  		}
  	}
  }
}
void ChinhSuaDauSach(pointerArray &DSDS,string s[],string TenSach){
	int i=Exist_DS(DSDS,TenSach);
	s[0] = DSDS.nodesDauSach[i]->TenSach;
	s[1] = DSDS.nodesDauSach[i]->ISBN;
	s[2] = DSDS.nodesDauSach[i]->TacGia;
	s[3] = DSDS.nodesDauSach[i]->TheLoai;
 	s[4] = to_string(DSDS.nodesDauSach[i]->SoTrang);
 	s[5] = to_string(DSDS.nodesDauSach[i]->NamXuatBan);
 	s[6] = "";
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
          s[6] = "-1";
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
        NhapDauSach2(155, 80, 0, 24, 7, s[0],i);
      }
      //ISBN
      else if(x>=150 && y>=130 && x<=415 && y<=150){
        NhapDauSach2(155, 130, 1, 4, 7, s[1],i);
      }
      //Tac gia
      else if(x>=150 && y>=180 && x<=415 && y<=200){
        NhapDauSach2(155, 180, 2, 17, 7, s[2],i);
      }
      //The loai
      else if(x>=150 && y>=230 && x<=415 && y<=250){
        NhapDauSach2(155, 230, 2, 11, 7, s[3],i);
      }
    	//So trang
      else if(x>=150 && y>=280 && x<=415 && y<=300){
    	NhapDauSach2(155, 280, 3, 999999, 7, s[4],i);
		}
		//NXB
      else if(x>=150 && y>=330 && x<=415 && y<=350){
      	NhapDauSach2(155, 330, 3, NamHienTai(), 7, s[5],i);
		}
      //Save
      else if(x>=170 && y>=405 && x<=280 && y<=455){
       
          thongbao = "Da chinh sua dau sach thanh cong";
          LuuDanhSachDauSach(DSDS);
          return;
   
        
      }
    }
  }	
	
}

void TaoMaSachTuDong(DauSach *DS, int soluong, string Sach[][3]){
  //Lay ma sach cuoi cung trong du lieu
  int prev;
  if(DS->SoLuongSach==0){
    prev = 0;
  }
  else{
    prev = stoi(DS->dms.tail->data.masach.substr(DS->ISBN.length(),DS->dms.tail->data.masach.length()-DS->ISBN.length()));
  }
  

  for (int i = 0; i < soluong;i++)
  {
    prev++;
    Sach[i][0] = DS->ISBN + to_string(prev);
  }
}

void ThemDanhMucSach(DauSach *DS, int i){
  setfillstyle(1, 8);
  bar(10,10,440,460);//Xoa o thong tin dau sach
  thongbao = "";
  notice_frame();
  required_quantity_frame();

  string s;
  char str[10];
  strcpy(str, to_string(SoSachDuocNhap(DS)).c_str());
  settextstyle(3, 0, 2);
  outtextxy(30 + width("So luong sach co the nhap: "), 85, str);
  NhapDauSach2(100, 120, 3, SoSachDuocNhap(DS), 15, s, i);
  bar(10,10,440,460);//Xoa o nhap so luong sach

  int SoSachCanNhap = stoi(s);
  int SoSachChuaNhap = SoSachCanNhap;
  char c;
  int k = 1;
  int times = 0;

  string Sach[SoSachCanNhap][3];
  bool isEmpty[SoSachCanNhap];
  for (int i = 0;i<SoSachCanNhap;i++){
    Sach[i][0] =  Sach[i][2] = "";
    Sach[i][1] ="0";
    isEmpty[i] = true;
  }
  TaoMaSachTuDong(DS, SoSachCanNhap, Sach);

  add_books_function(DS, SoSachCanNhap, SoSachChuaNhap, k-1, Sach);
  guide_frame3();
  int x, y;
  while(1){
    if(kbhit()){
      c = getch();

      if(c==KEY_LEFT && k>1){
        k--;
        add_books_function(DS, SoSachCanNhap, SoSachChuaNhap, k-1, Sach);
      }

      else if(c==KEY_RIGHT && k<SoSachCanNhap){
        k++;
        add_books_function(DS, SoSachCanNhap, SoSachChuaNhap, k-1, Sach);
      }

      if(c==27){
        times++;
        if(times==2){
          thongbao = "";
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

      //Trang Thai
//      if(x>=150 && y>=130 && x<=415 && y<=150){
//        NhapDauSach2(155, 130, 3, 2, 7, Sach[k - 1][1], i);
//        times = 0;
//      }
      
      //Vi tri
       if(x>=150 && y>=180 && x<=415 && y<=200){
        NhapDauSach2(155, 180, 4, 17, 7, Sach[k-1][2], i);
        for(int k=1;k<SoSachCanNhap;k++ ){
    	Sach[k][2] = Sach[k-1][2];
        
    	}
    	times = 0;
      }

      //SAVE
      else if(x>=170 && y>=405 && x<=280 && y<=455){
        bool canSave = true;
        for (int i = 0; i < SoSachCanNhap;i++){
          if(isEmpty[0]==true){
            canSave = false;
          }
        }
        if(canSave){
          for (int i = 0; i < SoSachCanNhap;i++){
            DanhMucSach DMS;
            DMS.masach = Sach[i][0];
            DMS.trangthai = stoi(Sach[i][1]);
            DMS.vitri = Sach[i][2];
            InsertLast_NodeSach(DS->dms, DMS);
          }
          DS->SoLuongSach += SoSachCanNhap;
          thongbao = "Them sach thanh cong";
          notice_frame();
          LuuDanhSachDauSach(DSDS);
          return;
        }
        else{
          thongbao = "Con sach chua dien thong tin";
          notice_frame();
        }
      }
      
    }

    if(Sach[k-1][1] !="" && Sach[k-1][2]!="" && isEmpty[k-1]==true){
      isEmpty[k - 1] = false;
      SoSachChuaNhap--;
      add_books_function(DS, SoSachCanNhap, SoSachChuaNhap, k-1, Sach);
    }
  }


}

void ChinhSuaDanhMucSach(NODE_SINGLY_LIST *p, string s[], int i){
  update_book_code(p->data);
  s[0] = p->data.masach;
  s[1] = to_string(p->data.trangthai);
  s[2] = p->data.vitri;

  int x, y;
  int times = 0;
  char c;
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

      //Trang Thai
      if(x>=150 && y>=130 && x<=415 && y<=150){
        NhapDauSach2(155, 130, 3, 2, 7, s[1], i);
        times = 0;
      }
      
      //Vi tri
      else if(x>=150 && y>=180 && x<=415 && y<=200){
        NhapDauSach2(155, 180, 4, 17, 7, s[2], i);
        times = 0;
      }

      //SAVE
      else if(x>=170 && y>=270 && x<=280 && y<=320){
        return;
      }
    }
  }
}

void TimKiemDanhMucSach(DauSach *DS, int i){
  setfillstyle(1, 8);
  bar(10,10,440,460);//Xoa o thong tin dau sach
  thongbao = "";
  notice_frame();
  search_book_code_frame();

  string s;
  NhapDauSach2(100, 120, 0, 7, 15, s, i);
  if(s=="EXIT"){
  	return;
  }
  NODE_SINGLY_LIST *p = Search_NodeSach(DS->dms, s);
  if(p==NULL){
    thongbao = "Khong tim thay ma sach";
    notice_frame();
    return;
  }

  setfillstyle(1, 8);
  bar(10,10,440,460);//Xoa bang tim kiem
  thongbao = "Da tim thay ma sach";
  notice_frame();
  book_code_info(p->data);
  guide_frame3();

  char c;
  int x, y;
  while(1){

    if(kbhit()){
      c=getch();

      if(c==27){
        thongbao = "";
        notice_frame();
        return;
      }
    }

    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
      x = mousex();
      y = mousey();
      setcolor(WHITE);
      outtextxy(x, y, "ADADADADADA");

      //BACK
      if(x>=1230 &&  y>=5 && x<=1365 && y<=45){
        thongbao = "";
        notice_frame();
        return;
      }

      //DELETE
  	  if(x>=280 && y>=270 && x<=390 && y<=320){
        if(p->data.trangthai==1 || p->data.trangthai==2){
          thongbao = "Sach khong the xoa";
          notice_frame();
        }
        else{
          Delete_NodeSach(DS->dms, p);
          DSDS.nodesDauSach[i]->SoLuongSach--;
          thongbao = "Da xoa sach thanh cong";
          LuuDanhSachDauSach(DSDS);
          notice_frame();
        }
        return;
      }

      //EDIT
			else if(x>=50 && y>=270 && x<=160 && y<=320){
        if(p->data.trangthai==2){
          thongbao = "Khong the sua thong tin";
          notice_frame();
        }
        else{
          string s[3];
          ChinhSuaDanhMucSach(p, s, i);
          if(s[0]!="-1"){
            p->data.trangthai = stoi(s[1]);
            p->data.vitri = s[2];
            while(p!=NULL){
            	p->data.vitri=s[2];
            	p=p->next;
			      }
            thongbao = "Da chinh sua thanh cong";
            LuuDanhSachDauSach(DSDS);
            notice_frame();
          }
        }
        
        return;
		  }
    }
  }
}

void TimKiemDauSach(DauSach *DS){

  int index = Exist_DS(DSDS, DS->TenSach);

  int page = 1;
  int maxPage = (DS->SoLuongSach%20==0 && DS->SoLuongSach>0) ? DS->SoLuongSach/20 : DS->SoLuongSach/20 + 1;
  book_information_function(DSDS,DS->TenSach,page,maxPage);
  thongbao = "Da hien thi dau sach";
  notice_frame();
  

    while (1)
    {
      if (kbhit())
      {
        char c=getch();
        if(c==27){
        thongbao = "";
        return;
      }
      }

      if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0)
      {
        int x, y;
        x = mousex();
        y = mousey();

        // BACK
        if (x >= 1230 && y >= 5 && x <= 1365 && y <= 45)
        {
          thongbao = "";
          delay(100);
          return;
        }

        // PREV
        if (x >= 750 && y >= 5 && x <= 887 && y <= 45)
        {
          if (page > 1)
          {
            page--;
            book_information_function(DSDS, DS->TenSach, page, maxPage);
          }
        }

        // NEXT
        else if (x >= 910 && y >= 5 && x <= 1047 && y <= 45)
        {
          if (page < maxPage)
          {
            page++;
            book_information_function(DSDS, DS->TenSach, page, maxPage);
          }
        }

        // DELETE
        else if (x >= 280 && y >= 410 && x <= 390 && y <= 460)
        {
          Delete_DauSach(DSDS, DS->TenSach);
          thongbao = "Da xoa dau sach thanh cong";
          LuuDanhSachDauSach(DSDS);
          return;
        }

        // EDIT
        else if (x >= 50 && y >= 410 && x <= 160 && y <= 460)
        {
          string *R = new string[7];
          string temp = DS->ISBN;
          ChinhSuaDauSach(DSDS, R, DS->TenSach);
          if (R[6] != "-1")
          {
            DS->TenSach = R[0];
            DS->ISBN = R[1];
            DS->TacGia = R[2];
            DS->TheLoai = R[3];
            DS->SoTrang = stoi(R[4]);
            DS->NamXuatBan = stoi(R[5]);
            NODE_SINGLY_LIST *p = DS->dms.head;
            while (p)
            {
              temp = DS->ISBN + p->data.masach.substr(temp.length(), p->data.masach.length() - temp.length());
              p->data.masach = temp;
              p = p->next;
            }
          }
          delete R;
          return;
        }

        // ADD danh muc sach
        else if (x >= 750 && y >= 710 && x <= 840 && y <= 760)
        {
          ThemDanhMucSach(DS, index);
          book_information_function(DSDS, DS->TenSach, page, maxPage);
        }

        // SEARCH ma sach
        else if (x >= 890 && y >= 710 && x <= 980 && y <= 760)
        {
          TimKiemDanhMucSach(DS, index);
          book_information_function(DSDS, DS->TenSach, page, maxPage);
        }
      }
	}
}



void ThemDauSach(){
  DauSach *DS = new DauSach;
  DS->TenSach = DS->ISBN = DS->TacGia = DS->TheLoai = "";
  DS->NamXuatBan = DS->SoTrang = -1;
  DS->dms.head = DS->dms.tail = NULL;
  string s;
  char str[20];
  char c;
  bool flag[6] = {0, 0, 0, 0, 0, 0};
  int times = 0;
  int x, y;

  setcolor(BLACK);
  setbkcolor(LIGHTGRAY);
  settextstyle(3, 0, 1);
  strcpy(str, s.c_str());
  outtextxy(155, 80, str);
  s = "";
  while(1){

    if(kbhit()){
      c = getch();
      if(c==27){
        times++;
        if(times==2){
          thongbao = "";
          return;
        }
        thongbao = "Nhan Esc lan nua de thoat nhap";
        notice_frame3();
        continue;
      }
    }

    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
      x = mousex();
      y = mousey();
      
      //Ten dau sach
      if(x>=613 && y>=165 && x<=878 && y<=185){
        s = DS->TenSach;
        NhapDauSach3(613, 165, 0, 24, 7, s);
        DS->TenSach = s;
        s = "";
        flag[0] = 1;
      }

      //ISBN
      else if(x>=613 && y>=205 && x<=878 && y<=225){
        s = DS->ISBN;
        NhapDauSach3(613, 205, 1, 4, 7, s);
        DS->ISBN = s;
        s = "";
        flag[1] = 1;
      }

      //Tac gia
      else if(x>=613 && y>=245 && x<=878 && y<=265){
        s = DS->TacGia;
        NhapDauSach3(613, 245, 2, 17, 7, s);
        DS->TacGia = s;
        s = "";
        flag[2] = 1;
      }

      //The loai
      else if(x>=613 && y>=285 && x<=878 && y<=305){
        s = DS->TheLoai;
        NhapDauSach3(613, 285, 2, 20, 7, s);
        DS->TheLoai = s;
        s = "";
        flag[3] = 1;
      }

      //So trang
      else if(x>=613 && y>=325 && x<=878 && y<=345){
        s = (DS->SoTrang == -1) ? "" : to_string(DS->SoTrang);
        NhapDauSach3(613, 325, 3, 999999, 7, s);
        DS->SoTrang = stoi(s);
        s = "";
        flag[4] = 1;
      }

      //NXB
      else if(x>=613 && y>=365 && x<=878 && y<=385){
        s = (DS->NamXuatBan == -1) ? "" : to_string(DS->NamXuatBan);
        NhapDauSach3(613, 365, 3, NamHienTai(), 7, s);
        DS->NamXuatBan = stoi(s);
        s = "";
        flag[5] = 1;
      }

      //Save
      else if(x>=628 && y>=415 && x<=738 && y<=470){
        if(flag[0] && flag[1] && flag[2] && flag[3] && flag[4] && flag[5]){
          DS->SoLuongSach = 0;
          InsertLastDauSach(DSDS, DS);
          thongbao = "Da them dau sach thanh cong";
          LuuDanhSachDauSach(DSDS);
          return;
        }
        else{
          thongbao = "Vui long nhap";
          notice_frame3();
          setbkcolor(WHITE);
        }
      }
    }
  }
}

void sort_Top10(DauSach *DS[],int left,int right){
    int i=left;
    int j=right;
    int pivot=DS[(left+right)/2]->SoLanMuon;
    string pivotto=DS[(left+right)/2]->TenSach;

    do{
        while(DS[i]->SoLanMuon>pivot || DS[i]->SoLanMuon==pivot && DS[i]->TenSach<pivotto) i++;
        while(DS[j]->SoLanMuon<pivot || DS[j]->SoLanMuon==pivot && DS[j]->TenSach>pivotto) j--;
        if(i<=j){
            swap_DS(DS[i],DS[j]);
            i++;j--;
        }
    }while(i<=j);
    if(left<j) sort_Top10(DS,left,j);
    if(i<right) sort_Top10(DS,i,right);
}


void Top10(DauSach *DS[]){

  for (int i = 0; i < DSDS.SoLuongDauSach;i++){
    DS[i] = DSDS.nodesDauSach[i];
  }
  sort_Top10(DS, 0, DSDS.SoLuongDauSach - 1);

}

void TraSach(TheDocGia &R){
  char c;
  int k = 0;
  char str[2];
  int x, y;
  NODE_DOUBLY_LIST *p = R.DoublyList_MuonTra.head;
  while(p->data.TrangThai!=0 && p->data.TrangThai!=2){
    p = p->next;
  }
  while(1){
    if(kbhit()){
      c = getch();
      if(c==KEY_UP && k>0){
        k--;
        list_borrowing_book1(R, k);
        if(p->prev->data.TrangThai==0){
          p = p->prev;
        }
        else{
          while(p->prev->data.TrangThai!=0){
            p = p->prev;
          }
          if(p->prev){
            p = p->prev;
          }
        }
      }
      else if(c==KEY_DOWN && k<R.SoSachDangMuon-1){
        k++;
        list_borrowing_book1(R, k);
        
        if(p->next->data.TrangThai==0){
          p = p->next;
        }
        else{
          while(p->next->data.TrangThai!=0){
            p = p->next;
          }
          if(p->next){
            p = p->next;
          }
        }
      }
      else if(c==27){
        list_borrowing_book1(R, -1);
        thongbao = "";
        return;
      }
      else if(c==13){
        DauSach *DS = TimSachBangMaSach(DSDS, p->data.MaSach);
        NODE_SINGLY_LIST *q = Search_NodeSach(DS->dms, p->data.MaSach);

        string *s = new string[2];
        book_return_confirmation(p,s);
        while(1){
          if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
            delay(100);
            x = mousex();
            y = mousey();
            //SAVE
            if(x>=503 && y>=340 && x<=623 && y<=390 && s[1].length()>0){
              stringstream ss(s[0]);
              ss >> p->data.NgayTra.Ngay >> c >> p->data.NgayTra.Thang >> c >> p->data.NgayTra.Nam;
              if(s[1]=="1"){
                p->data.TrangThai = 1;
                q->data.trangthai = 0;
              }
              else{
                p->data.TrangThai = 2;
                q->data.trangthai = 2;
              }
              R.SoSachDangMuon--;
              k = 0;
              if(R.SoSachDangMuon!=0){
                p = R.DoublyList_MuonTra.head;
                while(p->data.TrangThai!=0){
                  p = p->next;
                }
              }
              reader_information_function3(R);
              if(R.SoSachDangMuon!=0){
                list_borrowing_book1(R, 0);
              }
              else{
                R.TrangThai = 1;
                return;
              }
              notice_frame2();
              LuuDanhSachMuonTra(root);
              delete[] s;
              break;
            }
            //CANCEL
            else if(x>=743 && y>=340 && x<=863 && y<=390){
              reader_information_function3(R);
              list_borrowing_book1(R, k);
              notice_frame2();
              delete[] s;
              break;
            }
            //Ngay tra
            else if(x>=665 && y>=192 && x<=965 && y<=212){
              NhapMuonTra(670, 192, 0, 10, 7, s[0]);
            }
            //Trang thai sach
            else if(x>=665 && y>=252 && x<=965 && y<=272){
              NhapMuonTra(670, 252, 1, 1, 7, s[1]);
            }
          }
        }
      }
    }
  }
}

void MuonSach(TheDocGia &R){
  book_borrowing_confirmation();
  char c;
  char str[8];
  int x, y;
  string s,masach;
  bool isBookAvailable = false;
  DauSach *DS;
  NODE_SINGLY_LIST *p;
  MuonTra M;
  while(1){
    if(R.SoSachDangMuon==3){
      thongbao = "Da dat gioi han muon sach";
      return;
    }
    if(kbhit()){
      getch();
    }
    if((GetKeyState(VK_LBUTTON) & 0x8000) != 0){
      delay(100);
      x = mousex();
      y = mousey();
      //SAVE
      if(x>=503 && y>=340 && x<=623 && y<=390 && isBookAvailable){
        stringstream ss(s);
        M.MaSach = masach;
        ss >> M.NgayMuon.Ngay >> c >> M.NgayMuon.Thang >> c >> M.NgayMuon.Nam;
        M.TrangThai = 0;
        M.NgayTra.Ngay = M.NgayTra.Thang = M.NgayTra.Nam = 0;
        add_last_doubly_list(R.DoublyList_MuonTra, M);
        p->data.trangthai = 1;
        R.SoSachDaMuon++;
        R.SoSachDangMuon++;
        DS->SoLanMuon++;
        book_borrowing_confirmation();
        list_borrowing_book1(R, -1);
        thongbao = "Da muon thanh cong";
        notice_frame2();
        isBookAvailable = false;
        masach = "";
        LuuDanhSachMuonTra(root);
      }
      //CANCEL
       if(x>=743 && y>=340 && x<=863 && y<=390){
        thongbao = "";
        return;
      }
      //Nhap ma sach
      if(x>=665 && y>=182 && x<=965 && y<=202){
        NhapMuonTra(670, 182, 0, 10, 7, masach);
        //Kiem tra sach hop le
        DS = TimSachBangMaSach(DSDS, masach);
        if(DS && !MuonTrungSach(DS, R, masach)){
          isBookAvailable = true;
          p = Search_NodeSach(DS->dms, masach);
          if(p->data.trangthai!=0){
            thongbao = "Sach da duoc muon";
            notice_frame2();
          }
          else{
            //Hien thi thong tin sach
            strcpy(str, DS->TenSach.c_str());
            outtextxy(670,222,str);
            s = to_string(NgayHienTai()) + "/" + to_string(ThangHienTai()) + "/" + to_string(NamHienTai());
            strcpy(str,s.c_str());
            outtextxy(670, 262, str);
            strcpy(str,p->data.vitri.c_str());
            outtextxy(670, 302, str);
          }
        }
        else if(!DS){
          thongbao = "Sach khong ton tai";
          notice_frame2();
        }
        else if(MuonTrungSach(DS, R, masach)){
          thongbao = "Chi duoc muon 1 cuon sach moi dau sach";
          notice_frame2();
        }
      }
    }
  }
}
