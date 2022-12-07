/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#ifndef EDGE_H

#define EDGE_H

struct edge {
  int v1;
  int v2;
  int w;
};
typedef struct edge Edge;

Edge EDGE(int v1, int v2, int w);

#endif /* EDGE_H */
