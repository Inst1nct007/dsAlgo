#include "array.h"
#include <stdio.h>
#include <stdbool.h>

void linearSearch(int* arr, int size);
void binarySearch(int* arr, int size);

void main() {
    int* arr = allocateArray();
    linearSearch(arr + 1, *arr);
}

void linearSearch(int* arr, int size) {
    int element;
    bool elementFound = false;
    printf("Enter the element you want to search: ");
    scanf("%d", &element);
    for(int i=0; i<size; i++) {
        if(element == *(arr + i)) {
            printf("Element found at position %d", i + 1);
            elementFound = true;
            break;
        }
    }
    if(!elementFound) {
        printf("Element not present in array");
    }
}

void binarySearch(int* arr, int size) {
    int element;
    bool elementFound = false;
    printf("Enter the element you want to search: ");
    scanf("%d", &element);
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    while(start <= end) {
        if(arr[mid] == element) {
            printf("Element found at position %d", mid + 1);
            elementFound = true;
            break;
        }
        else if (element < arr[mid]) {
            end = mid - 1;
            mid = (start + end) / 2;
        }
        else {
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }
    if(!elementFound) {
        printf("Element not present in array");
    }
}