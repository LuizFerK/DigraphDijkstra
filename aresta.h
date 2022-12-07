/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#ifndef ARESTA_H

#define ARESTA_H

struct aresta {
    int v1;
    int v2;
    int p;
};
typedef struct aresta Aresta;

Aresta ARESTA(int v1, int v2, int p);

#endif /* ARESTA_H */
