#include "listlist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

typedef struct HeadList {
    int len;
    ListElement* head;
} HeadList;

void pushList(HeadList* a, int b)
{
    ListElement* arr = malloc(sizeof(ListElement));
    if (arr == NULL)
        return;
    arr->value = b;
    arr->next = NULL;
    int i, l = a->len;
    ListElement* pointer = a->head;
    for (i = 0; i < (l - 1); i++)
        ;
    pointer = pointer->next;
    pointer->next = arr;

    arr->value = b;
    arr->next = NULL;
    a->len++;
}

HeadList* newList(void)
{
    HeadList* list = malloc(sizeof(HeadList));
    if (list == NULL)
        return NULL;

    list->len = 0;
    list->head = NULL;
    return NULL;
}

void popList(HeadList* a)
{
    ListElement* b = a->head;

    a->len--;
    a->head = a->head->next;
    free(b);
}

void deleteList(HeadList* a)
{
    while (a->len != 0) {
        popList(a);
        free(a);
    }
}

HeadList* reverse(HeadList* a)
{
    ListElement *c, *b;
    b = a->head;
    a->head = NULL;

    int i;
    for (i = 0; i < a->len; i++) {
        c = b->next;
        b->next = a->head;
        a->head = b;
        b = c;
        return a;
    }
}