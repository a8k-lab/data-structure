#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define nil NULL

const int S = 50;
typedef struct Masakan infotype;
typedef struct ElmtMsk *address;

struct Masakan {
    int nomor;
    string nama;
    int sisaPorsi;
};
struct ElmtMsk {
    infotype info;
    address next;
};
struct List {
    address first;
};

void createNewList(List &L);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

// Fungsi mengembalikan True apabila mList adalah list kosong, atau False bila sebaliknya
bool isEmpty(List L);

// Fungsi mengembalikan elemen masakan yang data nomor dan nama masakan diisi berdasarkan parameter fungsi, dan data porsi diisi berdasarkan konstan S
infotype newMasakan(int nomor, string nama);

// Fungsi mengembalikan pointer yang menunjuk ke elemen masakan 
address newElementList(infotype m);

// I.S. Terdefinisi list yang mungkin kosong
// F.S. List akan terisi data masakan sebanyak N. Data masakan didapatkan dari user
void addNElementList(List &mList, int N);

// I.S. Terdefinisi list mList yang mungkin kosong
// F.S. Seluruh data masakan List mList akan tampil ke layar
void showAllFood(List mList);

// I.S. Terdefinisi list mList yang mungkin kosong
// F.S. Data masakan List mList yang porsinya masih tersisa
void showAvailableFood(List mList);

// Fungsi mengembalikan sisa porsi masakan yang paling sedikit (yang posisinya paling depan di list), atau NIL untuk list kosong
address findMinRemaining(List mList);

// I.S. Terdefinisi list mList yang mungkin kosong
// F.S. Data masakan List mList yang paling banyak terjual
void showBestSeller(List mList);

// I.S. Terdefinisi list mList yang mungkin kosong
// F.S. Data masakan yang sudah habis terjual terhapus dari list
void deleteAllSoldOut(List &mList);

// Fungsi yang menampilkan list menu dan mengembalikan input dari user
int selectMenu();

// Fungsi mengembalikan pointer yang menunjuk ke elemen masakan dengan nomor masakan yang sesuai
address findInfo(List mList, int noMasakan);

// I.S. List mungkin kosong.
// F.S. Menampilkan apakah hidangan tersedia atau tidak. Jika tersedia, kurangi porsi yang disimpan dalam list
void transaction(List &mList, int noMasakan, int porsi);

#endif // SLL_H_INCLUDED
