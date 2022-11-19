#include "GraphLink.h"

int main(int argc, char *argv[]) {
    GraphLink graph;
    InitGraphLink(&graph);
    InsertVertex(&graph, 'A');
    InsertVertex(&graph, 'B');
    InsertVertex(&graph, 'C');
    InsertVertex(&graph, 'D');
    InsertVertex(&graph, 'E');
    InsertVertex(&graph, 'F');

    InsertEdge(&graph, 'A', 'B');
    InsertEdge(&graph, 'A', 'C');
    InsertEdge(&graph, 'A', 'D');
    InsertEdge(&graph, 'C', 'B');
    InsertEdge(&graph, 'D', 'E');
    InsertEdge(&graph, 'C', 'E');
    InsertEdge(&graph, 'F', 'E');
    InsertEdge(&graph, 'F', 'D');
    ShowGraph(&graph);

    // DFSGraph(&graph, 'A');
    // BFSGraph(&graph, 'A');
    TopologicalSort(&graph);
    DestroyGraph(&graph);
    return 0;
}
