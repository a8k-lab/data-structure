#include "tree.h"

int main() {
    // Membuat array x dengan nilai-nilai node yang akan disisipkan pada BST, dengan urutan acak
    int x[9] = {15, 4, 9, 17, 7, 8, 12, 13, 6};

    // 1. Inisiasikan sebuah root BST
    adrNode root = nil;

    // 2. insertNode pada BST
    for (int i = 0; i < 9; i++) {
        adrNode newNode = newNode_103042310065(x[i]);
        insertNode_103042310065(root, newNode);
    }

    // 3. Tampilkan node pada tree menggunakan fungsi printInOrder
    // Urutannya adalah = 4, 6, 7, 8, 9, 12, 13, 15, 17
    cout << endl << "In-Order\t: ";
    printInOrder_103042310065(root);
    cout << endl;

    // 4. Tampilkan mostLeftNode
    // Dalam kasus ini mostLeftNode adalah = 4
    cout << "Most Left Node\t: ";
    adrNode mostLeftNode = mostLeftNode_103042310065(root);
    cout << info(mostLeftNode) << endl;

    // 5. Tampilkan mostRightNode
    // Dalam kasus ini mostRightNode adalah = 17
    cout << "Most Right Node\t: ";
    adrNode mostRightNode = mostRightNode_103042310065(root);
    cout << info(mostRightNode) << endl;

    return 0;
}
