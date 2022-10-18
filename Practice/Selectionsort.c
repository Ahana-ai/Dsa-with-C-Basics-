#include<stdio.h>

void selectionSort(int arr[], int size)
{
    int i, j, min, pos, temp, flag=0;
    for(i=0; i<size-1; i++)
    {
        min = arr[i];
        pos = i;
        for(j = i+1; j<size; j++)
        {
            if(min > arr[j])
            {
                flag = 1;
                min  = arr[j];
                pos = j;
            }
        }
        if(i != pos)
        {
            temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
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
    
    selectionSort(arr, size);
}