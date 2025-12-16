#pragma once

typedef  struct ListElement ListElement; 
typedef struct headStack headStack;


void  push (headStack*, char ); 

int  pop (headStack*);


int peek (headStack*);

headStack* newStack (void);


void deleteStack ( headStack*);

int getLen (headStack*);
