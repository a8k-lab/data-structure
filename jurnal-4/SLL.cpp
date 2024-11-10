#include "SLL.h"

void createList(List &L) {
    first(L) = nil;
}

adr allocate(infotype x) {
    adr P = new element;
    info(P) = x;
    next(P) = nil;
    return P;
}

void insertFirst(List &L, adr P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List &L, adr P) {
    adr q = first(L);
    while (next(q) != nil) {
        q = next(q);
    }
    next(q) = P;
}

void insertAfter(List &L, adr Prec, adr P) {
    adr q = first(L);
    while (q != Prec) {
        q = next(q);
    }
    next(q) = P;
}

void deleteFirst(List &L, adr &P) {
    P = first(L);
    first(L) = next(p);
}

void deleteLast(List &L, adr &P) {
    if (first(L) == nil) {
        P = nil;
        return;
    }
    if (first(L)->next == nil) {
        P = first(L);
        first(L) = nil;
        return;
    }
    adr q = first(L);
    while (next(q)->next != nil) {
        q = next(q);
    }
    P = next(q);
    next(q) = nil;
}

void deleteAfter(List &L, adr Prec, adr &P) {
    adr q = first(L);
    while (q != Prec) {
        q = next(q);
    }
    P = next(q);
    next(q) = nil;
}

void show(List L) {
    adr p = first(L);
    if (p != nil) {
        while (next(p) != nil) {
        cout << info(p) << ", ";
        p = next(p);
        }
        cout << info(p);
    }
    cout << endl;
}

adr findInfo(List L, infotype x) {
    adr p = first(L);
    while (p != nil) {
        if (info(p) == x) {
            return p;
        }
        p = next(p);
    }
    return nil;
}
