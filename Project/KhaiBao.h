#include <iostream>
#include <cstring>
using namespace std;

#define MaxNodes 10000
#define SoNgayDuocMuon 7
#define MienGiaTriNgauNhien 30001
#define MaxSoSachDuocMuon 3
#define MaxSoSachDangMuon 3

int SoLuongDocGia = 0;


//--------------------------
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
	DMS.head = newNode;
}

void InsertLast_NodeSach(LIST_DMS &DMS, DanhMucSach &sach){
    if(DMS.head == NULL){
      InsertFirst_NodeSach(DMS, sach);
      DMS.tail = DMS.head;
    } 
    else {
        NODE_SINGLY_LIST *newNode = CreateNodeSach(sach);
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

NODE_SINGLY_LIST* Search_NodeSach(LIST_DMS DMS, string masach){
  NODE_SINGLY_LIST *p = DMS.head;
  while(p){
    if(p->data.masach==masach){
      break;
    }
    p=p->next;
  }
  return p;
}

void DeleteFirst_NodeSach(LIST_DMS &DMS){
  if(DMS.head!=NULL){
    NODE_SINGLY_LIST *p = DMS.head;
		DMS.head = p->next;
		p->next = NULL;
		delete(p);
  }
}

void DeleteLast_NodeSach(LIST_DMS &DMS){
  if(DMS.head==DMS.tail){
    DeleteFirst_NodeSach(DMS);
  }
  NODE_SINGLY_LIST *p = DMS.head;
  while(p->next!=DMS.tail){
    p = p->next;
  }
  DMS.tail = p;
  p = p->next;
  DMS.tail->next = NULL;
  delete p;
}

void Delete_NodeSach(LIST_DMS &DMS, NODE_SINGLY_LIST *p){

    if(p==DMS.head){
      DeleteFirst_NodeSach(DMS);
    }
    else if(p==DMS.tail){
      DeleteLast_NodeSach(DMS);
    }
    else{
      NODE_SINGLY_LIST *q = DMS.head;
      while(q->next!=p){
        q = q->next;
      }
      q->next = p->next;
      delete p;
    }

}

// void delete_last_singly_node(NODE_SINGLY_LIST *&head){
// 	if(head != NULL){
// 		if(head->next == NULL){ //Danh sach co 1 phan tu
// 			delete_first_singly_node(head);
// 		}else{
// 			NODE_SINGLY_LIST *last;
// 			NODE_SINGLY_LIST *prev_last;
// 			while(last->next != NULL){
// 				prev_last = last;
// 				last = last->next;
// 			}
// 			prev_last->next = NULL;
// 			delete last;
// 		}
// 	}
// }
// void delete_after_singly_node(NODE_SINGLY_LIST *p){
//   NODE_SINGLY_LIST *q;
//   if(p == NULL || p->next == NULL){
//     return;
//   }else{
//     q = p->next;
//     p->next = q->next;
//     delete q;
//   }
// }
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
int Exist_DS(pointerArray &DSDS,string TenSach){
	for(int i=0;i<DSDS.SoLuongDauSach;i++){
		
		if(DSDS.nodesDauSach[i]->TenSach==TenSach){
			return i;
			break;
		}
	}
	return -1;
}
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

}
bool SearchISBN(pointerArray DSDS, string ISBN){
  for (int i = 0; i < DSDS.SoLuongDauSach;i++){
    if(DSDS.nodesDauSach[i]->ISBN==ISBN){
      return true;
    }
  }
  return false;
}
bool SearchISBN2(pointerArray DSDS, string ISBN,int j){
  for (int i = 0; i < DSDS.SoLuongDauSach;i++){
    if(i!=j && DSDS.nodesDauSach[i]->ISBN==ISBN){
      return true;
    }
  }
  return false;
}
//--------------------------
struct Date{
	int Ngay, Thang, Nam;
};
struct MuonTra{
	string MaSach;
	Date NgayMuon;
	Date NgayTra;
	int TrangThai; //0: dang muon chua tra; 1: da tra; 2: lam mat
};
struct NODE_DOUBLY_LIST{
	MuonTra data;
	NODE_DOUBLY_LIST *next;
	NODE_DOUBLY_LIST *prev;
};
struct DOUBLY_LIST{
	NODE_DOUBLY_LIST *head;
	NODE_DOUBLY_LIST *tail;
};
NODE_DOUBLY_LIST *create_doubly_node(MuonTra x){
	NODE_DOUBLY_LIST *p = new NODE_DOUBLY_LIST;
	p->data = x;
	p->prev = NULL;
	p->next = NULL;
	return p;
}
void add_first_doubly_list(DOUBLY_LIST &ls, MuonTra x){
	NODE_DOUBLY_LIST *p = create_doubly_node(x);
	if(ls.head == NULL){
		ls.head = ls.tail = p;
	}else{
		p->next = ls.head;
		ls.head->prev = p;
		ls.head = p;
	}
}
void add_last_doubly_list(DOUBLY_LIST &ls, MuonTra x){
	NODE_DOUBLY_LIST *p = create_doubly_node(x);
	if(ls.head == NULL){
		ls.head = ls.tail = p;
	}else{
		p->prev = ls.tail;
		ls.tail->next = p;
		ls.tail = p;
	}
}
void delete_first_doubly_list(DOUBLY_LIST &ls){
	if(ls.head != NULL){
		NODE_DOUBLY_LIST *p = ls.head;
		if(p->next == NULL){ //Danh sach co 1 phan tu
			ls.head = NULL;
			ls.tail = NULL;
		}else{
			ls.head = p->next;
			p->next->prev = NULL;
			p->next = NULL;
		}
		delete(p);
	}else cout << "EMPTY LIST !!!" << endl;
}
void delete_last_doubly_list(DOUBLY_LIST &ls){
	if(ls.head == NULL){
		NODE_DOUBLY_LIST *p = ls.tail;
		if(p->prev == NULL){ //Danh sach co 1 phan tu\
			ls.head = NULL;
			ls.tail = NULL;
		}else{
			ls.tail = p->prev;
			p->prev->next = NULL;
			p->next = NULL;
		}
		delete(p);
	}else cout << "EMPTY LIST !!!" << endl;
}
//--------------------------
struct TheDocGia{
	int MaThe;
	string Ho, Ten, Phai;
	int TrangThai; //1: binh thuong; 0: khoa
  int SoSachDaMuon;
  int SoSachDangMuon;
  DOUBLY_LIST DoublyList_MuonTra;
};
struct NODE_TREE{
	TheDocGia data;
	NODE_TREE *left;
	NODE_TREE *right;
}*root=NULL;
NODE_TREE *create_node_tree(TheDocGia x){
	NODE_TREE *p = new NODE_TREE;
	p->data = x;
	p->left = p->right = NULL;
	return p;
}

NODE_TREE *search_node_tree(NODE_TREE *root, int mathe){
  if(root == NULL){
    return NULL;
  }else{
    NODE_TREE *p = root;
    while(p != NULL && p->data.MaThe != mathe){
      if(p->data.MaThe > mathe){
        p = p->left;
      }else{
        p = p->right;
      }
    }
    return p;
  }
}

void insert_node_tree(NODE_TREE *&root, TheDocGia x){
	if(root == NULL){ //cay rong
		root = create_node_tree(x);
	}else{
		NODE_TREE *p = root;
		NODE_TREE *parent = NULL;
		while(p != NULL && p->data.MaThe != x.MaThe){
			parent = p;
			if(p->data.MaThe > x.MaThe){
				p = p->left;
			}else{
				p = p->right;
			}
		}
		if(p == NULL){
			p = create_node_tree(x);
			if(parent->data.MaThe < x.MaThe){
				parent->right = p;
			}else parent->left = p;
		}
	}
}

void delete_node_tree(NODE_TREE *&p, TheDocGia x) {
    if (p == NULL) {
        cout << "Khong tim thay";
    } else {
        if (x.MaThe < p->data.MaThe) {
            delete_node_tree(p->left, x);
        } else if (x.MaThe > p->data.MaThe) {
            delete_node_tree(p->right, x);
        } else {
            NODE_TREE *temp;
            if (p->left == NULL) {
                temp = p->right;
                delete p;
                p = temp;
            } else if (p->right == NULL) {
                temp = p->left;
                delete p;
                p = temp;
            } else {
                NODE_TREE *successor = p->right;
                while (successor->left != NULL) {
                    successor = successor->left;
                }
                p->data = successor->data;
                delete_node_tree(p->right, successor->data);
            }
        }
    }
}

struct QuaHan{
  int mathe;
  string masach;
  int songayquahan;
};
