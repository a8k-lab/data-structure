#include "graph.h"

int main() {
    graph G;
    adrVertex currentV;
    int count = 1;

    initGraph_103042310065(G);
    buildGraph_103042310065(G);

    addEdge_103042310065(G, 'A', 'D', 40);
    addEdge_103042310065(G, 'A', 'C', 12);
    addEdge_103042310065(G, 'B', 'A', 10);
    addEdge_103042310065(G, 'C', 'B', 12);
    addEdge_103042310065(G, 'C', 'D', 32);
    addEdge_103042310065(G, 'E', 'A', 7);

    currentV = firstVertex(G);
    cout << "Graph yang dibuat:" << endl;
    while (currentV != nil) {
        cout << endl << count << " ==================" << endl;
        cout << "Vertex\t\t: " << currentV->idVertex << endl;
        cout << "Out Degree\t: " << outDegree_103042310065(G, currentV->idVertex) << endl;
        cout << "In Degree\t: " << inDegree_103042310065(G, currentV->idVertex) << endl;
        cout << "Degree\t\t: " << degree_103042310065(G, currentV->idVertex) << endl;
        cout << "====================" << endl;
        currentV = nextVertex(currentV);
        count++;
    }
}
