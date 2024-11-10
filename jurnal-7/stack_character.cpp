#include "stack_character.h"

void createStack(stack &S) {
    Top(S) = 0;
}

bool isEmpty(stack S) {
    return Top(S) == 0;
}

bool isFull(stack S) {
    return Top(S) == MAXSTACK;
}

void push(stack &S, infotype x) {
    if (!isFull(S)) {
        Top(S)++;
        info(S)[Top(S)] = x;
    }
}

void pop(stack &S, infotype &x) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
    } else {
        x = info(S)[Top(S)];
        Top(S)--;
    }
}

void printInfo(stack S) {
    for (int i = 1; i <= Top(S); i++) {
        cout << info(S)[i] << " ";
    }
    cout << endl;
}

void ascending(stack &S) {
    infotype temp;
    for (int i = 1; i < Top(S); i++) {
        for (int j = 1; j <= Top(S) - i; j++) {
            // Bandingkan elemen di posisi j dan j+1
            if (info(S)[j] > info(S)[j + 1]) {
                // Tukar elemen jika dalam urutan yang salah
                temp = info(S)[j];
                info(S)[j] = info(S)[j + 1];
                info(S)[j + 1] = temp;
            }
        }
    }
}

void descending(stack &S) {
    infotype temp;
    for (int i = 1; i < Top(S); i++) {
        for (int j = 1; j <= Top(S) - i; j++) {
            // Bandingkan elemen di posisi j dan j+1
            if (info(S)[j] < info(S)[j + 1]) {
                // Tukar elemen jika dalam urutan yang salah
                temp = info(S)[j];
                info(S)[j] = info(S)[j + 1];
                info(S)[j + 1] = temp;
            }
        }
    }
}

void stringToStack(stack &S, const string &str) {
    for (int i = 0; i < str.length(); i++) {
        push(S, str[i]);
    }
}

void reverseStack(stack &S) {
    int temp;
    for (int i = 1; i <= Top(S)/2; i++) {
        temp = info(S)[i];
        info(S)[i] = info(S)[Top(S) - i + 1];
        info(S)[Top(S) - i + 1] = temp;
    }
}
