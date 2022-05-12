#include "graph.h"

/*
Cria um grafo com 'vertexNum' vertices
Entrada: numero de vertices e se o grafo eh orientado ou nao
Retorno: grafo com 'vertexNum' vertices
Pre-condicao: nenhuma
Pos-condicao: um grafo eh criado
*/
Graph createGraph(int vertexNum, int oriented) {
    int i;
    Graph g = (Graph)malloc(sizeof(struct graph));
    g->vertex = (List**)malloc(sizeof(List*)*vertexNum);
    g->n = vertexNum;
    g->oriented = oriented;
    for(i = 0; i < vertexNum; i++) g->vertex[i] = NULL;

    color = (int*)malloc(sizeof(int)*g->n);
    prev = (int*)malloc(sizeof(int)*g->n);
    d = (int*)malloc(sizeof(int)*g->n);
    f = (int*)malloc(sizeof(int)*g->n);

    return g;
}

/*
Imprime um grafo, suas arestas e pesos (semelhante ao formato do arquivo texto)
Entrada: grafo
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: grafo eh impresso
*/
void printGraph(Graph g) {
    int i;
    if(g->oriented)
        printf("orientado=sim\n");
    else
        printf("orientado=nao\n");
    printf("V=%d\n", g->n);
    for(i = 0; i < g->n; i++)
        printList(i, g->vertex[i]);
}

/*
Funcao auxiliar de busca em profundidade, percorre recursivamente de forma profunda todos os vertices brancos e os imprime
Entrada: grafo, vertice de origem
Retorno: nenhum
Pre-condicao: grafo precisa existir
Pos-condicao: busca em profundidade eh executada e impressa
*/
void dfsVisit(Graph g, int u) {
    int i;
    color[u] = GRAY;
    ListNode * aux = NULL;
    if(g->vertex[u])
        aux = g->vertex[u]->head;
    
    timestamp++;

    printf("[%d]", u);
    
    while(aux) {
        if(color[aux->edge] == WHITE) {
            prev[aux->edge] = u;
            dfsVisit(g, aux->edge);
        }
        aux = aux->next;
    }
    color[u] = BLACK;
    timestamp++;
    f[u] = timestamp;
}

/*
Funcao de busca em profundidade, inicializa as estruturas de dados iniciais e chama dfsVisit
Entrada: grafo, vertice de origem
Retorno: nenhum
Pre-condicao: grafo precisa existir
Pos-condicao: busca em profundidade eh executada e impressa
*/
void dfs(Graph g, int u) {
    int i;

    timestamp = 0;

    for(i = 0; i < g->n; i++) {
        color[i] = WHITE;
        prev[i] = -1;
    }
    
    dfsVisit(g, u);
}

/*
Funcao de busca em largura
Entrada: grafo, vertice de origem
Retorno: nenhum
Pre-condicao: grafo precisa existir
Pos-condicao: busca em largura eh executada e impressa
*/
void bfs(Graph g, int u) {
    int i, v;
    Queue * q = NULL;
    ListNode * aux;
    
    for(i = 0; i < g->n; i++) {
        color[i] = WHITE;
        d[i] = INFINITY;
        prev[i] = -1;
    }
    color[u] = GRAY;
    d[u] = 0;

    q = enqueue(q, u);

    printf("[%d]", u);
    while(!isEmpty(q)) {
        v = pop(q);
        if(g->vertex[v])
            aux = g->vertex[v]->head;
        else
            aux = NULL;
        while(aux) {
            if(color[aux->edge] == WHITE) {
                color[aux->edge] = GRAY;
                d[aux->edge] = d[v] + 1;
                prev[aux->edge] = v;
                printf("[%d]", aux->edge);
                q = enqueue(q, aux->edge);
            }
            aux = aux->next;
        }
        color[v] = BLACK;
    }

    free(q);
}

/*
Funcao do algoritmo de Bellman-Ford
Entrada: grafo, vertice de origem
Retorno: nenhum
Pre-condicao: grafo precisa existir
Pos-condicao: algoritmo de bellman-ford eh executado e impresso
*/
int bellmanFord(Graph g, int s) {
    int i, j;
    ListNode * aux;

    for(i = 0; i < g->n; i++) {
        d[i] = INFINITY;
        prev[i] = -1;
    }
    d[s] = 0;

    for(i = 0; i < g->n - 1; i++) {
        // cada aresta pertencente ao conjunto de arestas
        for(j = 0; j < g->n; j++) {
            aux = NULL;
            if(g->vertex[j])
                aux = g->vertex[j]->head;
            while(aux) {
                if(d[aux->edge] > d[j] + aux->weight) {
                    d[aux->edge] = d[j] + aux->weight;
                    prev[aux->edge] = j;
                }
                aux = aux->next;
            }
        }   
    }

    for(j = 0; j < g->n; j++) {
        aux = NULL;
        if(g->vertex[j])
            aux = g->vertex[j]->head;
        while(aux) {
            if(d[aux->edge] > d[j] + aux->weight) {
                printf("\nCiclo de peso negativo detectado\n");
                return 0;
            }
            aux = aux->next;
        }
    }

    printBfPath(s, g->n);
    return 1;
}

/*
Imprime os caminhos do algoritmo ja executado de Bellman-Ford
Entrada: vertice de origem, quantidade de vertices
Retorno: nenhum
Pre-condicao: Bellman-Ford executado (a funcao eh chamada ao final de 'bellmanFord')
Pos-condicao: os caminhos do algoritmo de Bellman-Ford sao impressos
*/
void printBfPath(int origin, int n) {
    int i, j, dist, pi, pl;
    int * path = (int*)malloc(sizeof(int) * n);

    printf("Origem:  %d\n", origin);
    
    for(i = 0; i < n; i++) {
        pi =  0;
        j = i;
        if(prev[j] != -1)
            while(j != origin) {
                path[pi] = j;
                pi++;
                j = prev[j];
            }
        printf("Destino: %d\tDistancia: %d\tCaminho: [%d]", i, d[i], origin);
        for(j = (pi-1); j >= 0; j--)
            printf("[%d]", path[j]);
        printf("\n");
    }
    printf("\n");
    free(path);
}

/*
Executa o algoritmo de kruskal e imprime uma arvore geradora minima e seu peso
Entrada: grafo
Retorno: nenhum
Pre-condicao: grafo precisa existir
Pos-condicao: algoritmo de kruskal eh executado e impresso
*/
void kruskal(Graph g) {
    ESet * A = createESet();
    VSetList * vertexSetList = createVSetList(g->n);
    EQueue * edgeQueue = NULL;
    ListNode * aux;
    Edge * edge;
    int i;
    int p1, p2;

    for(i = 0; i < g->n; i++) {
        aux = NULL;
        if(g->vertex[i])
            aux = g->vertex[i]->head;
        
        while(aux) {
            edgeQueue = enqueueEQueue(edgeQueue, i, aux->edge, aux->weight);
            aux = aux->next;
        }
    }

    while(edgeQueue->head) {
        edge = popEQueue(edgeQueue);
        if(!inSameSet(vertexSetList, edge->source, edge->dest)) {
            A = insertESet(A, edge->source, edge->dest, edge->weight);
            p1 = getSetPos(vertexSetList, edge->source);
            p2 = getSetPos(vertexSetList, edge->dest);
            mergeSets(vertexSetList, p1, p2);    
        }
        free(edge);
        edge = NULL;
    }
    printESet(A);

    destroyESet(A);
    destroyVSetList(vertexSetList);
    free(edgeQueue);
    //return A;
}

/*
Desaloca o grafo e todas as suas listas de adjacencia
Entrada: grafo
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: grafo e suas subestruturas sao limpas da memoria
*/
void destroyGraph(Graph g) {
    int i;
    ListNode * node, * aux;
    
    for(i = 0; i < g->n; i++) {
        node = NULL;
        if(g->vertex[i])
            node = g->vertex[i]->head;
        while(node) {
            aux = node;
            node = node->next;
            free(aux);
        }
        free(g->vertex[i]);
    }
    free(g->vertex);
    free(g);

    free(color);
    free(prev);
    free(d);
    free(f);
}