#include "insertSort.h"
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


/*
typedef struct Pointer {
    ListElement* point;
} Pointer
*/

void push(headList* list, int val, int index)
{ // на входе получили указатель, значение, и индекс  куда вставить
    ListElement* p;
    ListElement* newEl = malloc(sizeof(ListElement));
    if (newEl == NULL)
        return;
    list->len ++;
    p = list->head;
    if (index == 0){
	list->head = newEl;
	newEl -> value = val;
	newEl -> next = p;
	return ;
    }

        for (int i = 0; i < index-1; i++) {
            p= p->next;
        }
	p = newEl;
	newEl->next = p->next;
	newEl-> value = val;
    
}

void pop(headList* list, int index)
{
    ListElement*  p; 
    p = list->head;
    ListElement* b;
    if ( p == NULL) return ;

    for (int i = 0; i < index ; i++){
	p = p->next;
	}
    b = p;
    p= p->next;
    free(b);
    list ->len  --;
}

headList* newList(void)
{
    headList* list = malloc(sizeof(headList));
    if (list == NULL)
        return NULL;
    list->len = 0;
    list->head = NULL;
    return list;
}

void deleteList(headList* list)
{
    while(list->len != 0){
	pop(list, 0);
    }
    free(list);
}

int getValue(headList* list, int index)
{
    ListElement* p = list->head;
    for(int i = 0; i < index; i++){
	p = p->next;	
}    
    return p->value;
}

void showList (headList* list){
    ListElement*p = list->head;
    for(int i = 0; i< list->len; i++){
	printf("%d ", p->value);
	p = p->next;

    }
}

int retVal (headList* list, int index){
    ListElement* p = list->head;
    for (int i = 0; i< index; i++) p = p->next;
    return  p->value; 
}

void swap (headList* list, int index1, int index2){
    ListElement *a,*b, *p;
    p = list->head;
    for( int i = 0; i < index2; i++){
	if (index1 == i) a = p;
	p = p->next;
    }
    b = p;
    int c = a->value;
    a->value = b->value;
    b->value = c;
}
int getLen (headList* list){
    return list->len;
}


