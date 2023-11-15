#include <stdio.h>
#include "array.h"

int* selectionSort(int* arr, int size);
int* bubbleSort(int* arr, int size);

void main() {
    int* arr = allocateArray();
    int* sortedArr = bubbleSort(arr + 1, *arr);
    printArray(sortedArr, *arr);
}

int* selectionSort(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        int min = i;
        for(int j = i; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if(min != i) {
            arr[i] = arr[i] + arr[min];
            arr[min] = arr[i] - arr[min];
            arr[i] = arr[i] - arr[min];
        }
    }
    return arr;
}

int* bubbleSort(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] = arr[j] + arr[j + 1];
                arr[j+1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }
    return arr;
}