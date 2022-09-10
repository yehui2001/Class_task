#include <stdio.h>
#include <stdlib.h>
#define n 10

typedef struct SeqList
{
    int  length;    //已存储
    char *element;  //地址
    /* data */
} *SeqList;

SeqList SeqList_Create(int m){
    SeqList p;
    char text = 'a';
    p = (SeqList)malloc(sizeof(SeqList));
    p->element = (char*)malloc(sizeof(char) * m);
    for(int j = 0; j <= m ; j++)
    {
        p->length = j;
        p->element[j] = text++;
    }
    return p;
}

void SeqList_Read(SeqList L){
    SeqList list = L;
    for(int i = 0; i < list->length; i++){
        printf("%c",list->element[i]);
    }
}

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

int main(){
    SeqList list = SeqList_Create(n);
    SeqList_Read(list);
    SeqList_Transform(list);
    printf("\n");
    SeqList_Read(list);
    return 0;
}