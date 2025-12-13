#include <stdlib.h>
#include <stdio.h>
#pragma once

typedef struct ListElement{
    int value;
    struct ListElement* next;
}ListElement;

typedef struct HeadElement{
    int len;
    ListElement* head;
}HeadElement;

HeadElement* init (void){
    HeadElement* s = malloc(sizeof(HeadElement));
    if (s == NULL) return NULL;
    s -> len = 0;
    s -> head = NULL;
    return s;
}


int  pop (HeadElement* s){
    if (s -> len == 0) return -1;
    ListElement* b;
    b = s->head;
    s->head = b->next;
    free(b);
    return 0;
}

void  push (HeadElement* s, int a){
    ListElement* b;
    b = s-> head;
    if (s-> len == 0){
	ListElement* q = malloc(sizeof(ListElement));
	if (q == NULL) return ;
	s ->head = q;
	s -> len = 1;
	q -> value = a;
	q -> next = NULL;
    }
    else{
	while ((b->next)!= NULL){
	    b = b->next;
	}    
	ListElement*q = malloc(sizeof(ListElement));
	b-> next = q;
	q-> next = NULL;
	q-> value = a;
    
    s -> len ++;
    }
    
}

void  delete(HeadElement* s){
    while (s-> len != 0){
	pop(s);
    }
    free(s);
}
HeadElement*  connect (HeadElement* a, HeadElement* b){  

    ListElement* c = a->head;
    ListElement* d = b->head;
    ListElement* e = a->head;	

    for (int i = 0; i< b->len-1; i++){ // где-то тут видимо говоря core bumped происходит. я не знаю где. вероятно где-то разыменовываю указатель нулевой
	if (e->next == NULL || c->next == NULL || d-> next == NULL )  return a;
	e = e->next; // по логике этот бро идет только по а
	c->next = d;// вот здесь мы присоединяем указатель
	c->next->next = e; // здесь мы снова возвращаемся в а
	d = d->next;// этот бро идет только по b
    }
    return a;

}
int main (void){

    HeadElement* d = init();
    HeadElement* q = init();
    push(d,5);
    push(d,7);
    push(d,9);
    push(q,6);
    push(q,8);
    //push(q,10);
    ListElement* point = d->head;
    for (int i  = 0; i< d->len; i++){
	printf("%d ",  point->value );
	point = point->next;
    }
    HeadElement* end = connect(d,q);

    point = end->head;

    for (int i = 0; i<(d->len + q-> len); i++){
	printf("%d", point-> value);
	point = point -> next;

    }
}