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

typedef struct SeqList
{
    int  length;    //已存储
    char *element;  //地址
    /* data */
} *SeqList;


SeqList SeqListinput(int m){
    SeqList p;
    char text = 'a';
    p = (SeqList)malloc(sizeof(SeqList));
    p->element = (char*)malloc(sizeof(char) * m);
    //L.element=(char*)malloc(sizeof(char) * m);
    for(int j = 0; j <= m ; j++)
    {
        p->length = j;
        p->element[j] = text++;
    }
    return p;
}

void SeqListDestory(SeqList L){
        //printf("%s",*(L.element));
}


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
 
void update(node_pointer p, char target, char update_value){
    node_pointer update_cell = find_pointer(p, target, 0);
    update_cell->text = update_value;
}

int main()
{
    char flag;
    printf("Input Flag:");
    //flag = getchar();
    flag = 'b';
    switch(flag){
        case 'a':{
            printf("Use Method Link List\n");
            char target,insert_value;
            target = 'b';
            insert_value = 'o';
            node_pointer header;
            header = create();
            read(header);
            insert(header, target, insert_value);
            update(header, 'x', 'a');
            delete_cell(header,'z');
            read(header);
            //getchar();
            //system("pause");
            break;
        }   
        case 'b':{
            printf("Use Method Traditional List\n");
            //SeqList L;
            SeqList list = SeqListinput(26);
            for(int i = 0; i < list->length; i++){
                printf("%c",list->element[i]);
            }
            //SeqListDestory(L);
            //printf("%s",*L.element);
            break;
        }
        default:{
            printf("Thank you");
        }    
    }
    return 0;
}