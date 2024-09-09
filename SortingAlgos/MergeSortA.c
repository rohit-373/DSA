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

void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i];
    
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    
    while (i < n1) 
        arr[k++] = L[i++];
    
    while (j < n2) 
        arr[k++] = R[j++];
    
}

void mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = getArr(n);
    printf("Unsorted array: \n");
    printArr(arr, n);
    mergeSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArr(arr, n);
    return 0;
}