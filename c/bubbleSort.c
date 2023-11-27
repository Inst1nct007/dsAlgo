#include <stdio.h>
#include "array.h"

void bubbleSort(int* arr, int size);

int main() {
    int* arr = allocateArray(); // returns an array arr[0] is always the size of arr, the actual array starts from arr[1]
    bubbleSort(arr + 1, *arr);
    printArray(arr + 1, *arr);
}

void bubbleSort(int* arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        } // The highest element in the array bubbles up to the last position of the unsorted array
    } // This happens n - 1 times so every n - 1 elements bubble up to their appropriate place and the last element is automatically at it's place.
}
