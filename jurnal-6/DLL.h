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
typedef struct History infotype;
typedef struct ElmList *address;

struct History {
    string title;
    string url;
    string timestamp;
    int visitcount;
};
struct ElmList {
    infotype info;
    address prev;
    address next;
};
struct List {
    address first;
    address last;
};

// IS. –
// FS. Terbentuk sebuah list di mana, first dan last dari L bernilai NIL.
void createList(List &L);

// Return alamat alokasi memori sebuah elmList yang berisi dataBaru.
address createElemen(infotype dataBaru);

// IS. Terdefinisi pointer P berisi alamat elmList, dan sebuah list L (L mungkin kosong).
// FS. elmList yang ditunjuk oleh P ditambahkan ke dalam list sebagai elemen terakhir.
void insertLast(List &L, address P);

// IS. Terdefinisi pointer Prec dan P berisi alamat elmList. Prec ≠ Last(L).
// FS. elmList yang ditunjuk oleh P ditambahkan ke dalam list setelah elmList yang ditunjuk oleh Prec.
void insertAfter(address prec, address P);

// IS. Terdefinisi sebuah list L (L tidak kosong dan mungkin berisi satu elemen).
// FS. P berisi alamat elmList yang pertama, elmList yang ditunjuk oleh P dihapus dari list
void deleteFirst(List &L, address &P);

// IS. Terdefinisi sebuah list L (L tidak kosong dan mungkin berisi satu elemen).
// FS. P berisi alamat elmList yang terakhir, elmList yang ditunjuk oleh P dihapus dari list
void deleteLast(List &L, address &P);

// IS. Terdefinisi pointer Prec berisi alamat elmList. Prec ≠ Last(L). next(Prec) ≠ Last(L).
// FS. P berisi alamat elmList setelah Prec, elmList yang ditunjuk oleh P dihapus dari list
void deleteAfter(List &L, address Prec, address &P);

// IS. Terdefinisi sebuah list L
// FS. Menampilkan semua info elmList di list.
void printList(List L);




// IS. Terdefinisi pointer P berisi alamat elmList, dan sebuah list L (L tidak kosong).
// FS. elmList yang ditunjuk oleh P ditambahkan ke dalam list sebagai elemen pertama
void insertFirst(List &L, address P);

// IS. Terdefinisi sebuah data, dan sebuah list L (L mungkin kosong, jika list sudah ada isinya, asumsi isi list sudah terurut menaik berdasarkan “visitcount”).
// FS. dataBaru ditambahkan ke dalam list dengan aturan: data di dalam list harus selalu terurut secara menaik (ascending) berdasarkan “visitcount”.
// Note: Gunakan procedure insertFirst, insertLast, dan insertAfter yang sudah dibuat sebelumnya.
void insertAscending(List &L, address P);

// Mencari sebuah elemen dengan title X dalam list L. Kembalikan “true” jika ditemukan dan “false” jika tidak ditemukan.
bool findElemen(List L, string X);

// IS. List mungkin kosong.
// FS. Mengembalikan jumlah History yang memiliki visitcount lebih dari 1. Jika list kosong atau elemen tidak ditemukan di list, maka kembalikan 0.
int moreThanOnce(List L);

#endif // DLL_H_INCLUDED


