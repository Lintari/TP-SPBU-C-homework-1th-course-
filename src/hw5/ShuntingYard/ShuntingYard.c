#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int encode(char b) // две функции для того чтобы хранить в стеке операторы
{ // как раз в этой функции мы задаем понятие  operator precedence
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

char decode(int b)
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

int isOp(char a)
{
    if (a == '*' || a == '+' || a == '-' || a == '/')
        return 1;
    return 0;
}

int main(void)
{
    Stack* opStack = newStack(); //  объявили стек операторов
    char a[] = "2+3*(1-5/3+6+7-)";
    size_t i = 0;
    ListElement* pointer;
    printf("\n");
    while (i < strlen(a)) { //
        if ((a[i] == '(') || (a[i] == ')')) { // если скобки
            if (a[i] == '(')
                push(opStack, encode(a[i]));
            else {
                pointer = getHead(opStack);
                while (getValue(getHead(opStack)) != -4) { //  выводим все что было внутри скобок вплоть до открывающей
                    printf("%c", decode(getValue(pointer)));
                    pop(opStack); // не забываем в процессе удалять содерживмое стека
                    pointer = getHead(opStack);
                }
                pop(opStack);
            }

        } else if (isOp(a[i]) == 0) { // если символ
            printf("%c", a[i]);
        }

        else { // если оператор но не скобки
            if (getLen(opStack) == 0)
                push(opStack, encode(a[i]));
            else {
                if ((encode(a[i]) / 2) >= (peek(opStack) / 2)) { // проверяем operator presedence если он больше либо равен то просто пушим. в противном случае выводим предыдущий элемент из стека и затем пушим.
                    push(opStack, encode(a[i]));
                } else {
                    printf("%c", decode(peek(opStack)));
                    pop(opStack);
                    push(opStack, encode(a[i]));
                }
            }
        }
        i++;
    }

    pointer = getHead(opStack); // выводим остатки стека.
    for (int i = 0; i < getLen(opStack); i++) {
        printf("%c", decode(getValue(pointer)));
        pointer = nextElm(pointer);
    }
    return 0;
}
