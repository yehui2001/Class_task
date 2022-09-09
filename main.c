#include <stdio.h>
#include <stdlib.h>

#define iter 26

typedef struct node *node_pointer;

struct node
{
    char text;
    //node_pointer Lp;
    node_pointer Rp;
    /* data */
};

node_pointer create(){
    int i;
    char text = 'a';
    node_pointer header,p,q;
    header = (node_pointer)malloc(sizeof(node_pointer));
    q = header;
    q->text = text;
    q->Rp = NULL;
    for(i = 0; i < iter; i++){
        p = (node_pointer)malloc(sizeof(node_pointer));
        p->text = text++;
        p->Rp = NULL;
        q->Rp = p;
        q = p;
    }
    return header;
}

void read(node_pointer header){
    node_pointer p = header;
    while(p->Rp != NULL){
        putchar(p->text);
        printf("\n");
        p = p->Rp;
    }
}

int main()
{
    node_pointer header;
    header = create();
    read(header);    
    return 0;
}