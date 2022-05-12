#include "edgeset.h"

/*
Cria um noh de conjunto de arestas representando uma com origem, destino e peso e retorna
Entrada: vertice de origem, vertice de destino e peso
Retorno: Noh de conjunto de arestas
Pre-condicao: nenhuma
Pos-condicao: Noh de conjunto de arestas eh criado
*/
ESetNode * createESetNode(int source, int dest, int weight) {
    ESetNode * esn = (ESetNode*)malloc(sizeof(ESetNode));
    esn->source = source;
    esn->dest = dest;
    esn->weight = weight;
    esn->next = NULL;
    return esn;
}

/*
Cria um conjunto de arestas vazio
Entrada: nenhuma
Retorno: Conjunto de arestas
Pre-condicao: nenhuma
Pos-condicao: um conjunto de arestas eh criado
*/
ESet * createESet() {
    ESet * es = (ESet*)malloc(sizeof(ESet));
    es->head = NULL;
    es->tail = NULL;
    es->l = 0;
    es->weight = 0;
}

/*
Insere uma aresta no conjunto de arestas
Entrada: Conjunto de arestas, vertice de origem, destino e peso
Retorno: Conjunto de arestas atualizado
Pre-condicao: nenhuma
Pos-condicao: uma aresta eh inserida no conjunto de arestas
*/
ESet * insertESet(ESet * es, int source, int dest, int weight) {
    if(!es) es = createESet();

    if(!es->head) {
        es->head = createESetNode(source, dest, weight);
        es->tail = es->head;
    } else {
        es->tail->next = createESetNode(source, dest, weight);
        es->tail = es->tail->next;
    }

    es->l++;
    es->weight += weight;
    
    return es;
}

/*
Imprime o conjunto de arestas no termina
Entrada: Conjunto de arestas
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: arestas do conjunto de arestas sao impressas
*/
void printESet(ESet * es) {
    ESetNode * esn;
    if(!es || !es->head/*es->l == 0*/) return;

    printf("Peso total: %d\nArestas:", es->weight);
    esn = es->head;
    while (esn) {
        printf(" (%d,%d)", esn->source, esn->dest);
        esn = esn->next;
    }   
}

/*
Desaloca o conjunto de arestas e todas as suas estrturas relacionadas
Entrada: Conjunto de arestas
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: conjunto de arestas e suas arestas sao limpas da memoria
*/
void destroyESet(ESet * A) {
    ESetNode * node, * aux = NULL;
    if(!A || !A->head) return;

    node = A->head;
    while(node) {
        aux = node;
        node = node->next;
        free(aux);
    }
    free(A);
}