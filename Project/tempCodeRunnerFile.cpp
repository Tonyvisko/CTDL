#include "KhaiBao.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
int RandomArray[MienGiaTriNgauNhien];
int i = 0;
int STT=0;

DauSach* TimSachBangMaSach(pointerArray DSDS, string masach){
  for (int i = 0; i < DSDS.SoLuongDauSach;i++){
    if(masach.find(DSDS.nodesDauSach[i]->ISBN,0)==0){
      return DSDS.nodesDauSach[i];
    }
  }
}

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
    insert_node_tree(root, x);
    SoLuongDocGia++;
  }
  file.close();
}

void LayDanhSachMuonTra(NODE_TREE *root){
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
  DauSach *DS=NULL;
  while(getline(file,s)){
    istringstream ss(s);
    string token;
    getline(ss, token, ',');
    mathe = stoi(token);
    p = search_node_tree(root, mathe);

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

    add_last_doubly_list(p->data.DoublyList_MuonTra, x);
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



int main(){
  LayDanhSachDocGia(root);
  LayDanhSachDauSach(DSDS);
  LayDanhSachMuonTra(root);
  TaoMangNgauNhien();

  for (int i = 0; i < DSDS.SoLuongDauSach;i++){
    cout << DSDS.nodesDauSach[i]->TenSach << " " << DSDS.nodesDauSach[i]->SoLanMuon << endl;
  }

  // string masach = "IIII1";
  // string ISBN = "ABCD";
  // cout << masach.find(ISBN, 0) << endl;
}