#pragma once

typedef struct ListElement ListElement;
typedef struct List List;
typedef struct ListElement* ListIter;

ListIter nextPoint(ListIter);

List* newList(void);
void insert(List*, int, ListIter);
void removeEl(List*, ListIter);
int get(ListIter);
int getLen(List*);
ListIter getHead(List*);
ListIter getHeadHead(List*);
void showList(List*);
