#pragma once

typedef struct ListElement ListElement;
typedef struct List List;
typedef struct ListElement* ListIter;

ListIter getPoint(List*, int);
ListIter listNext(ListIter);
void insert(List*, int, ListIter);
void removeEl(List*, ListIter);

List* newList(void);

void deleteList(List*);

int get(ListIter);

void showList(List*);

int getLen(List*);

ListElement* getHead(List*);