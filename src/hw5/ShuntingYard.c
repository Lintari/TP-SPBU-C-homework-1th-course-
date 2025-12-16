#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int change(char b)
{
    if (b == "(")
        return 4;
    if (b == "*")
        return 3;
    if (b == "/")
        return 2;
    if (b == "+")
        return 1;
    return 0;
}

char revChange(int b)
{
    if (b == 4)
        return "(";
    if (b == 3)
        return "*";
    if (b == 2)
        return "/";
    if (b == 1)
        return "+" ;
    return "-";
}

int main(void)
{
    headStack* opStack = newStack();
    char a[] = "2+9*(5-3*7)";
    int i = 0;
    // printf("%ld", strlen(a));

    while (i < strlen(a)) {
        if (a == "(" || a == ")") {
            if (a == "(")
                push(opStack, change(a));
            else {
		while( 
            } // пройтись по стеку и вывести все до открывающей скобки 
        } else if (a[i] != "*" && a[i] != "+" && a[i] != "-" && a[i] != "/") { //
            printf("%d", a[i]);
        }

        else {
	    if (getLen(opStack) == 0 ) push( opStack, change(a[i]);  
            else{
		 if ( change(a[i]) / 2 >= peek(opStack)) {
		    printf( "%c", a[i]);
}
		else push(opStack, change(a[i]);
	    }
        }
        printf("%c", a[i]);
        i++;
    }

    ListElement* pointer = opStack->head;// выводим остатки стека.
    for (int i = 0; i < getLen(opStack); i++) {
        printf("%c", revChange(getValue(pointer)));
        pointer = nextElm(pointer);
        return 0;
    }
}