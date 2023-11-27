#include <stdio.h>
#include "array.h"

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void main() {
    int* arr = allocateArray(); // returns an array arr[0] is always the size of arr, the actual array starts from arr[1]
    mergeSort(arr + 1, 0, *arr - 1);
    printArray(arr + 1, *arr);
}

void mergeSort(int arr[], int left, int right) 
{ 
    if (left < right) { 
        int mid = (left + right) / 2; 
        mergeSort(arr, left, mid); // merge sort the left array
        mergeSort(arr, mid + 1, right); // merge sort the right array
        merge(arr, left, mid, right); // merge the left and the right sub arrays
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
