#include <iostream>
using namespace std;

struct Thedocgia{
  int mathe;
  string ho;
  string ten;
  string phai;
  int trangthaithe; //1: hoat dong, 0: khoa
};
struct NODE_TREE{
  Thedocgia data;
  NODE_TREE *pLeft;
  NODE_TREE *pRight;
};
typedef NODE_TREE* TREE;