#include "listlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    HeadList* s = newsList();
    pushList(s, 4);
    pushList(s, 5);
    deleteList();
    return 0;
}