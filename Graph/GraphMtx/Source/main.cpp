#include "GraphMtx.h"

int main(int argc, char *argv[]) {
    GraphMtx graph;
    InitGraphMtx(&graph);
    for(char i='A'; i<='E'; i++)
        InsertGraphMtx(&graph, i);

    InsertEdge(&graph, 'A', 'B');
    InsertEdge(&graph, 'A', 'D');
    InsertEdge(&graph, 'B', 'C');
    InsertEdge(&graph, 'B', 'E');
    InsertEdge(&graph, 'C', 'E');
    InsertEdge(&graph, 'C', 'D');
    ShowGraphMtx(&graph);

    RemoveVertex(&graph, 'C');
    ShowGraphMtx(&graph);

    int p = GetFirstNeighbor(&graph, 'A');

    return 0;
}
