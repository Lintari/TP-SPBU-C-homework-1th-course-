#pragma once

typedef struct ListElement ListElement;
typedef struct headList headList;
typedef struct ListElement* ListIter;

ListIter nextPoint(ListIter);

headList* newList(void);
void insert(headList*, int, ListIter);
void removee(headList*, ListIter);
int get(ListIter);
int getLen(headList*);
ListIter getHead(headList*);
ListIter getHeadHead(headList*);
void showList(headList*);
