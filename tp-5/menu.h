#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
#include <iostream>
using namespace std;
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define nil NULL
typedef int infotype;
typedef struct element *adr;

struct element {
    infotype info;
    adr next;
};

struct List {
    adr first;
    adr last;
};

void createList(List &L);

adr allocate(infotype x);

void insertFirst(List &L, adr P);

void insertLast(List &L, adr P);

void show(List L);

adr findMin(List L);

void insertMiddle(List &L, int value);

int selectMenu();

#endif // SLL_H_INCLUDED
