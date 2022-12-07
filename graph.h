/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#ifndef GRAPH_H

#define GRAPH_H

#include "edge.h"

typedef struct graph Graph;

Graph *GRAPH(int num_vertices);

void GRAPHinsert_edge(Graph *g, Edge e);

void GRAPHremove_edge(Graph *g, Edge e);

void GRAPHdijkstra(Graph *g, int s, int *parent, int *wd);

void GRAPHvar_dist(Graph *g, int s, int m);

void GRAPHwipe(Graph *g);

#endif /* GRAPH_H */
