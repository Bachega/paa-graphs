#include "edgequeue.h"

/*
Cria uma aresta com seus vertices de origem e destino e seu peso
Entrada: origem, destino, peso
Retorno: aresta
Pre-condicao: nenhuma
Pos-condicao: uma aresta '(s,d)' de peso 'w' eh criada
*/
Edge * createEdge(int s, int d, int w) {
    Edge * e = (Edge*)malloc(sizeof(Edge));
    e->source = s;
    e->dest = d;
    e->weight = w;
}

/*
Cria um noh de fila que vai gerar, em seguida, uma aresta para si
Entrada: origem, destino, peso
Retorno: noh de fila
Pre-condicao: nenhuma
Pos-condicao: um noh de fila eh criado e, em seguida, uma aresta '(s,d)' de peso 'w' eh criada
*/
EQueueNode * createEQueueNode(int source, int dest, int weight) {
    EQueueNode * eqn = (EQueueNode*)malloc(sizeof(EQueueNode));
    eqn->e = createEdge(source, dest, weight);
    eqn->next = NULL;
    return eqn;
}

/*
Cria uma fila de arestas
Entrada: nenhuma
Retorno: fila de arestas
Pre-condicao: nenhuma
Pos-condicao: uma fila de arestas eh criada
*/
EQueue * createEQueue() {
    EQueue * eq = (EQueue*)malloc(sizeof(EQueue));
    eq->head = NULL;
    eq->tail = NULL;
    return eq;
}

/*
Verifica se uma aresta ja esta presente na fila
Entrada: fila de arestas, vertice de origem, vertice de destino
Retorno: 0 se a aresta nao esta na fila ou 1 se ela esta
Pre-condicao: nenhuma
Pos-condicao: nenhuma
*/
int inEQueue(EQueue * eq, int source, int dest) {
    EQueueNode * eqn = NULL;
    
    if(!eq || !eq->head) return 0;

    eqn = eq->head;
    while (eqn) {
        if((eqn->e->source == source && eqn->e->dest == dest) || (eqn->e->source == dest && eqn->e->dest == source))
            return 1;
        eqn = eqn->next;
    }

    return 0;
}

/*
Insere uma aresta na fila ordenada pelo seu peso (em ordem crescente)
Entrada: Fila de arestas, vertice de origem, vertice de destino e peso
Retorno: Fila de arestas atualizada
Pre-condicao: nenhuma
Pos-condicao: aresta eh inserida na fila de forma ordenada pelo peso
*/
EQueue * enqueueEQueue(EQueue * eq, int source, int dest, int weight) {
    EQueueNode * aux, * prevAux;
    
    if(!eq) eq = createEQueue();

    if(inEQueue(eq, source, dest))
        return eq;

    aux = eq->head;
    while(aux) {
        if(aux->e->source == source && aux->e->dest == dest)
            return eq;
        aux = aux->next;
    }

    if(!eq->head) {
        eq->head = createEQueueNode(source, dest, weight);
        eq->tail = eq->head;
    } else {
        aux = eq->head;
        prevAux = NULL;
        
        while(aux && weight > aux->e->weight) {
            prevAux = aux;
            aux = aux->next;
        }

        if(!prevAux) {
            eq->head = createEQueueNode(source, dest, weight);
            eq->head->next = aux;
        } else {
            prevAux->next = createEQueueNode(source, dest, weight);
            prevAux->next->next = aux;
        }
    }

    return eq;
}

/*
Remove a primeira aresta da fila e a retorna
Entrada: Fila de arestas
Retorno: Aresta
Pre-condicao: conter arestas na fila
Pos-condicao: uma aresta eh removida da fila de arestas e retornada
*/
Edge * popEQueue(EQueue * eq) {
    Edge * edge;
    EQueueNode * aux;

    if(!eq || !eq->head) return NULL;

    edge = eq->head->e;
    aux = eq->head;

    if(eq->head == eq->tail)
        eq->tail = NULL;
    
    eq->head = eq->head->next;
    free(aux);
    
    return edge;
}