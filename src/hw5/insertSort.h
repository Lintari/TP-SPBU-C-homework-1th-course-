#pragma once

typedef struct ListElement ListElement;
typedef struct headList headList;
typedef struct Pointer Pointer;


void push( headList*, int, int);

void pop (headList*, int);


headList* newList (void);

void deleteList (headList*);

int getValue (headList*, int);

void showList(headList*);

void swap(headList*, int, int);

int retValue (headList*, int);
int getLen( headList*);