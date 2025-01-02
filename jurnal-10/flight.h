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

typedef struct elemenJadwal *adrJadwalP;
typedef struct elemenPenumpang *adrPenumpangP;
typedef struct jadwalPenerbangan infotypeJadwal;
typedef struct penumpang infotypePenumpang;

struct penumpang {
    string nama;
    string nik;
    string jk;
    int usia;
};

struct elemenPenumpang {
    infotypePenumpang info;
    adrJadwalP jadwalP;
    adrPenumpangP next;
};

struct listPenumpang {
    adrPenumpangP first;
};

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
    infotypeJadwal info;
    adrJadwalP next;
};

struct listJadwal {
    adrJadwalP first;
};

void createListJadwal_103042310065(listJadwal &LJ);

adrJadwalP createElemenJadwal_103042310065(infotypeJadwal X);

void insertLastJ_103042310065(listJadwal &LJ, adrJadwalP P);

void showJadwal_103042310065(listJadwal LJ);

void deleteFirstJ_103042310065(listJadwal &LJ, adrJadwalP &P);

adrJadwalP searchJ_103042310065(listJadwal LJ, string dari, string ke, string tanggal);

void createListPenumpang_103042310065(listPenumpang &LP);

adrPenumpangP createElemenPenumpang_103042310065(infotypePenumpang X);

void insertLastP_103042310065(listPenumpang &LP, adrPenumpangP P);

/**
 * I.S. Terdefinisi sebuah list penumpang, data penumpang, dan data jadwal penerbangannya berupa asal penerbangan (dari), tujuan penerbangan(ke), dan tanggal penerbangan(tanggal). Asumsi hanya ada 1 jadwal penerbangan dari A ke B pada tanggal X pada list Jadwal, namun bisa saja tidak ditemukan. List Penumpang bisa kosong.
 * F.S. Elemen penumpang baru masuk menjadi elemen akhir di list penumpang, dan jadwal nya terkoneksi ke element pada list Jadwal
 */
void booking_103042310065(listPenumpang &LP, infotypePenumpang X, listJadwal LJ, string dari, string ke, string tanggal);

void showPenumpang_103042310065(listPenumpang LP);

/**
 * I.S. Terdefinisi sebuah list penumpang, data penumpang, dan data jadwal penerbangannya berupa asal penerbangan (dari), tujuan penerbangan(ke), dan tanggal penerbangan(tanggal). Asumsi hanya ada 1 jadwal penerbangan dari A ke B pada tanggal X pada list Jadwal, namun bisa saja tidak ditemukan. List Penumpang bisa kosong.
 * F.S. Elemen penumpang baru masuk menjadi elemen akhir di list penumpang, dan jadwal nya terkoneksi ke element pada list Jadwal
 */
void reschedule_103042310065(listPenumpang &LP, listJadwal LJ, string NIK, string newDari, string newKe, string newTanggal);

void showAllListPenumpang_103042310065(listJadwal LJ, listPenumpang LP, string kode);

#endif // FLIGHT_H_INCLUDED