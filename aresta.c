/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#include "aresta.h"

Aresta ARESTA(int v1, int v2, int p) {
    return ((Aresta) {.v1 = v1, .v2 = v2, .p = p});
}
