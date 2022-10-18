#include<stdio.h>

void bubblesort(int arr[], int size)
{
    int i, j, temp, flag=0;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag = 1;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(!flag)
        {
            printf("\nThe array is already sorted.");
            return;
        }
        
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
    
    bubblesort(arr, size);
}