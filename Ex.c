#include <stdio.h>
#include <stdlib.h>
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
    //q->text = text; //无头节点需要注释此处
    q->Rp = NULL;
    for(i = 0; i <=iter; i++){
        p = (node_pointer)malloc(sizeof(node_pointer));
        if(i%3 ==0){text++;}
        p->text = text;
        p->Rp = NULL;
        q->Rp = p;
        q = p;
    }
    return header;
}

node_pointer node_generator(int length, char word[]){
    char *word_pointer = word;
    node_pointer header,p,q;
    header = (node_pointer)malloc(sizeof(node_pointer));
    q = header;
    //q->text = text; //无头节点需要注释此处
    q->Rp = NULL;
    for(int i = 0; i <=length; i++){
        p = (node_pointer)malloc(sizeof(node_pointer));
        //if(i%3 ==0){text++;}
        p->text = *word++;
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
    putchar(p->text);//打印末节点的text
    printf("\n");
}

// Delete the particular nodes which are located in specified position  
void node_delete(node_pointer p,int j,int k){
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

int node_length(node_pointer p){
    int length = 0;
    while(p->Rp != NULL){
        length++;
        p = p->Rp;
    }
    return(length);
}

//
void node_merge(node_pointer p){
    node_pointer q; 
    while(p->Rp != NULL){
        q = p;
        while(q->Rp != NULL){
            if(q->Rp->text == p->text){
                q->Rp = q->Rp->Rp;
            }
            else{
                q = q->Rp;
            }
        }
        if(p->Rp != NULL)p = p->Rp;
    }
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

#define flag '0'

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
        node_pointer list3 = node_create();
        node_read(list3);
        node_delete(list3,1,3);// From the first node delete to  the third node.
        node_read(list3);
    }
    case '4':{
        node_pointer list4 = node_create();
        node_read(list4);
        node_merge(list4);
        node_read(list4);
        break;
    }
    case '0':{
        char word[] = "aabbaabbbaaababbaaaerhjfklawkerhfajkwelfabbah.f/./../.@#$$*&^%&*^%*^&&*(^&^$&^%$$%^$*^(&^(*&%&*(%*^$&#%^jfffdjkalwkjdfkabbaaababbaaababbaaabab";
        node_pointer p = node_generator(sizeof(word), word);
        node_read(p);
        node_merge(p);
        node_read(p);
        //printf('6');
    }
    }
    return 0;
}