#include<stdio.h>
#include<stdlib.h>
#define N 7
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int);
void dequeue(void);
void display(void);
void peek(void);
int main()
{
    enqueue(2);
    enqueue(45);
    enqueue(5);
    enqueue(6);
    enqueue(9);
    dequeue();
    display();
    enqueue(23);
    peek();
    display();
  
}
void enqueue(int x)
{
    if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
        printf("inserted element is %d",x);
        printf("\n");
    }
    else if((rear+1)%N==front) /*in circular queue [rear++ == (rear+1)%N]  means full condition work when rear increase and become equal to front  */
    {
        printf("queue is full");
        printf("\n");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x; 
        printf("inserted element is %d",x);
        printf("\n");    
    }
}
void dequeue()
{
    if( front==-1&&rear==-1)
    printf("queue is empty");
    else if(front==rear)
    front=rear=-1;
    else
    {
        printf("deleted element is %d",queue[front]);
        front=(front+1)%N;
        printf("\n");

    }
}
void peek()
{
    if( front==-1&&rear==-1)
    printf("queue is empty");
    else
    {
        printf("toppest element is %d",queue[front]);
        printf("\n");
    }

}
void display()
{   
    int i=front;
    if( front==-1&&rear==-1)
    printf("queue is empty");
    else
    {
        printf("queue is");
        while(i!=rear)
        {
            printf("  %d",queue[i]);
            i=(i+1)%N;
        }
        printf("  %d",queue[rear]);
        printf("\n");

    }

}