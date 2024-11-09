#include <iostream>
#include "menu.h"

using namespace std;

int main() {
    int num = 0, pilihan = 0, loop;
    string konfirm;
    infotype x;
    List list;
    adr P;

    createList(list);
    pilihan = selectMenu();

    while (pilihan != 0) {
        switch (pilihan) {
        case 1:
            do {
                cout << "Jumlah data yang akan ditambahkan: ";
                cin >> loop;
                for (int i = 1; i <= loop; i++) {
                    cout << "Masukkan data baru: ";
                    cin >> x;
                    P = allocate(x);
                    if (i == 1) {
                        insertFirst(list, P);
                    } else {
                        insertLast(list, P);
                    }
                }
                cout << endl;
                cout << "Kembali ke menu utama? (Y/N): ";
                cin >> konfirm;
            } while (konfirm == "N" || konfirm == "n");
            break;
        case 2:
            cout << "Semua data: ";
            show(list);
            break;
        case 3:
            P = findMin(list);
            cout << "Data terkecil: " << info(P) << endl;
            break;
        case 4:
            cout << "Masukkan data: ";
            cin >> x;
            insertMiddle(list, x);
            break;
        default:
            break;
        }
        pilihan = selectMenu();
    }
    return 0;
}
