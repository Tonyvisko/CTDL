#include <iostream>
#include <cstring>
using namespace std;

#define MaxNodes 10000
#define SoNgayDuocMuon 7


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
NODE_SINGLY_LIST *create_singly_node(DanhMucSach x){
	NODE_SINGLY_LIST *p = new NODE_SINGLY_LIST;
	p->data = x;
	p->next = NULL;
	return p;
}
void insert_first_singly_node(NODE_SINGLY_LIST *&head, DanhMucSach x){
	NODE_SINGLY_LIST *p = create_singly_node(x);
	p->data = x;
	p->next = head;
	head = p;
}
void insert_last_singly_node(NODE_SINGLY_LIST *&head, DanhMucSach x){
	NODE_SINGLY_LIST *p = create_singly_node(x);
	if(head == NULL){
		insert_first_singly_node(head, x);
		return;
	}else{
		NODE_SINGLY_LIST *last = head;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = p;
	}
}
void insert_after_singly_node(NODE_SINGLY_LIST *p, DanhMucSach x){
  NODE_SINGLY_LIST *q;
  if(p == NULL){
    return;
  }else{
    q = create_singly_node(x);
    q->next=p->next;
    p->next=q;
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
  DanhMucSach *dms;
};

struct pointerArray{
  int SoLuongDauSach;
  DauSach* nodesDauSach[MaxNodes];
};
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
  NODE_DOUBLY_LIST *DoublyList_MuonTra;
};
struct NODE_TREE{
	TheDocGia data;
	NODE_TREE *left;
	NODE_TREE *right;
};
NODE_TREE *create_node_tree(TheDocGia x){
	NODE_TREE *p = new NODE_TREE;
	p->data = x;
	p->left = p->right = NULL;
	return p;
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
void delete_node_tree(NODE_TREE *&root, TheDocGia x){
	if(root != NULL){
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
		if(p != NULL){
			NODE_TREE *t;
			if(p->left == NULL){
				t = p->right;
			}else t = p->left;
			if(parent->data.MaThe > p->data.MaThe){
				parent->left = t;
			}else parent->right = t;
			delete(p);
		}else cout << "NOT FOUND !!!" << endl;
	}else cout << "EMPTY TREE !!!" << endl;
}
