#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define nil NULL

typedef struct Driver infotype;
typedef struct ElmList *address;

struct Driver {
    string name;
    float rating;
};

struct ElmList {
    infotype info;
    address prev;
    address next;
};

struct List {
    address first;
    address last;
};

void createList(List &L);

address allocate(infotype Elm);

void insertLast(List &L, address P);

void deleteLast(List &L, address &P);

void showList(List L);

void resetList(List &L);

void splitList(List &L, List &A, List &B, float N);

#endif // DRIVER_H_INCLUDED










