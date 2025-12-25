#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct ListElement {
    int value; 
    struct ListElement* next; 

} ListElement;

typedef struct Stack{
    int len;
    ListElement* head; 

}Stack;


void push ( Stack* stack , int val){
    ListElement* newEl  = malloc(sizeof(ListElement));
    if (newEl == NULL) return ;
    newEl -> value = val;
    newEl -> next = stack-> head; 
    stack -> head = newEl;
    stack -> len ++;
}


int  pop (Stack* stack){
    if (stack-> len == 0){
	return -1; 
    }
    ListElement* val;
    val = stack->head;
    stack-> head = val-> next;
    free(val);
    stack -> len --;
    return 0;
}

int peek (Stack* stack){
    if( stack-> len == 0) return -1;
    return stack->head-> value;

}

Stack* newStack (void){
    Stack* stack  = malloc(sizeof(Stack));
    if (stack == NULL) return NULL;
    stack -> len = 0;
    stack -> head = NULL;
    return stack;
}

int getLen (Stack* stack){
    return stack->len;
}

int getValue (ListElement* element){
    return element->value; 
}

ListElement* nextElm (ListElement* element){
    return element-> next;
}

ListElement* getHead (Stack* stack){
    return stack-> head; 

}

void deleteStack (Stack* stack){
    while (stack->len > 0){
	pop(stack);
}
    free(stack);
}

