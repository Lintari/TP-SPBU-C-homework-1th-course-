#include <stdio.h>

int main()
{
    int count;
    char c;
    count = 0;
    while ((c = getchar()) != '\n') {
        if (c == '(') {
            count++;
        } else if (c == ')') {
            count--;

            if (count < 0) {
                break;
            }
        }
    }

    if (count == 0) {
        printf("Выражение корректно\n");
    } else {
        printf("Выражение некорректно\n");
    }

    return 0;
}
