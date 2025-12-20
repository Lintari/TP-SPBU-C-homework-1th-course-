#include "insrtSort.h"
#include <stdio.h>
#include <stdlib.h>

void push(headList* list, int a)
{
    ListIter p = getHead(list);
    while (p != NULL && listNext(p) != NULL && get(listNext(p)) < a) {
        p = listNext(p);
    }
    insert(list, a, p);
}

void pop(headList* list, int a)
{
    ListIter p = getHead(list);
    while (listNext(p) != NULL && get(listNext(p)) != a)
        p = listNext(p);
    removee(list, p);
}

int main(void)
{
    int a = -1;
    int b = 0;
    printf("new stroke\n");
    headList* list = newList();
    while (a != 0) {
        scanf("%d", &a);
        if (a == 1) { // insert
            scanf("%d", &b);
            push(list, b);
        } else if (a == 2) { // pop
            scanf("%d", &b);
            pop(list, b);
        }

        else if (a == 3) { // print
            showList(list);
        }
    }
}