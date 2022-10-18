#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int info;
	struct node *next;
}*start=NULL;

void create(int data);
void add_start(int data);
void add_after(int data,int pos);
void add_end(int data);
void del(int data);
void display();

void main()
{
	while(1)
	{
		int ch,i,n,m,pos;
		printf("\n1. Create a list\n2. Insert at beginning\n3. Insert at intermediate position\n4. Insertion at end position\n");
		printf("5. Deletion\n6. Display\n7. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : 
                printf("Enter how many nodes you want to create : ");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("Enter the item : ");
                    scanf("%d",&m);
                    create(m);
                }
                break;

			case 2 : 
                printf("Enter the element to be inserted : ");
                scanf("%d",&m);
                add_start(m);
                break;

			case 3 : 
                printf("Enter the element to be inserted : ");
                scanf("%d",&m);
                printf("Enter the element after which to insert : ");
                scanf("%d",&pos);
                add_after(m,pos);
                break;

			case 4 : 
                printf("Enter the element to be inserted : ");
                scanf("%d",&m);
                add_end(m);
                break;

			case 5 : 
                if(start==NULL)
                {
                    printf("The list is empty");
                    return;
                }
                printf("Enter the item for deletion : ");
                scanf("%d",&m);
                del(m);
                break;

			case 6 : 
                display();
                break;

			case 7 : 
                exit(0);
                break;

			default : 
                printf("Wrong choice!!");
		}
	}
}
void create(int data)
{
	struct node *q,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->next=NULL;
	if(start==NULL)
	{
		tmp->prev=NULL;
		start=tmp;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
		     q=q->next;
		q->next=tmp;
		tmp->prev=q;
	}
}
void add_start(int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->prev=NULL;
	tmp->info=data;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
}
void add_after(int data,int pos)
{
	struct node *tmp,*q;
	int i;
	q=start;
	for(i=0;i<pos-1;i++)
	{
		q=q->next;
		if(q==NULL)
		{
			printf("There are less than %d elements\n");
			return;
		}
	}
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	q->next->prev=tmp;
	tmp->next=q->next;
	tmp->prev=q;
	q->next=tmp;
}
void add_end(int data)
{
	struct node *q,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->next=NULL;
	if(start==NULL)
	{
		tmp->prev=NULL;
		start=tmp;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
		     q=q->next;
		q->next=tmp;
		tmp->prev=q;
	}
}
void del(int data)
{
	struct node *q,*tmp;
	if(start->next==NULL && start->info==data)
	{
		tmp=start;
		free(tmp);                
		start=NULL;
		return;
	}
	if(start->info==data)
	{
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);               
		return;
	}
	q=start;
	while(q->next->next!=NULL)
	{
		if(q->next->info==data)
		{
			tmp=q->next;
			q->next=tmp->next;
			tmp->next->prev=q;
			free(tmp);           
			return;
		}
		q=q->next;
	}
	if(q->next->info==data)
	{
		tmp=q->next;
		free(tmp);               
		q->next=NULL;
		return;
	}
	printf("Element %d not found\n",data);
}
void display()
{
	struct node *q;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	q=start;
	printf("List is : \n");
	while(q!=NULL)
	{
		printf("%d ",q->info);
		q=q->next;
	}
	printf("\n");
}