#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct ListElement {
    int value; 
    struct ListElement* next; 

} ListElement;

typedef struct headStack{
    int len;
    ListElement* head; 

}headStack;


void push ( headStack* stack , int b){
    ListElement* a  = malloc(sizeof(ListElement));
    if (a == NULL) return ;
    a -> value = b;
    a -> next = stack-> head; 
    stack -> head = a;
    stack -> len ++;
}


int  pop (headStack* a){
    if (a-> len == 0){
	return -1; // tyu dolbaeb
    }
    ListElement* b;
    b = a->head;
    a-> head = b-> next;
    free(b);
    a -> len --;
    return 0;
}

int peek (headStack* a){
    if( a-> len == 0) return -1;
    return a->head-> value;

}

headStack* newStack (void){
    headStack* stack  = malloc(sizeof(headStack));
    if (stack == NULL) return NULL;
    stack -> len = 0;
    stack -> head = NULL;
    return stack;
}

int getLen (headStack* a){
    return a->len;
}

int getValue (ListElement* a){
    return a->value; 
}

ListElement* nextElm (ListElement* a){
    return a-> next;
}

void deleteStack (headStack* a){
    while (a->len > 0){
	pop(a);
}
    free(a);
}

