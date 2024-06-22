#include "KhaiBao.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

TheDocGia A[100];
int i = 0;

void Inorder(NODE_TREE *root){

  if(root != NULL){
    Inorder(root->left);
    A[i++] = root->data;
    Inorder(root->right);
  }
}

void SapXepTheoTen(NODE_TREE *root){
  Inorder(root);
  for(int j = 0; j < i-1; j++){
    for(int k = j+1; k < i; k++){
      if(A[j].Ten > A[k].Ten){
        TheDocGia temp = A[j];
        A[j] = A[k];
        A[k] = temp;
      }
      else if(A[j].Ten == A[k].Ten){
        if(A[j].Ho > A[k].Ho){
          TheDocGia temp = A[j];
          A[j] = A[k];
          A[k] = temp;
        }
      }
    }
  }
}

int main(){
  NODE_TREE *root = NULL;
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
  }
  while(1){
    int c;
    cin >> c;
    if(c == 0){
      i = 0;
      SapXepTheoTen(root);
      for(int j = 0; j < i; j++){
        cout << A[j].MaThe << " " << A[j].Ho << " " << A[j].Ten << " " << A[j].Phai << " " << A[j].TrangThai << endl;
      }
    }
    else if(c==1){
      i = 0;
      Inorder(root);
      for(int j = 0; j < i; j++){
        cout << A[j].MaThe << " " << A[j].Ho << " " << A[j].Ten << " " << A[j].Phai << " " << A[j].TrangThai << endl;
      }
    }
  }
  file.close();
  return 0;
}
