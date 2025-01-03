#include "tree.h"

int main() {
    int x[12] = {6,3,8,1,5,7,9,0,2,4,15,11};
    /* Tampilkan isi dari array */
    for (int i = 0; i < 12; i++) {
        cout << x[i] << " ";
    }

    /* 1. Tambahkan setiap elemen array x kedalam BST secara berurutan */
    /* sehingga dihasilkan BST seperti Gambar 1, gunakan looping*/
    adrNode root = nil;
    for (int i = 0; i < 12; i++) {
        adrNode newNode = newNode_103042310065(x[i]);
        insertNode_103042310065(root, newNode);
    }

    /* 2. Tampilan node dari BST secara In-Order, Pre-Order, dan Post-Order*/
    cout << endl << "In-Order\t: ";
    printInOrder_103042310065(root);
    cout << endl << "Pre-Order\t: ";
    printPreOrder_103042310065(root);
    cout << endl << "Post-Order\t: ";
    printPostOrder_103042310065(root);
    cout << endl;

    /* 3. Menampilkan node paling kiri dan kanan dari BST*/
    cout << "Left Most Node\t: ";
    printLeftMostNode_103042310065(root);
    cout << endl << "Right Most Node\t: ";
    printRightMostNode_103042310065(root);
    cout << endl;

    /* 4. Tampilkan leluhur keturuan dari node 3*/
    cout << "Descendant of 3\t: ";
    printDescendant_103042310065(root, 3);
    cout << endl;

    /* 5. Tampilkan total info semua node pada BST */ 
    cout << "Sum of BST Info\t: ";
    cout << sumNode_103042310065(root) << endl;

    /* 6. Tampilkan banyak node dari BST */ 
    cout << "Number of Node\t: ";
    cout << countNode_103042310065(root) << endl;

    /* 7. Tampilkan banyaknya daun dari BST */ 
    cout << "Number of Leaves: ";
    cout << countLeaves_103042310065(root) << endl;

    /* 8. Tampilkan Tinggi dari Tree*/ 
    cout << "Height of Tree\t: ";
    cout << heightTree_103042310065(root) << endl;

    /* 9. Menampilkan ancestor dari node 3 */
    cout << "Ancestor of 3\t: ";
    printAncestor_103042310065(root, 3);
    cout << endl;

    /* 10. Menampilkan banyaknya node yang minimal memiliki satu anak dari BST */
    cout << "Internal Node\t: ";
    cout << countInternalNode_103042310065(root) << endl;

    /* 11. Menampilkan kedalaman dari node 3 */
    cout << "Depth of 3\t: ";
    cout << depthNode_103042310065(root, 3) << endl;

    /* 12. Menampilkan kedalaman dari node 3 */
    cout << "Level of 3\t: ";
    cout << levelNode_103042310065(root, 3) << endl;

    return 0;
}
