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
        p->text = ++text;
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
        //printf("\n");
        p = p->Rp;
    }
    printf("\n");
}

void insert(node_pointer header, char target, char insert_value){
    node_pointer p;
    p =  header;
    node_pointer insert_cell = (node_pointer)malloc(sizeof(node_pointer));
    insert_cell->text = insert_value;
    while(p->text != target)
    {
        p = p->Rp; 
    }
    insert_cell->Rp = p->Rp;
    p->Rp = insert_cell;

}

int main()
{
    char target,insert_value;
    target = 'b';
    insert_value = 'k';
    node_pointer header;
    header = create();
    read(header);
    insert(header, target, insert_value);
    read(header);    
    return 0;
}