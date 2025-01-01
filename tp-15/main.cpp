#include "tree.h"

int main() {
    int x[9] = {8, 9, 12, 13, 15, 17, 7, 6, 4};
    // 1. Inisiasikan sebuah root BST
    adrNode root = nil, newNode = nil;

    // 2. Insert node pada BST
    for (int i = 0; i < 9; i++) {
        insertNode_103042310065(root, newNode_103042310065(x[i]));
    }

    printInOrder_103042310065(root);
    cout << endl;

    // 3. Hapus node pada BST dan tampilkan
    for (int i = 0; i < 9; i++) {
        newNode = newNode_103042310065(x[i]);
        deleteNode_103042310065(root, newNode);
        printInOrder_103042310065(root);
        cout << endl;
    }

    return 0;
}
