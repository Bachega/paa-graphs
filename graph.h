#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>

#include "list.h"
#include "queue.h"
#include "edgequeue.h"
#include "edgeset.h"
#include "vertexset.h"

//Definicao de infinito para Bellman-Ford e Kruskal
#define INFINITY 1073741823

//Cores para Bellman-Ford
#define WHITE 0
#define GRAY 1
#define BLACK 2

/*
Estrutura de um grafo (listas de adjacencia)
*/
struct graph {
    List ** vertex; // vetor de vertices adjacentes
    int n; // quantidade de vertices do grafo
    int oriented; // 1- orientado || 0- nao orientado
};

int timestamp;
int * color, * prev, * d, * f;

typedef struct graph * Graph;

/*
Cria um grafo com 'vertexNum' vertices
Entrada: numero de vertices e se o grafo eh orientado ou nao
Retorno: grafo com 'vertexNum' vertices
Pre-condicao: nenhuma
Pos-condicao: um grafo eh criado
*/
Graph createGraph(int vertexNum, int oriented);

/*
Imprime um grafo, suas arestas e pesos (semelhante ao formato do arquivo texto)
Entrada: grafo
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: grafo eh impresso
*/
void printGraph(Graph g);

/*
Funcao auxiliar de busca em profundidade, percorre recursivamente de forma profunda todos os vertices brancos e os imprime
Entrada: grafo, vertice de origem
Retorno: nenhum
Pre-condicao: grafo precisa existir
Pos-condicao: busca em profundidade eh executada e impressa
*/
void dfsVisit(Graph g, int u);

/*
Funcao de busca em profundidade, inicializa as estruturas de dados iniciais e chama dfsVisit
Entrada: grafo, vertice de origem
Retorno: nenhum
Pre-condicao: grafo precisa existir
Pos-condicao: busca em profundidade eh executada e impressa
*/
void dfs(Graph g, int u);

/*
Funcao de busca em largura
Entrada: grafo, vertice de origem
Retorno: nenhum
Pre-condicao: grafo precisa existir
Pos-condicao: busca em largura eh executada e impressa
*/
void bfs(Graph g, int u);

/*
Funcao do algoritmo de Bellman-Ford
Entrada: grafo, vertice de origem
Retorno: nenhum
Pre-condicao: grafo precisa existir
Pos-condicao: algoritmo de bellman-ford eh executado e impresso
*/
int bellmanFord(Graph g, int s);

/*
Imprime os caminhos do algoritmo ja executado de Bellman-Ford
Entrada: vertice de origem, quantidade de vertices
Retorno: nenhum
Pre-condicao: Bellman-Ford executado (a funcao eh chamada ao final de 'bellmanFord')
Pos-condicao: os caminhos do algoritmo de Bellman-Ford sao impressos
*/
void printBfPath(int origin, int n);

/*
Executa o algoritmo de kruskal e imprime uma arvore geradora minima e seu peso
Entrada: grafo
Retorno: nenhum
Pre-condicao: grafo precisa existir
Pos-condicao: algoritmo de kruskal eh executado e impresso
*/
void kruskal(Graph g);

/*
Desaloca o grafo e todas as suas listas de adjacencia
Entrada: grafo
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: grafo e suas subestruturas sao limpas da memoria
*/
void destroyGraph(Graph g);

#endif // GRAPH_H