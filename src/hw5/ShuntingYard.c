#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int change(char b)
{
    if (b == "(")
        return 5;
    if (b == ")")
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
    if (b == 5)
        return "(";
    if (b == 4)
        return ")";
    if (b == 3)
        return "*";
    if (b == 2)
        return "/";
    if (b == 1)
        return "+" return;
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
		
            } // пройтись по стеку и вывести все до открывающей скобки 
        } else if (a[i] != "*" && a[i] != "+" && a[i] != "-" && a[i] != "/") { //
            printf("%d", a[i]);
        }

        else {
	    if (opStack -> len == 0 )
            if (a[i] == z "*" || a[i] == "/") { // эти операции имеют более высокий приоритет а значит просто добавляются в стек
		
            }
	     else {  в противном случае выводим данный знак
            
	    }
        }
        printf("%c", a[i]);
        i++;
    }

    ListElement* pointer = opStack->head;// выводим остатки стека.
    for (int i = 0; i < opStack->len; i++) {
        printf("%c", revChange(pointer->value));
        pointer = pointer->next;
        return 0;
    }
}