/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#ifndef ITEM_H

#define ITEM_H

struct item {
  int idx;
  int dist;
};
typedef struct item Item;

Item ITEM(int idx, int dist);

int ITEMcompare(Item item1, Item item2);

#endif /* ITEM_H */
