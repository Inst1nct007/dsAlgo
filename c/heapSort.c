#include <stdio.h>
#include "array.h"

void createMaxHeap(int* arr, int size);
int insertMaxHeap(int* arr, int size, int element);
void heapSort(int* arr, int size);
void heapify(int* arr, int size);

void main() {
    int* arr = allocateArray(); // returns an array arr[0] is always the size of arr, the actual array starts from arr[1]
    createMaxHeap(arr + 1, *arr);
    // *arr = insertMaxHeap(arr + 1, *arr, 33);
    // *arr = insertMaxHeap(arr + 1, *arr, 31);
    heapSort(arr + 1, *arr);
    printArray(arr + 1, *arr);
}

void heapSort(int* arr, int size) {
    int i = 0;
    int temp = size;
    while(i < size - 1) {
        heapify(arr, temp);
        temp--;
        i++;
    }
}

void heapify(int* arr, int size) { // Swaps the root element with the last, then creates max heap accordingly
    arr[0] += arr[size - 1];
    arr[size - 1] = arr[0] - arr[size - 1];
    arr[0] -= arr[size - 1];
    size--;
    int i = size - 1;
    while(i >= 0) {
        if(arr[i] < arr[i * 2 + 1] && i * 2 + 1 < size) {
            arr[i] += arr[i * 2 + 1];
            arr[i * 2 + 1] = arr[i] - arr[i * 2 + 1];
            arr[i] -= arr[i * 2 + 1];
            i = i * 2 + 1;
        }
        else if(arr[i] < arr[i * 2 + 2] && i * 2 + 2 < size) {
            arr[i] += arr[i * 2 + 2];
            arr[i * 2 + 2] = arr[i] - arr[i * 2 + 2];
            arr[i] -= arr[i * 2 + 2];
            i = i * 2 + 2;
        } else {
            i--;
        }
    }
}

int insertMaxHeap(int* arr, int size, int element) { // Inserts an element in the max heap
    int i = size;
    arr[size] = element;
    while(i >= 0) {
        if(arr[i] < arr[(i * 2) + 1] && i * 2 + 1 < size + 1) {
            arr[i] += arr[(i * 2) + 1];
            arr[(i * 2) + 1] = arr[i] - arr[(i * 2) + 1];
            arr[i] -= arr[(i * 2) + 1];
        } else if (arr[i] < arr[i * 2 + 2] && i * 2 + 2 < size + 1) {
            arr[i] += arr[i * 2 + 2];
            arr[i * 2 + 2] = arr[i] - arr[i * 2 + 2];
            arr[i] -= arr[i * 2 + 2];
        } else {
            i--;
        }
    }
    return size + 1;
}

void createMaxHeap(int* arr, int size) { // Creates the max heap with an array, a Max heap is where the parent element is always larger than it's children
    int i = size - 1;
    while(i >= 0) {
        if(arr[i] < arr[i * 2 + 1] && i * 2 + 1 < size) {
            arr[i] += arr[i * 2 + 1];
            arr[i * 2 + 1] = arr[i] - arr[i * 2 + 1];
            arr[i] -= arr[i * 2 + 1];
        } else if (arr[i] < arr[i * 2 + 2] && i * 2 + 2 < size) {
            arr[i] += arr[i * 2 + 2];
            arr[i * 2 + 2] = arr[i] - arr[i * 2 + 2];
            arr[i] -= arr[i * 2 + 2];
        } else {
            i--;
        }
    }
}
