#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* link;
}*top = NULL;

void push()
{
    struct Node *temp;
    int value;
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter new element: ");
    scanf("%d", &value);
    temp->data = value;
    temp->link = NULL;
    if(top == NULL)
        top = temp;
    else
    {
        temp->link = top;
        top = temp;
    }
}

void pop()
{
    struct Node *ptr;
    if(top == NULL)
        printf("\nThe Stack is empty.");
    else
    {
        ptr = top;
        printf("\nPopped element is %d.", ptr->data);
        top = ptr->link;
        free(ptr);
    }
}

void display()
{
    struct Node *ptr;
    if(top == NULL)
        printf("\nThe Stack is empty.");
    else
    {
        ptr = top;
        while(ptr != NULL)
        {
            printf(" %d ", ptr->data);
            ptr = ptr->link;
        }
    }
}

void main()
{
    int choice;
    char ch;
    do
    {
        printf("\nEnter your choice: \n1.Push \n2.Pop \n3.Display\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            default:
                printf("\nWrong Choice!");

        }
        fflush(stdin);
        printf("\nPress Y to continue: ");
        scanf("%c", &ch);
    }while(ch == 'Y' || ch == 'y');
    
}