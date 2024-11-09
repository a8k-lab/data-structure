#include "Province.h"

void buatProvinsi(Provinsi *prov) {
    cout << "Masukkan nama provinsi: ";
    cin >> prov->nama;
    cout << "Masukkan ibukota: ";
    cin >> prov->ibuKota;
    prov->popTerbesar = 0;
    prov->nKab = 0;
    prov->nKota = 0;
}

void tambahDaerah(Provinsi *prov, bool flag) {
    string namaDaerah;
    int popDaerah;

    cout << "Masukkan nama daerah: ";
    cin >> namaDaerah;
    cout << "Masukkan populasi daerah: ";
    cin >> popDaerah;

    if (flag) {
        // Menambahkan sebagai kota
        if (prov->nKota < 19) {
            prov->kota[prov->nKota] = namaDaerah;
            prov->nKota++;
        } else {
            cout << "Jumlah kota sudah mencapai batas maksimum." << endl;
        }
    } else {
        // Menambahkan sebagai kabupaten
        if (prov->nKab < 19) {
            prov->kabupaten[prov->nKab] = namaDaerah;
            prov->nKab++;
        } else {
            cout << "Jumlah kabupaten sudah mencapai batas maksimum." << endl;
        }
    }

    // Memperbaharui nilai terbesar dan popTerbesar
    if (popDaerah > prov->popTerbesar) {
        prov->terbesar = namaDaerah;
        prov->popTerbesar = popDaerah;
    }
}

void perbaharuiTerbesar(Provinsi *prov, string daerah, int populasi) {
    if (populasi > prov->popTerbesar) {
        prov->terbesar = daerah;
        prov->popTerbesar = populasi;
    }
}

bool terdaftar(Provinsi prov, string daerah, bool flag) {
    if (flag) {
        // Pencarian di array kota
        for (int i = 0; i < prov.nKota; i++) {
            if (prov.kota[i] == daerah) {
                return true;
            }
        }
    } else {
        // Pencarian di array kabupaten
        for (int i = 0; i < prov.nKab; i++) {
            if (prov.kabupaten[i] == daerah) {
                return true;
            }
        }
    }
    return false;
}

void tampilProvinsi(Provinsi prov) {
    cout 
        << "Nama Provinsi: " 
        << prov.nama
        << "(" << prov.ibuKota << ")"
        << endl;
    
    cout
        << "Daerah Terbesar adalah "
        << prov.terbesar
        << " dari "
        << prov.nKab + prov.nKota
        << " Kota dan Kabupaten"
        << endl;
}
