#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int);
void dequeue(void);
void display(void);
void peek(void);
int main()
{
    enqueue(2);
    enqueue(8);
    enqueue(6);
    enqueue(34);
    enqueue(55);
    display();
    dequeue();
    peek();
    display();
    dequeue();
    display();
    
}
void enqueue( int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(rear==NULL)
    {
        front=rear=newnode;
        rear->next=front;
        printf("inserted element is %d",x);
        printf("\n");
    }
     else
     {
         rear->next=newnode;
         rear=newnode;
         rear->next=front;
         printf("inserted element is %d",x);
        printf("\n");
     }
}
void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==NULL&&rear==NULL)
    {
     printf("underflow");
     printf("\n");
	}
    else if(front==rear)
    {
        printf("deleted element is  %d",temp->data);
        printf("\n");
        front=rear=NULL;
        free(temp);
    }
    else
    {
    	 printf("deleted element is  %d",temp->data);
        printf("\n");
		front=front->next;
        rear->next=front;
        free(temp);
    }
}
 void peek()
    {
        if(front==NULL&&rear==NULL)
    printf("underflow");
     else
     {
     	printf("toppest elements is  %d",front->data);
     	printf("\n");
	 }
     
        
    }
  void display()
  {
      struct node *temp;
      temp=front;
       if(front==NULL&&rear==NULL)
    printf("underflow");
     else
	 {
     	printf("elements are: ");
         while(temp->next!=front)
         {
             printf("  %d",temp->data);
             temp=temp->next;
         }
         printf("  %d",temp->data);
     }
      printf("\n");

  }  