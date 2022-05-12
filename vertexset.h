#ifndef VERTEXSET_H
#define VERTEXSET_H

#include <stdlib.h>
#include <stdio.h>

/*
Noh de conjunto de vertices (para Kruskal)
*/
typedef struct vsetnode {
    int v; // vertice
    struct vsetnode * next; // ponteiro para proximo
}VSetNode;

/*
Conjunto de vertices com cabeca e cauda (para Kruskal)
*/
typedef struct vset {
    VSetNode * head; // cabeca
    VSetNode * tail; // cauda
    int l; // quantidade de vertices
}VSet;

/*
Vetor de conjuntos de vertices (para Kruskal)
*/
typedef struct vsetlist {
    VSet ** set; // vetor de conjunto de vertices
    int l; // quantidade de conjunto de vertices
}VSetList;

/*
Cria um noh de conjunto de vertice com um vertice atribuido
Entrada: vertice
Retorno: Noh de conjunto de vertice
Pre-condicao: nenhuma
Pos-condicao: um noh de conjunto de vertice eh criado
*/
VSetNode * createVSetNode(int vertex);

/*
Cria um conjunto de vertices vazio
Entrada: nenhuma
Retorno: conjunto de vertices vazio
Pre-condicao: nenhuma
Pos-condicao: um conjunto de vertices vazio eh criado
*/
VSet * createVSet();

/*
Insere um vertice no conjunto de vertices (UNIAO)
Entrada: conjunto de vertices, vertice
Retorno: conjunto de vertices atualizado
Pre-condicao: nenhuma
Pos-condicao: um vertice eh inserido no conjunto de vertices
*/
VSet * insertVSet(VSet * vs, int vertex);

/*
Cria uma lista de conjuntos de vertices de 'n' conjuntos
Entrada: quantidade de conjuntos (quantidade de vertices do grafo)
Retorno: lista de conjuntos de vertices onde cada conjunto contem exatamente um vertice
Exemplo: supondo os vertices 0 - 1 - 2, a lista de vertices sera lista[0] contem {0}, lista[1] contem {1}, lista[2] contem {2}
Pre-condicao: nenhuma
Pos-condicao: uma lista de conjuntos de vertices com todos os vertices do grafo eh criada
*/
VSetList * createVSetList(int n);

/*
Faz a uniao entre dois conjuntos de vertices
Entrada: lista de conjuntos de vertices e as posicoes i, j dos dois conjuntos a serem unidos
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: os conjuntos lista[i] U lista[j] e lista[j] eh apagado da lista de conjuntos (ficando so a sua uniao em lista[i]) 
*/
void mergeSets(VSetList * vsl, int i, int j);

/*
Retorna a posicao na lista de conjuntos de vertices que o vertice 'v' se encontra
Entrada: lista de conjuntos de vertices, vertice
Retorno: posicao do conjunto em que o vertice v se encontra ou -1 caso nao esteja
Pre-condicao: nenhuma
Pos-condicao: nenhuma
*/
int getSetPos(VSetList * vl, int v);

/*
Verifica se os vertices 'v1' e 'v2' pertencem ao mesmo conjunto de vertices
Entrada: lista de conjuntos de vertices, vertice 1, vertice 2
Retorno: 1 caso estejam no mesmo conjunto e 0 caso contrario
Pre-condicao: nenhuma
Pos-condicao: nenhuma
*/
int inSameSet(VSetList * vl, int v1, int v2);

/*
Desaloca a lista de conjuntos de vertices, os conjuntos de vertices e seus nohs
Entrada: lista de conjuntos de vertices
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: a lista de conjuntos, os conjuntos e seus nohs sao limpos da memoria
*/
void destroyVSetList(VSetList * vsl);

#endif // VERTEXSET_H