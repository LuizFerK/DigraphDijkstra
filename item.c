/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#include "item.h"

Item ITEM(int idx, int dist) {
  return ((Item) {.idx = idx, .dist = dist});
}

int ITEMcompare(Item item1, Item item2) {
  return (item1.dist - item2.dist);
}