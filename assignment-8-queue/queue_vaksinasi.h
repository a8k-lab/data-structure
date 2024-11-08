#ifndef QUEUE_VAKSINASI_H_INCLUDED
#define QUEUE_VAKSINASI_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define head(Q) Q.head
#define tail(Q) Q.tail
#define info(P) P->info
#define next(P) P->next
#define nil NULL

struct Infotype {
    string nama;
    int usia;
    string pekerjaan;
    bool prioritas;
    int nomor_antrean;
    int waktu_daftar;  // dalam hitungan menit
    bool kondisi_darurat;
};

struct ElemQ {
    Infotype info;
    ElemQ *next;
};

struct Queue {
    ElemQ *head;
    ElemQ *tail;
};

// I.S. -
// F.S. terbentuk queue dengan head dan tail NIL
void createQueue(Queue &Q);

// Mengembalikan nilai true jika queue kosong
bool isEmpty(Queue Q);

// Mengembalikan sebuah pointer yang
// menunjuk ke elemen queue (ElemQ)
ElemQ* createElemQueue(string nama, int usia, string pekerjaan, int nomor_antrean);

// I.S.: Queue Q mungkin kosong, pointer P
// menunjuk ke elemen queue yang akan
// ditambahkan
// F.S.: Elemen yang ditunjuk oleh P ditambahkan
// ke dalam queue Q sesuai aturan:
// • Jika info.prioritas = true, elemen
// dimasukkan di depan antrean setelah
// elemen prioritas lainnya
// • Jika info.prioritas = false, elemen
// dimasukkan di belakang antrean
void enqueue(Queue &Q, ElemQ *P);

// I.S.: Queue Q mungkin kosong
// F.S.: Jika Q tidak kosong, elemen pertama
// dihapus dari Q dan P menunjuk ke elemen
// tersebut. Jika Q kosong, P bernilai NIL dan
// mencetak "Semua warga telah terlayani."
void dequeue(Queue &Q, ElemQ *&P);

// Mengembalikan pointer ke elemen pertama 
// dalam queue Q
ElemQ* front(Queue Q);

// Mengembalikan pointer ke elemen terakhir
// dalam queue Q
ElemQ* back(Queue Q);

// Mengembalikan jumlah elemen dalam queue Q
// dengan menghitung dari head hingga tail
int size(Queue Q);

// Non-Primitive

// I.S. terdefinisi queue mungkin kosong
// F.S. Menampilkan seluruh informasi warga yang ada dalam antrean Q dari head hingga
// tail tanpa mengubah isi atau urutan dalam antrean.
void printInfo(Queue Q);

// I.S.: Queue Q mungkin kosong atau terisi dengan data warga.
// F.S.: Melayani warga dalam antrean Q hingga kapasitas maksimal per hari (100 orang)
// atau hingga antrean kosong.
// - Setiap elemen yang dilayani dihapus dari antrean.
// - Menampilkan pesan konfirmasi vaksinasi untuk setiap warga yang dilayani.
// - Jika kapasitas harian tercapai (100 orang), menampilkan pesan bahwa kapasitas
// telah penuh.
// - Jika masih ada warga di antrean, menampilkan pesan bahwa warga yang belum
// terlayani diminta kembali besok.
void serveQueue(Queue &Q);

// I.S.: Queue Q terdefinisi, mungkin terdapat warga yang belum terlayani dari antrean
// sebelumnya.
// F.S.: Memindahkan warga dari antrean tunggu ke antrean prioritas atau antrean normal
// pada hari berikutnya sesuai kategori prioritas masing-masing warga.
// - Warga prioritas ditempatkan di depan antrean prioritas.
// - Warga non-prioritas ditempatkan di belakang antrean normal
void reassignQueue(Queue &Q);

// I.S.: Queue Q terdefinisi, mungkin terdapat warga yang menunggu terlalu lama dalam
// antrean.
// F.S.: Mengecek waktu tunggu setiap warga dalam antrean Q.
// - Jika waktu tunggu warga lebih dari 2 jam (120 menit), mereka dipindahkan ke
// Queue Prioritas jika belum berada di sana.
// - Mengatur ulang posisi warga dalam antrean sesuai dengan perubahan prioritas
// akibat waktu tunggu
void checkWaitingTime(Queue &Q, int waktu_sekarang);

// I.S.: Queue Q terdefinisi dan berisi warga dalam antrean.
// F.S.: Jika ditemukan warga dengan nomor_antrean yang sesuai dan mengalami kondisi
// darurat, maka:
// - kondisi_darurat warga tersebut diubah menjadi true.
// - Warga tersebut dipindahkan ke posisi paling depan di Queue Prioritas untuk
// dilayani segera.
// - Jika nomor_antrean tidak ditemukan, menampilkan pesan bahwa warga dengan
// nomor tersebut tidak ada dalam antrean.
void emergencyHandle(Queue &Q, int nomor_antrean);

// I.S.: Queue Q terdefinisi dan berisi warga dalam antrean.
// F.S.: Mengatur ulang antrean setiap jam untuk memastikan warga yang memenuhi syarat
// prioritas mendapatkan tempat sesuai dengan tingkat urgensi.
// - Warga yang memiliki prioritas atau menunggu lebih dari 2 jam dipindahkan ke
// depan antrean.
// - Warga dalam kondisi darurat berada di paling depan antrean.
// - Warga non-prioritas berada di belakang antrean setelah warga prioritas.
void updatePriority(Queue &Q);

// I.S.: Queue Q terdefinisi dan berisi warga dalam antrean.
// F.S.: Mengembalikan alamat elemen yang berisi nomor_antrean yang sesuai dan
// menghapus elemen tersebut dari antrean Q.
// - Jika elemen ditemukan, elemen tersebut dihapus dari antrean dan alamatnya
// dikembalikan.
// - Jika elemen tidak ditemukan, mengembalikan NIL dan menampilkan pesan bahwa
// warga dengan nomor antrean tersebut tidak ada dalam antrean.
ElemQ* findAndRemove(Queue &Q, int nomor_antrean);

#endif
