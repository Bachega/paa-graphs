#include "list.h"

/*
Cria um noh de lista encadeada com seu valor de aresta e peso e retorna
Entrada: aresta, peso
Retorno: noh de lista encadeada
Pre-condicao: nenhuma
Pos-condicao: um elemento de lista de adjacencia eh criado
*/
ListNode * createListNode(int edge, int weight) {
    ListNode * n = (ListNode*)malloc(sizeof(ListNode));
    n->edge = edge;
    n->weight = weight;
    n->next = NULL;
    return n;
}   

/*
Cria uma lista de adjacencia, com cabeca e cauda, que contem as arestas do vertice
Entrada: nenhuma
Retorno: lista de adjacencia
Pre-condicao: nenhuma
Pos-condicao: lista de adjacenica eh criada
*/
List * createList() {
    List * l = (List*)malloc(sizeof(List));
    l->head = l->tail = NULL;
    return l;
}

/*
Insere uma aresta na lista de adjacencia, ordenada em ordem crescente pela aresta
Entrada: lista de adjacencia, aresta, peso
Retorno: lista de adjacencia atualizada
Pre-condicao: nenhuma
Pos-condicao: uma aresta eh inserida na lista de adjacencia
*/
List * insertList(List * l, int edge, int weight) {
    ListNode * aux, * prevAux;
    
    if(l == NULL)
        l = createList();

    if(l->head == NULL)
        l->head = l->tail = createListNode(edge, weight);
    else {
        aux = l->head;
        prevAux = NULL;
        while (aux && edge > aux->edge) {
            prevAux = aux;
            aux = aux->next;
        }

        if(!prevAux) {
            l->head = createListNode(edge, weight);
            l->head->next = aux;
        } else {
            prevAux->next = createListNode(edge, weight);
            prevAux->next->next = aux;
        }
    }

    return l;
}

/*
Imprime todas as arestas de um vertice 'i' no terminal
Entrada: vertice, lista de adjacencia
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: arestas do vertice 'i' sao impressas
*/
void printList(int i, List * l) {
    if(l == NULL) return;
    ListNode * aux = l->head;
    while (aux) {
        printf("(%d,%d):%d\n", i, aux->edge, aux->weight);
        aux = aux->next;
    } 
}