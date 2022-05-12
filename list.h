#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

/*
Noh de lista encadeada para uma lista de adjacencia, junto com o peso da aresta
*/
typedef struct listnode {
    int edge; // aresta
    int weight; // peso
    struct listnode * next; // ponteiro para proximo noh
}ListNode;

/*
Lista de adjacenica, contendo cabeca e cauda
*/
typedef struct list {
    ListNode * head; // cabeca
    ListNode * tail; // cauda
}List;

/*
Cria um noh de lista encadeada com seu valor de aresta e peso e retorna
Entrada: aresta, peso
Retorno: noh de lista encadeada
Pre-condicao: nenhuma
Pos-condicao: um elemento de lista de adjacencia eh criado
*/
ListNode * createListNode(int edge, int weight);

/*
Cria uma lista de adjacencia, com cabeca e cauda, que contem as arestas do vertice
Entrada: nenhuma
Retorno: lista de adjacencia
Pre-condicao: nenhuma
Pos-condicao: lista de adjacenica eh criada
*/
List * createList();

/*
Insere uma aresta na lista de adjacencia, ordenada em ordem crescente pela aresta
Entrada: lista de adjacencia, aresta, peso
Retorno: lista de adjacencia atualizada
Pre-condicao: nenhuma
Pos-condicao: uma aresta eh inserida na lista de adjacencia
*/
List * insertList(List * l, int edge, int weight);

/*
Imprime todas as arestas de um vertice 'i' no terminal
Entrada: vertice, lista de adjacencia
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: arestas do vertice 'i' sao impressas
*/
void printList(int i, List * l);

#endif // LIST_H