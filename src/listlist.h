#pragma once

typedef struct ListElement ListElement;
typedef struct HeadList HeadList;

HeadList* newList(void);

void deleteList(HeadList*);
void pushList(HeadList*, int);
void popList(HeadList*);

HeadList* reverseList(HeadList*);
