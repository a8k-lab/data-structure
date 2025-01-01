#include "tree.h"

int main() {
    int x[9] = {5, 3, 9, 10, 4, 7, 1, 8, 6};
    adrNode root = nil;
    int totalInfo, totalLeaves, treeHeight;

    cout << "================================================================================" << endl;
    /* Tampilkan isi dari array */
    for (int i = 0; i < 9; i++) {
        cout << x[i] << " ";
    }

    /* 1. Tambahkan setiap elemen array x kedalam BST secara berurutan */
    /* sehingga dihasilkan BST seperti Gambar 1, gunakan looping*/
    for (int i = 0; i < 9; i++) {
        insertNode_103042310065(root, newNode_103042310065(x[i]));
    }

    /* 2. Tampilkan node dari BST secara Pre-Order */
    printf("\n");
    printf("\nPre Order\t\t: ");
    printPreOrder_103042310065(root);

    /* 3. Tampilkan keturunan dari node 9*/
    printf("\n");
    printf("\nDescendent of Node 9\t: ");
    printDescendant_103042310065(root, 9);

    /* 4. Tampilkan total info semua node pada BST */
    printf("\n\n");
    printf("Sum of BST Info\t\t: ");
    totalInfo = sumNode_103042310065(root);
    cout << totalInfo << endl;

    /* 5. Tampilkan banyaknya daun dari BST */
    printf("Number of Leaves\t: ");
    totalLeaves = countLeaves_103042310065(root);
    cout << totalLeaves << endl;

    /* 4. Tampilkan Tinggi dari Tree*/
    printf("Height of Tree\t\t: ");
    treeHeight = heightTree_103042310065(root);
    cout << treeHeight << endl;

    cout << "================================================================================" << endl;

    return 0;
}
