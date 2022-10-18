 #include<stdio.h>
 #include<stdlib.h>

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

void insertNodeatStart(int data)
{
    Node *temp, *q;
    temp = (Node*)malloc(sizeof(Node));
    q = head;
    temp->info= data;
    temp->link = q;
    head = temp;
}

void insertNodeatMid(int data, int x)
{
    Node *temp, *q;
    q = head;
    for(int i=1; i<x; i++)
        q = q->link; 

    temp = (Node*)malloc(sizeof(Node));
    temp->info = data;
    temp->link = q->link;
    q->link = temp;
}

void deleteNode(int data)
{
    Node *t1, *t2;
    t1 = head;
    t2 = head->link;
    if(head->info == data)
    {
        head = t2;
        free(t1);
        return;
    }
    while(t2->info != data)
    {
        t1 = t2;
        t2 = t2->link;
        if(t2 == NULL)
        {
            printf("\nThe value is not present in the list.");
            return;
        }
    }
    t1->link = t2->link;
    free(t2);
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

void countNodes()
{
    Node *temp;
    int count = 0;
    temp = head;
    while(temp != NULL)
    {
        temp = temp->link;
        count++;
    }
    printf("\nThe total number of nodes in the list is: %d", count);
}

void searchNode(int data)
{
    Node *temp;
    int count = 0, flag =0;
    temp = head;
    while(temp != NULL)
    {
        count++;
        if(temp->info == data)
        {
            flag = 1;
            printf("\nThe element %d found at %d number in the list.", data, count);
            return;
        }
        temp = temp->link;
    }
    if(flag == 0)
    printf("\nThe given value is not present in the list.");
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

 void main()
 {
     int choice, n, data, x;
     char ch;
     printf("\nEnter the number of nodes you want: ");
     scanf("%d", &n);
     for(int i=0; i<n; i++)
     {
         printf("\nEnter the element: ");
         scanf("%d", &data);
         createNode(data);
     }

     do
     {
        printf("\nEnter your choice: \n1.Insert a node at end \n2.Insert a node at beginning \n3.Insert a node at the middle \n4.Delete a node \n5.Display the list \n");
        printf("6.Count the number of nodes \n7.Search an element \n8.Reverse the list \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the new element: ");
                scanf("%d", &data);
                createNode(data);
                break;

            case 2:
                printf("\nEnter the new element: ");
                scanf("%d", &data);
                insertNodeatStart(data);
                break;

            case 3:
                printf("\nEnter the position after which you want to insert the element: ");
                scanf("%d", &x);
                printf("\nEnter the new element: ");
                scanf("%d", &data);
                insertNodeatMid(data, x);
                break;

            case 4:
                if(head == NULL)
                {
                    printf("\nThe list is empty.");
                    break;
                }
                else
                {
                    printf("\nEnter the data you want to delete: ");
                    scanf("%d", &data);
                    deleteNode(data);
                    break;
                }

            case 5: 
                if(head == NULL)
                {
                    printf("\nThe list is empty.");
                    break;
                }
                traverse();
                break;

            case 6:
                if(head == NULL)
                {
                    printf("\nThe list is empty.");
                    break;
                }
                if(head->link == NULL)
                {
                    printf("\nThe list has only one element %d. ", head->info);
                    break;
                }
                countNodes();
                break;

            case 7:
                if(head == NULL)
                {
                    printf("\nThe list is empty.");
                    break;
                }
                printf("\nEnter the element you want to search for: ");
                scanf("%d", &data);
                searchNode(data);
                break;

            case 8:
                if(head == NULL)
                {
                    printf("\nThe list is empty.");
                    break;
                }
                if(head->link == NULL)
                {
                    printf("\nThe list has only one element %d. ", head->info);
                    break;
                }
                reverseList();
                break;

            default:
                printf("\nWrong choice!");
        }
        fflush(stdin);
        printf("\nPress Y to continune: ");
        scanf("%c", &ch);
     } while (ch == 'Y' || ch == 'y');
 }