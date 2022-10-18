#include<stdio.h>
int arr[10];

void swap(int a, int b){
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

int Partition(int start, int end){
    int pivot = arr[end];
    int i = start-1;
    for(int j=start; j<end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(i,j);
        }
    }
    swap(i+1, end);
    return (i+1);
}

void QS(int start, int end){
    if(start < end){
        int q = Partition(start, end);
        QS(start, q-1);
        QS(q+1, end);
    }
}

void main(){
    int n, i;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("\nEnter %d element: ", i+1);
        scanf("%d", &arr[i]);
    }

    QS(0, n-1);
    printf("\nThe sorted array is: ");
    for(i=0; i<n; i++){
        printf(" %d ", arr[i]);
    }
}