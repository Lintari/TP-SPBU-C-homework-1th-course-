#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int change(char b) // две функции для того чтобы хранить в стеке операторы
{
    if (b == '(')
        return -4;
    if (b == '*')
        return 3;
    if (b == '/')
        return 2;
    if (b == '+')
        return 1;
    return 0;
}

char revChange(int b)
{
    if (b == 4)
        return '(';
    if (b == 3)
        return '*';
    if (b == 2)
        return '/';
    if (b == 1)
        return '+';
    return '-';
}

int main(void)
{
    headStack* opStack = newStack(); //  объявили стек операторов
    char a[] = "2+3*(2-1/5)";
    int i = 0;
    ListElement* pointer;
    printf("\n");
    while (i < strlen(a)) { //
        if ((a[i] == '(') || (a[i] == ')')) {
            if ((a[i] == '('))
                push(opStack, change(a[i]));
            else {
                pointer = getHead(opStack);
                while (getValue(getHead(opStack)) != -4) { //  выводим все что было внутри скобок вплоть до открывающей
                    printf("%c", revChange(getValue(pointer)));
                    pop(opStack);
                }
                pop(opStack);
            }

        } else if (a[i] != '*' && a[i] != '+' && a[i] != '-' && a[i] != '/') { //
            printf("%c", a[i]);
        }

        else {
            if (getLen(opStack) == 0)
                push(opStack, change(a[i]));
            else {
                if ((change(a[i]) / 2) >= (peek(opStack) / 2)) { // проверяем operator presedence
                    push(opStack, change(a[i]));
                } else
                    printf("%c", a[i]);
            }
        }
        i++;
    }

    pointer = getHead(opStack); // выводим остатки стека.
    for (int i = 0; i < getLen(opStack); i++) {
        printf("%c", revChange(getValue(pointer)));
        pointer = nextElm(pointer);
    }
    return 0;
}