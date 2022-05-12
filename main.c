#include <string.h>

#include "filehandler.h"
#include "graph.h"

/*
Menu inicial
Entrada: nenhuma
Retorno: nenhum
Pre-condicao: nenhuma
Pos-condicao: nenhum
*/
int main(int argc, char * argv[]) {
    Graph graph = NULL;
    int op = 1, origin;
    char buff[256];

    while(op) {
        if(graph) {
            printf("\n1- Carregar novo grafo\n");
            printf("2- Imprimir grafo\n");
            printf("3- Busca em Profundidade\n");
            printf("4- Busca em Largura\n");
            printf("5- Bellman-Ford\n");
            printf("6- Kruskal\n");
            printf("0- Sair\n");
            scanf("%d", &op); fflush(stdin);
            printf("\n");

            switch(op) {
                case 1:
                    destroyGraph(graph);
                    graph = NULL;
                    printf("\nInsira o caminho do arquivo\nExemplo: ./pasta/arquivo.txt\n");
                    fgets(buff, 256, stdin); fflush(stdin);
                    buff[strlen(buff)-1] = '\0';
                    graph = load(buff);
                break;
                case 2:
                    printGraph(graph);
                break;
                case 3:
                    printf("\nInsira o vertice de origem: ");
                    scanf("%d", &origin); fflush(stdin);
                    printf("\n");
                    if(origin >= 0 && origin < graph->n)
                        dfs(graph, origin);
                    else
                        printf("Vertice invalido");
                    printf("\n");
                break;
                case 4:
                    printf("\nInsira o vertice de origem: ");
                    scanf("%d", &origin); fflush(stdin);
                    printf("\n");
                    if(origin >= 0 && origin < graph->n)
                        bfs(graph, origin);
                    else
                        printf("Vertice invalido");
                    printf("\n");
                break;
                case 5:
                    printf("\nInsira o vertice de origem: ");
                    scanf("%d", &origin); fflush(stdin);
                    printf("\n");
                    if(origin >= 0 && origin < graph->n)
                        bellmanFord(graph, origin);
                    else
                        printf("Vertice invalido\n");
                break;
                case 6:
                    printf("\n");
                    kruskal(graph);
                    printf("\n");
                break;
            }
        } else {
            printf("1- Carregar grafo\n");
            printf("0- Sair\n");
            scanf("%d", &op); fflush(stdin);

            switch(op) {
                case 1:
                    printf("\nInsira o caminho do arquivo\nExemplo: ./pasta/arquivo.txt\n");
                    fgets(buff, 256, stdin); fflush(stdin);
                    buff[strlen(buff)-1] = '\0';
                    graph = load(buff);
                break;
            }
        }
    }

    return 0;
}