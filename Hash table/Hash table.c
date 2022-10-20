#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define maxsize 13

/*链地址法(拉链法),将地址相同的数据元素用一个单链表🔗,将其他地址不同的放入线性表中*/

/*定义单链表*/
typedef struct link *link_pointer,link;
struct link{
    int data;
    link_pointer next;
};

/*定义线性表*/
typedef struct table *table_pointer,table;
struct table{
    int length; //链地址表的目前长度；
    //link *elem;采用动态分配时，未成功分配到空间。
    link elem[maxsize];
};

/*线性表初始化*/
table_pointer table_init(table *t){
    t = (table_pointer)malloc(sizeof(table));
    //t->elem =(link_pointer)malloc(sizeof(link) * maxsize);
    t->length = 0;
    return t;
}

/*Hash 函数*/
void Hash(table *t,int *num){
    link_pointer p,q,header;
    for(int i = 0; i < maxsize; i++){
        int temp = num[i]%13;
        if(t->elem[temp].data == 0){
            temp = num[i]%13;
            //t->elem[temp].next->data = 6;没有分配上空间
            //t->elem[temp].next = NULL;
            q = (link_pointer)malloc(sizeof(link));
            q->data = num[i];
            q->next = NULL;
            t->elem[temp].data = num[i];
            // p->next = NULL;
            // q->next = p;
            // q = p;
            t->length++;
        }
        else{
            //t->elem[temp].next = (link_pointer)malloc(sizeof(link));
            //p = t->elem[temp].next;
            //t->elem[temp].data = num[i];
            q = (link_pointer)malloc(sizeof(link));
            q->data = num[i];
            q->next = NULL;

            t->elem[temp].next = q;
        }
    }
    printf("Hash successed");
}

/*读取表中内容*/

int main()
{
    table t;
    table *T = table_init(&t);
    int num[13] = {14,27,40,3,4,27,14,7,8,9,10,11,12};
    Hash(T,num);
    return  0;
}