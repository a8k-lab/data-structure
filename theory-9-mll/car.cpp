#include "car.h"

adrSales searchSales(MLL listSales, string nama) {
    adrSales S = first(listSales);
    while (S != nil) {
        if (info(S).nama == nama) {
            return S;
        }
        S = next(S);
    }
    return nil;
}

void insertLastSales(MLL &listSales, adrSales S) {
    adrSales last = first(listSales);
    if (last == nil) {
        first(listSales) = S;
    } else {
        while (next(last) != nil) {
            last = next(last);
        }
        next(last) = S;
        next(S) = nil;
    }
}

void createList(MLL &listSales) {
    first(listSales) = nil;
}

void newElmSales(Sales info, adrSales &S) {
    S = new ElmSales;
    next(S) = nil;
    nextJual(S) = nil;
    info(S) = info;
}

void newElmJual(int info, adrJual &J) {
    J = new ElmJual;
    next(J) = nil;
    info(J) = info;
}

void insertNewPenjualan(MLL &listSales, adrSales S, adrJual J) {
    adrJual last = nextJual(S);
    if (last == nil) {
        nextJual(S) = J;
    } else {
        while (next(last) != nil) {
            last = next(last);
        }
        next(last) = J;
        next(J) = nil;
    }
}

void deleteFirstPenjualan(MLL &listSales, adrSales S, adrJual &J) {
    if (first(listSales) == nil) {
        cout << "List kosong!" << endl;
        return;
    }
    if (next(first(listSales)) == nil) {
        S = first(listSales);
        first(listSales) = nil;
    } else {
        S = first(listSales);
        first(listSales) = next(S);
    }
}

void deleteLastPenjualan(MLL &listSales, adrSales S, adrJual &J) {
    if (first(listSales) == nil) {
        cout << "List kosong!" << endl;
        return;
    }
    if (next(first(listSales)) == nil) {
        S = first(listSales);
        first(listSales) = nil;
    } else {
        adrSales prec = first(listSales);
        while (next(prec) != nil) {
            prec = next(prec);
        }
        J = nextJual(prec);
        next(prec) = nil;
    }
}

void deleteAfterPenjualan(MLL &listSales, adrSales S, adrJual prec, adrJual &J) {
    if (first(listSales) == nil) {
        cout << "List kosong!" << endl;
        return;
    }
    if (next(first(listSales)) == nil) {
        S = first(listSales);
        first(listSales) = nil;
    } else {
        next(prec) = nil;
    }
}

void showDataSales(MLL listSales) {
    adrSales S = first(listSales);
    while (S != nil) {
        cout << info(S).nama << " " << info(S).gol << endl;
        S = next(S);
    }
}

void deletePenjualan(MLL &listSales) {
    // setting awal pointer sales
    adrSales S = first(listSales);

    //loop pointer sales menelusuri semua elemen sales
    while (S != nil) {
        //setting awal pointer penjualan
        adrJual J = nextJual(S);
        //loop pointer penjualan menelusuri semua elemen penjualan
        while (J != nil) {
            //Pengecekan apakah data penjualan saat ini kurang dari 3 atau tidak
            if (info(J) < 3) {
                //menghapus elemen penjualan
                adrJual prec = J;
                J = next(J);
                delete prec;
            } else {
                //mengganti elemen penjualan dengan elemen penjualan setelahnya
                J = next(J);
            }
        }
        //menghapus elemen sales
        adrSales prec = S;
        S = next(S);
        delete prec;
    }
}
