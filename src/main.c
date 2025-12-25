#include "CycleList.h"
#include <stdio.h>
#include <stdlib.h>

ListIter pop(List* list, ListIter iter, int m) // функция удаления следующего m-го элемента
{
    for (int i = 0; i < m - 1; i++) {
        iter = nextPoint(iter);
    }
    removeEl(list, iter);
    return iter;
}

int main(void) // будем последовательно удалять все элементы из списка пока в нем не останется один элемент. затем мы выводим список.
{
    int n, m; // n-  общее количетсво воинов, m - интервал убийства.
    scanf("%d %d", &n, &m);
    List* list = newList();
    ListIter iter = getHead(list);
    insert(list, 1, iter);
    iter = getHead(list);
    for (int i = 2; i <= n; i++) { //  заполнили список
        insert(list, i, iter);
        iter = nextPoint(iter);
    }

    while (getLen(list) != 1) { //  удалили все элементы пока не остался 1
        iter = pop(list, iter, m);
    }

    printf("\n");
    showList(list); // вывели тот самый 1 элемент
    return 0;
}