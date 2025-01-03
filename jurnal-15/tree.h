#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
using std::cout;
using std::endl;

#define info(node) node->info
#define left(node) node->left
#define right(node) node->right
#define nil NULL

typedef int infotype;
typedef struct node* adrNode;

struct node {
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
 * I.S. terdefinisi root dari BST (mungkin NULL).
 * F.S. menampilkan node dari BST secara InOrder atau dengan urutan left, root dan right.
 */
void printInOrder_103042310065(adrNode root);

/**
 * Mengembalikan alamat node paling kiri (most-left node) dalam BST. Catatan: implementasikan secara REKURSIF
 */
adrNode mostLeftNode_103042310065(adrNode root);

/**
 * Mengembalikan alamat node paling kanan (most-right node) dalam BST. Catatan: implementasikan secara REKURSIF
 */
adrNode mostRightNode_103042310065(adrNode root);

#endif // TREE_H_INCLUDED