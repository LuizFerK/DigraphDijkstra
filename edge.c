/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#include "edge.h"

Edge EDGE(int v1, int v2, int w) {
  return ((Edge) {.v1 = v1, .v2 = v2, .w = w});
}
