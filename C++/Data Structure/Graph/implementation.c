#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct list
{
    struct node *head;
};
struct Graph
{
    int v;
    struct list *array;
};
struct node *createnode(int);
struct Graph *creategraph(int );
void addEdge(struct Graph* , int , int);
void print(struct Graph*);

int main()
{
    int n,d,s;
    printf("enter number of vertixes ");
    scanf("%d",&n);
    struct Graph *graph = creategraph(n);
    addEdge(graph, 0, 1); 
	addEdge(graph, 0, 4); 
	addEdge(graph, 1, 2); 
	addEdge(graph, 1, 3); 
	addEdge(graph, 1, 4);  
	addEdge(graph, 2, 3); 
	addEdge(graph, 3, 4);
    print(graph);
}

struct Graph * creategraph(int p)
{
    int i;
    struct Graph *g=(struct Graph*)malloc(sizeof(struct Graph));
    g->v=p;
    g->array=(struct list*)malloc(p * sizeof(struct list));
    for(i=0;i<p;i++)
        g->array[i].head=NULL;
    return g;
}

void addEdge(struct Graph* graph,int src,int dest)
{
    struct node* temp=createnode(dest);
    temp->next=graph->array[src].head;
    graph->array[src].head=temp;

    temp = createnode(src);
    temp->next = graph->array[dest].head;
    graph->array[dest].head = temp; 

}

struct node * createnode(int x)
{
    struct node *q=(struct node *)malloc(sizeof(struct node));
    q->data=x;
    q->next=NULL;
    return q;
}

void print(struct Graph * graph)
{
    int v;
    for(v=0;v<graph->v;v++)
    {
        struct node *trav=graph->array[v].head;
        printf("adjecenty list of vertex %d",v);
        while (trav!=NULL)
        {
            printf("->%d",trav->data);
            trav=trav->next;
        }
        printf("\n");
    }
}


