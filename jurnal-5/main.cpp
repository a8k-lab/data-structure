#include "SLL.h"

int main() {
    // buat list kosong
    List mList;
    createNewList(mList);

    int menu = selectMenu();
    while (menu != 0) {
        switch (menu) {
        case 1:
            int jumlahTambah;
            cout << "Masukkan jumlah masakan yang akan ditambahkan: ";
            cin >> jumlahTambah;
            addNElementList(mList, jumlahTambah);
            break;
        case 2:
            showAllFood(mList);
            break;
        case 3:
            showAvailableFood(mList);
            break;
        case 4:
            showBestSeller(mList);
            break;
        case 5:
            deleteAllSoldOut(mList);
            break;
        case 6:
            int noMasakan, porsi;
            cout << "Masukkan nomor masakan: ";
            cin >> noMasakan;
            cout << "Masukkan jumlah porsi: ";
            cin >> porsi;
            transaction(mList, noMasakan, porsi);
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        menu = selectMenu();
    }
    return 0;
}
