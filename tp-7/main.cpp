#include "stack.h"

int main() {
    stack sLengkap, sPop, tempStack;
    createStack(sLengkap);
    createStack(sPop);
    createStack(tempStack);  // stack penampungan sementara

    string kata = "HALOBANDUNG";
    for (int i = 0; i < kata.length(); i++) {
        push(sLengkap, kata[i]);
    }

    printInfo(sLengkap);

    // Pindahkan 7 elemen pertama dari sLengkap ke sPop dengan urutan yang benar
    for (int i = 0; i < 7; i++) {
        push(tempStack, pop(sLengkap));  // Pindahkan ke tempStack untuk membalik urutannya
    }

    // Sekarang pindahkan dari tempStack ke sPop agar urutannya benar
    while (!isEmpty(tempStack)) {
        push(sPop, pop(tempStack));
    }

    printInfo(sPop);

    return 0;
}
