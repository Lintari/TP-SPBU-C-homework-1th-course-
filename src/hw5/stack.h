#pragma once

typedef  struct ListElement ListElement; 
typedef struct headStack headStack;


void  push (headStack*, int); 

int  pop (headStack*);


int peek (headStack*);

headStack* newStack (void);


void deleteStack ( headStack*);

int getLen (headStack*);
int getValue (ListElement*);
ListElement* nextElm (ListElement*);
ListElement* getHead (headStack*);