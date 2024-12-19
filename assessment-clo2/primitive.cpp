#include "primitive.h"

void createGraph(Graph &G) {
  start(G) = nil;
}

adrNode createNode(nodetype data) {
  adrNode newNode;
  newNode = new ElmNode;
  info(newNode) = data;
  firstEdge(newNode) = nil;
  nextNode(newNode) = nil;
  return newNode;
}

adrEdge createEdge(edgetype data) {
  adrEdge newEdge;
  newEdge = new ElmEdge;
  info(newEdge) = data;
  nextEdge(newEdge) = nil;
  return newEdge;
}

void insertLastNode(G &Graph, adrNode P) {
  adrNode Q;

  if (start(Graph) == nil) {
    start(Graph) = P;
  } else {
    Q = start(Graph);
    while (nextNode(Q) != nil) {
      Q = nextNode(Q);
    }
    nextNode(Q) = P;
  }
}