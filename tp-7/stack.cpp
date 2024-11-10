#include "stack.h"

void createStack(stack &S) {
    Top(S) = 0;
}

bool isEmpty(stack S) {
    return Top(S) == 0;
}

bool isFull(stack S) {
    return Top(S) == 15;
}

void push(stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh." << endl;
    } else {
        Top(S)++;
        info(S)[Top(S)] = x;
    }
}

infotype pop(stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return 0;
    } else {
        infotype x = info(S)[Top(S)];
        Top(S)--;
        return x;
    }
}

void printInfo(stack S) {
    for (int i = 1; i <= Top(S); i++) {
        cout << info(S)[i] << " ";
    }
    cout << endl;
}
