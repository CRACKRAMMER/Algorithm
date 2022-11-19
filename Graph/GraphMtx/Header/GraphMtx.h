#ifndef __GRAPHMTX_H__
#define __GRAPHMTX_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define DEFAULT_VERTICES_SIZE 10
#define ElemType char
#define MAX_COST 0x7FFFFFFF

typedef struct GraphMtx {
   int MaxVertices; 
   int NumVertices; 
   int NumEdges; 

   ElemType *VerticesList;
   int **Edge;
} GraphMtx;

void InitGraphMtx(GraphMtx *graph);
void ShowGraphMtx(GraphMtx *graph);
void InsertGraphMtx(GraphMtx *graph, ElemType data);
void InsertEdge(GraphMtx *graph, ElemType v1, ElemType v2, int cost);
void RemoveVertex(GraphMtx *graph, ElemType data);
void RemoveEdge(GraphMtx *graph, ElemType v1, ElemType v2);
void DestroyGraph(GraphMtx *graph);
int GetVertexPos(GraphMtx *graph, ElemType data);
int GetFirstNeighbor(GraphMtx *graph, int data);
int GetNextNeighbor(GraphMtx *graph, int pv1, int pv2);
int GetWeight(GraphMtx *graph, int v1, int v2);
void MinSpanTree_Prim(GraphMtx *graph, ElemType data);
void MinSpanTree_Kruskal(GraphMtx *graph);
void ShortestPath(GraphMtx *graph, int pos, int dist[], int path[]);

typedef struct Edge {
    int i;
    int j;
    int cost;
} Edge;

void MinSpanTree_Kruskal(GraphMtx *graph);

#endif //__GRAPHMTX_H__
