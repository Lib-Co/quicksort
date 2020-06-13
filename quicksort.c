#include <stdio.h>
#include <stdlib.h>


//Functionality to swap elements in the array using pointers
void swap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
};

//Use last element in the array as the pivot
//Split array into two parts
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        //Sort elements left of the partition
        quickSort(arr, low, pIndex - 1);
        //Sort elements right of the partition
        quickSort(arr, pIndex + 1, high);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {5, 1, -21, 4, 2, 6, 3, -1, 45, 7, 89, 0, 11, 14, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\nArray to sort: ");
    printArray(arr, n);    
    quickSort(arr, 0, n - 1);
    printf("\nSorted array: ");
    printArray(arr, n);
    return 0;
}