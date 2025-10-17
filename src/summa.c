#include <stdio.h>
#include <stdlib.h>

int summm(int a)
{
    
    int sum = 0;
    while (a > 0)
        {
            sum = sum + a % 10;
            a = a / 10;

        }
    return sum;

}


int main (void)
{

    int a;
    int temp;
    printf ("введите длину массива");
    scanf ("%d\n", &a);
    int arr[a];

    for (int i=0; i<a; i++)
    {
        //printf("%d", a);
        scanf("%d", &arr [i]);// заполнили массив

    }


    for (int i=0; i<a-1; i++)
    {
        for (int y=0; y<a-1-i; y++)
            if ( summm(arr[y]) > summm(arr[y+1]))
            {
                temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
            


    }
    const int max = summm(arr[a-1]);

    for (int i=0; i<a; i++){
        if (max == summm(arr[i])){
            printf("%d ",arr[i]);
        }

    }

}