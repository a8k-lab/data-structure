#include "DLL.h"

int main() {
    List L1, L2, L3;
    address P, Prec;

    // 1. Membuat list dan menambahkan elemen musik berdasarkan ilustrasi
    createList(L1);
    createList(L2);
    createList(L3);

    // Menambah lagu "Foster The People - Imagination" sebagai elemen pertama
    P = createNewElmt("Imagination");
    insertFirst(L1, P);

    // Menambah lagu "The Corrs - Radio" sebagai elemen berikutnya setelah elemen pertama
    P = createNewElmt("Radio");
    insertLast(L1, P);

    // Menambah lagu "Maroon 5 - Sugar" sebagai elemen terakhir
    P = createNewElmt("Sugar");
    insertLast(L1, P);

    cout << "List L1 setelah penambahan elemen:" << endl;
    P = first(L1);
    while (P != nil) {
        cout << info(P) << endl;
        P = next(P);
    }

    // 2. Mencari lagu "Radio" pada list
    P = findLagu("Radio", L1);
    if (P != nil) {
        cout << "Lagu 'Radio' ditemukan: " << info(P) << endl;
    } else {
        cout << "Lagu 'Radio' tidak ditemukan." << endl;
    }

    // 3. Menghapus elemen pertama (Foster The People - Imagination)
    deleteFirst(L1, P);
    cout << "List L1 setelah elemen pertama dihapus:" << endl;
    P = first(L1);
    while (P != nil) {
        cout << info(P) << endl;
        P = next(P);
    }

    // 4. Menghapus lagu "Sugar"
    removeLagu("Sugar", L1);
    cout << "List L1 setelah lagu 'Sugar' dihapus:" << endl;
    P = first(L1);
    while (P != nil) {
        cout << info(P) << endl;
        P = next(P);
    }

    // 5. Menambah elemen list di L2 untuk contoh operasi concat
    P = createNewElmt("Lagu A");
    insertFirst(L2, P);

    P = createNewElmt("Lagu B");
    insertLast(L2, P);

    P = createNewElmt("Lagu C");
    insertLast(L2, P);

    concat(L1, L2, L3);
    cout << "List L3 hasil concatenation L1 dan L2:" << endl;
    P = first(L3);
    while (P != nil) {
        cout << info(P) << endl;
        P = next(P);
    }

    return 0;
}
