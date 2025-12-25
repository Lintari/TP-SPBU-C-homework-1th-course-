#pragma once

typedef  struct ListElement ListElement; 
typedef struct Stack Stack;


void  push (Stack*, int); 

int  pop (Stack*);


int peek (Stack*);

Stack* newStack (void);


void deleteStack ( Stack*);

int getLen (Stack*);
int getValue (ListElement*);
ListElement* nextElm (ListElement*);
ListElement* getHead (Stack*);

