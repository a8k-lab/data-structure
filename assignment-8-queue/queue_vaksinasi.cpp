#include "queue_vaksinasi.h"

void createQueue(Queue &Q) {
    head(Q) = nil;
    Q.tail = nil;
}

bool isEmpty(Queue Q) {
    return head(Q) == nil;
}

ElemQ *createElemQueue(string nama, int usia, string pekerjaan, int nomor_antrean) {
    ElemQ *P = new ElemQ;
    info(P).nama = nama;
    info(P).usia = usia;
    info(P).pekerjaan = pekerjaan;
    info(P).prioritas = (usia >= 60 || pekerjaan == "tenaga kesehatan");
    info(P).nomor_antrean = nomor_antrean;
    info(P).kondisi_darurat = false;
    next(P) = nil;
    return P;
}

void enqueue(Queue &Q, ElemQ *P) {
    if (isEmpty(Q)) {
        head(Q) = P;
        tail(Q) = P;
    } else if (info(P).prioritas) {
        if (!info(head(Q)).prioritas) {
            next(P) = head(Q);
            head(Q) = P;
        } else {
            ElemQ *temp = head(Q);
            while (next(temp) != nil && info(next(temp)).prioritas) {
                temp = next(temp);
            }
            next(P) = next(temp);
            next(temp) = P;
            if (next(P) == nil) {
                tail(Q) = P;
            }
        }
    } else {
        next(tail(Q)) = P;
        tail(Q) = P;
    }
}

void dequeue(Queue &Q, ElemQ *&P) {
    if (isEmpty(Q)) {
        P = nil;
        cout << "Semua warga telah terlayani." << endl;
    } else {
        P = head(Q);
        head(Q) = next(head(Q));
        if (head(Q) == nil) {
            tail(Q) = nil;
        }
        next(P) = nil;
    }
}

ElemQ *front(Queue Q) {
    return head(Q);
}

ElemQ *back(Queue Q) {
    return tail(Q);
}

int size(Queue Q) {
    int count = 0;
    ElemQ *temp = head(Q);
    while (temp != nil) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Non-Primitive

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Antrean kosong." << endl;
    } else {
        ElemQ *P = head(Q);
        cout << "Daftar Antrean:" << endl;
        while (P != nil) {
            cout << "Nama: " << P->info.nama << endl
                << "Usia: " << P->info.usia << endl
                << "Pekerjaan: " << P->info.pekerjaan << endl
                << "Prioritas: " << (P->info.prioritas ? "Ya" : "Tidak") << endl
                << "Nomor Antrean: " << P->info.nomor_antrean << endl;
            P = next(P);
            cout << "----------------------------" << endl;
        }
    }
}

void serveQueue(Queue &Q) {
    int count = 0;
    while (!isEmpty(Q) && count < 100) {
        ElemQ *P;
        dequeue(Q, P);

        cout << "Melayani warga: " << endl;
        cout << "Nama\t : " << P->info.nama << endl;
        cout << "Usia\t : " << P->info.usia << endl;
        cout << "Pekerjaan: " << P->info.pekerjaan << endl;
        cout << "Prioritas: " << (P->info.prioritas ? "Ya" : "Tidak") << endl;
        cout << "Vaksinasi berhasil." << endl;
        cout << "----------------------------" << endl;

        delete P;
        count++;
    }
    if (count == 100) {
        cout << "Kapasitas harian telah penuh." << endl;
    }
    if (!isEmpty(Q)) {
        cout << "Warga yang belum terlayani diminta kembali besok." << endl;
    }
}

void reassignQueue(Queue &Q) {
    cout << "Memindahkan warga dari Queue Tunggu ke antrean Prioritas atau Normal." << endl;

    Queue newQueue;
    createQueue(newQueue);

    ElemQ *temp = head(Q);
    while (temp != nil) {
        ElemQ *P = createElemQueue(info(temp).nama, info(temp).usia, info(temp).pekerjaan, info(temp).nomor_antrean);
        P->info.prioritas = info(temp).prioritas;
        enqueue(newQueue, P);
        temp = next(temp);
    }
    Q = newQueue;
}

void checkWaitingTime(Queue &Q, int waktu_sekarang) {
    cout << "Mengecek waktu tunggu warga dalam antrean Q." << endl;

    ElemQ *temp = head(Q);
    while (temp != nil) {
        int waktu_tunggu = waktu_sekarang - info(temp).waktu_daftar;
        if (waktu_tunggu > 120 && !info(temp).prioritas) {
            info(temp).prioritas = true;
        }
        temp = next(temp);
    }
    updatePriority(Q);
}

void emergencyHandle(Queue &Q, int nomor_antrean) {
    ElemQ *temp = head(Q);
    while (temp != nil) {
        if (info(temp).nomor_antrean == nomor_antrean) {
            info(temp).kondisi_darurat = true;
            break;
        }
        temp = next(temp);
    }
    if (temp == nil) {
        cout << "Warga dengan nomor antrean " << nomor_antrean << " tidak ditemukan." << endl;
    } else {
        updatePriority(Q);
    }
}

void updatePriority(Queue &Q) {
    cout << "Mengatur ulang antrean berdasarkan prioritas dan kondisi darurat." << endl;

    Queue newQueue;
    createQueue(newQueue);

    ElemQ *temp = head(Q);
    while (temp != nil) {
        ElemQ *P = createElemQueue(info(temp).nama, info(temp).usia, info(temp).pekerjaan, info(temp).nomor_antrean);
        P->info.prioritas = info(temp).prioritas;
        P->info.kondisi_darurat = info(temp).kondisi_darurat;

        if (info(P).kondisi_darurat) {
            next(P) = head(newQueue);
            head(newQueue) = P;
            if (tail(newQueue) == nil) tail(newQueue) = P;
        } else if (info(P).prioritas) {
            enqueue(newQueue, P);
        } else {
            if (isEmpty(newQueue)) {
                head(newQueue) = P;
                tail(newQueue) = P;
            } else {
                next(tail(newQueue)) = P;
                tail(newQueue) = P;
            }
        }
        temp = next(temp);
    }
    Q = newQueue;
}

ElemQ *findAndRemove(Queue &Q, int nomor_antrean) {
    ElemQ *P = head(Q);
    ElemQ *prev = nil;

    while (P != nil) {
        if (P->info.nomor_antrean == nomor_antrean) {
            if (prev == nil) {
                head(Q) = next(P);
            } else {
                prev->next = next(P);
            }
            if (P == Q.tail) {
                Q.tail = prev;
            }
            next(P) = nil;
            return P;
        }
        prev = P;
        P = next(P);
    }

    cout << "Warga dengan nomor antrean " << nomor_antrean << " tidak ditemukan." << endl;
    return nil;
}
