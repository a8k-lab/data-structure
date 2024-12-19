#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <iostream>
using namespace std;

#define start(L) L.start
#define last(L) L.last
#define nextEdge(P) P->nextEdge
#define nextNode(P) P->nextNode
#define firstEdge(P) P->firstEdge
#define info(P) P->info
#define nil NULL

typedef struct Node nodetype;
typedef struct ElmNode *adrNode;
typedef struct Edge edgetype;
typedef struct ElmEdge *adrEdge;

struct Graph {
  adrNode start;
};

struct Node {
  string id;
  string name;
  int followers;
  int following;
};

struct ElmNode {
  nodetype info;
  adrNode nextNode;
  adrEdge firstEdge;
};

struct G {
  adrNode start;
  adrNode last;
};

struct Edge {
  string id;
  string name;
  int followers;
  int following;
};

struct ElmEdge {
  edgetype info;
  adrNode nextEdge;
};

struct EdgeList {
  adrEdge start;
};

void createGraph(G &Graph);

// dihasilkan pointer elementNode yang berisi data. Jumlah follower dan following di set 0
adrNode createNode(nodetype data);

// I.S Terdefinisi sebuah graf yang mungkin kosong dan sebuah pointer elementNode
// F.S Element node menjadi element terakhir pada graf
void insertLastNode(G &Graph, adrNode node);

#endif // PRIMITIVE_H