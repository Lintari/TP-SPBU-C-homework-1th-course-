#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int x, x2;
    scanf("%d", &x);
    x2 = x * x; // первое умножение
    printf("%d\n", (x2 + x + 1) * (x2 + 1) - x2); // второе умножение
    return 0;
}
