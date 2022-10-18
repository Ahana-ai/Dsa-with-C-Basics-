#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
   int *queue;
   int front, size, rear;
}DeQueue;

void createQueue(DeQueue *arr);
void InputRestricted(DeQueue *arr);
int InsertLeft(DeQueue *arr);
int InsertRight(DeQueue *arr);
void OutputRestricted(DeQueue *arr);
int DeleteLeft(DeQueue *arr);
int DeleteRight(DeQueue *arr);
int Display(DeQueue *arr);

void createQueue(DeQueue *arr)
{
    arr = (DeQueue*)malloc(sizeof(int));
}

void InputRestricted(DeQueue *arr)
{
    int choice;
    char ch;
    do
    {
        printf("\n1.Input from right. \n2.Delete from left. \n3.Delete from right. \n4.Display. \nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                InsertRight(arr);
                break;

            case 2:
                DeleteLeft(arr);
                break;

            case 3:
                DeleteRight(arr);
                break;

            case 4:
                Display(arr);
                break;

            default:
                printf("\nWrong choice!");
                break;
        }
        fflush(stdin);
        printf("\nPress Y to continue: ");
        scanf("%c", &ch);
    } while (ch == 'Y' || ch == 'y');
}

int InsertLeft(DeQueue *arr)+
{
    int value;
    if((arr->front == 0 && arr->rear == arr->size-1) || (arr->front == arr->size-1))
    {
        printf("\nQueue Overflow!");
        return 0;
    }

    if(arr->front == -1)//for first element in queue
    {
        arr->front = 0;
        arr->rear = 0;
    }

    else if(arr->front == 0)
    {
        arr->front = arr->size-1;
    }

    else
    {
        arr->front -= 1;
        printf("\nEnter the element: ");
        scanf("%d", &value);
        arr->queue[arr->front] = value;
    }
}

int InsertRight(DeQueue *arr)
{
    int value;
    if((arr->front == 0 && arr->rear == arr->size-1) || arr->front == arr->size-1)
    {
        printf("\nQueue Overflow!");
        return 0;
    }

    if(arr->front == -1)
    {
        arr->front = 0;
        arr->rear = 0;
    }

    else if(arr->rear == arr->size-1)
    {
        printf("\nThe queue is full from right.");
        return 0;
    }

    else
    {
        printf("\nEnter the element: ");
        scanf("%d", &value);
        arr->queue[++arr->rear] = value;
    }
}

void OutputRestricted(DeQueue *arr)
{
    int choice;
    char ch;
    do
    {
        printf("\n1.Delete from left. \n2.Input from left. \n3.Input from right. \n4.Display. \nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                DeleteLeft(arr);
                break;

            case 2:
                InsertLeft(arr);
                break;

            case 3:
                InsertRight(arr);
                break;

            case 4:
                Display(arr);
                break;

            default:
                printf("\nWrong choice!");
                break;
        }
        fflush(stdin);
        printf("\nPress Y to continue: ");
        scanf("%c", &ch);
    } while(ch == 'Y' || ch == 'y');
}

int DeleteLeft(DeQueue *arr)
{
    if(arr->front == -1)
    {
        printf("\nQueue Underflow!");
        return 0;
    }

    printf("\nThe element deleted was: %d", arr->queue[arr->front]);

    if(arr->front == arr->rear)
    {
        arr->front = -1;
        arr->rear = -1;
    }
    else if(arr->front == arr->size-1)
       arr->front = 0;
    else
        arr->front += 1;
}

int DeleteRight(DeQueue *arr)
{
    if(arr->front == -1)
    {
        printf("\nQueue Underflow!");
        return 0;
    }

    printf("\nThe element deleted was: %d", arr->queue[arr->rear]);

    if(arr->front == arr->rear)
    {
        arr->front = -1;
        arr->rear = -1;
    }
    else if(arr->rear == 0)
       arr->rear = arr->size-1;
    else
    arr->rear -= 1;
}

int Display(DeQueue *arr)
{
    if(arr->front == -1)
    {
        printf("\nQueue Underflow!");
        return 0;
    }

    printf("\nThe Queue elements: ");
    int i = arr->front;
    if(arr->front <= arr->rear)
    {
        while(i<= arr->rear)
        {
            printf(" %d ", arr->queue[i]);
            i++;
        }
    }
    else
    {
        i = 0;
        while(i <= arr->rear)
        {
            printf(" %d ", arr->queue[i]);
            i++;
        }
    }
}

void main()
{
    int choice;
    char ch;
    DeQueue arr;
    arr.front = -1;
    arr.rear = -1;
    printf("\nEnter the size of the Dequeue: ");
    scanf("%d", &arr.size);
    createQueue(&arr);
    do{
        printf("\n1.Input restricted Dequeue. \n2.Output restricted Dequeue. \nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                InputRestricted(&arr);
                break;

            case 2:
                OutputRestricted(&arr);
                break;

            default:
                printf("\nWrong choice.");
        }
        fflush(stdin);
        printf("\nPress Y to continue: ");
        scanf("%c", &ch);
    }while(ch == 'Y' || ch == 'y');
    free(arr);
}