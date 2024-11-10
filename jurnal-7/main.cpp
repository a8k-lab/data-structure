#include "stack_character.h"

int main() {
    stack S1, S2, S3;
    infotype xpop;

    createStack(S1);
    printInfo(S1);

    push(S1, 'E');
    printInfo(S1);

    push(S1, 'T');
    printInfo(S1);

    push(S1, 'U');
    printInfo(S1);

    pop(S1, xpop);
    printInfo(S1);

    cout << endl << "Data diurutkan ascending:" << endl;
    ascending(S1);
    printInfo(S1);
    cout << endl << "Data diurutkan descending:" << endl;
    descending(S1);
    printInfo(S1);

    createStack(S2);
    string kalimat = "Hai kamu!!!";
    cout <<endl<< "\'Hai kamu!!!\' di dalam stack:" <<endl;
    stringToStack(S2,kalimat);
    printInfo(S2);
    cout << endl << "Data diurutkan ascending:" << endl;
    ascending(S2);
    printInfo(S2);
    cout << endl << "Data diurutkan descending:" << endl;
    descending(S2);
    printInfo(S2);

    createStack(S3);
    cout <<endl<< "Membalik urutan elemen " <<endl;
    string input;

    cout << "Masukkan string: ";
    // Inputkan “IFLAB 2024/2025”
    getline(cin, input); // Menggunakan getline untuk membaca string dengan spasi

    stringToStack(S3, input);
    cout << endl << "Data sebelum dibalik:";
    printInfo(S3);
    cout << endl;

    reverseStack(S3);
    cout << "Data setelah dibalik:";
    printInfo(S3);
    cout << endl;

    return 0;
}
