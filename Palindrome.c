#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 10

typedef struct patient{
  char name;
  int no;
  char sick;  
}datatype;

typedef struct{
    int rear,front;
    datatype *elem;
    int length;
}Sequeue; 

void Queue_init(Sequeue* Q){
    Q->elem = (datatype *)malloc(sizeof(datatype)*maxsize);
    Q->rear  = 0;
    Q->front = 0;
    Q->length = 0; 
}

void Queue_insert(Sequeue* Q,datatype x){
    if(Q->rear>= maxsize)
        printf("Full queue \n");
    else
    {
        Q->elem[Q->rear -1] = x;
        Q->rear++;
        Q->length++;
    }
}


int main()
{
    int i=0 ;
    Sequeue Q;
    datatype x;
    Queue_init(&Q);
    while(i<5){
    scanf("%c",&x.name);
    scanf("%d",&x.no);
    scanf("%c",&x.sick);
    Queue_insert(&Q,x);   
    i++;   
    }
    
}