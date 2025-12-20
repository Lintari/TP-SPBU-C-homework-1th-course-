#include "insrtSort.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

typedef struct headList {
    int len;
    ListElement* head;
} headList;

typedef struct ListElement* ListIter;

ListIter getPoint(headList* list, int index)
{
    ListIter p = list->head->next;
    if (index == 0)
        return NULL;
    for (int i = 0; i < index; i++)
        p = p->next;
    return p;
}

ListIter listNext(ListIter p)
{ // функция понадобится в основной части кода
    return p->next;
}

void insert(headList* list, int val, ListIter p)
{ // на входе получили указатель, значение, и iter after which we should put
    ListElement* newEl = malloc(sizeof(ListElement));
    if (newEl == NULL)
        return;
    list->len++;
    newEl->next = p->next;
    newEl->value = val;
    p->next = newEl;
}

void removee(headList* list, ListIter p) // iter elemts after we should pop
{
    ListElement* b;
    if (p->next == NULL) {
        printf("вы пытаетесь удалить несуществующий элемент");
        return;
    }
    b = p->next;
    p->next = p->next->next;
    list->len--;
    free(b);
}

headList* newList(void)
{
    headList* list = malloc(sizeof(headList));
    ListElement* b = malloc(sizeof(ListElement)); // сделаем нулевой элемент чтобы упростить себе жизнь
    if (list == NULL)
        return NULL;
    list->len = 0;
    list->head = b;
    b->next = NULL;
    return list;
}

void deleteList(headList* list)
{
    while (list->len != 0) {
        removee(list, 0);
    }
    free(list);
}

int get(ListIter p)
{
    return p->value;
}

void showList(headList* list)
{
    ListIter p = list->head->next;
    for (int i = 1; i < list->len + 1; i++) {
        printf("%d ", p->value);
        p = p->next;
    }
}

int getLen(headList* list)
{
    return list->len;
}

ListElement* getHead(headList* list)
{
    return list->head;
}