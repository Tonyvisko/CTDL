#include "menu.h"
#include "LoadingScreen.h"

int main(){
  initwindow(1366, 768, "");
  LayDanhSachDauSach(DSDS);
  LayDanhSachDocGia(root);
  LayDanhSachMuonTra(root);
  TaoMangNgauNhien();
  //loadingScreen();
  menu();
  return 0;
}
