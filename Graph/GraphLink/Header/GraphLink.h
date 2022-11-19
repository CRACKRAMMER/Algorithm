#ifndef __GRAPHLINK_H__
#define __GRAPHLINK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define DEFAULT_VERTEX_SIZE 10
typedef char ElemType;

typedef struct Edge {
    int dest;
    struct Edge *link;
} Edge;

typedef struct Vertex {
    ElemType data;
    Edge *adj;
} Vertex;

typedef struct GraphLink {
    int MaxVertices;
    int NumVertices;
    int NumEdges;

    Vertex *NodeTable;
} GraphLink;

void InitGraphLink(GraphLink *graph);
int GetVertexPos(GraphLink *graph, ElemType data);
void ShowGraph(GraphLink *graph);
void InsertVertex(GraphLink *graph, ElemType data);
void InsertEdge(GraphLink *graph, ElemType v1, ElemType v2);

void RemoveVertex(GraphLink *graph, ElemType data);
void RemoveEdge(GraphLink *graph, ElemType v1, ElemType v2);
void DestroyGraph(GraphLink *graph);
int GetFirstNeighbor(GraphLink *graph, int pos);
int GetNextNeighbor(GraphLink *graph, int pv1, int pv2);

void DFSGraph(GraphLink *graph, ElemType data);
void BFSGraph(GraphLink *graph, ElemType data);

void TopologicalSort(GraphLink *graph);

#endif //__GRAPHLINK_H__
