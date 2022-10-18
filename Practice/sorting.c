#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int *arr, int lbound, int mid, int upbound)
{
    int i = lbound;
    int j = mid+1;
    int k = lbound;
    int b[10];
    while(i <= mid && j <= upbound)
    {
        if(arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    //if(i > mid)
    {
        while(j <= upbound)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    //else
    {
        while(i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for(k=lbound; k<=upbound; k++)
        arr[k] = b[k];
}

void bubbleSort(int *arr, int size)
{
    int temp, i, j, flag;
    for(i=0; i<size-1; i++)
    {
        flag = 0;
        for(j=0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nThe array is already sorted.");
            break;
        }
    }
    
}

void insertionSort(int *arr, int size)
{
    int i, j, key, flag = 0;
    for(i=1; i<size; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
            flag = 1;
        }
        arr[j+1] = key;
    }
    if(flag == 0)
        printf("\nThe array is already sorted.");
}

void selectionSort(int *arr, int size)
{
    int min, i, j, flag = 0;
    for(i=0; i<size-1; i++)
    {
        min = i;
        for(j=i+1; j<size; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
                flag = 1;
            }
        }
            swap(&arr[i], &arr[min]);
    }
    if(flag == 0)
        printf("\nThe array is already sorted.");
}

void mergeSort(int *arr, int lowbound, int upbound)
{
    if(lowbound < upbound)
    {
        int mid = (lowbound + upbound)/2;
        mergeSort(arr, lowbound, mid);
        mergeSort(arr, mid+1, upbound);
        merge(arr, lowbound, mid, upbound);
    }
}

void printarr(int *arr, int size)
{
    printf("\nThe sorted array is: ");
    for(int i=0; i<size; i++)
        printf(" %d ", arr[i]);
}

void main()
{
    int size, choice, *arr, lbound=0;
    char ch;

    do
    {
        printf("\nEnter the size of the array: ");
        scanf("%d", &size);

        arr = (int *)malloc(size * sizeof(int));

        printf("\nEnter the elements: ");
        for(int i=0; i<size; i++)
        {
            printf("\nEnter %d element: ", i+1);
            scanf("%d", &arr[i]);
        }
            printf("\nEnter your choice: \n1.Bubble sort \n2.Insertion sort \n3.Selection sort \n4.Merge Sort \n");
            scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                bubbleSort(arr, size);
                break;

            case 2:
                insertionSort(arr, size);
                break;

            case 3:
                selectionSort(arr, size);
                break;

            case 4:
                mergeSort(arr, lbound, size-1);
                break;

            default:
                printf("\nWrong choice.");
        }
        printarr(arr, size);
        fflush(stdin);
        printf("\nPress Y to continue: ");
        scanf("%c", &ch);
    } while (ch == 'Y' || ch == 'y');
    free(arr);
}