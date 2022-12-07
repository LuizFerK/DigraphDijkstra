/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "graph.h"

int main() {
  int v, e, x, y, z, r, m;
  scanf("%d %d", &v, &e);

  Graph *g = GRAPH(v);

  for (int i = 0; i < e; i++) {
    scanf("%d %d %d", &x, &y, &z);
    GRAPHinsert_edge(g, EDGE(x, y, z));
  }

  scanf("%d", &r);

  for (int i = 0; i < r; i++) {
    scanf("%d %d", &x, &m);
    GRAPHvar_dist(g, x, m);
  }

  GRAPHwipe(g);

  return 0;
}
