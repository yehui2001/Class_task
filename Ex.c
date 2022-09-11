#include <stdio.h>
#include <stdlib.h>
#define n 10
#define flag '2'
#define iter 26

//Define Sequence_List struct
typedef struct SeqList_struct
{
    int  length;    //已存储
    char *element;  //地址
    /* data */
} *SeqList;

//Define Linked_list struct
typedef struct node
{
    char text;
    //node_pointer Lp;
    node_pointer Rp;
    /* data */
}*node_pointer;

//Linked_list initialization
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

// Read Linked_list
void read(node_pointer p){
    while(p->Rp != NULL){
        putchar(p->text);
        //printf("\n");
        p = p->Rp;
    }
    printf("\n");
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
        SeqList list3 = SeqList_Create(n);








    }
    default:
        break;
    }
    
    return 0;
}