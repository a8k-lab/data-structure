#include "graph.h"

int inDegree(Graph G, adrVertex V) {
    int count = 0;
    adrVertex P = first(G);
    while (P != nil) {
        adrEdge E = firstEdge(P);
        while (E != nil) {
            if (E->idVertex == V->id) {
                count++;
            }
            E = next(E);
        }
        P = next(P);
    }
    return count;
}

int outDegree(Graph G, adrVertex V) {
    int count = 0;
    adrEdge E = firstEdge(V);
    while (E != nil) {
        count++;
        E = next(E);
    }
    return count;
}

int degree(Graph G, adrVertex V) {
    return inDegree(G, V) + outDegree(G, V);
}

bool isSimpleGraph(Graph G) {
    adrVertex P = first(G);
    while (P != nil) {
        adrEdge E1 = firstEdge(P);
        while (E1 != nil) {
            adrEdge E2 = next(E1);
            while (E2 != nil) {
                if (E1->idVertex == E2->idVertex) {
                    return false;
                }
                E2 = next(E2);
            }
            E1 = next(E1);
        }
        P = next(P);
    }
    return true;
}

// bool isSimpleGraph(Graph G) {
//     adrVertex current = first(G);
//     while (current != nil) {
//         if (outDegree(G, current) != 1) {
//             return false;
//         }
//         current = next(current);
//     }
//     return true;
// }
