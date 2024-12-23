#include "graph.h"

void initGraph_103042310065(graph &G) {
    firstVertex(G) = nil;
}

void createVertex_103042310065(char newVertexID, adrVertex &newVertex) {
    newVertex = new vertex;
    newVertex->id = newVertexID;
    nextVertex(newVertex) = nil;
    firstEdge(newVertex) = nil;
}

void addVertex_103042310065(graph &G, char newVertexID) {
    adrVertex newVertex;
    createVertex_103042310065(newVertexID, newVertex);
    if (firstVertex(G) == nil) {
        firstVertex(G) = newVertex;
    } else {
        adrVertex current = firstVertex(G);
        while (nextVertex(current) != nil) {
            current = nextVertex(current);
        }
        nextVertex(current) = newVertex;
    }
}

void buildGraph_103042310065(graph &G) {
    char newVertexID;
    adrVertex newVertex;
    cout << "Masukkan ID vertex/simpul baru:" << endl;
    while (cin >> newVertexID) {
        if (
            (newVertexID >= 'A' && newVertexID <= 'Z')
            || (newVertexID >= 'a' && newVertexID <= 'z')
        ) {
            if (hasVertex_103042310065(G, newVertexID)) {
                cout << "Simpul dengan id " << newVertexID << " sudah ada!" << endl;
            } else {
                addVertex_103042310065(G, newVertexID);
            }
        } else {
            break;
        }
    }
}

bool hasVertex_103042310065(graph G, char simpulID) {
    adrVertex current = firstVertex(G);
    while (current != nil) {
        if (simpulID == current->id) {
            return true;
        }
        current = nextVertex(current);
    }
    return false;
}
