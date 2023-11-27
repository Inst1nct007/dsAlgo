#include <stdio.h>
#include "array.h"

void insertionSort(int* arr, int size);

int main() {
    int* arr = allocateArray(); // returns an array arr[0] is always the size of arr, the actual array starts from arr[1]
    insertionSort(arr + 1, *arr);
    printArray(arr + 1, *arr);
}

void insertionSort(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                arr[j] = arr[j] + arr[j - 1];
                arr[j - 1] = arr[j] - arr[j - 1];
                arr[j] = arr[j] - arr[j - 1];
            }
        } // An element is swapped till it is at it's appropriate position
    } // This happens for n elements, so every element is at it's appropriate position
}
