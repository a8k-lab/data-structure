#include "SLL.h"

void createNewList(List &L){
    first(L) = nil;
}

void insertLast(List &L, address p){
    address x;

    if (first(L) == nil){
        first(L) = p;
    } else {
        x = first(L);
        while (next(x) != nil){
            x = next(x);
        }
        next(x) = p;
    }
}

void deleteFirst(List &L, address &p){
    if (first(L) == nil){
        cout << "List masakan kosong" << endl;
    } else {
        if (next(first(L)) == nil){
            p = first(L);
            first(L) = nil;
        } else {
            p = first(L);
            first(L) = next(p);
        }
    }
}

void deleteLast(List &L, address &p){
    if (first(L) == nil){
        cout << "List masakan kosong" << endl;
    } else {
        if (next(first(L)) == nil){
            p = first(L);
            first(L) = nil;
        } else {
            address q;
            p = first(L);
            while (next(p) != nil){
                q = p;
                p = next(p);
            }
            next(q) = nil;
        }
    }
}

void deleteAfter(List &L, address prec, address &p){
    p = next(prec);
    if (next(p) == nil){
        next(prec) = nil;
    } else {
        next(prec) = next(p);
        next(p) = nil;
    }
}

bool isEmpty(List L){
    return first(L) == nil;
}

infotype newMasakan(int nomor, string nama){
    infotype m;
    m.nomor = nomor;
    m.nama = nama;
    m.sisaPorsi = S;
    return m;
}

address newElementList(infotype m){
    address p;
    p = new ElmtMsk;
    info(p) = m;
    next(p) = nil;
    return p;
}

void addNElementList(List &mList, int N){
    address p;
    int nomor;
    string nama;
    for (int i = 1; i <= N; i++){
        cout << "Masukkan nama masakan ke-" << i << ": ";
        cin >> nama;
        p = newElementList(newMasakan(i, nama));
        insertLast(mList, p);
    }
}

void showAllFood(List mList){
    address p;
    p = first(mList);
    while (p != nil){
        cout << info(p).nomor << ". " << info(p).nama << " (" << info(p).sisaPorsi << ")" << endl;
        p = next(p);
    }
}

void showAvailableFood(List mList){
    address p;
    p = first(mList);
    while (p != nil){
        if (info(p).sisaPorsi > 0){
            cout << info(p).nomor << ". " << info(p).nama << " (" << info(p).sisaPorsi << ")" << endl;
        }
        p = next(p);
    }
}

address findMinRemaining(List mList){
    address p;
    p = first(mList);
    address min = p;
    while (next(p) != nil){
        if (info(p).sisaPorsi < info(min).sisaPorsi){
            min = p;
        }
        p = next(p);
    }
    return min;
}

void showBestSeller(List mList){
    address p;
    p = findMinRemaining(mList);
    while (p != nil){
        cout << info(p).nomor << ". " << info(p).nama << " (" << info(p).sisaPorsi << ")" << endl;
        p = next(p);
    }
}

void deleteAllSoldOut(List &mList) {
    address p = first(mList);
    address prec = nil;

    while (p != nil) {
        if (info(p).sisaPorsi == 0) {
            address temp = p;
            if (p == first(mList)) { // Jika elemen pertama
                first(mList) = next(p);
                p = first(mList); // Pindahkan ke elemen baru setelah penghapusan
            } else { // Jika elemen bukan pertama
                next(prec) = next(p);
                p = next(p); // Pindahkan ke elemen baru setelah penghapusan
            }
            delete temp; // Menghapus temp agar tidak terjadi garbage/memory leak
        } else {
            prec = p;
            p = next(p);
        }
    }
}


int selectMenu() {
    cout << endl;
    cout << "====== MENU =======" << endl;
    cout << "1. Tambah data masakan" << endl;
    cout << "2. Tampilkan semua data masakan" << endl;
    cout << "3. Tampilkan semua data masakan yang masih tersedia (belum habis terjual)" << endl;
    cout << "4. Tampilkan semua data masakan yang paling laku terjual (best seller)" << endl;
    cout << "5. Hapus semua data masakan yang sudah laku terjual" << endl;
    cout << "6. Transaksi" << endl;
    cout << "0. Selesai" << endl;
    cout << "===============" << endl;
    cout << "Pilih menu: ";

    int input = 0;
    cin >> input;
    cout << "===============" << endl;
    return input;
}

address findInfo(List mList, int noMasakan) {
    address p;
    p = first(mList);
    while (p != nil) {
        if (info(p).nomor == noMasakan) {
            return p;
        }
        p = next(p);
    }
    return nil;
}

void transaction(List &mList, int noMasakan, int porsi) {
    address p;
    p = findInfo(mList, noMasakan);
    if (p == nil) {
        cout << "Data masakan dengan nomor " << noMasakan << " tidak ditemukan." << endl;
    } else {
        if (info(p).sisaPorsi >= porsi) {
            info(p).sisaPorsi -= porsi;
            cout << "Data masakan dengan nomor " << noMasakan << " berhasil dibeli " << porsi << " porsi." << endl;
        } else {
            cout << "Data masakan dengan nomor " << noMasakan << " tidak memiliki " << porsi << " porsi yang tersedia." << endl;
        }
    }
}
