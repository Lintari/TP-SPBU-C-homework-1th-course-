#include "insrtSort.h"
#include <stdio.h>
#include <stdlib.h>

void push(List* list, int a)
{
    ListIter iter = getHead(list);
    while (iter != NULL && listNext(iter) != NULL && get(listNext(iter)) < a) {
        iter = listNext(iter);
    }
    insert(list, a, iter);
}

void pop(List* list, int a)
{
    ListIter iter = getHead(list);
    while (listNext(iter) != NULL && get(listNext(iter)) != a)
        iter = listNext(iter);
    removeEl(list, iter);
}

int main(void)
{
    int a = -1;
    int b = 0;
    printf("new stroke\n");
    List* list = newList();
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