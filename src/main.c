#include "CycleList.h"
#include <stdio.h>
#include <stdlib.h>

/*
*@brief  удаляем удаляет следующий по счету m - ый элемент
*/
void pop(headList* list, ListIter p, int m)
{
    for (int i = 0; i < m - 1; i++) {
        p = nextPoint(p);
    }
    removee(list, p);
}

/**
* @param n  количество воинов
* @param m  какого по счету убивают 
* @return последнего оставшегося
*/

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    headList* list = newList();
    ListIter p = getHead(list);
    for (int i = 1; i <= n; i++) { 
        insert(list, i, p);
        p = nextPoint(p);
    }
    p = getHeadHead(list);
    while (getLen(list) != 1) {
        pop(list, p, m);
    }
    printf("\n");
    showList(list); 
    return get(p);
}