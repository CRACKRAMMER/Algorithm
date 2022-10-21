#include "GraphMtx.h"

void InitGraphMtx(GraphMtx *graph) {
    graph->MaxVertices = DEFAULT_VERTICES_SIZE;
    graph->NumEdges = graph->NumVertices = 0;
    
    graph->VerticesList = (ElemType *)malloc(sizeof(ElemType) * graph->MaxVertices);
    assert(graph->VerticesList != NULL);
    graph->Edge = (int **)malloc(sizeof(int*)*graph->MaxVertices);
    assert(graph->Edge != NULL);

    for(int i=0; i<graph->MaxVertices; i++) {
        graph->Edge[i] = (int *)malloc(sizeof(int)*graph->MaxVertices);
        assert(graph->Edge[i] != NULL);
    }

    for(int i=0; i<graph->MaxVertices; i++) {
        for(int j=0; j<graph->MaxVertices; j++) {
            graph->Edge[i][j] = 0;
        }
    }
}

void ShowGraphMtx(GraphMtx *graph) {
    printf(" ");
    for(int i=0; i<graph->NumVertices; i++) {
        printf("\t%c", graph->VerticesList[i]);
    }
    printf("\n");
    for(int i=0; i<graph->NumVertices; i++) {
        printf("%c", graph->VerticesList[i]);
        for(int j=0; j<graph->NumVertices; j++) {
            printf("\t%d", graph->Edge[i][j]);
        }
        printf("\n");
    }
}

void InsertGraphMtx(GraphMtx *graph, ElemType data) {
    graph->VerticesList[graph->NumVertices++] = data;
}

int GetVertexPos(GraphMtx *graph, ElemType data) {
    for(int i=0; i<graph->NumVertices; i++) {
        if(graph->VerticesList[i] == data) {
            return i;
        }
    }
    return -1;
}

void InsertEdge(GraphMtx *graph, ElemType v1, ElemType v2) {
   int pv1 = GetVertexPos(graph, v1); 
   int pv2 = GetVertexPos(graph, v2); 

   if(pv1==-1 || pv2==-1 || pv1 == pv2)
       return;

   graph->Edge[pv1][pv2] = graph->Edge[pv2][pv1] = 1;
   graph->NumEdges++;
}

void RemoveVertex(GraphMtx *graph, ElemType data) {
    int pos = GetVertexPos(graph, data);
    if(data == -1)
        return;

    for(int i=pos; i<graph->NumVertices-1; i++) {
        graph->VerticesList[i] = graph->VerticesList[i+1];
    }

    int edge_num=0;
    for(int i=0; i<graph->NumVertices; i++) {
        edge_num += graph->Edge[pos][i];
    }

    for(int i=pos; i<graph->NumVertices-1; i++) {
        for(int j=0; j<graph->NumVertices; j++) {
            graph->Edge[i][j] = graph->Edge[i+1][j];
        }
    }

    for(int i=pos; i<graph->NumVertices-1; i++) {
        for(int j=0; j<graph->NumVertices; j++) {
            graph->Edge[j][i] = graph->Edge[j][i+1];
        }
    }
    graph->NumVertices--;
    graph->NumEdges -= edge_num;
}

void RemoveEdge(GraphMtx *graph, ElemType v1, ElemType v2) {
   int pv1 = GetVertexPos(graph, v1); 
   int pv2 = GetVertexPos(graph, v2); 
   if(pv1==-1 || pv2==-1 || pv1 == pv2)
       return;
   graph->Edge[pv1][pv2] = graph->Edge[pv2][pv1] = 0;

}

void DestroyGraph(GraphMtx *graph) {
    free(graph->VerticesList);
    for(int i = 0; i<graph->NumVertices; i++) {
        free(graph->Edge[i]);
    }
    free(graph->Edge);
    graph->Edge = (int**)0;
    graph->VerticesList = NULL;
    graph->MaxVertices = graph->NumEdges = graph->NumVertices = 0;
}

int GetFirstNeighbor(GraphMtx *graph, ElemType data) {
    int pos = GetVertexPos(graph, data);
    if(pos == -1)
        return -1;

    for(int i=0; i<graph->NumVertices; i++) {
        if(graph->Edge[pos][i] == 1)
            return i;
    }
    return -1;
}

int GetNextNeighbor(GraphMtx *graph, ElemType v1, ElemType v2) {
    int pv1 = GetVertexPos(graph, v1);
    int pv2 = GetVertexPos(graph, v2);
    if(pv1 == -1 || pv2 == -1)
        return -1;

    for(int i=pv2; i<graph->NumVertices; i++) {
        if(graph->Edge[pv1][i] == 1)
            return i;
    }
    return -1;
}
