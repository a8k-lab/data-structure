#include <iostream>
#include "SLL.h"

using namespace std;

int main() {
    List listProduk;
    adr P;
    infotype nama, lokasiHapus;

    createList(listProduk);

    // Input 5 produk
    for (int i = 1; i <= 5; i++) {
        cout << "Masukkan nama produk ke-" << i << ": ";
        cin >> nama;
        P = allocate(nama);
        
        if (i == 1) {
            insertFirst(listProduk, P);
        } else if (i == 2) {
            insertAfter(listProduk, first(listProduk), P);
        } else {
            insertLast(listProduk, P);
        }
        cout << endl;
    }

    cout << "Daftar produk saat ini adalah: ";
    show(listProduk);

    // Cari produk
    cout << endl;
    if (first(listProduk) == nil) {
        cout << "Maaf, daftar produk kosong";
    } else {
        cout << "Masukkan nama produk yang dicari: ";
        cin >> nama;
        P = findInfo(listProduk, nama);

        if (P == nil) {
            cout << "MAAF, PRODUK TIDAK DITEMUKAN";
        } else {
            cout << "PRODUK DITEMUKAN PADA ALAMAT " << P;
        }
    }

    // Hapus 5 produk
    cout << endl;
    cout << "Daftar awal produk: ";
    show(listProduk);
    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Lokasi produk yang akan dihapus (depan/belakang): ";
        cin >> lokasiHapus;
        if (lokasiHapus == "depan") {
            deleteFirst(listProduk, P);
        } else if (lokasiHapus == "belakang") {
            deleteLast(listProduk, P);
        }

        cout << "Daftar setelah dihapus: ";
        if (first(listProduk) == nil) {
            cout << "Daftar produk kosong";
        } else {
            show(listProduk);
        }
    }

    cout << endl;
    cout << "SELESAI";

    return 0;
}
