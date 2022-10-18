#include<stdio.h>
#include<stdlib.h>
//Write a C program to create a single linked list and print the elements in reverse order.

typedef struct node
 {
     int info;
     struct node* link;
 }Node;

Node *head = NULL;

void createNode(int data)
{
    Node *temp, *q;
    temp = (Node*)malloc(sizeof(Node));
    temp->info = data;
    temp->link = NULL;

    if(head == NULL)
        head = temp;
    else
    {
        q = head;
        while(q->link != NULL)
            q = q->link;
        
        q->link = temp;
    }
}

void reverseList()
{
    Node *prevNode, *curNode;
    prevNode = head;
    curNode = head->link;
    head = curNode;
    prevNode->link = NULL;
    while(head != NULL)
    {
        head = head->link;
        curNode->link = prevNode;
        prevNode = curNode;
        curNode = head;
    }
    head = prevNode;
}

void traverse()
{
    Node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf(" %d ", temp->info);
        temp = temp->link;
    }
}

void main()
{
    int choice, n, data;
     char ch;
     printf("\nEnter the number of nodes you want: ");
     scanf("%d", &n);
     for(int i=0; i<n; i++)
     {
         printf("\nEnter the element: ");
         scanf("%d", &data);
         createNode(data);
     }

    reverseList();
    traverse();
}