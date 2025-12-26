#include <stdio.h>
#include <stdlib.h>

int check(int a)
{
    int sum = 0;
    int val;
    for (int i = 0; i < 30; i++) {
        val = a & (1 << i);
        if (val != 0) {
            sum++;
            // printf( "%d\n", val);
            // printf("%d  ", sum);//(a & (1<< i )));
        }
    }
    return sum;
}

int main(void)
{

    int a, b;

    a = 255;
    b = 1024;
    if (check(a) > check(b))
        printf("%d\n", a);
    else
        printf("%d\n", b);
    // printf("%d", check(a));
    return 0;
}
