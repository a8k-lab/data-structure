#include "tree.h"

adrNode newNode_103042310065(infotype x) {
    adrNode newNode = new node();
    info(newNode) = x;
    left(newNode) = nil;
    right(newNode) = nil;
    return newNode;
}

adrNode findNode_103042310065(adrNode root, infotype x) {
    if (root == nil || x == info(root)) {
        return root;
    }
    if (x > info(root)) {
        return findNode_103042310065(right(root), x);
    }
    return findNode_103042310065(left(root), x);
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

void printPreOrder_103042310065(adrNode root) {
    if (root == nil) {
        return;
    }
    cout << info(root) << " ";
    printPreOrder_103042310065(left(root));
    printPreOrder_103042310065(right(root));
}

void printDescendant_103042310065(adrNode root, infotype x) {
    adrNode foundNode = findNode_103042310065(root, x);
    if (foundNode == nil) {
        return;
    }
    if (left(foundNode) != nil) {
        cout << info(left(foundNode)) << " ";
        printDescendant_103042310065(left(foundNode), info(left(foundNode)));
    }
    if (right(foundNode) != nil) {
        cout << info(right(foundNode)) << " ";
        printDescendant_103042310065(right(foundNode), info(right(foundNode)));
    }
}

int sumNode_103042310065(adrNode root) {
    if (root == nil) {
        return 0;
    }
    return info(root) + sumNode_103042310065(left(root)) + sumNode_103042310065(right(root));
}

int countLeaves_103042310065(adrNode root) {
    if (root == nil) {
        return 0;
    }
    if (left(root) == nil && right(root) == nil) {
        return 1;
    }
    return countLeaves_103042310065(left(root)) + countLeaves_103042310065(right(root));
}

int heightTree_103042310065(adrNode root) {
    if (root == nil) {
        return 0;
    }
    return 1 + heightTree_103042310065(left(root));
}

void printInOrder_103042310065(adrNode root) {
    if (root == nil) {
        return;
    }
    printInOrder_103042310065(left(root));
    cout << info(root) << " ";
    printInOrder_103042310065(right(root));
}

void printPostOrder_103042310065(adrNode root) {
    if (root == nil) {
        return;
    }
    printPostOrder_103042310065(left(root));
    printPostOrder_103042310065(right(root));
    cout << info(root) << " ";
}

void printLeftMostNode_103042310065(adrNode root) {
    if (root == nil) {
        return;
    }
    if (left(root) == nil) {
        cout << info(root) << " ";
    } else {
        printLeftMostNode_103042310065(left(root));
    }
}

void printRightMostNode_103042310065(adrNode root) {
    if (root == nil) {
        return;
    }
    if (right(root) == nil) {
        cout << info(root) << " ";
    } else {
        printRightMostNode_103042310065(right(root));
    }
}

int countNode_103042310065(adrNode root) {
    if (root == nil) {
        return 0;
    }
    return 1 + countNode_103042310065(left(root)) + countNode_103042310065(right(root));
}

void printAncestor_103042310065(adrNode root, infotype x) {
    adrNode foundNode = findNode_103042310065(root, x);
    if (foundNode == nil) {
        return;
    }
    cout << info(foundNode) << " ";
    if (left(foundNode) != nil) {
        printAncestor_103042310065(left(foundNode), x);
    }
    if (right(foundNode) != nil) {
        printAncestor_103042310065(right(foundNode), x);
    }
}

int countInternalNode_103042310065(adrNode root) {
    if (root == nil) {
        return 0;
    }
    return countNode_103042310065(left(root)) + countNode_103042310065(right(root));
}

int depthNode_103042310065(adrNode root, infotype n) {
    if (root == nil) {
        return 0;
    }
    int leftDepth = depthNode_103042310065(left(root), n);
    int rightDepth = depthNode_103042310065(right(root), n);
    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    }
    return rightDepth + 1;
}

int levelNode_103042310065(adrNode root, infotype n) {
    if (root == nil) {
        return 0;
    }
    int leftLevel = levelNode_103042310065(left(root), n);
    int rightLevel = levelNode_103042310065(right(root), n);
    if (leftLevel > rightLevel) {
        return leftLevel + 1;
    }
    return rightLevel + 1;
}
