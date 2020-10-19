#include<stdio.h>
#include<conio.h>
#define MAX 30
typedef struct node
{
  int vertex;
  struct node *next;
}node;
typedef struct q
{
  int r,f;
  int data[MAX];
}q;
node *g[20];                                    
int n;                                          
int visited[MAX];
void creategraph();               
void insert(int vi,int vj);
void bfs(int i);
void dfs(int i);
void enquee(q *,int);
int dequee(q *);
int empty(q *);
int full(q *);
void main()
{
  int i,k;
  do
   {
        printf("\n1.CREATE A GRAPH\n2.DFS\n3.BFS\n4.QUIT.");
        printf("\nEnter your choice:");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
                creategraph();
                break;
            case 2:
                for(i=0;i<n;i++)
                visited[i]=0;
                printf("\nEnter the start node:");
                scanf("%d",&i);
                dfs(i);
                break;
            case 3:
                printf("\nEnter the start node:");
                scanf("%d",&i);
                bfs(i);
                break;
        }
   }
   while(k!=4);
}
void creategraph()
{
    int i,j,vi,vj,no;
    printf("\nEnter the no. of vertices:");
    scanf("%d",&n);
    for(i=0;i<n;i++)                
        g[i]=NULL;
    printf("\nEnter the no. of edges:");         
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
        printf("\nEnter the edge(u,v):");
        scanf("%d%d",&vi,&vj);
        insert(vi,vj);
        insert(vj,vi);
    }

}
void insert(int vi,int vj)
{
    node *p,*q;
    q=(node*)malloc(sizeof(node));         
    q->vertex=vj;
    q->next=NULL;


    if(g[vi]==NULL)
        g[vi]=q;                             
    else
    {
        p=g[vi];
        while(p->next!=NULL)                      
            p=p->next;
        p->next=q;
    }
}
void dfs(int i)
{
    node *p;
    p=g[i];
    visited[i]=1;
    printf("\nVisit->%d",i);
    while(p!=NULL)
    {
        i=p->vertex;                                         // next connected vertexs
        if(!visited[i])
            dfs(i);
        else
            p=p->next;
    }
}
void bfs(int v)
{
    int i,w;
    q x;
    node *p;
    x.r=x.f=-1;               
    for(i=0;i<n;i++)
    visited[i]=0;

    enquee(&x,v);
    printf("\nVisit->%d",v);
    visited[v]=1;
    while(!empty(&x))
    {
        v=dequee(&x);
        for(p=g[v];p!=NULL;p=p->next)
        {
            w=p->vertex;                              // w is all connected vertexs ...
            if(visited[w]==0)
            {
                enquee(&x,w);
                visited[w]=1;
                printf("\nVisit->%d",w);
            }
        }
    }
}
int empty(q *p)
{
    if(p->r==-1 &&p->f==-1)
        return(1);
    else
        return(0);
}

int full(q *p)
{
    if(p->r==MAX-1)
        return(1);
    return(0);
}

void enquee(q *p,int x)
{
    if(p->r==-1)
    {
        p->r=p->f=1;
    }
    else
        p->r=p->r+1;
    p->data[p->r]=x;
}

int dequee(q *p)
{
    int x;
    x=p->data[p->f];
    if(p->f==p->r)
        p->r=p->f=-1;
    else
        p->f=p->f+1;
    return(x);
}



