#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* last = NULL;

void createNode(int info)
{
    struct  Node* newNode;  
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = info;
    newNode->next = NULL;

    if(last == NULL)
    {
        last = newNode;
        newNode->next = last;
    }

    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void insertNodeatStart(int info)
{
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = info;
    newNode->next = last->next;
    last->next = newNode;    
}

void insertNodeatMid(int info, int x)
{
    struct Node *newNode, *temp;
    int i;
    temp = last->next;
    for(i=0; i<x; i++)
    {
        temp = temp->next;
        if(temp == last->next)
        {
            printf("\nInvalid position.");
            return;
        }
    }
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = temp->next;
    newNode->data = info;
    temp->next = newNode;
    if(temp == last)
        last = newNode;
}

void delete(int info)
{
    struct Node *tmp,*q;
    if(last->next==last && last->data==info) /* Only one element */
    {
        tmp=last;
        last=NULL;
        free(tmp);
        return;
    }
    q=last->next;
    if(q->data==info) /* deletion of first node*/
    {
        tmp=q;
        last->next = q->next;
        free(tmp);
        return;
    }
    while(q->next != last)
    {
        if(q->next->data == info) /* Element deleted in between*/
        {
            tmp = q-> next;
            q->next = tmp->next; 
            free(tmp);
            printf("\n%d deleted", info);
            return;
        }
        q = q->next;
    }
    if(q->next->data == info) /*Last element deleted*/
    {
        tmp = q->next; 
        q->next = last->next;
        free(tmp);
        last = q;
        return;
    }
    printf("\nElement %d not found", info);
}

void display()
{
    struct Node *temp;
    if(last == NULL)
    {
        printf("\nThe list is empty.");
    }
    temp = last->next;
    printf("\nThe list is: ");
    while(temp != last)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf(" %d ", last->data);
}

void main()
{
    int choice, info, x, n;
    char ch;

    do
    {
        printf("\nEnter your choice: \n1.Createnode \n2.Insert Node at beginning \n3.Insert Node at intermediate Position.");
        printf("\n4.Insert Node at End \n5.Deletion \n6.Display\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the number of nodes you want: ");
                scanf("%d", &n);
                for(int i=0; i<n; i++)
                {
                    printf("\nEnter the element: ");
                    scanf("%d", &info);
                    createNode(info);
                }
                break;

            case 2:
                printf("\nEnter the new element: ");
                scanf("%d", &info);
                insertNodeatStart(info);
                break;

            case 3:
                printf("\nEnter the position after which you want to insert the element: ");
                scanf("%d", &x);
                printf("\nEnter the new element: ");
                scanf("%d", &info);
                insertNodeatMid(info, x);
                break;

            case 4:
                printf("\nEnter the new element: ");
                scanf("%d", &info);
                createNode(info);
                break;

            case 5:
                if(last == NULL)
                {
                    printf("\nThe list is empty.");
                    break;
                }
                else
                {
                    printf("\nEnter the element you want to delete: ");
                    scanf("%d", &info);
                    delete(info);
                    break;
                }

            case 6:
                display();
                break;

            default:
                printf("\nWrong Choice.");
        }
        fflush(stdin);
        printf("\nPress Y to continue: ");
        scanf("%c", &ch);
    }while(ch == 'Y' || ch == 'y');
}