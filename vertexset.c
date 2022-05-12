#include "vertexset.h"

/*
Cria um noh de conjunto de vertice com um vertice atribuido
Entrada: vertice
Retorno: Noh de conjunto de vertice
Pre-condicao: nenhuma
Pos-condicao: um noh de conjunto de vertice eh criado
*/
VSetNode * createVSetNode(int vertex) {
    VSetNode * vsn = (VSetNode*)malloc(sizeof(VSetNode));
    vsn->v = vertex;
    vsn->next = NULL;
    return vsn;
}

/*
Cria um conjunto de vertices vazio
Entrada: nenhuma
Retorno: conjunto de vertices vazio
Pre-condicao: nenhuma
Pos-condicao: um conjunto de vertices vazio eh criado
*/
VSet * createVSet() {
    VSet * vs = (VSet*)malloc(sizeof(VSet));
    vs->head = NULL;
    vs->tail = NULL;
    vs->l = 0;
    return vs;
}

/*
Insere um vertice no conjunto de vertices (UNIAO)
Entrada: conjunto de vertices, vertice
Retorno: conjunto de vertices atualizado
Pre-condicao: nenhuma
Pos-condicao: um vertice eh inserido no conjunto de vertices
*/
VSet * insertVSet(VSet * vs, int vertex) {
    VSetNode * aux, * prevAux;

    if(!vs) {
        vs = createVSet();
        vs->head = createVSetNode(vertex);
        vs->tail = vs->head;
        vs->l++;
        return vs;
    }

    if(!vs->head) {
        vs->head = createVSetNode(vertex);
        vs->tail = vs->head;
        vs->l++;
    } else {
        aux = vs->head;
        prevAux = NULL;
        while (aux && vertex > aux->v) {
            prevAux = aux;
            aux = aux->next;
        }

        if(aux == NULL || vertex != aux->v) {
            if(!prevAux) {
                vs->head = createVSetNode(vertex);
                vs->head->next = aux;
            } else {
                prevAux->next = createVSetNode(vertex);
                prevAux->next->next = aux;
            }
            vs->l++;
        }
        
    }

    return vs;
}

/*
Cria uma lista de conjuntos de vertices de 'n' conjuntos
Entrada: quantidade de conjuntos (quantidade de vertices do grafo)
Retorno: lista de conjuntos de vertices onde cada conjunto contem exatamente um vertice
Exemplo: supondo os vertices 0 - 1 - 2, a lista de vertices sera lista[0] contem {0}, lista[1] contem {1}, lista[2] contem {2}
Pre-condicao: nenhuma
Pos-condicao: uma lista de conjuntos de vertices com todos os vertices do grafo eh criada
*/
VSetList * createVSetList(int n) {
    int i;
    VSetList * sl = (VSetList*)malloc(sizeof(VSetList));
    sl->set = (VSet**)malloc(sizeof(VSet*) * n);
    sl->l = n;

    for(i = 0; i < sl->l; i++) {
        sl->set[i] = insertVSet(NULL, i);
    }

    return sl;
}

/*
Faz a uniao entre dois conjuntos de vertices
Entrada: lista de conjuntos de vertices e as posicoes i, j dos dois conjuntos a serem unidos
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: os conjuntos lista[i] U lista[j] e lista[j] eh apagado da lista de conjuntos (ficando so a sua uniao em lista[i]) 
*/
void mergeSets(VSetList * vsl, int i, int j) {
    VSet * set1, * set2;
    VSetNode * aux1, * aux2;

    set1 = vsl->set[i];
    set2 = vsl->set[j];

    if(!set1) {
        vsl->set[i] = vsl->set[j];
        vsl->set[j] = NULL;
        return;
    }

    if(!set2) return;

    if(!set1->head) {
        vsl->set[i] = vsl->set[j];
        vsl->set[j] = NULL;
        return;
    }
    
    if(!set2->head) {
        set2 = vsl->set[j];
        vsl->set[j] = NULL;
        free(set2);
        return;
    }

    aux1 = set2->head;

    while(aux1) {
        //set1 = insertVSet(set1, aux1->v);
        vsl->set[i] = insertVSet(vsl->set[i], aux1->v);
        aux1 = aux1->next;
    }

    aux1 = set2->head;
    aux2 = NULL;
    while(aux1) {
        aux2 = aux1;
        aux1 = aux1->next;
        free(aux2);
    }
    free(set2);
    vsl->set[j] = NULL;
}

/*
Retorna a posicao na lista de conjuntos de vertices que o vertice 'v' se encontra
Entrada: lista de conjuntos de vertices, vertice
Retorno: posicao do conjunto em que o vertice v se encontra ou -1 caso nao esteja
Pre-condicao: nenhuma
Pos-condicao: nenhuma
*/
int getSetPos(VSetList * vl, int v) {
    int i;
    VSet * vs;
    VSetNode * vsn;

    for(i = 0; vl->l; i++) {
        vsn = NULL;
        if(vl->set && vl->set[i] /*&& vl->set[i]->head*/)
            vsn = vl->set[i]->head;
        while(vsn) {
            if(vsn->v == v) return i;
            vsn = vsn->next;
        }
    }
    return -1;
}

/*
Verifica se os vertices 'v1' e 'v2' pertencem ao mesmo conjunto de vertices
Entrada: lista de conjuntos de vertices, vertice 1, vertice 2
Retorno: 1 caso estejam no mesmo conjunto e 0 caso contrario
Pre-condicao: nenhuma
Pos-condicao: nenhuma
*/
int inSameSet(VSetList * vl, int v1, int v2) {
    int i;
    int check = 0;
    VSetNode * vsn;

    for(i = 0; i < vl->l; i++) {
        vsn = NULL;
        check = 0;
        if(vl->set && vl->set[i]) {
            vsn = vl->set[i]->head;
            while(vsn) {
                if(vsn->v == v1) check++;
                if(vsn->v == v2) check++;
                if(check > 1) return 1;
                vsn = vsn->next;
            }
        }
    }
    return 0;
}

/*
Desaloca a lista de conjuntos de vertices, os conjuntos de vertices e seus nohs
Entrada: lista de conjuntos de vertices
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: a lista de conjuntos, os conjuntos e seus nohs sao limpos da memoria
*/
void destroyVSetList(VSetList * vsl) {
    int i;
    VSetNode * node, * aux;

    for(i = 0; i < vsl->l; i++) {
        node = NULL;
        aux = NULL;
        if(vsl->set && vsl->set[i])
            node = vsl->set[i]->head;
        
        while(node) {
            aux = node;
            node = node->next;
            free(aux);
        }
        
    }
}