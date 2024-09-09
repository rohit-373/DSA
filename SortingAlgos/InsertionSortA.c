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

void insertionSort(int* arr, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = getArr(n);
    printf("Unsorted array: \n");
    printArr(arr, n);
    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArr(arr, n);
    return 0;
}