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
#include <stdbool.h>
#include <limits.h>
#include "graph.h"
#include "min_pri_queue.h"
#include "item.h"

typedef struct adjListNode {
  int v;
  int w;
  struct adjListNode *next;
} AdjListNode;

struct graph {
  int v_num;
  int e_num;
  AdjListNode **adj_lists;
};

static bool GRAPHvalid_vertex(Graph *g, int v) {
  if ((v >= 0) && (v <= (g->v_num - 1))) return true;
  return false;
}

static bool GRAPHvalid_edge(Graph *g, Edge e) {
  if (GRAPHvalid_vertex(g, e.v1) && GRAPHvalid_vertex(g, e.v2)) return true;
  return false;
}

Graph *GRAPH(int v_num) {
  Graph *g = malloc(sizeof(*g));

  g->v_num = v_num;
  g->e_num = 0;

  g->adj_lists = malloc(v_num * sizeof(*(g->adj_lists)));

  for (int i = 0; i < v_num; i++) {
    g->adj_lists[i] = NULL;
  }

  return g;
}

static bool GRAPHhave_edge(Graph *g, Edge e) {
  AdjListNode *neighbor;

  if (!GRAPHvalid_edge(g, e)) {
    printf("Error on operation GRAPHhave_edge: the edge %d %d is invalid!\n", e.v1, e.v2);
    exit(EXIT_FAILURE);
  }

  neighbor = g->adj_lists[e.v1];

  while (neighbor != NULL) {
    if (neighbor->v == e.v2) return true;

    neighbor = neighbor->next;
  }

  return false;
}

void GRAPHinsert_edge(Graph *g, Edge e) {
  AdjListNode *neighbor;

  if (!GRAPHvalid_edge(g, e)) {
    printf("Error on operation GRAPHinsert_edge: the edge %d %d is invalid!\n", e.v1, e.v2);
    exit(EXIT_FAILURE);
  }

  if (GRAPHhave_edge(g, e) || (e.v1 == e.v2)) return;

  neighbor = malloc(sizeof(*neighbor));
  neighbor->v = e.v2;
  neighbor->w = e.w;

  neighbor->next = g->adj_lists[e.v1];
  g->adj_lists[e.v1] = neighbor;

  g->e_num++;
}

void GRAPHremove_edge(Graph *g, Edge e) {
  AdjListNode *neighbor;
  AdjListNode *last_neighbor;

  if (!GRAPHvalid_edge(g, e)) {
    printf("Error on operation GRAPHremove_edge: the edge %d %d is invalid!\n", e.v1, e.v2);
    exit(EXIT_FAILURE);
  }

  last_neighbor = NULL;
  neighbor = g->adj_lists[e.v1];
  while (neighbor != NULL) {
    if (neighbor->v == e.v2) {
      if (last_neighbor == NULL) {
        g->adj_lists[e.v1] = neighbor->next;
      } else {
        last_neighbor->next = neighbor->next;
      }

      free(neighbor);

      g->e_num--;

      break;
    }

    last_neighbor = neighbor;
    neighbor = neighbor->next;
  }
}

void GRAPHwipe(Graph *g) {
  AdjListNode *aux;

  for (int i = 0; i < g->v_num; i++) {
    while (g->adj_lists[i] != NULL) {
      aux = g->adj_lists[i];
      g->adj_lists[i] = g->adj_lists[i]->next;

      free(aux);
    }
  }

  free(g->adj_lists);
  free(g);
}

void GRAPHdijkstra(Graph *g, int s, int *parent, int *wd) {
  MinPriQueue *q = MIN_PRI_QUEUE(g->v_num);
  Item item;

  for (int i = 0; i < g->v_num; i++) {
    parent[i] = -1;
    wd[i] = INT_MAX;
  }

  wd[s] = 0;

  for (int i = 0; i < g->v_num; i++) {
    MIN_PRI_QUEUEinsert(q, ITEM(i, wd[i]));
  }

  while (!MIN_PRI_QUEUEempty(q)) {
    item = MIN_PRI_QUEUEremove(q);

    if (item.dist != INT_MAX) {
      AdjListNode *u = g->adj_lists[item.idx];
      
      while (u != NULL) {
        if (wd[u->v] > item.dist + u->w) {
          wd[u->v] = item.dist + u->w;
          MIN_PRI_QUEUEupdate_dist(q, u->v, wd[u->v]);
          parent[u->v] = item.idx;
        }

        u = u->next;
      }
    }
  }

  MIN_PRI_QUEUEwipe(q);
}

void GRAPHvar_dist(Graph *g, int s, int m) {
  int *parent = malloc(g->v_num * sizeof(int));
  int *wd = malloc(g->v_num * sizeof(int));

  GRAPHdijkstra(g, s, parent, wd);

  // Prints
  for (int i = 0; i < g->v_num; i++) {
    if (wd[i] == INT_MAX || wd[i] > m) {
      printf("%d: sem caminho viavel partindo de %d\n", i, s);
    } else if (i != s) {
      printf("%d: %d,", i, wd[i]);

      int aux = i;

      while (parent[aux] != -1) {
        printf(" %d", aux);
        aux = parent[aux];
      }

      printf(" %d\n", s);
    }
  }
}
