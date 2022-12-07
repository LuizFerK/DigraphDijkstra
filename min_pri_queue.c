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
#include "item.h"
#include "min_pri_queue.h"

struct minPriQueue {
  Item *items;
  int *queue_idx;
  int max_n;
  int n;
};

bool valid_idx(MinPriQueue *q, int idx) {
  if ((idx >= 0) && (idx <= (q->max_n - 1))) return true;
  return false;
}

int parent(int i) {
  return ((i - 1) / 2);
}

int left_child(int i) {
  return ((2 * i) + 1);
}

int right_child(int i) {
  return ((2 * i) + 2);
}

void swap(MinPriQueue *q, int i, int j) {
  Item aux = q->items[i];
  q->items[i] = q->items[j];
  q->items[j] = aux;

  q->queue_idx[q->items[i].idx] = i;
  q->queue_idx[q->items[j].idx] = j;
}

void fixUp(MinPriQueue *q, int i) {
  while (i > 0) {
    if (ITEMcompare(q->items[i], q->items[parent(i)]) >= 0) break;

    swap(q, i, parent(i));
    i = parent(i);
  }
}

void fixDown(MinPriQueue *q, int i) {
  int smaller_child;

  while (left_child(i) < q->n) {
    smaller_child = left_child(i);

    if (right_child(i) < q->n) {
      if (ITEMcompare(q->items[right_child(i)], q->items[left_child(i)]) < 0) {
        smaller_child = right_child(i);
      }
    }

    if (ITEMcompare(q->items[i], q->items[smaller_child]) <= 0) break;

    swap(q, i, smaller_child);
    i = smaller_child;
  }
}

MinPriQueue *MIN_PRI_QUEUE(int max_n) {
  MinPriQueue *q;

  q = malloc(sizeof(*q));

  q->items = malloc(max_n * sizeof(*(q->items)));

  q->queue_idx = malloc(max_n * sizeof(*(q->queue_idx)));
  for (int i = 0; i < max_n; i++) {
    q->queue_idx[i] = -1;
  }

  q->max_n = max_n;
  q->n = 0;

  return q;
}

bool MIN_PRI_QUEUEempty(MinPriQueue *q) {
  return (q->n == 0);
}

bool MIN_PRI_QUEUEfull(MinPriQueue *q) {
  return (q->n == q->max_n);
}

bool MIN_PRI_QUEUEhave_idx(MinPriQueue *q, int idx) {
  if (!valid_idx(q, idx)) {
    printf("Error on operation MIN_PRI_QUEUEhave_idx: the index %d is invalid!\n", idx);
    exit(EXIT_FAILURE);
  }

  return (q->queue_idx[idx] != -1);
}

void MIN_PRI_QUEUEinsert(MinPriQueue *q, Item i) {
  if (MIN_PRI_QUEUEfull(q)) {
    printf("Error on operation MIN_PRI_QUEUEinsert: queue full!\n");
    exit(EXIT_FAILURE);
  }

  if (!valid_idx(q, i.idx)) {
    printf("Error on operation MIN_PRI_QUEUEinsert: the index %d is invalid!\n", i.idx);
    exit(EXIT_FAILURE);
  }

  if (MIN_PRI_QUEUEhave_idx(q, i.idx)) {
    printf("Error on operation MIN_PRI_QUEUEinsere: the idx %d already exists on the queue!\n", i.idx);
    exit(EXIT_FAILURE);
  }

  q->items[q->n] = i;
  q->queue_idx[i.idx] = q->n;
  q->n++;

  fixUp(q, (q->n - 1));
}

Item MIN_PRI_QUEUEremove(MinPriQueue *q) {
  Item i;

  if (MIN_PRI_QUEUEempty(q)) {
    printf("Error on operation MIN_PRI_QUEUEremove: empty queue!\n");
    exit(EXIT_FAILURE);
  }

  i = q->items[0];

  q->queue_idx[q->items[0].idx] = -1;

  q->items[0] = q->items[q->n - 1];
  q->queue_idx[q->items[0].idx] = 0;

  q->n--;

  fixDown(q, 0);

  return i;
}

int MIN_PRI_QUEUEdist(MinPriQueue *q, int idx) {
  if (!valid_idx(q, idx)) {
    printf("Error on operation MIN_PRI_QUEUEdist: the index %d is invalid!\n", idx);
    exit(EXIT_FAILURE);
  }

  if (!MIN_PRI_QUEUEhave_idx(q, idx)) {
    printf("Error on operation MIN_PRI_QUEUEdist: the index %d does not exists on the queue!\n", idx);
    exit(EXIT_FAILURE);
  }

  return q->items[q->queue_idx[idx]].dist;
}

void MIN_PRI_QUEUEupdate_dist(MinPriQueue *q, int idx, int c) {
  if (!valid_idx(q, idx)) {
    printf("Error on operation MIN_PRI_QUEUEupdate_dist: the index %d is invalid!\n", idx);
    exit(EXIT_FAILURE);
  }

  if (!MIN_PRI_QUEUEhave_idx(q, idx)) {
    printf("Error on operation MIN_PRI_QUEUEupdate_dist: the index %d does not exists on the queue!\n", idx);
    exit(EXIT_FAILURE);
  }

  q->items[q->queue_idx[idx]].dist = c;

  fixUp(q, q->queue_idx[idx]);
}

void MIN_PRI_QUEUEwipe(MinPriQueue *q) {
  free(q->items);
  free(q->queue_idx);

  free(q);
}
