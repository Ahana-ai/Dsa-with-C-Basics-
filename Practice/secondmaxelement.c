#include<stdio.h>

void main()
{
    int arr[10], n, i, max, s_max;
    printf("\nEnter the number of elements of the array: ");
    scanf("%d", &n);

    printf("\nEnter the elements: ");;
    for(i=0; i<n; i++)
    {
        printf("\nEnter %d element: ",i+1);
        scanf("%d", &arr[i]);
    }

    max = arr[0] = s_max;
    for(i=0; i<n; i++)
    {
        if(arr[i]>max)
        {
            s_max = max;
            max = arr[i];
        }
    
        else if(arr[i] < max && arr[i] > s_max)
            s_max = arr[i];
    }

    printf("\nThe second maximum of the array is: %d", s_max);
    printf("\nThe maximum number of the array is: %d", max);
}