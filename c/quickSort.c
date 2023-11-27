#include <stdio.h>
#include "array.h"

void quickSort(int* arr, int start, int pivot);

void main() {
    int* arr = allocateArray(); // returns an array arr[0] is always the size of arr, the actual array starts from arr[1]
    quickSort(arr + 1, 0, *arr);
    printArray(arr + 1, *arr);
}

void quickSort(int* arr, int start, int end) {
    int pivot = end - 1, pos = start, i;
    for(i = start; i < pivot; i++) {
        if(arr[i] < arr[pivot]) {
            pos++;
        }
    }
    if(pos != pivot) {
        arr[pos] += arr[pivot];
        arr[pivot] = arr[pos] - arr[pivot];
        arr[pos] -= arr[pivot];
    }
    pivot = pos;
    i = start;
    pos = pivot + 1;
    while(i < pivot) {
        if(arr[i] > arr[pivot] && arr[pos] <= arr[pivot]) {
            arr[i] += arr[pos];
            arr[pos] = arr[i] - arr[pos];
            arr[i] -= arr[pos];
        }
        else if (arr[i] > arr[pivot] && arr[pos] > arr[pivot]) {
            pos++;
            i--;
        }
        i++;
    }
    if((pivot - start) > 1) {
        quickSort(arr, start, pivot);
    }
    if((end - pivot) > 1){
        quickSort(arr, pivot + 1, end);
    }
}
