#include <stdio.h>
#include "array.h"

int* selectionSort(int* arr, int size);
int* bubbleSort(int* arr, int size);
int* insertionSort(int* arr, int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void main() {
    int* arr = allocateArray(); // returns an array arr[0] is always the size of arr, the actual array starts from arr[1]
    mergeSort(arr + 1, 0, *arr - 1);
    printArray(arr + 1, *arr);
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
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }
    return arr;
}

int* insertionSort(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                arr[j] = arr[j] + arr[j - 1];
                arr[j - 1] = arr[j] - arr[j - 1];
                arr[j] = arr[j] - arr[j - 1];
            }
        }
    }
    return arr;
}

void mergeSort(int arr[], int left, int right) 
{ 
    if (left < right) { 
        int mid = left + (right - left) / 2; 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right); 
    } 
}

void merge(int arr[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int sizeOfLeft = mid - left + 1; 
    int sizeOfRight = right - mid;
  
    int L[sizeOfLeft], R[sizeOfRight]; 
  
    for (i = 0; i < sizeOfLeft; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < sizeOfRight; j++) 
        R[j] = arr[mid + 1 + j]; 
    i = 0; 
    j = 0; 
    k = left; 
    while (i < sizeOfLeft && j < sizeOfRight) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < sizeOfLeft) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < sizeOfRight) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
