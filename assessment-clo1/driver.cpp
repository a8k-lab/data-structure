#include "driver.h"

void createList(List &L) {
    first(L) = nil;
    last(L) = nil;
}

address allocate(infotype Elm) {
    address newElm = new ElmList;
    info(newElm) = Elm;
    prev(newElm) = nil;
    next(newElm) = nil;
    return newElm;
}

void insertLast(List &L, address P) {
    if (first(L) == nil) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void deleteLast(List &L, address &P) {
    P = last(L);
    if (first(L) == last(L)) {
        first(L) = nil;
        last(L) = nil;
    } else {
        last(L) = prev(last(L));
        next(last(L)) = nil;
        prev(P) = nil;
    }
}

void showList(List L) {
    address P = first(L);

    if (P == nil) {
        cout << "List masih kosong" << endl;
        return;
    }

    cout << "Daftar list driver: " << endl;
    while (P != nil) {
        cout << info(P).name << " - " << info(P).rating << endl;
        P = next(P);
    }
}

void resetList(List &L) {
    address P = last(L);

    while (P != nil) {
        cout << "Mereset data " << info(P).name << " dengan rating " << info(P).rating << endl;
        deleteLast(L, P);
        P = last(L);
    }
}

void splitList(List &L, List &A, List &B, float N) {
    address P = first(L);

    while (first(L) != nil) {
        if (info(P).rating < N) {
            insertLast(A, P);
            deleteLast(L, P);
        } else {
            insertLast(B, P);
            deleteLast(L, P);
        }
    }
}






