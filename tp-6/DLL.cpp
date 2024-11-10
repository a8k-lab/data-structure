#include "DLL.h"

bool isEmpty(List L) {
    return first(L) == nil;
}

void createList(List &L) {
    first(L) = nil;
}

address createNewElmt(infotype X) {
    address newP = new elmList;
    if (newP != nil) {  // Jika alokasi berhasil
        info(newP) = X;
        next(newP) = nil;
        prev(newP) = nil;
        return newP;
    }
    return nil;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void insertAfter(List &L, address Prec, address P) {
    address q = first(L);
    while (q != Prec) {
        q = next(q);
    }
    next(q) = P;
}

void insertLast(List &L, address P) {
    address q = first(L);
    while (next(q) != nil) {
        q = next(q);
    }
    next(q) = P;
}

void deleteFirst(List &L, address &P) {
    P = first(L);
    first(L) = next(P);
}

void deleteAfter(List &L, address Prec, address &P) {
    address q = first(L);
    while (q != Prec) {
        q = next(q);
    }
    P = next(q);
    next(q) = nil;
}

void deleteLast(List &L, address &P) {
    if (first(L) == nil) {
        P = nil;
        return;
    }
    if (next(first(L)) == nil) {
        P = first(L);
        first(L) = nil;
        return;
    }
    address q = first(L);
    while (next(next(q)) != nil) {
        q = next(q);
    }
    P = next(q);
    next(q) = nil;
}

void concat(List L1, List L2, List &L3) {
    if (isEmpty(L1)) {
        L3 = L2;
        return;
    } else if (isEmpty(L2)) {
        L3 = L1;
        return;
    }
    
    L3 = L1;
    address P = first(L2);
    while (P != nil) {
        address newP = createNewElmt(info(P));
        insertLast(L3, newP);
        P = next(P);
    }
}

address findLagu(infotype Judul, List L) {
    address p = first(L);
    while (p != nil) {
        if (Judul == info(p)) {
            return p;
        }
        p = next(p);
    }
    return nil;
}

void removeLagu(infotype Judul, List &L) {
    address p = findLagu(Judul, L);
    if (p == nil) {
        cout << "Judul " << Judul << " tidak ditemukan." << endl;
        return;
    }
    deleteFirst(L, p);
}
