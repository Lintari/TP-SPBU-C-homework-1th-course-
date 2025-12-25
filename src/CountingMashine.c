#include "CycleList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief  Структура, представляющая узел списка
 * value -   Значение в узле  next  -  Указатель на следующий список
 */
typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

/**
 * @brief    Структура, представляющая циклический односвязный список
 * len - длина списка    head -  указатеь на один из элементов списка
 */
typedef struct List {
    int len;
    ListElement* head;
} List;

/**
 * @brief    Итератор для обхода списка
 */
typedef struct ListElement* ListIter;


/**
 * @brief  функция получения указателя на следующий элемент списка
 * @param p  Итератор, указывающий на действующий элемент
 */
ListIter nextPoint(ListIter iter)
{
    return iter->next;
}
/**
 * @brief  функция инициализации нового списка
 * @note head указывает NULL  на а len  = 0
 */
List* newList(void)
{
    List* list = malloc(sizeof(List));
    if (list == NULL)
        return NULL;
    list->len = 0;
    list->head = NULL;
    return list;
}

/**
 * @brief функция вставки элемента.
 * @param list   Указатель на сам список
 * @param val Значение которое будет сохранено в новом элементе
 * @param p  Итератор, указывающий на элемент списка после которого будет вставлен элемент
 * @warining  Передаваемый итератор должен указывать на существующий элемент списка
 * @note  После успешной вставки размер списка увеличивается на 1 и выделяется память под новый элемент.
 */
void insert(List* list, int val, ListIter iter)
{
    ListElement* newEl = malloc(sizeof(ListElement));
    if (newEl == NULL)
        return;
    if (list->len == 0) { // нам нужно избавиться от NULL и указать уже на существующую голову
        list->head = newEl;
        newEl->next = newEl;
        newEl->value = val;
        list->len = 1;
        return;
    }
    // стандартный случай
    newEl->next = iter->next;
    newEl->value = val;
    iter->next = newEl;
    list->len++;
}

/**
 * @brief функция удаления элемента.
 * @param list Указатель на сам список
 * @param p  Итератор, указывающий  на элемент списка после которого будет вставлен элемент
 * @note  После успешного удаления размер списка уменьшается на 1 и значение удаленного элемента стирается из памяти
 */
void removeEl(List* list, ListIter iter)
{
    ListElement* b;
    b = iter->next;
    if (b == list->head) { // значит мы хотим удалить элемент на который указывает голова. перенесем указатель головы
        list->head = iter;
    }
    iter->next = iter->next->next;
    list->len--;
    free(b);
}

/**
 * @brief функция получения значения по указателю
 * @param p Итератор, указывающий на необходимый нам обхект
 */
int get(ListIter iter)
{
    return iter->value;
}

/**
 * @brief функция получения длины списка
 * @param list  Указатель на сам список
 */
int getLen(List* list)
{
    return list->len;
}

/**
 * @brief Функция получения указателя на голову списка
 * @param list Указатель на сам список
 */
ListIter getHead(List* list)
{

    return list->head;
}

/**
 * @brief функция вывода списка
 * @param list   Указатель на сам список
 */
void showList(List* list)
{
    ListIter iter  = list->head;
    for (int i = 0; i < list->len; i++) {
        printf("%d ", iter->value);
        iter = iter->next;
    }
}
