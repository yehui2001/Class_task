#include <stdio.h>
#include <stdlib.h>
#define flag '3'
#define n 10
#define iter 26

typedef struct node *node_pointer;

//Define Sequence_List struct
typedef struct SeqList_struct
{
    int  length;    //已存储
    char *element;  //地址
    /* data */
} *SeqList;

//Define Linked_list struct
struct node
{
    char text;
    //node_pointer Lp;
    node_pointer Rp;
    /* data */
};

//Linked_list initialization
node_pointer node_create(){
    int i;
    char text = 'a';
    node_pointer header,p,q;
    header = (node_pointer)malloc(sizeof(node_pointer));
    q = header;
    //q->text = text; 
    q->Rp = NULL;
    for(i = 0; i <=iter; i++){
        p = (node_pointer)malloc(sizeof(node_pointer));
        p->text = text++;
        p->Rp = NULL;
        q->Rp = p;
        q = p;
    }
    return header;
}

// Read Linked_list
void node_read(node_pointer p){
    while(p->Rp != NULL){
        putchar(p->text);
        //printf("\n");
        p = p->Rp;
    }
    printf("\n");
}

node_pointer node_delete(node_pointer p,int j,int k){
    int l = 1;
    node_pointer r;
    node_pointer q;
    // find the position of i+1
    for(int i = 0; i < j; i++)
    {
        r = p;
        p = p->Rp;
    }
    printf("%c",r->text);
    //通过指向开始删除的节点的指针，删除从开始删除位置到最后删除位置的所有节点，并找到指向最后要删除节点的后驱节点的指针
    for(int l = 0; l < k; l++)
    {
        q = p;
        p = p->Rp;
        //free(q);
    }  
    r->Rp = p;
}

// SeqList_Create initialization
SeqList SeqList_Create(int m){
    SeqList p;
    char text = 'a';
    p = (SeqList)malloc(sizeof(SeqList));
    p->element = (char*)malloc(sizeof(char) * m);
    for(int j = 0; j <= m ; j++)
    {
        p->length = j;
        //p->element[j] = text++;
        scanf("%c",&p->element[j]);
    }
    return p;
}

// Read SeqList
void SeqList_Read(SeqList L){
    SeqList list = L;
    for(int i = 0; i < list->length; i++){
        printf("%c",list->element[i]);
    }
}

// SeqList_Inversion
void SeqList_Transform(SeqList L){
    char q;
    SeqList list = L;
    printf("\n逆置后的顺序:");
    int i = 0;
    while(i <list->length-1-i)
    {
        q = list->element[i];
        list->element[i] = list->element[(list->length-1-i)];
        list->element[(list->length-1-i)] = q;
        i++;
    } 
}

// Find and delete the all x in the SeqList
void SeqList_Delete(SeqList list,char x){ //查找所有等于x的值并删除
    for(int i = 0; i < n; i++){
        if(list->element[i] == x)
        {
            
            for(int j = i; j < n; j++)
            {
                list->element[j] = list->element[j+1];
            }
            list->length--;
            i--; //因为发生前移，可能第一个x后面还是x,导致原本处于i+1处的x值跑到i处，从而找不到。
        }
    }
}

int main(){
    switch (flag)
    {//case '1'  '2'  represent the 
    case '1':{
        SeqList list = SeqList_Create(n);
        SeqList_Read(list);
        SeqList_Transform(list);
        printf("\n");
        SeqList_Read(list);
        break;
    }

    case '2':{
        SeqList list2 = SeqList_Create(n);
        SeqList_Read(list2);
        printf("\n");
        SeqList_Delete(list2,'a');
        SeqList_Read(list2);
        break;
    }

    case '3':{
        node_pointer p;
        node_pointer list3 = node_create(n);
        node_read(list3);
        node_delete(list3,1,3);// From the first node delete to  the third node.
        node_read(list3);
    }
    case '4':
        break;
    }
    
    return 0;
}