#include <iostream>
#include <mylib.h>
#include <conio.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main(){
  int Set[] = {12, 15, 15};
  int counter=1;
  char key;
  for (int i = 0;;){
    key = getch();

    gotoxy(0, 0);
    SetBGColor(Set[0]);
    cout << "1.Them " << endl;
    SetBGColor(15);

    gotoxy(0, 1);
    SetBGColor(Set[1]);
    cout << "2.Xoa  " << endl;
    SetBGColor(15);

    gotoxy(0, 2);
    SetBGColor(Set[2]);
    cout << "3.Thoat" << endl;
    SetBGColor(15);

    if(key==72){
      counter--;
    }
    else if(key==80){
      counter++;
    }
    if(counter==0){
      counter=3;
    }
    else if(counter==4){
      counter=1;
    }

    Set[0] = 15;
    Set[1] = 15;
    Set[2] = 15;
    if(counter==1){
      Set[0] = 12;
    }
    else if(counter==2){
      Set[1] = 12;
    }
    else if(counter==3){
      Set[2] = 12;
    }
  }
}