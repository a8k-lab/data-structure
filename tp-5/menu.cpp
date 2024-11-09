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
    while (q->next != nil) {
        q = q->next;
    }
    q->next = P;
}

void show(List L) {
    adr p = first(L);
    if (p != nil) {
        while (p->next != nil) {
        cout << info(p) << ", ";
        p = p->next;
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
    while (p->next != nil) {
        if (info(p) < info(min)) {
            min = p;
        }
        p = p->next;
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
