#pragma once

typedef struct ListElement ListElement;
typedef struct headList headList;
typedef struct ListElement* ListIter;

ListIter getPoint(headList*, int);
ListIter listNext(ListIter);
void insert(headList*, int, ListIter);
void removee(headList*, ListIter);

headList* newList(void);

void deleteList(headList*);

int get(ListIter);

void showList(headList*);

int getLen(headList*);

ListElement* getHead(headList*);