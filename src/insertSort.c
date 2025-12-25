#include "insrtSort.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

typedef struct List {
    int len;
    ListElement* head;
} List;

typedef struct ListElement* ListIter;

ListIter getPoint(List* list, int index)
{
    ListIter iter = list->head->next;
    if (index == 0)
        return NULL;
    for (int i = 0; i < index; i++)
        iter = iter->next;
    return iter;
}

ListIter listNext(ListIter iter)
{ // функция понадобится в основной части кода
    return iter->next;
}

void insert(List* list, int val, ListIter iter)
{ // на входе получили указатель, значение, и iter after which we should put
    ListElement* newEl = malloc(sizeof(ListElement));
    if (newEl == NULL)
        return;
    list->len++;
    newEl->next = iter->next;
    newEl->value = val;
    iter->next = newEl;
}

void removeEl(List* list, ListIter iter) // iter elemts after we should pop
{
    ListElement* b;
    if (iter->next == NULL) {
        printf("вы пытаетесь удалить несуществующий элемент");
        return;
    }
    b = iter->next;
    iter->next = iter->next->next;
    list->len--;
    free(b);
}

List* newList(void)
{
    List* list = malloc(sizeof(List));
    ListElement* b = malloc(sizeof(ListElement)); // сделаем нулевой элемент чтобы упростить себе жизнь
    if (list == NULL)
        return NULL;
    list->len = 0;
    list->head = b;
    b->next = NULL;
    return list;
}

void deleteList(List* list)
{
    while (list->len != 0) {
        removeEl(list, 0);
    }
    free(list);
}

int get(ListIter iter)
{
    return iter->value;
}

void showList(List* list)
{
    ListIter iter = list->head->next;
    for (int i = 1; i < list->len + 1; i++) {
        printf("%d ", iter->value);
        iter = iter->next;
    }
}

int getLen(List* list)
{
    return list->len;
}

ListElement* getHead(List* list)
{
    return list->head;
}