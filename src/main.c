#include "CycleList.h"
#include <stdio.h>
#include <stdlib.h>

ListIter pop(List* list, ListIter p, int m) // функция удаления следующего m-го элемента
{
    for (int i = 0; i < m - 1; i++) {
        p = nextPoint(p);
    }
    removeEl(list, p);
    return p;
}

int main(void) // будем последовательно удалять все элементы из списка пока в нем не останется один элемент. затем мы выводим список.
{
    int n, m; // n-  общее количетсво воинов, m - интервал убийства.
    scanf("%d %d", &n, &m);
    List* list = newList();
    ListIter p = getHead(list);
    insert(list, 1, p);
    p = getHead(list);
    for (int i = 2; i <= n; i++) { //  заполнили список
        insert(list, i, p);
        p = nextPoint(p);
    }

    while (getLen(list) != 1) { //  удалили все элементы пока не остался 1
        p = pop(list, p, m);
    }

    printf("\n");
    showList(list); // вывели тот самый 1 элемент
    return 0;
}