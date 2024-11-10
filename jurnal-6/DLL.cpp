#include "DLL.h"

void createList(List &L) {
    first(L) = nil;
    last(L) = nil;
}

address createElemen(infotype dataBaru) {
    address newP = new ElmList;
    if (newP != nil) {
        info(newP) = dataBaru;
        next(newP) = nil;
        prev(newP) = nil;
        return newP;
    }
    return nil;
}

void insertLast(List &L, address p) {
    if (first(L) == nil){
        first(L) = p;
        last(L) = p;
    } else {
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}

void insertAfter(address prec, address p) {
    next(p) = next(prec);
    prev(next(prec)) = p;
    next(prec) = p;
    prev(p) = prec;
}

void deleteFirst(List &L, address &p) {
    p = first(L);
    if (next(first(L)) == nil) {
        first(L) = nil;
        last(L) = nil;
    } else {
        first(L) = next(first(L));
        prev(first(L)) = nil;
        next(p) = nil;
    }
}

void deleteLast(List &L, address &p) {
    p = last(L);
    if (first(L) == last(L)) {
        first(L) = nil;
        last(L) = nil;
    } else {
        last(L) = prev(last(L));
        next(last(L)) = nil;
        prev(p) = nil;
    }
}

void deleteAfter(address prec, address &p) {
    p = next(prec);
    next(prec) = next(p);
    prev(next(p)) = prec;
    next(p) = nil;
    prev(p) = nil;
}

void printList(List L) {
    address p = first(L);
    while (p != nil) {
        cout << info(p).title << " " << info(p).url << " " << info(p).timestamp << " " << info(p).visitcount;
        cout << endl;
        p = next(p);
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void insertAscending(List &L, address P) {
    address q = first(L);
    while (q != nil) {
        if (info(P).visitcount < info(q).visitcount) {
            insertFirst(L, P);
            return;
        }
        q = next(q);
    }
    insertLast(L, P);
}

bool findElemen(List L, string X) {
    address p = first(L);
    while (p != nil) {
        if (info(p).title == X) {
            return true;
        }
        p = next(p);
    }
    return false;
}

int moreThanOnce(List L) {
    int count = 0;
    address p = first(L);
    while (p != nil) {
        if (info(p).visitcount > 1) {
            count++;
        }
        p = next(p);
    }
    return count;
}
