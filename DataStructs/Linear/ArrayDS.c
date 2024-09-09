#include <stdio.h>
#include <stdlib.h>

int* getArr(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    return arr;
}

void printArr(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int start, int end) {
    for (; start < end; start++, end--) {
        swap(&arr[start], &arr[end]);
    }
}

void rightShift(int *arr, int size, int d) {
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = arr[size-d+i];
    for (int i = size-1-d; i >= 0; i--)
        arr[i+d] = arr[i];
    for (int i = 0; i < d; i++)
        arr[i] = temp[i];
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = getArr(size);
    printArr(arr, size);
    //reverse(arr, 0, size - 1);
    rightShift(arr, size, 3);
    printArr(arr, size);
    return 0;
}