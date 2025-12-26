#include "quickSort.h"
#include <stdlib.h>

void sort(int* arr, int left, int right)
{
    if (left >= right)
        return;

    int pivot = arr[right]; //
    int index = left - 1;
    int lVal = left;
    while (lVal <= right) { // lVal is green one  and index is orange one
        if (arr[lVal] > pivot)
            lVal++;
        else {
            index++;
            if (lVal > index) {
                int c = arr[lVal];
                arr[lVal] = arr[index];
                arr[index] = c;
            }
            lVal++;
        }
    }
    sort(arr, left, index - 1);
    sort(arr, index + 1, right);
}
