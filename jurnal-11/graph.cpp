#include "graph.h"

void initGraph_103042310065(graph &G) {
    firstVertex(G) = nil;
}

void createVertex_103042310065(char newVertexID, adrVertex &newVertex) {
    newVertex = new vertex;
    newVertex->idVertex = newVertexID;
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
    cout << "Masukkan ID vertex/simpul (A-Z/a-z):" << endl;
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
        if (simpulID == current->idVertex) {
            return true;
        }
        current = nextVertex(current);
    }
    return false;
}

adrVertex searchVertex_103042310065(graph G, char simpulID) {
    adrVertex currentV = firstVertex(G);
    while (currentV != nil) {
        if (simpulID == currentV->idVertex) {
            return currentV;
        }
        currentV = nextVertex(currentV);
    }
    return nil;
}

void createEdge_103042310065(char simpulID, int weight, adrEdge &e) {
    e = new edge();
    e->destVertexId = simpulID;
    e->weight = weight;
    nextEdge(e) = nil;
}

void addEdge_103042310065(graph &G, char simpulIDAsal, char simpulIDTujuan, int weight) {
    adrVertex vAsal = searchVertex_103042310065(G, simpulIDAsal);
    adrEdge e = new edge();
    createEdge_103042310065(simpulIDTujuan, weight, e);
    if (firstEdge(vAsal) == nil) {
        firstEdge(vAsal) = e;
    } else {
        nextEdge(e) = firstEdge(vAsal);
        firstEdge(vAsal) = e;
    }
}

int outDegree_103042310065(graph G, char simpulID) {
    adrVertex currentV = firstVertex(G);
    adrEdge currentE = firstEdge(currentV);
    int outDegree = 0;
    if (currentV != nil) {
        currentE = firstEdge(currentV);
        while (currentE != nil) {
            outDegree++;
            currentE = nextEdge(currentE);
        }
        return outDegree;
    }
    return -1;
}

int inDegree_103042310065(graph G, char simpulID) {
    adrVertex currentV = firstVertex(G);
    adrEdge currentE = firstEdge(currentV);
    int inDegree = 0;
    if (currentV != nil) {
        while (currentV != nil) {
            currentE = firstEdge(currentV);
            while (currentE != nil) {
                if (simpulID == currentE->destVertexId) {
                    inDegree++;
                }
                currentE = nextEdge(currentE);
            }
            currentV = nextVertex(currentV);
        }
        return inDegree;
    }
    return -1;
}

int degree_103042310065(graph G, char simpulID) {
    return outDegree_103042310065(G, simpulID) + inDegree_103042310065(G, simpulID);
}
