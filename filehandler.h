#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

/*
Carrega um arquivo texto representando um grafo, gera um grafo e o retorna
Entrada: caminho do arquivo
Retorno: grafo gerado pelo arquivo
Pre-condicao: caminho de arquivo valido
Pos-condicao: um grafo eh carregado para a memoria
*/
Graph load(char * filename);

#endif // FILEHANDLER_H