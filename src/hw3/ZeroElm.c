#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* arr = malloc(100 * sizeof(int));
    int memCounter = 100;
    int len = 1;

    int a;
    scanf("%d", &a);
    arr[0] = a;

    char c;
    while ((c = getchar()) != '\n') {
        if (len == memCounter) {
            memCounter += 100;
            arr = realloc(arr, memCounter * sizeof(int));
        }
        scanf("%d", &a);
        arr[len] = a;
        len++;
    }
    
    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == 0) {
            counter++;
        }
    }
    
    printf("%d", counter);
    free(arr);
    return 0;
}
