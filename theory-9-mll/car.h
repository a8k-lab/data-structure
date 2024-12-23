#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#define first(L) L.first
#define next(P) P->next
#define nextJual(P) P->nextJual
#define prev(P) P->prev
#define info(P) P->info
#define nil NULL

typedef struct ElmJual* adrJual;
typedef struct ElmSales* adrSales;

struct ElmJual {
    int info;
    adrJual next;
};

struct Sales {
    string nama;
    string gol;
};

struct ElmSales {
    Sales info;
    adrSales next;
    adrJual nextJual;
};

struct MLL {
    adrSales first;
};


/**
 * Fungsi ini akan mencari nama sales pada list sales, jika ditemukan maka akan dikembalikan alamatnya, jika tidak ditemukan maka akan dikembalikan NIL
 */
adrSales searchSales(MLL listSales, string nama);

/**
 * I.S. Terdefinisi list sales yang mungkin kosong, dan elemen sales baru yang disimpan oleh pointer S, yang akan diinsertkan menjadi elemen sales paling akhir pada list sales
 * F.S. elemen baru menjadi elemen sales paling akhir pada list sales
 */
void insertLastSales(MLL &listSales, adrSales S);

/**
 * I.S. –
 * F.S. Dihasilkan sebuah multi linked list 1 ke N dengan pointer first yang NIL}
 */
void createList(MLL &listSales);

/**
 * I.S. terdefinisi data sales dan pointer yang akan menyimpan alamat elemen dari data sales yang baru
 * F.S. data sales baru sudah menjadi elemen dan alamatnya disimpan oleh pointer S
 */
void newElmSales(Sales info, adrSales &S);

/**
 * I.S. terdefinisi data jumlah penjualan dan pointer yang akan menyimpan alamat elemen dari data penjualan yang baru
 * F.S. data sales baru sudah menjadi elemen dan alamatnya disimpan oleh pointer S}
 */
void newElmJual(int info, adrJual &J);

/**
 * I.S. Terdefinisi list sales yang tidak kosong, dan elemen penjualan baru yang akan disisipkan menjadi data penjualan pada sales S. Data penjualan pada sales S tidak kosong.
 * F.S. Elemen penjualan baru akan disisipkan menjadi data penjualan paling akhir di sales pada elemen S.
 * CLUE : Konsep Insert Last
 */
void insertNewPenjualan(MLL &listSales, adrSales S, adrJual J);

/**
 * I.S. Terdefinisi list sales yang tidak kosong, dan elemen sales yang akan dihapus elemen penjualannya yang berada di posisi paling pertama
 * F.S. Elemen penjualan pertama dari sales S dihapus dan alamatnay disimpan di pointer J.
 * CLUE : Konsep delete first 
 */
void deleteFirstPenjualan(MLL &listSales, adrSales S, adrJual &J);

/**
 * I.S. Terdefinisi list sales yang tidak kosong, dan elemen sales yang akan dihapus elemen penjualannya yang berada di posisi paling akhir
 * F.S. Elemen penjualan paling akhir dari sales S dihapus dan alamatnya disimpan di pointer J. 
 * CLUE : Konsep delete last
 */
void deleteLastPenjualan(MLL &listSales, adrSales S, adrJual &J);

/**
 * I.S. Terdefinisi list sales yang tidak kosong, pointer prec
 * F.S. Elemen penjualan yang berada setelah pointer prec dihapus. 
 * CLUE : Konsep delete after
 */
void deleteAfterPenjualan(MLL &listSales, adrSales S, adrJual prec, adrJual &J);

/**
 * I.S. Terdefinisi list sales yang tidak kosong
 * F.S. Data penjualan setiap sales tampil ke layar
 * HINT : Anda membutuhkan 2 pointer, pointer yang akan menelusuri elemen sales satu persatu, dan setiap kali pointer itu mengunjungi sebuah elemen sales, ada pointer kedua yang akan menelusuri elemen data penjualan dari sales tsb. Setelah selesai penelusuran elemen penjualan di sebuah elemen sales, maka pointer pertama tadi bergeser ke sales selanjutnya, dna mengulangi Langkah yang sama, hingga semua sales terkunjungi.
 */
void showDataSales(MLL listSales);

/**
 * I.S. Terdefinisi list sales yang tidak kosong
 * F.S. Data penjualan kurang dari 3 dihapus dari elemen penjualan
 * Clue : telusuri semua data penjualan dari setiap sales, jika menenukan data penjualan kurang dari 3 maka lakukan penghapusan dengan cara memanggai procedure delete sesuai kondisi elemennya (Apakah elemen nya di paling awal, atau di paling akhir, atau diantaranya)
 */
void deletePenjualan(MLL &listSales);

#endif // CAR_H
