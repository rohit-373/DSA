#include <stdio.h>
#include <stdlib.h>

int* getArr(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) 
        scanf("%d", &arr[i]);
    return arr;
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int* arr, int n) {
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = getArr(n);
    printf("Unsorted array: \n");
    printArr(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArr(arr, n);
    return 0;
}