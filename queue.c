#include "queue.h"

/*
Testa se uma fila eh vazia
Entrada: fila
Retorno: 0 para nao vazia e 1 para vazia
Pre-condicao: nenhuma
Pos-condicao: nenhuma
*/
int isEmpty(Queue * q) {
    return (q == NULL || q->head == NULL);
}

/*
Cria um noh de fila de vertices com um vertice
Entrada: vertice
Retorno: noh de fila de vertices
Pre-condicao: nenhuma
Pos-condicao: noh de fila de vertices eh criado
*/
QueueNode * createQueueNode(int info) {
    QueueNode * qn = (QueueNode*)malloc(sizeof(QueueNode));
    qn->info = info;
    qn->next = NULL;
    return qn;
}

/*
Cria uma fila de vertices vazia
Entrada: nenhuma
Retorno: fila de vertices vazia
Pre-condicao: nenhuma
Pos-condicao: fila de vertices vazia eh criada
*/
Queue * createQueue() {
    Queue * q = (Queue*)malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    return q;
}

/*
Insere um vertice na fila
Entrada: fila, vertice
Retorno: fila atualizada
Pre-condicao: nenhuma
Pos-condicao: um vertice eh inserido na fila
*/
Queue * enqueue(Queue * q, int info) {
    if(!q)
        q = createQueue();

    if(q->head) {
        q->tail->next = createQueueNode(info);
        q->tail = q->tail->next;
    } else {
        q->head = createQueueNode(info);
        q->tail = q->head;
    }
        
    return q;
}

/*
Remove um vertice do comeco da fila e o retorna
Entrada: fila
Retorno: vertice na cabeca da fila ou -1 para fila vazia
Pre-condicao: nenhuma
Pos-condicao: um vertice eh removido da fila e seu valor eh retornado
*/
int pop(Queue * q) {
    int info;
    QueueNode * aux;

    if(!q || !q->head) return -1;

    info = q->head->info;
    aux = q->head;
    
    if(q->head == q->tail)
        q->tail = NULL;
    
    q->head = q->head->next;

    free(aux);

    return info;
}

/*
Imprime todos os vertices da fila no terminal
Entrada: fila
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: vertices da fila sao impressos
*/
void printQueue(Queue * q) {
    QueueNode * n;
    if(!q) return;

    n = q->head;

    while(n) {
        printf("{%d}", n->info);
        n = n->next;
    }
}