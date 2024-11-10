#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#include <iostream>
using namespace std;
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define nil NULL
typedef string infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address prev;
    address next;
};

struct List {
    address first;
    address last;
};

// Fungsi mengirimkan true jika list kosong, dan false jika tidak kosong}
bool isEmpty(List L);

// I.S. –
// F.S. terdefinisi L, list kosong
void createList(List &L);

// I.S. X adalah info yang akan ditempatkan pada elemen baru yang dialokasi
// F.S. terdefinisi elemen list dengan address P, dimana info dari P adalah X, atau
// dikembalikan NULL jika alokasi elemen baru gagal
address createNewElmt(infotype X);

// I.S List L mungkin kosong. Telah terdefinisi P untuk disisipkan ke dalam L; next(P) dan
// Prev(P)= NULL
// F.S. P menjadi elemen pertama dari list L
void insertFirst(List &L, address P);

// I.S. Prec tidak NULL dan merupakan elemen list L. P akan disisipkan setelah Prec
// F.S. P sudah disisipkan ke dalam L dan terletak setelah Prec
void insertAfter(List &L, address Prec, address P);

// I.S List L mungkin kosong. Telah terdefinisi P untuk disisipkan ke dalam L; next(P) dan
// prev(P)= NULL
// F.S. P menjadi elemen terakhir pada dari list L
void insertLast(List &L, address P);

// I.S. L mempunyai satu atau lebih elemen
// F.S. Elemen pertama sudah dihapus dan dicatat pada P. List L mungkin menjadi kosong
void deleteFirst(List &L, address &P);

// I.S. Prec adalah elemen list L dan next(prec) tidak NULL. Next(prec) mungkin menunjuk
// ke elemen terakhir
// F.S. Elemen setelah Prec sudah dihapus dari L dan diingat pada P
void deleteAfter(List &L, address Prec, address &P);

// I.S. L mempunyai satu atau lebih elemen
// F.S. Elemen terakhir sudah dihapus dan dicatat pada P. List L mungkin menjadi kosong
void deleteLast(List &L, address &P);

// I.S. L1 dan L2 masing-masing mempunyai satu atau lebih elemen
// F.S. L3 berisi semua elemen L1 digabung dengan semua elemen L
void concat(List L1, List L2, List &L3);

// Mencari lagu dengan judul tertentu.
// IS: Terdefinisi List L dan lagu yang akan dicari. List mungkin kosong.
// FS: Return alamat dimana lagu ditemukan, return nil jika tidak ditemukan
address findLagu(string Judul, List L);

// IS: List mungkin kosong. Jika tidak kosong, minimal memiliki 1 elemen.
// FS: Lagu dengan Judul tsb di-dealokasi dari List L.
// Notes:
// a. Gunakan function findLagu untuk mencari judul lagu.
// b. Lagu yang dihapus mungkin merupakan elemen pertama, tengah, atau terakhir
void removeLagu(string Judul, List &L);

#endif // DLL_H_INCLUDED
