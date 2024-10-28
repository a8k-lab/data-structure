#ifndef PROVINCE_H_INCLUDED
#define PROVINCE_H_INCLUDED

#include <iostream>
#include <array>
using namespace std;

typedef struct {
    string nama;
    string ibuKota;
    string terbesar;
    int popTerbesar;
    array<string, 19> kabupaten;
    array<string, 19> kota;
    int nKab;
    int nKota;
} Provinsi;

void buatProvinsi(Provinsi *prov);
// I.S. data nama provinsi prov dan ibuKota telah siap pada piranti masukan
// Proses: menerima masukan nama provinsi dan ibuKota. Gunakan underscore "_"
// apabila terdapat spasi pada nama provinsi dan ibuKota.
// F.S. terdefinisi sebuah provinsi baru dengan nama dan ibuKota yang 
// diperoleh dari masukan. Nilai popTerbesar, nKab, nKota bernilai nol karena belum ada data

void tambahDaerah(Provinsi *prov, bool flag);
// I.S. terdefinisi data suatu provinsi prov dan boolean flag, selain itu data 
// nama daerah dan populasinya telah siap pada piranti masukan
// Proses: menerima masukan berupa nama daerah dan banyaknya populasi daerah 
// tersebut. Gunakan underscore "_" apabila terdapat spasi pada nama daerah.
// F.S. data daerah ditambahkan sebagai kota apabila flag bernilai true/1 
// atau sebagai kabupaten apabila flag bernilai false/0. Selanjutnya nilai terbesar, 
// popTerbesar, nKab dan nKota diperbaharui sesuai penambahan yang dilakukan

void perbaharuiTerbesar(Provinsi *prov, string daerah, int populasi);
// I.S. terdefinisi data suatu provinsi prov, data daerah baru beserta populasinya.
// F.S. terbesar dan popTerbesar diperbaharui apabila daerah baru memiliki populasi 
// lebih besar dibandingkan populasi pada daerah terbesar saat ini

bool terdaftar(Provinsi prov, string daerah, bool flag);
// mengembalikan true/1 apabila daerah merupakan kabupaten atau kota yang terdaftar
// pada provinsi prov. dan false/0 apabila sebaliknya. Apabila flag bernilai true/1
// maka lakukan pencarian di array kota, sedangkan apabila false/0 maka lakukan 
// pencarian di array kabupaten. Gunakan algoritma pencarian Sequential Search yang 
// sudah pernah dipelajari pada mata kuliah Algoritma Pemrograman

void tampilProvinsi(Provinsi prov);
// I.S. terdefinisi data suatu provinsi prov
// F.S. menampikan data provinsi berupa nama, ibuKota, daerah dengan populasi terbesar 
// dan total kabupaten/kota yang terdapat pada provinsi tersebut. Catatan: Lihat 
// contoh pada Soal 3 poin d

#endif // PROVINCE_H_INCLUDED
