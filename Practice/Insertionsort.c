#include<stdio.h>

void insertionSort(int arr[], int size)
{
    int i, j, key, flag=0;
    for(j=1; j<size; j++)
    {
        key = arr[j];
        i = j-1;
        while(i>=0 && arr[i] > key)
        {
            flag = 1;
            arr[i+1] = arr[i];
            i -= 1;
        }
        arr[i+1] = key;
    }
    if(!flag)
    {
        printf("\nThe array is already sorted.");
        return;
    }
    printf("\nThe sorted array is: ");
    for(i=0; i<size; i++)
        printf(" %d ", arr[i]);
}

void main()
{
    int arr[10], size, i;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);
    for(i=0; i<size; i++)
    {
        printf("\nEnter %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, size);
}