#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define nil NULL

typedef struct jadwalPenerbangan infotype;
typedef struct elemenJadwal *adrJadwalP;

struct jadwalPenerbangan {
  string kode;
  string jenis;
  string tanggal;
  string waktu;
  string asal;
  string tujuan;
  int kapasitas;
};

struct elemenJadwal {
  infotype info;
  adrJadwalP next;
};

struct listJadwal {
  adrJadwalP first;
};

// IS: -
// FS: L berisi sebuah list kosong
void createListJadwal_103042310065(listJadwal &L);

// Mengembalikan alamat elemen list hasil alokasi, info berisi data dari masukan
adrJadwalP createElemenJadwal_103042310065(infotype X);

// IS: Terdefinisi sebuah list L (mungkin kosong) dan sebuah pointer p yang berisi alamat elemen baru
// FS: Elemen baru yang ditambahkan sebagai elemen terakhir dari list L
void insertLastJ_103042310065(listJadwal &L, adrJadwalP P);

// IS: terdefinisi sebuah list L (mungkin kosong)
// FS: menampilkan isi dari list L secara horizontal
void showJadwal_103042310065(listJadwal L);

// IS: Terdefinisi sebuah list L (mungkin kosong)
// FS: Pointer P berisi alamat elemen terakhir dari list L, dan elemen tersebut dihapus dari list L
void deleteFirstJ_103042310065(listJadwal &L, adrJadwalP &P);

// IS: Terdefinisi sebuah list L (mungkin kosong)
// FS: mengembalikan alamat dari elemen list L yang memiliki info asal=dari, tujuan=ke dan tanggal keberangkatan=tanggal, atau NIL apabila tidak ditemukan
adrJadwalP searchJ_103042310065(listJadwal L, string dari, string ke, string tanggal);

#endif // FLIGHT_H_INCLUDED
