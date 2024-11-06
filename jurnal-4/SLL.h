#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define nil NULL

typedef string infotype;
typedef struct element *adr;

struct element {
    infotype info;
    adr next;
};

struct List {
    adr first;
    adr last;
};

// 1. Procedure createList(output L: list)
// Membuat list kosong.
void createList(List &L);

// 2. Function alokasi(data:infotype) → adr
// Mengalokasikan memori untuk menyimpan data string yang berupa nama produk
adr allocate(infotype x);

// 3. Procedure insertFirst(input/output L:list, input P:adr)
// Menambahkan elemen P di awal list.
void insertFirst(List &L, adr P);

// 4. Procedure insertLast(input/output L:list, input P:adr)
// Menambahkan elemen P di akhir list.
void insertLast(List &L, adr P);

// 5. Procedure insertAfter(input/output L:list, input Prec,P:adr)
// Menambahkan elemen P setelah elemen yang ditunjuk oleh Prec.
void insertAfter(List &L, adr Prec, adr P);

// 6. Procedure deleteFirst(input/output L:list, output P:adr)
// Menghapus elemen pertama dari list kemudian menyimpan elemen tersebut pada P
void deleteFirst(List &L, adr &P);

// 7. Procedure deleteLast(input/output L:list, output P:adr)
// Menghapus elemen terakhir dari list kemudian menyimpan elemen tersebut pada P
void deleteLast(List &L, adr &P);

// 8. Procedure deleteAfter(input/output L:list, input Prec:adr, output P:adr)
// Menghapus elemen yang berada setelah Prec dari list kemudian menyimpan elemen tersebut pada P
void deleteAfter(List &L, adr Prec, adr &P);

// 9. Procedure show(input L : list)
// Menampilkan seluruh elemen di dalam list.
void show(List L);

// 10. Function findInfo(L : list) → adr
// Mencari elemen di dalam list dengan nama produk tertentu kemudian mengembalikan addressnya
adr findInfo(List L, infotype x);

#endif // SLL_H_INCLUDED
