#include "quickSort.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* arr = malloc(100 * sizeof(int));
    int i = 1;

    scanf("%d", &arr[0]);
    char c;

    while ((c = (char)getchar()) != '\n')
    {
        scanf("%d", &arr[i]);
        i++;
    }

    sort(arr, 0, i - 1);
    for (int y = 0; y < i; y++)
        printf("%d ", arr[y]);

    printf("\n");
    free(arr);
    return 0;
}
