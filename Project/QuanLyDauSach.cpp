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

// Hàm hi?n th? thông tin c?a các cu?n sách cùng v?i danh m?c sách c?a chúng
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
void LayDanhSachDauSach(pointerArray &DSDS){
	ifstream fileDauSach("inputdausach.txt");
	if (!fileDauSach.is_open()) {
        cerr << "Không the mo tap tin inputdausach.txt" << endl;
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
//int ExitsDauSach(pointerArray &DSDS, string TenSach){
//	for(int i=0;i<DSDS.SoLuongDauSach;i++){
//		if(DSDS.nodesDauSach[i]->TenSach==TenSach){
//			int deleteindex = i;
//			delete DSDS.nodesDauSach[i];
//			return deleteindex;
//		}
//	}
//	return -1;
//}
void Delete_DauSach(pointerArray &DSDS,string TenSach){
	int index =-1;
	for(int i=0;i<DSDS.SoLuongDauSach;i++){
		if(DSDS.nodesDauSach[i]->TenSach == TenSach){
			index = i;
			delete DSDS.nodesDauSach[i];
			break;
		}
	}
	if(index !=-1){
		for(int j=index;j<DSDS.SoLuongDauSach;j++){
			DSDS.nodesDauSach[j]=DSDS.nodesDauSach[j+1];
		}
		DSDS.SoLuongDauSach--;
	}
	else{
		cout<<"Khong tim thay sach de xoa!"<<endl;
	}
}

int main(){
	LayDanhSachDauSach(DSDS);
	SapXepTheoTenSach(DSDS,DSDS.SoLuongDauSach);
	string TenSach;
	getline(cin,TenSach);
	DeleteDauSach(DSDS,TenSach);
	inds(DSDS);
  return 0;
}
