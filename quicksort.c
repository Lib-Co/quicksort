#include <stdio.h>
#include <stdlib.h>

//Functionality to swap elements in the array using pointers
void swap(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
};

//Use last element in the array as the pivot: low is the first index, high is the last index in array
int partition(int arr[], int low, int high)
{
    //Place the pivot at the last index in the array. Sort elements to left- or right-handside of pivot after comparing values to pivot
    int pivot = arr[high];
    int i = (low - 1);
    //Iterate over array until last index is reached
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}



void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //Set pIndex as the partition idex
        int pIndex = partition(arr, low, high);
        //Sort elements left of the partition
        quickSort(arr, low, pIndex - 1);
        //Sort elements right of the partition
        quickSort(arr, pIndex + 1, high);
    }
}

//Iterate over array and print each value
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {5, 1, -21, 4, 2, 6, 3, -1, 45, 7, 89, 0, 11, 14, 8, 29, 43, -128, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nArray to sort: ");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("\nSorted array: ");
    printArray(arr, n);
    return 0;
}