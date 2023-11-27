#include <stdio.h>
#include "array.h"

int* selectionSort(int* arr, int size);
int* bubbleSort(int* arr, int size);
int* insertionSort(int* arr, int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quickSort(int* arr, int start, int pivot);
void createMaxHeap(int* arr, int size);
int insertMaxHeap(int* arr, int size, int element);
void heapSort(int* arr, int size);
void heapify(int* arr, int size);

void main() {
    int* arr = allocateArray(); // returns an array arr[0] is always the size of arr, the actual array starts from arr[1]
    createMaxHeap(arr + 1, *arr);
    *arr = insertMaxHeap(arr + 1, *arr, 33);
    *arr = insertMaxHeap(arr + 1, *arr, 31);
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

void createMaxHeap(int* arr, int size) { // Creates the max heap with an array
    int i = 0;
    while(i < size) {
        if(arr[i] < arr[i * 2 + 1] && i * 2 + 1 < size) {
            arr[i] += arr[i * 2 + 1];
            arr[i * 2 + 1] = arr[i] - arr[i * 2 + 1];
            arr[i] -= arr[i * 2 + 1];
            i = i / 2;
        } else if (arr[i] < arr[i * 2 + 2] && i * 2 + 2 < size) {
            arr[i] += arr[i * 2 + 2];
            arr[i * 2 + 2] = arr[i] - arr[i * 2 + 2];
            arr[i] -= arr[i * 2 + 2];
            i = i / 2;
        } else {
            i++;
        }
    }
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

int* selectionSort(int* arr, int size) {
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
    return arr;
}

int* bubbleSort(int* arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        } // The highest element in the array bubbles up to the last position of the unsorted array
    } // This happens n - 1 times so every n - 1 elements bubble up to their appropriate place and the last element is automatically at it's place.
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
        } // An element is swapped till it is at it's appropriate position
    } // This happens for n elements, so every element is at it's appropriate position
    return arr;
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
