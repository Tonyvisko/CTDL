#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
  string s;
  char c;
  ifstream file("inputdocgia.txt");
  while(getline(file, s, ',')){
    cout << s << endl;
  }
  file.close();
  return 0;
}