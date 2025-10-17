
// код не дописан 
#include <stdio.h>
#include <string.h>

char bin(int){
    
}


int palindrom (char* a,int x){
    int l = 1;
    for (i = 0; i<x; i++ ){
        if ( *(a+i) != *(a+x-i)){
            l = 0;
        }
    }
    return l
}


int main (void){
    int a;
    scanf("%d", &a);
    char b[] = "hello";
    char* pt = b;
    printf("%c %d", *pt, strlen(b));

    for (int i = 1; i<a+1; i++)
    {
        if (palindrom(bin(i)) == 1)
        {
            printf("%d ", i);
        }

    }

}