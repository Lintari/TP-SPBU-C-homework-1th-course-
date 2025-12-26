#include <stdio.h>
#include <stdlib.h>

int check(int value, int len, int* b)
{ //  тыкс. подаем на вход список длину списка и элемент. бежим. проверяем каждый элемент. вообще можно это сделать более потимизированно через сорт но как будто бы на контрольной не до этого
    for (int i = 0; i < len; i++) {
        if (b[i] - 1 == value) {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int* arr = NULL;
    int len = 0;
    int a = -1;
    while (a != 0) {

        scanf("%d", &a);

        arr = realloc(arr, sizeof(int));
        arr[len] = a;
        len++;
    }

    for (int i = 0; i < len - 1; i++) {
        if (check(arr[i], len, arr) == 0) {
            printf("%d ", arr[i]);
        }
    }
    free(arr);
    return 0;
}
