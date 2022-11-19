#include "GraphMtx.h"

int main(int argc, char *argv[]) {
    GraphMtx graph;
    InitGraphMtx(&graph);
    for(char i='A'; i<='E'; i++)
        InsertGraphMtx(&graph, i);

    // InsertEdge(&graph, 'A', 'B', 6);
    // InsertEdge(&graph, 'A', 'C', 1);
    // InsertEdge(&graph, 'A', 'D', 5);
    // InsertEdge(&graph, 'B', 'C', 5);
    // InsertEdge(&graph, 'C', 'D', 5);
    // InsertEdge(&graph, 'B', 'E', 3);
    // InsertEdge(&graph, 'C', 'E', 6);
    // InsertEdge(&graph, 'C', 'F', 4);
    // InsertEdge(&graph, 'D', 'F', 2);
    // InsertEdge(&graph, 'E', 'F', 6);

    InsertEdge(&graph, 'A', 'B', 10);
    InsertEdge(&graph, 'A', 'D', 30);
    InsertEdge(&graph, 'A', 'E', 100);
    InsertEdge(&graph, 'B', 'C', 50);
    InsertEdge(&graph, 'C', 'E', 10);
    InsertEdge(&graph, 'D', 'C', 20);
    InsertEdge(&graph, 'D', 'E', 60);
    ShowGraphMtx(&graph);

    // MinSpanTree_Prim(&graph, 'A');
    // MinSpanTree_Kruskal(&graph);
    int n = graph.NumVertices;
    int *dist = (int *)malloc(sizeof(int)*n);
    int *path = (int *)malloc(sizeof(int)*n);
    assert(dist!=NULL && path!=NULL);

    ShortestPath(&graph, 0, dist, path);
    for(int i=0; i<n; i++) {
        printf("dist[%d]:%d -- path[%d]:%d\n", i, dist[i], i, path[i]);
    }

    return 0;
}
