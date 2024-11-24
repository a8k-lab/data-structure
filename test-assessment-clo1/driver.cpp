#include "driver.h"

void createList(List &L) {
    first(L) = nil;
    last(L) = nil;
}

address allocate(infotype Elm) {
    address newElm = new ElmList;
    info(newElm) = Elm;
    next(newElm) = nil;
    prev(newElm) = nil;
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

void deleteLast(List &L, address &elm) {
    elm = last(L);
    if (first(L) == last(L)) {
        first(L) = nil;
        last(L) = nil;
    } else {
        last(L) = prev(last(L));
        next(last(L)) = nil;
        prev(elm) = nil;
    }
}

void showList(List L) {
    address elm = first(L);

    if (elm == nil) {
        cout << "List kosong" << endl;
        return;
    }

    int number = 1;
    cout << "List dari driver: " << endl;
    while (elm != nil) {
        cout << number << ". " << info(elm).name << " (rating " << info(elm).rating << ")" << endl;
        number++;
        elm = next(elm);
    }
    cout << endl;
}

void resetList(List &L) {
    address elm = last(L);
    while (elm != nil) {
        cout << "Mereset " << info(elm).name << " dengan rating " << info(elm).rating << endl;
        deleteLast(L, elm);
        elm = last(L);
    }
    cout << "Reset selesai" << endl;
}

void splitList(List &L, List &A, List &B, int N) {
    address elm = first(L);
    while (first(L) != nil) {
        if (info(elm).rating < N) {
            insertLast(A, elm);
            deleteLast(L, elm);
        } else {
            insertLast(B, elm);
            deleteLast(L, elm);
        }
    }
}
