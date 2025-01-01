#include "tree.h"

adrNode newNode_103042310065(infotype x) {
    adrNode newNode = new Node();
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

void deleteNode_103042310065(adrNode &root, adrNode &p) {
    if (root == nil) {
        return;
    }
    adrNode temp;
    if (info(p) < info(root)){
        deleteNode_103042310065(left(root), p);
    } else if (info(p) > info(root)){
        deleteNode_103042310065(right(root), p);
    } else{
        if (left(root) == nil && right(root) == nil){
            delete root;
            root = nil;
        } else if (left(root) == nil){
            temp = root;
            root = right(root);
            delete temp;
        } else if (right(root) == nil){
            temp = root;
            root = left(root);
            delete temp;
        } else {
            temp = findMin_103042310065(right(root));
            info(root) = info(temp);
            deleteNode_103042310065(right(root), temp);
        }
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

adrNode findMin_103042310065(adrNode root) {
    if (root == nil || left(root) == nil) {
        return root;
    }
    return findMin_103042310065(left(root));
}
