#include <stdio.h>
#include "array.h"

void selectionSort(int* arr, int size);

int main() {
    int* arr = allocateArray(); // returns an array arr[0] is always the size of arr, the actual array starts from arr[1]
    selectionSort(arr + 1, *arr);
    printArray(arr + 1, *arr);
}

void selectionSort(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        int min = i;
        for(int j = i; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j; // The minimum within the unsorted array is selected 
            }
        }
        if(min != i) {
            arr[i] = arr[i] + arr[min];
            arr[min] = arr[i] - arr[min];
            arr[i] = arr[i] - arr[min];
        } // The minimum is swapped with the first position of the unsorted array
    }
}
