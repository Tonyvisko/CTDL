#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
  srand(time(NULL));
  int a[100];
  for (int i = 0; i < 100; i++){
    a[i] = i;
  }
  
  for (int i = 0; i < 100; i++) {
		int j = rand() % (100 - i) + i ; //j tu i den max-1 
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
  }
	for(int i = 0; i < 100; i++){
    cout << a[i] << endl;
  }
  return 0;
}