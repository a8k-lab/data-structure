#include "flight.h"
#include <iostream>

int main() {
    string inputNIK, inputAsal, inputTujuan, inputTanggal, inputKode;
    // 1. Buatlah 1 buah list Jadwal
    listJadwal LJ;
    createListJadwal_103042310065(LJ);

    // 2. Dengan menggunakan perulangan, Buatlah 4 element berisi 
    // jadwal penerbangan. Data jadwal penerbangan sesuka Anda, 
    // namun pastikan kode jadwal unik dan ada minimal 2 element 
    // yang berisi jadwal penerbangan pada asal dan tujuan yang 
    // sama namun berbeda tanggal
    cout << "Input Penerbangan" << endl;
    for (int i = 0; i < 4; i++) {
        infotypeJadwal J;
        cout << "Data ke-" << i + 1 << endl;
        cout << "Kode\t: ";
        cin >> J.kode;
        cout << "Jenis\t: ";
        cin >> J.jenis;
        cout << "Tanggal\t: ";
        cin >> J.tanggal;
        cout << "Waktu\t: ";
        cin >> J.waktu;
        cout << "Asal\t: ";
        cin >> J.asal;
        cout << "Tujuan\t: ";
        cin >> J.tujuan;
        cout << "Kapasitas: ";
        cin >> J.kapasitas;
        cout << endl;
        adrJadwalP newJadwal = createElemenJadwal_103042310065(J);
        insertLastJ_103042310065(LJ, newJadwal);
    }

    // 3. Tampilkan 4 jadwal yang sudah Anda insert ke list jadwal
    showJadwal_103042310065(LJ);

    // 4. Buatlah 1 buah list penumpang
    listPenumpang LP;
    createListPenumpang_103042310065(LP);

    // 5. Dengan menggunakan perulangan, panggil procedure insertLastP dan masukkan data 6 penumpang. Aturan nama pada 6 data sbb adalah: 
    // (1) Nama Anda, 
    // (2) Nama Panggilan Dosen Wali Anda, 
    // (3) Nama/kode asprak Anda hari ini, 
    // (4) Nama panggilan teman Anda yang duduk di sebelah 
    // kiri/kanan Anda, 
    // (5) Nama penyanyi yang Anda sukai, 
    // (6) Salah satu nama dosen MK Anda semester ini. 
    // Data detail penumpang selain nama bebas, namun pastikan 
    // saat mengisi NIK datanya UNIK. Data jadwal per penumpang 
    // silahkan Anda tentukan sesuai data pada list jadwal yang 
    // Anda buat sebelumnya
    cout << endl << "Input Jadwal" << endl;
    for (int i = 0; i < 6; i++) {
        infotypePenumpang P;
        cout << "Nama\t: ";
        cin >> P.nama;
        cout << "NIK\t: ";
        cin >> P.nik;
        cout << "Jenis Kelamin\t: ";
        cin >> P.jk;
        cout << "Usia\t: ";
        cin >> P.usia;
        cout << "Asal Penerbangan\t: ";
        cin >> inputAsal;
        cout << "Tujuan Penerbangan\t: ";
        cin >> inputTujuan;
        cout << "Tanggal Penerbangan\t: ";
        cin >> inputTanggal;
        cout << endl << endl;
        booking_103042310065(LP, P, LJ, inputAsal, inputTujuan, inputTanggal);
    }

    // 6. Tampilkan 6 data penumpang yang telah Anda buat dengan 
    // memanggil procedure show Penumpang
    showPenumpang_103042310065(LP);

    // 7. Tampilkan data jadwal dan list penumpangnya dengan 
    // memanggil procedure showAllListPenumpang
    cout << "Tampilkan penumpang berdasarkan kode penerbangan." << endl;
    cout << "Kode\t: ";
    cin >> inputKode;
    showAllListPenumpang_103042310065(LJ, LP, inputKode);

    // 8. Pindahkan 1 penumpang ke tanggal penerbangan lain (asal 
    // dan tujuan sama)
    cout << "Reschedule" << endl;
    cout << "NIK\t: ";
    cin >> inputNIK;
    cout << "Asal\t: ";
    cin >> inputAsal;
    cout << "Tujuan\t: ";
    cin >> inputTujuan;
    cout << "Tanggal\t: ";
    cin >> inputTanggal;
    reschedule_103042310065(LP, LJ, inputNIK, inputAsal, inputTujuan, inputTanggal);

    // 9. Tampilkan data jadwal dan list penumpangnya dengan 
    // memanggil procedure showAllListPenumpang. Cek apakah data 
    // yang Anda reschedule sudah berubah
    showAllListPenumpang_103042310065(LJ, LP, inputKode);
}