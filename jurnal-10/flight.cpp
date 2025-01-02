#include "flight.h"

void createListJadwal_103042310065(listJadwal &L) {
    first(L) = nil;
}

adrJadwalP createElemenJadwal_103042310065(infotypeJadwal X) {
    adrJadwalP newElm = new elemenJadwal();
    info(newElm) = X;
    next(newElm) = nil;
    return newElm;
}

void insertLastJ_103042310065(listJadwal &L, adrJadwalP P) {
    if (first(L) == nil) {
        first(L) = P;
    } else {
        adrJadwalP currentJ = first(L);
        while (next(currentJ) != nil) {
            currentJ = next(currentJ);
        }
        next(currentJ) = P;
    }
}

void showJadwal_103042310065(listJadwal L) {
    adrJadwalP currentJ = first(L);
    cout << "=================JADWAL=================" << endl;
    while (currentJ != nil) {
        cout << "Kode\t: " << info(currentJ).kode << endl;
        cout << "Jenis\t: " << info(currentJ).jenis << endl;
        cout << "Tanggal\t: " << info(currentJ).tanggal << endl;
        cout << "Waktu\t: " << info(currentJ).waktu << endl;
        cout << "Asal\t: " << info(currentJ).asal << endl;
        cout << "Tujuan\t: " << info(currentJ).tujuan << endl;
        cout << "Kapasitas: " << info(currentJ).kapasitas << endl;
        cout << endl;
        currentJ = next(currentJ);
    }
    cout << "=======================================" << endl;
}

void deleteFirstJ_103042310065(listJadwal &L, adrJadwalP &P) {
    if (first(L) == nil) {
        cout << "List kosong!" << endl;
        return;
    }
    if (next(first(L)) == nil) {
        P = first(L);
        first(L) = nil;
    } else {
        P = first(L);
        first(L) = next(P);
    }
}

adrJadwalP searchJ_103042310065(listJadwal L, string dari, string ke, string tanggal) {
    adrJadwalP currentJ = first(L);
    while (currentJ != nil) {
        if (info(currentJ).asal == dari
            && info(currentJ).tujuan == ke
            && info(currentJ).tanggal == tanggal
        ) {
            return currentJ;
        }
            currentJ = next(currentJ);
    }
    return nil;
}

void createListPenumpang_103042310065(listPenumpang &LP) {
    first(LP) = nil;
}

adrPenumpangP createElemenPenumpang_103042310065(infotypePenumpang X) {
    adrPenumpangP newElm = new elemenPenumpang();
    info(newElm) = X;
    next(newElm) = nil;
    return newElm;
}

void insertLastP_103042310065(listPenumpang &LP, adrPenumpangP P) {
    if (first(LP) == nil) {
        first(LP) = P;
    } else {
        adrPenumpangP currentP = first(LP);
        while (next(currentP) != nil) {
            currentP = next(currentP);
        }
        next(currentP) = P;
    }
}

void booking_103042310065(listPenumpang &LP, infotypePenumpang X, listJadwal LJ, string dari, string ke, string tanggal) {
    adrPenumpangP newElm = createElemenPenumpang_103042310065(X);
    insertLastP_103042310065(LP, newElm);
    adrJadwalP jadwal = searchJ_103042310065(LJ, dari, ke, tanggal);
    if (jadwal == nil) {
        cout << "Data jadwal tidak ditemukan!" << endl;
        return;
    }
    newElm->jadwalP = jadwal;
}

void showPenumpang_103042310065(listPenumpang LP) {
    adrPenumpangP currentP = first(LP);
    cout << "=================PENUMPANG=================" << endl;
    while (currentP != nil) {
        cout << "Nama\t: " << info(currentP).nama << endl;
        cout << "NIK\t: " << info(currentP).nik << endl;
        cout << "Jenis Kelamin\t: " << info(currentP).jk << endl;
        cout << "Usia\t: " << info(currentP).usia << endl;
        cout << "Kode\t: " << info(currentP->jadwalP).kode << endl;
        currentP = next(currentP);
    }
    cout << "==========================================" << endl;
}

void reschedule_103042310065(listPenumpang &LP, listJadwal LJ, string NIK, string newDari, string newKe, string newTanggal) {
    adrPenumpangP currentP = first(LP);
    while (currentP != nil) {
        if (info(currentP).nik == NIK) {
            adrJadwalP jadwal = searchJ_103042310065(LJ, newDari, newKe, newTanggal);
            if (jadwal == nil) {
                cout << "Data jadwal tidak ditemukan!" << endl;
                return;
            }
            currentP->jadwalP = jadwal;
            return;
        }
        currentP = next(currentP);
    }
    cout << "Penumpang tidak ditemukan!" << endl;
}

void showAllListPenumpang_103042310065(listJadwal LJ, listPenumpang LP, string kode) {
    if (first(LP) == nil || first(LJ) == nil) {
        cout << "List kosong!" << endl;
        return;
    }
    
    adrPenumpangP currentP = first(LP);
    adrJadwalP jadwal = first(LJ);
    cout << "=================PENUMPANG=================" << endl;
    while (currentP != nil) {
        if (info(jadwal).kode == kode) {
            cout << "Nama\t: " << info(currentP).nama << endl;
            cout << "NIK\t: " << info(currentP).nik << endl;
            cout << endl;
        }
        currentP = next(currentP);
        jadwal = next(jadwal);
    }
    cout << "Total Penumpang\t: " << currentP - first(LP) << endl;
    cout << "==========================================" << endl;
}