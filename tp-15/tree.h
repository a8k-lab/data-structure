#include <iostream>
using std::cout;
using std::endl;

#define info(node) node->info
#define left(node) node->left
#define right(node) node->right
#define nil NULL

typedef int infotype;
typedef struct Node* adrNode;

struct Node {
    infotype info;
    adrNode left;
    adrNode right;
};

/* mengembalikan alamat dari suatu node hasil alokasi, dengan info adalah x dan left dan right adalah NULL */
adrNode newNode_103042310065(infotype x);

/**
 * I.S. terdefinisi root dari BST (mungkin NULL), dan pointer p yang berisi alamat node yang mau ditambahkan pada BST.
 * F.S. elemen yang ditunjuk oleh p ditambahkan sebagai node dari BST.
 * Catatan: implementasikan secara REKURSIF.
 */
void insertNode_103042310065(adrNode &root, adrNode p);

/**
 * I.S. Terdefinisi root dari BST (mungkin NULL) dan pointer p yang menunjuk alamat node yang akan dihapus dari BST. Node p dipastikan berada di dalam BST.
 * F.S. Node yang ditunjuk oleh p dihapus dari BST. 
 * Struktur BST tetap terjaga, dengan menggantikan node yang dihapus sesuai aturan BST:
 * - Jika node yang dihapus adalah daun, langsung dihapus.
 * - Jika node memiliki satu anak, anak tersebut menggantikan node yang dihapus.
 * - Jika node memiliki dua anak, elemen pengganti diambil dari node dengan nilai terbesar di subtree kiri atau nilai terkecil di subtree kanan. 
 */
void deleteNode_103042310065(adrNode &root, adrNode &p);

/**
 * I.S. Terdefinisi root dari BST (mungkin NULL).
 * F.S. Semua elemen BST dicetak secara in-order (urut dari terkecil ke terbesar).
 */
void printInOrder_103042310065(adrNode root);

/**
 * I.S. Terdefinisi root dari BST (tidak NULL).
 * F.S. Mengembalikan pointer ke node dengan nilai terkecil pada subtree dengan root tersebut.
 * Catatan: Tidak ada perubahan pada struktur BST.
 */
adrNode findMin_103042310065(adrNode root);
