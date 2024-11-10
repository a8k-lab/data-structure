#ifndef STACK_CHARACTER_H_INCLUDED
#define STACK_CHARACTER_H_INCLUDED
#include <iostream>
using namespace std;
#define Top(S) S.Top
#define info(S) S.info
typedef char infotype;
const int MAXSTACK = 10;
struct stack {
    infotype info[MAXSTACK];
    int Top;
};

// F.S. terbentuk stack dengan Top = 0
void createStack(stack &S);

// Mengembalikan nilai true jika stack kosong
bool isEmpty(stack S);

// Mengembalikan nilai true jika stack penuh
bool isFull(stack S);

// I.S. mungkin penuh
// F.S. menambahkan elemen pada stack dengan nilai xpush, top = top + 1
void push(stack &S, infotype xpush);

// I.S. mungkin kosong
// F.S. mengeluarkan elemen pada stack dengan nilai xpop, top = top - 1
void pop(stack &S, infotype &xpop);

// I.S. stack mungkin kosong
// F.S. Jika stack tidak kosong, maka menampilkan semua info yang ada pada stack
void printInfo(stack S);

// procedure ascending dan procedure descending yang masing-masing membuat info stack terurut menaik dan menurun
void ascending(stack &S);
void descending(stack &S);
// procedure stringToStack untuk menerima masukkan berupa string yang setiap karakternya akan diinputkan ke dalam stack
void stringToStack(stack &S, const string &str);
// procedure reverseStack untuk membalik urutan elemen dalam suatu stack
void reverseStack(stack &S);

#endif // STACK_CHARACTER_H_INCLUDED
