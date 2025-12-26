#include "insertSort.h"
#include <stdlib.h>
#include <stdio.h>


int main (void){
    int a;
    headList* list = newList();
    for (int i = 0; i<10; i++){
	scanf("%d", &a);
	push(list, a, 0); // учитывайте что список вводится задом наперед что впрочем не влияет на итоговый вывод
}
    printf("\n");
    for (int i = 1; i< getLen(list); i++){ // первый элемент уже отсортированн поэтому с 1 начинаем
	for( int j  = i;j>0 && getValue(list, j-1)>getValue(list,j)   ;j--){// внутри отсортированной  части сортируем
	    swap (list, j-1, j);
	}
}

    showList(list);
}