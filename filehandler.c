#include "filehandler.h"

#define BUFFER_SIZE 256

/*
Carrega um arquivo texto representando um grafo, gera um grafo e o retorna
Entrada: caminho do arquivo
Retorno: grafo gerado pelo arquivo
Pre-condicao: caminho de arquivo valido
Pos-condicao: um grafo eh carregado para a memoria
*/
Graph load(char * filename) {
    FILE * file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    int i = 0, oriented, n = 0, vertex, edge, weight, sign, pos = 0;
    Graph g = NULL;
    ListNode * aux = NULL;

    if(file == NULL) {
        printf("\nERRO: nao foi possivel carregar o grafo do arquivo texto, por favor cheque o caminho\n\n");
        return g;
    }

    fgets(buffer, BUFFER_SIZE-1, file);
    while(buffer[i] != '=') i++;
    while(buffer[i] != 's' && buffer[i] != 'n') i++;

    if(buffer[i] == 's' && buffer[i+1] == 'i' && buffer[i+2] == 'm')
        oriented = 1;
    else
        oriented = 0;

    i = 0;
    fgets(buffer, BUFFER_SIZE-1, file);
    while(buffer[i] != '=') i++;
    i++;
    while(buffer[i] > 47 && buffer[i] < 58) {
        n *= 10;
        n += (buffer[i] - 48);
        i++;
    }

    g = createGraph(n, oriented);

    i = 0;
    while(!feof(file)) {
        i = vertex = edge = weight = 0;
        sign = 1;
        buffer[0] = '\0';

        fgets(buffer, BUFFER_SIZE-1, file);

        if(buffer[0] != '(') continue;

        while(buffer[i] < 48 || buffer[i] > 57) i++;
        do {
            vertex *= 10;
            vertex += (buffer[i] - 48);
            i++;
        } while(buffer[i] > 47 && buffer[i] < 58);

        while(buffer[i] < 48 || buffer[i] > 57) i++;
        do {
            edge *= 10;
            edge += (buffer[i] - 48);
            i++;
        } while(buffer[i] > 47 && buffer[i] < 58);
        
        while(buffer[i] < 48 || buffer[i] > 57) i++;
        if(buffer[i-1] == '-') sign = -1;
        do {
            weight *= 10;
            weight += (buffer[i] - 48);
            i++;
        } while(buffer[i] > 47 && buffer[i] < 58);
        weight *= sign;

        g->vertex[vertex] = insertList(g->vertex[vertex], edge, weight);
        if(!oriented)
            g->vertex[edge] = insertList(g->vertex[edge], vertex, weight);
    }

    fclose(file);

    return g;
}