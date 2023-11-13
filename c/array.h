#include <stdio.h>
#include <stdlib.h>

int* allocateArray();

void printArray(int* arr);

int* allocateArray() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int* arr = (int*)malloc((size + 1) * sizeof(int));
    printf("Enter the elements of array: ");
    *arr = size;
    for(int i=1; i<=size; i++) {
        scanf("%d", &*(arr + i));
    }
    return arr;
}

void printArray(int* arr) {
    for(int i=0; i<*(arr); i++) {
        printf("%d ", *(arr + i + 1));
    }
}
