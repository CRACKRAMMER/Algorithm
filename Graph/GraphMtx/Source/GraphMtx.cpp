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
            if(i == j)
                graph->Edge[i][j] = 0;
            else
                graph->Edge[i][j] = MAX_COST;
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
            if(graph->Edge[i][j] == MAX_COST)
                printf("\t@");
            else
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

void InsertEdge(GraphMtx *graph, ElemType v1, ElemType v2, int cost) {
   int pv1 = GetVertexPos(graph, v1); 
   int pv2 = GetVertexPos(graph, v2); 

   if(pv1==-1 || pv2==-1 || pv1 == pv2)
       return;

   // graph->Edge[pv1][pv2] = graph->Edge[pv2][pv1] = cost;
   graph->Edge[pv1][pv2] = cost;
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

int GetFirstNeighbor(GraphMtx *graph, int pos) {
    if(pos == -1)
        return -1;

    for(int i=0; i<graph->NumVertices; i++) {
        if(graph->Edge[pos][i] == 1)
            return i;
    }
    return -1;
}

int GetNextNeighbor(GraphMtx *graph, int pv1, int pv2) {
    if(pv1 == -1 || pv2 == -1)
        return -1;

    for(int i=pv2; i<graph->NumVertices; i++) {
        if(graph->Edge[pv1][i] == 1)
            return i;
    }
    return -1;
}

int GetWeight(GraphMtx *graph, int v1, int v2) {
    if(v1==-1||v2==-1) {
        return MAX_COST;
    }
    return graph->Edge[v1][v2];
}

void MinSpanTree_Prim(GraphMtx *graph, ElemType data) {
    int n = graph->NumVertices;
    int *lowcoat = (int *)malloc(sizeof(int)*n);
    int *mst = (int *)malloc(sizeof(int)*n);
    assert(mst!=NULL && lowcoat!=NULL);

    int k = GetVertexPos(graph, data);
    for(int i=0; i<n; i++) {
        lowcoat[i] = graph->Edge[k][i];
        mst[i] = k;
    }

    int min, min_index;
    for(int i=0; i<n-1; i++) {
        min = MAX_COST;
        min_index = -1;
        for(int j=0; j<n; j++) {
            if(lowcoat[j]!=0 && lowcoat[j]<min) {
                min = lowcoat[j];
                min_index = j;
            }
        }

        if(min_index == -1)
            break;

        printf("%c-->%c : %d\n", graph->VerticesList[mst[min_index]], graph->VerticesList[min_index], min);
        for(int j=0; j<n; j++) {
            int weight = graph->Edge[min_index][j];
            if(weight < lowcoat[j]) {
                lowcoat[j] = weight;
                mst[j] = min_index;
            }
        }
    }
}

int cmp(const void *edge1, const void *edge2) {
    return (((Edge*)edge1)->cost - ((Edge*)edge2)->cost);
}

bool Is_Same(int *father, int i, int j) {
    while(father[i] != i) {
        i = father[i];
    }

    while(father[j] != j) {
        j = father[j];
    }

    return i==j;
}

void Mark_Same(int *father, int i, int j) {
    while(father[i] != i) {
        i = father[i];
    }

    while(father[j] != j) {
        j = father[j];
    }

    father[j] = i;
}

void MinSpanTree_Kruskal(GraphMtx *graph) {
    int n = graph->NumVertices;
    Edge *edge = (Edge *)malloc(sizeof(Edge)*(n*(n-1)/2));
    int k = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            edge[k].i = i;
            edge[k].j = j;
            edge[k].cost = graph->Edge[i][j];
            k++;
        }
    }
    
    qsort(edge, k, sizeof(Edge), cmp);
    int *father = (int*)malloc(sizeof(int)*n);
    for(int i=0 ;i<n; i++) {
       father[i] = i; 
    }
    
    for(int i=0; i<n-1; i++) {
        k = 0;
        while(Is_Same(father, edge[k].i, edge[k].j)) {
            k++;
        }
        if(edge[k].cost == MAX_COST)
            return;
        printf("%c-->%c : %d\n", graph->VerticesList[edge[k].i],graph->VerticesList[edge[k].j], edge[k].cost);
        Mark_Same(father, edge[k].i, edge[k].j);
    }
}

void ShortestPath(GraphMtx *graph, int pos, int dist[], int path[]) {
   int n = graph->NumVertices;
   bool *S = (bool *)malloc(sizeof(bool)*n);
   assert(S!=NULL);

   for(int i=0; i<n; i++) {
       dist[i] = GetWeight(graph, pos, i);
       S[i] = false;
       if(i!=pos && dist[i]<MAX_COST) {
           path[i] = pos;
       } else {
           path[i] = -1;
       }
   }

   S[pos] = true;
   int min;
   int w;

   for(int i=0; i<n-1; i++) {
       min = MAX_COST;
       int u = pos;
       for(int j=0; j<n; j++) {
           if(!S[j] && dist[j]<min) {
               u = j;
               min = dist[j];
           }
       }
       S[u] = true;
       for(int k=0; k<n; k++) {
           w = GetWeight(graph, u, k);
           if(!S[k] && w<MAX_COST && dist[u]+w<dist[k]) {
               dist[k] = dist[u]+w;
               path[k] = u;
           }
       }
   }
}
