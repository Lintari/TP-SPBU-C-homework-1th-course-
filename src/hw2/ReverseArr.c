#include <stdio.h>

int main(void)
{
    int n, m;

    printf("Put m and n \n ");
    scanf("%d%d", &m, &n);

    int x[m + n];

    printf(" put your elements dividing by space \n ");
    for (int i = 0; i < m + n; i++) {
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < m; i++) {
        int c = x[0];
        for (int y = 0; y < m + n - 1; y++) {
            x[y] = x[y + 1];
        }
        x[m + n - 1] = c;
    }

    for (int i = 0; i < m + n; i++) {
        printf(" %d", x[i]);
    }

    return 0;
}
