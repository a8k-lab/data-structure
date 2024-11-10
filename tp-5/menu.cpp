#include "menu.h"

void createList(List &L) {
    first(L) = nil;
}

adr allocate(infotype x) {
    adr P = new element;
    info(P) = x;
    next(P) = nil;
    return P;
}

void insertFirst(List &L, adr P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List &L, adr P) {
    adr q = first(L);
    while (next(q) != nil) {
        q = next(q);
    }
    next(q) = P;
}

void show(List L) {
    adr p = first(L);
    if (p != nil) {
        while (next(p) != nil) {
        cout << info(p) << ", ";
        p = next(p);
        }
        cout << info(p);
    }
    cout << endl;
}

adr findMin(List L) {
    // Fungsi mengembalikan alamat dari data yang berisi nilai terkecil.
    // Dengan asumsi list tidak kosong, fungsi mengembalikan data terkec dari list.
    adr p = first(L);
    adr min = p;
    while (next(p) != nil) {
        if (info(p) < info(min)) {
            min = p;
        }
        p = next(p);
    }
    return min;
}

void insertMiddle(List &L, int value) {
    // Prosedur menyisipkan/menambahkan data bilangan ke tengah List.
    // I.S. Panjang list adalah ganjil.
    // F.S. Menambahkan data bilangan ke tengah list.

    adr P = allocate(value);
    if (first(L) == nil) {
      first(L) = P;
    } else {
      adr curr = first(L);
      int count = 0;
      while (curr != nil) {
        count++;
        curr = next(curr);
      }
      curr = first(L);
      for (int i = 0; i < count/2; i++) {
        curr = next(curr);
      }
      next(P) = next(curr);
      next(curr) = P;
    }
}

int selectMenu() {
    cout << "======MENU=======" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data" << endl;
    cout << "3. Mencari data terkecil" << endl;
    cout << "4. Menambah data di tengah" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilih menu: ";

    int input = 0;
    cin >> input;
    return input;
}
