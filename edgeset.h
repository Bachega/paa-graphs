#ifndef EDGESET_H
#define EDGESET_H

#include <stdlib.h>
#include <stdio.h>

/*
Noh de um conjunto de arestas
*/
typedef struct esetnode {
    int source; // vertice de origem
    int dest; // vertice de destino
    int weight; // peso
    struct esetnode * next; // ponteiro para proximo
}ESetNode;

/*
Conjunto de arestas com cabeca e cauda, peso total das arestas e quantidade de arestas
*/
typedef struct eset {
    ESetNode * head; // cabeca
    ESetNode * tail; // cauda
    int weight; // peso total das arestas
    int l; // quantidade de arestas
}ESet;

/*
Cria um noh de conjunto de arestas representando uma com origem, destino e peso e retorna
Entrada: vertice de origem, vertice de destino e peso
Retorno: Noh de conjunto de arestas
Pre-condicao: nenhuma
Pos-condicao: Noh de conjunto de arestas eh criado
*/
ESetNode * createESetNode(int source, int dest, int weight);

/*
Cria um conjunto de arestas vazio
Entrada: nenhuma
Retorno: Conjunto de arestas
Pre-condicao: nenhuma
Pos-condicao: um conjunto de arestas eh criado
*/
ESet * createESet();

/*
Insere uma aresta no conjunto de arestas
Entrada: Conjunto de arestas, vertice de origem, destino e peso
Retorno: Conjunto de arestas atualizado
Pre-condicao: nenhuma
Pos-condicao: uma aresta eh inserida no conjunto de arestas
*/
ESet * insertESet(ESet * es, int source, int dest, int weight);

/*
Imprime o conjunto de arestas no termina
Entrada: Conjunto de arestas
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: arestas do conjunto de arestas sao impressas
*/
void printESet(ESet * es);

/*
Desaloca o conjunto de arestas e todas as suas estrturas relacionadas
Entrada: Conjunto de arestas
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: conjunto de arestas e suas arestas sao limpas da memoria
*/
void destroyESet(ESet * A);

#endif // EDGESET_H