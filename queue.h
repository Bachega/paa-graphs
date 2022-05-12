#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

/*
Noh de fila de vertices (para Bellman-Ford)
*/
typedef struct queuenode {
    int info; // vertice
    struct queuenode * next; // ponteiro para proximo
}QueueNode;

/*
Fila de vertices com cabeca e cauda (para Bellman-Ford)
*/
typedef struct queue {
    struct queuenode * head; // cabeca
    struct queuenode * tail; // cauda
}Queue;

/*
Testa se uma fila eh vazia
Entrada: fila
Retorno: 0 para nao vazia e 1 para vazia
Pre-condicao: nenhuma
Pos-condicao: nenhuma
*/
int isEmpty(Queue * q);

/*
Cria um noh de fila de vertices com um vertice
Entrada: vertice
Retorno: noh de fila de vertices
Pre-condicao: nenhuma
Pos-condicao: noh de fila de vertices eh criado
*/
QueueNode * createQueueNode(int info);

/*
Cria uma fila de vertices vazia
Entrada: nenhuma
Retorno: fila de vertices vazia
Pre-condicao: nenhuma
Pos-condicao: fila de vertices vazia eh criada
*/
Queue * createQueue();

/*
Insere um vertice na fila
Entrada: fila, vertice
Retorno: fila atualizada
Pre-condicao: nenhuma
Pos-condicao: um vertice eh inserido na fila
*/
Queue * enqueue(Queue * q, int info);

/*
Remove um vertice do comeco da fila e o retorna
Entrada: fila
Retorno: vertice na cabeca da fila ou -1 para fila vazia
Pre-condicao: nenhuma
Pos-condicao: um vertice eh removido da fila e seu valor eh retornado
*/
int pop(Queue * q);

/*
Imprime todos os vertices da fila no terminal
Entrada: fila
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: vertices da fila sao impressos
*/
void printQueue(Queue * q);

#endif // QUEUE_H 