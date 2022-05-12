#ifndef EDGEQUEUE_H
#define EDGEQUEUE_H

#include <stdlib.h>

/*
Aresta para noh de fila de arestas (para Kruskal)
*/
typedef struct edge {
    int source; // vertice origem
    int dest; // vertice destino
    int weight; // peso da aresta
}Edge;

/*
Noh de fila de arestas (para Kruskal)
*/
typedef struct edgequeuenode {
    Edge * e; // aresta
    struct edgequeuenode * next; // ponteiro para proximo
}EQueueNode;

/*
Fila de arestas com cabeca e cauda (para Kruskal)
*/
typedef struct edgequeue {
    struct edgequeuenode * head; // cabeca
    struct edgequeuenode * tail; // cauda
}EQueue;

/*
Cria uma aresta com seus vertices de origem e destino e seu peso
Entrada: origem, destino, peso
Retorno: aresta
Pre-condicao: nenhuma
Pos-condicao: uma aresta '(s,d)' de peso 'w' eh criada
*/
Edge * createEdge(int s, int d, int w);

/*
Cria um noh de fila que vai gerar, em seguida, uma aresta para si
Entrada: origem, destino, peso
Retorno: noh de fila
Pre-condicao: nenhuma
Pos-condicao: um noh de fila eh criado e, em seguida, uma aresta '(s,d)' de peso 'w' eh criada
*/
EQueueNode * createEQueueNode(int source, int dest, int weight);

/*
Cria uma fila de arestas
Entrada: nenhuma
Retorno: fila de arestas
Pre-condicao: nenhuma
Pos-condicao: uma fila de arestas eh criada
*/
EQueue * createEQueue();

/*
Verifica se uma aresta ja esta presente na fila
Entrada: fila de arestas, vertice de origem, vertice de destino
Retorno: 0 se a aresta nao esta na fila ou 1 se ela esta
Pre-condicao: nenhuma
Pos-condicao: nenhuma
*/
int inEQueue(EQueue * eq, int source, int dest);

/*
Insere uma aresta na fila ordenada pelo seu peso (em ordem crescente)
Entrada: Fila de arestas, vertice de origem, vertice de destino e peso
Retorno: Fila de arestas atualizada
Pre-condicao: nenhuma
Pos-condicao: aresta eh inserida na fila de forma ordenada pelo peso
*/
EQueue * enqueueEQueue(EQueue * eq, int source, int dest, int weight);

/*
Remove a primeira aresta da fila e a retorna
Entrada: Fila de arestas
Retorno: Aresta
Pre-condicao: conter arestas na fila
Pos-condicao: uma aresta eh removida da fila de arestas e retornada
*/
Edge * popEQueue(EQueue * eq);

#endif // EDGEQUEUE_H