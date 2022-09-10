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

void read(node_pointer p){
    while(p->Rp != NULL){
        putchar(p->text);
        //printf("\n");
        p = p->Rp;
    }
    printf("\n");
}

/* flag:-1 表示查找前驱节点，0 表示查找当前节点，1 表示查找后继节点*/
node_pointer find_pointer(node_pointer p, char target,int flag){ 
switch(flag){
    case -1:    while(p->Rp->text != target){p = p->Rp; };break;

    case 0:     while(p->text != target){p = p->Rp; };break;

    case 1:     while(p->text != target){p = p->Rp->Rp; };break;
    }
    return p;
}

void delete_cell(node_pointer p, char target){
    node_pointer target_cell = find_pointer(p, target, -1);
    target_cell->Rp = target_cell->Rp->Rp;
    //free(target_cell);
}

void insert(node_pointer p, char target, char insert_value){
    node_pointer insert_cell = (node_pointer)malloc(sizeof(node_pointer));
    insert_cell->text = insert_value; 
    p = find_pointer(p, target, 0);
    insert_cell->Rp = p->Rp;
    p->Rp = insert_cell;
}

int main()
{
    char target,insert_value;
    target = 'b';
    insert_value = 'o';
    node_pointer header;
    header = create();
    read(header);
    insert(header, target, insert_value);
    delete_cell(header,'x');
    delete_cell(header,'z');
    read(header);
    //getchar();
    //system("pause");
    return 0;
}