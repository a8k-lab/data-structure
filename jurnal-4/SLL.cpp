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
    while (q->next != nil) {
        q = q->next;
    }
    q->next = P;
}

void insertAfter(List &L, adr Prec, adr P) {
    adr q = first(L);
    while (q != Prec) {
        q = q->next;
    }
    q->next = P;
}

void deleteFirst(List &L, adr &P) {
    P = first(L);
    first(L) = P->next;
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
    while (q->next->next != nil) {
        q = q->next;
    }
    P = q->next;
    q->next = nil;
}

void deleteAfter(List &L, adr Prec, adr &P) {
    adr q = first(L);
    while (q != Prec) {
        q = q->next;
    }
    P = q->next;
    q->next = nil;
}

void show(List L) {
    adr p = first(L);
    if (p != nil) {
        while (p->next != nil) {
        cout << info(p) << ", ";
        p = p->next;
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
        p = p->next;
    }
    return nil;
}
