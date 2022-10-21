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
    InsertVertex(&graph, 'G');
    InsertVertex(&graph, 'H');

    InsertEdge(&graph, 'A', 'B');
    InsertEdge(&graph, 'A', 'C');
    InsertEdge(&graph, 'B', 'D');
    InsertEdge(&graph, 'B', 'E');
    InsertEdge(&graph, 'D', 'H');
    InsertEdge(&graph, 'E', 'H');
    InsertEdge(&graph, 'C', 'F');
    InsertEdge(&graph, 'C', 'G');
    InsertEdge(&graph, 'F', 'G');
    ShowGraph(&graph);
    // RemoveEdge(&graph, 'A', 'C');
    // RemoveVertex(&graph, 'C');
    // ShowGraph(&graph);

    DFSGraph(&graph, 'A');
    BFSGraph(&graph, 'A');
    DestroyGraph(&graph);
    return 0;
}
