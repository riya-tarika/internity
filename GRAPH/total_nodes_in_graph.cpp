#include<cstdio>
#include<conio.h>
#include<cstdlib>
 
#define MAX 10  
 
#define init 1 //initial
#define wait 2  //waiting
#define vis 3   //visiting
 
int n;    
int adj[MAX][MAX];
int s[MAX]; 
void create_graph();
void BFS_Traversal();
void BFS(int v);
 
int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
 
int main()
{
    create_graph();
    BFS_Traversal();
    return 0;
}
 
void BFS_Traversal()
{
    int v;
    
    for(v=0; v<n; v++) 
        s[v] = init;
    
    printf("Enter Start Vertex for BFS: \n");
    scanf("%d", &v);
    BFS(v);
}
 
void BFS(int v)
{
    int i;
    
    insert_queue(v);
    s[v] = wait;
    
    while(!isEmpty_queue())
    {
        v = delete_queue( );
        printf("%d ",v);
        s[v] = vis;
        
        for(i=0; i<n; i++)
        {
            if(adj[v][i] == 1 && s[i] == init) 
            {
                insert_queue(i);
                s[i] = wait;
            }
        }
    }
    printf("\n");
}
 
void insert_queue(int vertex)
{
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1) 
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}
 
int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}
 
int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    
    delete_item = queue[front];
    front = front+1;
    return delete_item;
}
 
void create_graph()
{
    int count,max_edge,origin,destin;
 
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    max_edge = n*(n-1);
 
    for(count=1; count<=max_edge; count++)
    {
        printf("Enter edge %d( -1 -1 to quit ) : ",count);
        scanf("%d %d",&origin,&destin);
 
        if((origin == -1) && (destin == -1))
            break;
 
        if(origin>=n || destin>=n || origin<0 || destin<0)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}
