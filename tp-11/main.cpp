#include "graph.h"

int main() {
    graph newGraph;

    initGraph_103042310065(newGraph);
    buildGraph_103042310065(newGraph);

    cout << "Graph yang dibuat:" << endl;
    adrVertex current = firstVertex(newGraph);
    while (current != nil) {
        cout << current->id << " ";
        current = nextVertex(current);
    }
    cout << endl;

    return 0;
}
