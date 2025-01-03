#include "tree.h"

adrNode newNode_103042310065(infotype x) {
    adrNode newNode = new node();
    info(newNode) = x;
    left(newNode) = nil;
    right(newNode) = nil;
    return newNode;
}

void insertNode_103042310065(adrNode &root, adrNode p) {
    if (root == nil) {
        root = p;
        return;
    }

    if (info(p) < info(root)) {
        insertNode_103042310065(left(root), p);
    } else {
        insertNode_103042310065(right(root), p);
    }
}

void printInOrder_103042310065(adrNode root) {
    if (root == nil) {
        return;
    }
    printInOrder_103042310065(left(root));
    cout << info(root) << " ";
    printInOrder_103042310065(right(root));
}

adrNode mostLeftNode_103042310065(adrNode root) {
    if (root == nil) {
        return nil;
    }
    if (left(root) == nil) {
        return root;
    }
    return mostLeftNode_103042310065(left(root));
}

adrNode mostRightNode_103042310065(adrNode root) {
    if (root == nil) {
        return nil;
    }
    if (right(root) == nil) {
        return root;
    }
    return mostRightNode_103042310065(right(root));
}
