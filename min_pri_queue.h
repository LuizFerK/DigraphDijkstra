/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#ifndef MIN_PRI_QUEUE_H

#define MIN_PRI_QUEUE_H

#include <stdbool.h>
#include "item.h"

typedef struct minPriQueue MinPriQueue;

MinPriQueue *MIN_PRI_QUEUE(int max_n);

bool MIN_PRI_QUEUEempty(MinPriQueue *q);

bool MIN_PRI_QUEUEfull(MinPriQueue *q);

bool MIN_PRI_QUEUEhave_idx(MinPriQueue *q, int ind);

void MIN_PRI_QUEUEinsert(MinPriQueue *q, Item i);

Item MIN_PRI_QUEUEremove(MinPriQueue *q);

int MIN_PRI_QUEUEdist(MinPriQueue *q, int ind);

void MIN_PRI_QUEUEupdate_dist(MinPriQueue *q, int ind, int c);

void MIN_PRI_QUEUEwipe(MinPriQueue *q);

#endif /* MIN_PRI_QUEUE_H */
