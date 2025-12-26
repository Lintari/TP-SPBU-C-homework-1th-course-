#include <stdio.h>

int main(void)
{
    int count[28] = { 0 };
    for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 0; c <= 9; c++) {
                count[a + b + c]++;
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < 28; i++) {
        counter += count[i] * count[i];
    }
    printf("%d", counter);
    return 0;
}
