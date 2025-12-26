#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
 
    if (b == 0) {
        printf("Деление на 0");
        return 0;
    }
 
    int sign;
    if (a * b > 0) {
        sign = 1;
    } else {
        sign = -1;
    }
 
    int absA = abs(a);
    int absB = abs(b);
    int counter = 0;
 
    while (absA >= 0) {
        absA -= absB;
        counter++;
    }
    absA += absB;
    counter--;
 
    if (absA == 0) {
        printf("%d", sign * counter);
    } else {
        printf("%d", sign * (counter + (a < 0)));
    }
    return 0;
}
 
