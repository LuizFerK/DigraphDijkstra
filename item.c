/*
 * Tarefa 03 - Destinos Viaveis
 *
 * GEN254 - Grafos - 2022/2
 *
 * Nome:      Luiz Fernando Klein
 * Matricula: 2111100001
 */

#include "item.h"

Item ITEM(int ind, int chave) {
    return ((Item) {.ind = ind, .chave = chave});
}

int ITEMcompara(Item item1, Item item2) {
    return (item1.chave - item2.chave);
}