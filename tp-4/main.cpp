#include <iostream>
#include "list.h"
using namespace std;

int main() {
    List myList;
    address P;

    // 1. Panggil create list
    createList(myList);

    // 2. Buat sintak menanyakan angka pertama yang ingin diinputkan user ke list
    int angka;
    cout << "Masukkan angka pertama: ";
    cin >> angka;

    // 3. Panggil fungsi allocate agar data tersebut dijadikan elemen
    P = allocate(angka);

    // 4. Panggil procedure insertFirst yang telah dibuat
    insertFirst(myList, P);

    // 5. Panggil procedure printInfo untuk mengecek apakah angka tersebut berhasil menjadi elemen di list
    cout << "Isi list setelah memasukkan angka pertama: ";
    printInfo(myList);

    // 6. Buat kembali sintak no 2 s/d no 5 untuk data angka kedua dari user
    cout << "\nMasukkan angka kedua: ";
    cin >> angka;
    P = allocate(angka);
    insertFirst(myList, P);
    cout << "Isi list setelah memasukkan angka kedua: ";
    printInfo(myList);

    // 7. Buat kembali sintak no 2 s/d no 5 untuk data angka ketiga dari user
    cout << "\nMasukkan angka ketiga: ";
    cin >> angka;
    P = allocate(angka);
    insertFirst(myList, P);
    cout << "Isi list setelah memasukkan angka ketiga: ";
    printInfo(myList);

    return 0;
}
