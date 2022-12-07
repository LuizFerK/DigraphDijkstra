/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#include <stdio.h>
#include <stdlib.h>
#include "aresta.h"
#include "grafo.h"

int main() {
    int v, e, x, y, z, r, m;
    Grafo *grafo;

    scanf("%d %d", &v, &e);

    grafo = GRAFOconstroi(v);

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &x, &y, &z);

        GRAFOinsere_aresta(grafo, ARESTA(x, y, z));
    }

    scanf("%d", &r);

    for (int i = 0; i < r; i++) {
        scanf("%d %d", &x, &m);

        GRAFOdestinos_viaveis(grafo, x, m);
    }

    GRAFOdestroi(grafo);

    return 0;
}
