#include "GraphLink.h"
#include "LinkQueue.h"

void _RemoveEdge(GraphLink *graph, int pv1, int pv2);
void _DFSGraph(GraphLink *graph, int pos, bool *visited);
void _BFSGraph(GraphLink *graph, int pos, bool *visited, LinkQueue *queue);

void InitGraphLink(GraphLink *graph) {
   graph->MaxVertices = DEFAULT_VERTEX_SIZE; 
   graph->NodeTable = (Vertex*)malloc(sizeof(Vertex)*graph->MaxVertices);
   assert(graph->NodeTable != NULL);
   for(int i=0; i<graph->MaxVertices; i++) {
       graph->NodeTable[i].adj = NULL;
   }
}

int GetVertexPos(GraphLink *graph, ElemType data) {
    for(int i=0; i<graph->NumVertices; i++) {
        if(graph->NodeTable[i].data == data)
            return i;
    }
    return -1;
}

void ShowGraph(GraphLink *graph) {
   for(int i=0; i<graph->NumVertices; i++) {
       printf("%c:>", graph->NodeTable[i].data);
       Edge *p = graph->NodeTable[i].adj;
       while(p) {
           printf("%d-->", p->dest);
           p = p->link;
       }
       printf("Nul.\n");
   } 
   printf("\n");
}

void InsertVertex(GraphLink *graph, ElemType data) {
    graph->NodeTable[graph->NumVertices++].data = data;
}

void InsertEdge(GraphLink *graph, ElemType v1, ElemType v2) {
    int pv1 = GetVertexPos(graph, v1);
    int pv2 = GetVertexPos(graph, v2);
    if(pv1==-1 || pv2==-1)
        return;

    Edge *p1 = (Edge *)malloc(sizeof(Edge));
    p1->dest = pv2;
    p1->link = graph->NodeTable[pv1].adj;
    graph->NodeTable[pv1].adj = p1;

    // Edge *p2 = (Edge *)malloc(sizeof(Edge));
    // p2->dest = pv1;
    // p2->link = graph->NodeTable[pv2].adj;
    // graph->NodeTable[pv2].adj = p2;
}

void RemoveVertex(GraphLink *graph, ElemType data) {
    int pos = GetVertexPos(graph, data);
    if(pos == -1)
        return;
    Edge *edge = graph->NodeTable[pos].adj;
    while(edge) {
        _RemoveEdge(graph, edge->dest, pos);
        _RemoveEdge(graph, pos, edge->dest);
        edge = graph->NodeTable[pos].adj;
    }
    for(int i=pos; i<graph->NumVertices-1; i++) {
        graph->NodeTable[i].data = graph->NodeTable[i+1].data;
        graph->NodeTable[i].adj = graph->NodeTable[i+1].adj;
    }
    graph->NumVertices--;
}

void _RemoveEdge(GraphLink *graph, int pv1, int pv2) {
    Edge *p1 = graph->NodeTable[pv1].adj;
    Edge *q1 = NULL;
    while(p1) {
        if(p1->dest == pv2) {
            break;
        }
        q1 = p1;
        p1 = p1->link;
    }

    if(p1 == NULL) {
        return;
    } else  {
        if(q1) {
            q1->link = p1->link;
        } else {
            graph->NodeTable[pv1].adj = p1->link;
        }
        free(p1);
    }
}

void RemoveEdge(GraphLink *graph, ElemType v1, ElemType v2) {
    int pv1 = GetVertexPos(graph, v1);
    int pv2 = GetVertexPos(graph, v2);
    if(pv1 == -1 || pv2 == -1)
        return;
    _RemoveEdge(graph, pv1, pv2);
    // _RemoveEdge(graph, pv2, pv1);
}

void DestroyGraph(GraphLink *graph) {
    for(int i=0; i<graph->NumVertices; i++) {
        Edge *p1 = graph->NodeTable[i].adj;   
        while(p1) {
            graph->NodeTable[i].adj = p1->link;
            free(p1);
            p1 = graph->NodeTable[i].adj;
        }
    }
    free(graph->NodeTable);
}

int GetFirstNeighbor(GraphLink *graph, int pos) {
    if(pos == -1 || graph->NodeTable[pos].adj == NULL)
        return -1;
    return graph->NodeTable[pos].adj->dest;
}

int GetNextNeighbor(GraphLink *graph, int pv1, int pv2) {
    if(pv1 == -1 || pv2 == -1)
        return -1;
    Edge *edge = graph->NodeTable[pv1].adj;
    while(edge) {
        if(edge->dest == pv2) {
            if(edge->link) {
                return edge->link->dest;
            } else {
                return -1;
            }
        }
        edge = edge->link;
    }

    return -1;
}

void _DFSGraph(GraphLink *graph, int pos, bool *visited) {
    if(visited[pos])
        return;
    visited[pos] = true;
    printf("%c-->", graph->NodeTable[pos].data);
    int fn = GetFirstNeighbor(graph, pos);
    while(fn != -1) {
        _DFSGraph(graph, fn, visited);
        fn = GetNextNeighbor(graph, pos, fn);
    }
}

void DFSGraph(GraphLink *graph, ElemType data) {
    int pos = GetVertexPos(graph, data);
    if(pos == -1)
        return;

    bool *visited = (bool *)malloc(sizeof(bool)*graph->NumVertices);
    for(int i=0; i<graph->NumVertices; i++)
        visited[i] = false;
    _DFSGraph(graph, pos, visited);
    printf("Nul.\n");
    free(visited);
}

void _BFSGraph(GraphLink *graph, int pos, bool *visited, LinkQueue *queue) {
    bool flag = false;
    if(visited[pos] == false) {
        visited[pos] = true;
        printf("%c-->", graph->NodeTable[pos].data);
    }
    int fn = GetFirstNeighbor(graph, pos);
    while(fn != -1) {
        if(visited[fn]==false) {
            flag = true;
            visited[fn] = true;
            printf("%c-->", graph->NodeTable[fn].data);
        }
        fn = GetNextNeighbor(graph, pos, fn);
    }

    if(!flag)
        return;

    fn = GetFirstNeighbor(graph, pos);
    while(fn != -1) {
        _BFSGraph(graph, fn, visited, queue);
        fn = GetNextNeighbor(graph, pos, fn);
    }
}

void BFSGraph(GraphLink *graph, ElemType data) {
    int pos = GetVertexPos(graph, data);
    if(pos == -1)
        return;

    bool *visited = (bool *)malloc(sizeof(bool)*graph->NumVertices);
    LinkQueue queue;
    InitQueue(&queue);
    
    for(int i=0; i<graph->NumVertices; i++)
        visited[i] = false;
    
    EnQueue(&queue, pos);
    visited[pos] = true;

    int fn;
    while(Length(&queue)) {
        DeQueue(&queue, &pos);
        printf("%c-->", graph->NodeTable[pos].data);
        fn = GetFirstNeighbor(graph, pos);
        while(fn != -1) {
            if(!visited[fn]) {
                EnQueue(&queue, fn);
                visited[fn] = true;
            }
            fn = GetNextNeighbor(graph, pos, fn);
        }
    }
    printf("Nul.\n");
    free(visited);
}

void TopologicalSort(GraphLink *graph) {
    int n = graph->NumVertices;
    int *count = (int*)malloc(sizeof(int)*n);
    int top = -1;
    memset(count, 0, sizeof(int)*n);

    for(int i=0; i<n; i++) {
        Edge *edge = graph->NodeTable[i].adj;
        while(edge) {
            count[edge->dest]++;
            edge = edge->link;
        }
    }

    for(int i=0; i<n; i++) {
        if(count[i] == 0) {
            count[i] = top;
            top = i;
        }
    }

    for(int i=0; i<n; i++) {
        if(top == -1) {
            printf("error-->");
            break;
        } else {
            printf("%c-->", graph->NodeTable[top].data);
            Edge *edge = graph->NodeTable[top].adj;
            top = count[top];
            while(edge) {
                if(--count[edge->dest] == 0) {
                    count[edge->dest] = top;
                    top = edge->dest;
                }
                edge = edge->link;
            }
        }
    }
    printf("Nul\n");
}
