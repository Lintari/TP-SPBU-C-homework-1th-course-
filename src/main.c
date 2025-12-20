#include "CycleList.h"
#include <stdio.h>
#include <stdlib.h>
void pop(headList* list, ListIter p, int m)
{
    for (int i = 0; i < m - 1; i++) {
        p = nextPoint(p);
    }
    removee(list, p);
}

int main(void)
{
    int n, m; // n - общее количество воинов   m - какого по счету убивают
    scanf("%d %d", &n, &m);
    headList* list = newList();
    ListIter p = getHead(list);
    for (int i = 1; i <= n; i++) { // сгенерировали список.
        insert(list, i, p);
        p = nextPoint(p);
    }
    p = getHeadHead(list);
    while (getLen(list) != 1) {
        pop(list, p, m);
    }
    printf("\n");
    showList(list); // вернули позицию
    return get(p);
}