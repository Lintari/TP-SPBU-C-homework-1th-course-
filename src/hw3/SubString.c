#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char c;
    char* S = malloc(100 * sizeof(char));
    int len = 0;
    int memCounter = 100;

    printf("Введите строку S: ");
    while ((c = getchar()) != '\n') {
        if (len + 1 == memCounter) {
            memCounter += 100;
            S = realloc(S, sizeof(char) * memCounter);
        }
        S[len] = c;
        len++;
    }
    S[len] = '\0';

    char* S1 = malloc(100 * sizeof(char));
    int len1 = 0;
    memCounter = 100;
    printf("Введите S1: ");
    while ((c = getchar()) != '\n') {
        if (len1 + 1 == memCounter) {
            memCounter += 100;
            S1 = realloc(S1, sizeof(char) * memCounter);
        }
        S1[len1] = c;
        len1++;
    }
    S1[len1] = '\0';

    int count = 0;
    char* pos = S;

    while ((pos = strstr(pos, S1)) != NULL) {
        count++;
        pos += len1;
    }

    printf("Количество вхождений %d\n", count);

    free(S);
    free(S1);
    return 0;
}
