#include "CycleList.h"
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

ListIter nextPoint(ListIter p)
{
    return p->next;
}

headList* newList(void)
{
    headList* list = malloc(sizeof(headList));
    ListElement* b = malloc(sizeof(ListElement));
    if (list == NULL)
        return NULL;
    list->len = 0;
    list->head = b;
    b->next = b;
    b->value = -1;
    return list;
}

/**
* @brief функция вставки элемента. 
* @note функция вставляет значение после итератора. Также отдельно рассматривается случай вставки первого элементп
*/

void insert(headList* list, int val, ListIter p)
{ 
    ListElement* newEl = malloc(sizeof(ListElement));
    if (newEl == NULL)
        return;
    if (list->head == p) { 
        p->next = newEl;
        newEl->next = newEl;
        list->len++;
        newEl->value = val;
        return;
    }
    newEl->next = p->next;
    newEl->value = val;
    p->next = newEl;
    list->len++;
}
/**
* @brief функция удаления элемента. 
* @note Отдельно рассматриваем случай когда мы удаляем элемент, с которым связана голова списка
*/
void removee(headList* list, ListIter p)
{
    ListElement* b;
    b = p->next;
    if (p->next == list->head->next) { 
        list->head->next = p;
    }
    p->next = p->next->next;
    list->len--;
    free(b);
}

int get(ListIter p)
{
    return p->value;
}

int getLen(headList* list)
{
    return list->len;
}

ListIter getHead(headList* list)
{

    return list->head->next;
}

ListIter getHeadHead(headList* list)
{
    return list->head; 
}

void showList(headList* list)
{
    ListIter p = list->head->next;
    for (int i = 0; i < list->len; i++) {
        printf("%d ", p->value);
        p = p->next;
    }
}
