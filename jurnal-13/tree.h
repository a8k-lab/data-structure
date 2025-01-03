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
typedef struct Node* adrNode;

struct Node {
    infotype info;
    adrNode left;
    adrNode right;
};

/* mengembalikan alamat dari suatu node hasil alokasi, dengan info adalah x dan left dan right adalah NULL */
adrNode newNode_103042310065(infotype x);

/** 
 * mengembalikan alamat dari node yang memiliki info sama dengan x, atau NULL apabila tidak ditemukan.
 * Catatan: implementasikan secara REKURSIF.
 */
adrNode findNode_103042310065(adrNode root, infotype x);

/**
 * I.S. terdefinisi root dari BST (mungkin NULL), dan pointer p yang berisi alamat node yang mau ditambahkan pada BST.
 * F.S. elemen yang ditunjuk oleh p ditambahkan sebagai node dari BST.
 * Catatan: implementasikan secara REKURSIF.
 */
void insertNode_103042310065(adrNode &root, adrNode p);

/** 
 * I.S. terdefinisi root dari BST (mungkin NULL).
 * F.S. menampilkan node dari BST secara Preorder atau dengan urutan root, left  dan right.
 * Catatan: implementasikan secara REKURSIF.
 */
void printPreOrder_103042310065(adrNode root);

/** 
 * I.S. terdefinisi suatu root dari BST (mungkin NULL), dan infotype x.
 * F.S. menampilkan subtree atau keturunan dari node yang memiliki info x.
 * Catatan: implementasikan secara REKURSIF.
 */
void printDescendant_103042310065(adrNode root, infotype x);

/** 
 * mengembalikan hasil penjumlahan semua info node yang terdapat pada BST.
 * Catatan: implementasikan secara REKURSIF.
 */
int sumNode_103042310065(adrNode root);

/** 
 * mengembalikan banyaknya daun atau node yang tidak memiliki anak dari BST.
 * Catatan: implementasikan secara REKURSIF.
 */
int countLeaves_103042310065(adrNode root);

/**
 * mengembalikan banyaknya edge dari suatu root menuju daun yang terjauh.
 * Catatan: implementasikan secara REKURSIF.
 */
int heightTree_103042310065(adrNode root);

void printInOrder_103042310065(adrNode root);

void printPostOrder_103042310065(adrNode root);

void printLeftMostNode_103042310065(adrNode root);

void printRightMostNode_103042310065(adrNode root);

int countNode_103042310065(adrNode root);

void printAncestor_103042310065(adrNode root, infotype x);

int countInternalNode_103042310065(adrNode root);

int depthNode_103042310065(adrNode root, infotype n);

int levelNode_103042310065(adrNode root, infotype n);

bool isComplete(adrNode root);

#endif // TREE_H_INCLUDED