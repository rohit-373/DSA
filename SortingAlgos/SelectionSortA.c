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

void selectionSort(int* arr, int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = getArr(n);
    printf("Unsorted array: \n");
    printArr(arr, n);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArr(arr, n);
    return 0;
}