#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#define first(G) G.first
#define next(P) P->next
#define firstEdge(V) V->firstEdge
#define nil NULL

typedef struct Edge* adrEdge;
typedef struct Vertex* adrVertex;

struct Edge {
    char idVertex;
    int weight;
    adrEdge next;
};

struct Vertex {
    char id;
    adrVertex next;
    adrEdge firstEdge;
};

struct Graph {
    adrVertex first;
};

/**
 * Menghitung derajat masuk (in-degree) untuk simpul v
 */
int inDegree(Graph G, adrVertex V);

/**
 * Menghitung derajat keluar (out-degree) untuk simpul v
 */
int outDegree(Graph G, adrVertex V);

/**
 * Menghitung derajat simpul v
 */
int degree(Graph G, adrVertex V);

/**
 * Menghasilkan true jika G graf sederhana atau false jika bukan graf sederhana.
 * Graf sederhana tidak mengandung busur parallel. Pada graf berarah beberapa busur disebut busur parallel jika simpul awal dan simpul tujuannya sama
 */
bool isSimpleGraph(Graph G);

#endif // GRAPH_H_INCLUDED