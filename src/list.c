#include <stdio.h>
#include <stdlib.h>
#pragma once

typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

typedef struct HeadElement {
    int len;
    ListElement* head;
} HeadElement;

HeadElement* init(void)
{
    HeadElement* list  = malloc(sizeof(HeadElement));
    if (list == NULL)
        return NULL;
    list->len = 0;
    list->head = NULL;
    return list;
}

int pop(HeadElement* list)
{
    if (list->len == 0)
        return -1;
    ListElement* newEl;
    newEl = list->head;
    list->head = newEl->next;
    free(newEl);
    return 0;
}

void push(HeadElement* list, int val)
{
    ListElement* pointer;
    pointer = list->head;
    if (list->len == 0) {
        ListElement* newEl = malloc(sizeof(ListElement));
        if (newEl == NULL)
            return;
        list->head = newEl;
        list->len = 1;
        newEl->value = val;
        newEl->next = NULL;
    } else {
        while ((pointer->next) != NULL) {
            pointer = pointer->next;
        }
        ListElement* newEl = malloc(sizeof(ListElement));
        pointer->next = newEl;
        newEl->next = NULL;
        newEl->value = val;

        list->len++;
    }
}

void delete(HeadElement* list)
{
    while (list->len != 0) {
        pop(list);
    }
    free(list);
}
HeadElement* connect(HeadElement* list1, HeadElement* list2)
{

    ListElement* point11 = list1->head;
    ListElement* point12 = list1->head;
    ListElement* point21 = list2->head;

    for (int i = 0; i < list2->len - 1; i++) { // где-то тут видимо говоря core bumped происходит. я не знаю где. вероятно где-то разыменовываю указатель нулевой
        if (point12->next == NULL || point11->next == NULL || point21->next == NULL)
            return list1;
        point12 = point12->next; // по логике этот бро идет только по list1
        point11->next = point21; // вот здесь мы присоединяем указатель
        point11->next->next = point12; // здесь мы снова возвращаемся в list1
        point21 = point21->next; // этот бро идет только по list2
    }
    return list1;
}
int main(void)
{

    HeadElement* list1 = init();
    HeadElement* list2 = init();
    push(list1, 5);
    push(list1, 7);
    push(list1, 9);
    push(list2, 6);
    push(list2, 8);
    // push(q,10);
    ListElement* point = list1->head;
    for (int i = 0; i < list1->len; i++) {
        printf("%d ", point->value);
        point = point->next;
    }
    HeadElement* listEnd = connect(list1, list2);

    point = listEnd->head;

    for (int i = 0; i < (list1->len + list2->len); i++) {
        printf("%d", point->value);
        point = point->next;
    }
}