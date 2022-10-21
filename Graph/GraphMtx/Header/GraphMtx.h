#ifndef __GRAPHMTX_H__
#define __GRAPHMTX_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define DEFAULT_VERTICES_SIZE 10
#define ElemType char

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
void InsertEdge(GraphMtx *graph, ElemType v1, ElemType v2);
void RemoveVertex(GraphMtx *graph, ElemType data);
void RemoveEdge(GraphMtx *graph, ElemType v1, ElemType v2);
void DestroyGraph(GraphMtx *graph);
int GetFirstNeighbor(GraphMtx *graph, ElemType data);
int GetNextNeighbor(GraphMtx *graph, ElemType v1, ElemType v2);

#endif //__GRAPHMTX_H__
